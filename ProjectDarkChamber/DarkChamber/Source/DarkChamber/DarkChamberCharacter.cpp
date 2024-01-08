// Copyright Epic Games, Inc. All Rights Reserved.

#include "DarkChamberCharacter.h"
#include "Animation/AnimInstance.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "HealthComponent.h"
#include "InputMappingContext.h"
#include"InteractInterface.h"
#include "Item.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Net/UnrealNetwork.h"
#include "Perception/AIPerceptionStimuliSourceComponent.h"
#include "Perception/AISense_Sight.h"


//////////////////////////////////////////////////////////////////////////
// ADarkChamberCharacter

void ADarkChamberCharacter::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ADarkChamberCharacter, Inventory);
	DOREPLIFETIME(ADarkChamberCharacter, InventoryMaxSize);
	DOREPLIFETIME(ADarkChamberCharacter, CurrentlySelectedInventoryItem);
	DOREPLIFETIME(ADarkChamberCharacter, CurrentItemHeld);
	DOREPLIFETIME(ADarkChamberCharacter, ItemPlaceHolderMeshComponent);
	DOREPLIFETIME(ADarkChamberCharacter, PlayerHealth);
	DOREPLIFETIME(ADarkChamberCharacter, canMove);
	DOREPLIFETIME(ADarkChamberCharacter, IsSprinting);
	DOREPLIFETIME(ADarkChamberCharacter, FirstPersonCameraComponent);
	DOREPLIFETIME(ADarkChamberCharacter, MovementVectorr);
	DOREPLIFETIME(ADarkChamberCharacter, HealthCheatIsOn);
}

ADarkChamberCharacter::ADarkChamberCharacter()
{
	//Cheats
	HealthCheatIsOn = false;
	//sprint stuff
	IsSprinting = false;
	SprintStaminaAddValue = 0.1f;
	SprintStaminaReduceValue = 0.2f;
	//character can move at start
	canMove = true;

	RunningSpeedMultiplier = 1.5f;
	DefaultWalkingSpeed = GetCharacterMovement()->MaxWalkSpeed;

	//Inventory Stuff
	CurrentlySelectedInventoryItem = Inventory.Num();

	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(55.f, 96.0f);

	// Create a CameraComponent	
	FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FirstPersonCameraComponent->SetupAttachment(GetCapsuleComponent());
	FirstPersonCameraComponent->SetRelativeLocation(FVector(-10.f, 0.f, 60.f)); // Position the camera
	FirstPersonCameraComponent->bUsePawnControlRotation = true;

	// Create a mesh component that will be used when being viewed from a '1st person' view (when controlling this pawn)
	Mesh1P = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CharacterMesh1P"));
	Mesh1P->SetOnlyOwnerSee(true);
	Mesh1P->SetupAttachment(FirstPersonCameraComponent);
	Mesh1P->bCastDynamicShadow = false;
	Mesh1P->CastShadow = false;
	Mesh1P->SetGenerateOverlapEvents(true);
	//Mesh1P->SetRelativeRotation(FRotator(0.9f, -19.19f, 5.2f));
	Mesh1P->SetRelativeLocation(FVector(-30.f, 0.f, -150.f));

	SetupStimulusSource();

	//HEALTH STUFF
	PlayerHealth = CreateDefaultSubobject<UHealthComponent>("health");
	InventoryMaxSize = 5;
}

void ADarkChamberCharacter::BeginPlay()
{
	// Call the base class  
	Super::BeginPlay();
	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<
			UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}
	PlayerStartLocation = GetActorLocation();
}

void ADarkChamberCharacter::InteractWithActor()
{
	FVector Start = GetFirstPersonCameraComponent()->GetComponentLocation();
	FVector End = Start + GetFirstPersonCameraComponent()->GetComponentRotation().Vector() * 500.0f;
	DrawDebugLine(GetWorld(), Start, End, FColor::Red, false, 3.0f, 0, 2.0f);
	FHitResult HitResult;
	FCollisionQueryParams Params;
	Params.AddIgnoredActor(this);
}

void ADarkChamberCharacter::ConstantLineTraceToCheckObjectsForward()
{
	FVector Start = GetFirstPersonCameraComponent()->GetComponentLocation();
	FVector End = Start + GetFirstPersonCameraComponent()->GetComponentRotation().Vector() * 500.0f;
	//DrawDebugLine(GetWorld(), Start, End, FColor::Purple, false, 0.1f, 0, 2.0f);
	FHitResult HitResult;
	FCollisionQueryParams Params;
	Params.AddIgnoredActor(this);
	TWeakInterfacePtr<IInteractInterface> InteractInterfaceTemp;
	if (GetWorld()->LineTraceSingleByChannel(HitResult, Start, End, ECC_Visibility, Params))
	{
		InteractInterfaceTemp = Cast<IInteractInterface>(HitResult.GetActor());
		if (InteractInterfaceTemp.IsValid())
		{
			if (currentInteractableActor != HitResult.GetActor())
			{
				currentInteractableActor = HitResult.GetActor();
				InteractInterface = Cast<IInteractInterface>(HitResult.GetActor());
				InteractInterface->OnInteractHoverBegin(this);
			}
		}
		else
		{
			if (InteractInterface != nullptr)
			{
				InteractInterface->OnInteractHoverEnd(this);
				currentInteractableActor = nullptr;
				InteractInterface = nullptr;
			}
		}
	}
	else
	{
		if (InteractInterface != nullptr)
		{
			InteractInterface->OnInteractHoverEnd(this);
			currentInteractableActor = nullptr;
			InteractInterface = nullptr;
		}
	}
}


void ADarkChamberCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	ConstantLineTraceToCheckObjectsForward();
	if (IsSprinting && PlayerHealth->CurrentStamina - SprintStaminaReduceValue >= 0)
	{
		PlayerHealth->CurrentStamina -= SprintStaminaReduceValue;
		if (PlayerHealth->CurrentStamina < SprintStaminaReduceValue)GetCharacterMovement()->MaxWalkSpeed = 450.f;
	}
	else if (!IsSprinting && PlayerHealth->CurrentStamina + SprintStaminaAddValue <= PlayerHealth->MaxStamina)
	{
		PlayerHealth->CurrentStamina += SprintStaminaAddValue;
	}
}


//////////////////////////////////////////////////////////////////////////// Input

void ADarkChamberCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		//EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &ACharacter::Jump);
		//EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);

		//Moving
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ADarkChamberCharacter::Move);

		//Running
		EnhancedInputComponent->BindAction(SprintAction, ETriggerEvent::Started, this, &ADarkChamberCharacter::Sprint);
		EnhancedInputComponent->BindAction(SprintAction, ETriggerEvent::Completed, this,
		                                   &ADarkChamberCharacter::StopSprint);

		//Crouching	
		EnhancedInputComponent->BindAction(CrouchAction, ETriggerEvent::Triggered, this,
		                                   &ADarkChamberCharacter::Crouchh);

		//Looking
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &ADarkChamberCharacter::Look);

		//interact
		EnhancedInputComponent->BindAction(InteractAction, ETriggerEvent::Started, this,
		                                   &ADarkChamberCharacter::InteractStarted);
		EnhancedInputComponent->BindAction(InteractAction, ETriggerEvent::Canceled, this,
		                                   &ADarkChamberCharacter::InteractCanceledOrCompleted);
		EnhancedInputComponent->BindAction(InteractAction, ETriggerEvent::Completed, this,
		                                   &ADarkChamberCharacter::InteractCanceledOrCompleted);
		EnhancedInputComponent->BindAction(InteractAction, ETriggerEvent::Triggered, this,
		                                   &ADarkChamberCharacter::InteractTriggered);

		EnhancedInputComponent->BindAction(DelayedInteractAction, ETriggerEvent::Triggered, this,
		                                   &ADarkChamberCharacter::InteractTriggered);
		//InventorySelection
		//EnhancedInputComponent->BindAction(, ETriggerEvent::Triggered, this,
		//                                   &ADarkChamberCharacter::SelectInventorySlot, 1);
		//throw Actions
		EnhancedInputComponent->BindAction(HoldTrowAction, ETriggerEvent::Started, this,
		                                   &ADarkChamberCharacter::HoldTrowStarted);
		EnhancedInputComponent->BindAction(HoldTrowAction, ETriggerEvent::Completed, this,
		                                   &ADarkChamberCharacter::HoldTrowStop);
		EnhancedInputComponent->BindAction(HoldTrowAction, ETriggerEvent::Canceled, this,
		                                   &ADarkChamberCharacter::HoldTrowStop);
		EnhancedInputComponent->BindAction(TrowAction, ETriggerEvent::Started, this,
		                                   &ADarkChamberCharacter::ServerTrowItem);

		//CHEATS
		EnhancedInputComponent->BindAction(SpawnItems1Action, ETriggerEvent::Started, this,
		                                   &ADarkChamberCharacter::SpawnItems_Implementation, 1);
		EnhancedInputComponent->BindAction(SpawnItems2Action, ETriggerEvent::Started, this,
		                                   &ADarkChamberCharacter::SpawnItems_Implementation, 2);
		EnhancedInputComponent->BindAction(SpawnItems3Action, ETriggerEvent::Started, this,
		                                   &ADarkChamberCharacter::SpawnItems_Implementation, 3);
		EnhancedInputComponent->BindAction(ToggleGodAction, ETriggerEvent::Triggered, this,
		                                   &ADarkChamberCharacter::TogleHealthAndStamina);
	}
}

void ADarkChamberCharacter::InteractTriggered(const FInputActionValue& Value)
{
	RequestInteractionWith(currentInteractableActor, this);
}

void ADarkChamberCharacter::InteractCanceledOrCompleted(const FInputActionValue& Value)
{
	canMove = true;
}

void ADarkChamberCharacter::InteractStarted(const FInputActionValue& Value)
{
	canMove = false;

	//InteractWithActor();
}

void ADarkChamberCharacter::SelectInventorySlot_Implementation(int n)
{
	if (Inventory[n - 1] != nullptr)
	{
		CurrentlySelectedInventoryItem = n - 1;
		MakeItemsInvisible(Inventory[CurrentlySelectedInventoryItem]);
	}
}

void ADarkChamberCharacter::HoldTrowStarted()
{
	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<
			UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(HoldingItemMappingContext, 0);
		}
	}
}

void ADarkChamberCharacter::HoldTrowStop()
{
	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<
			UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->RemoveMappingContext(HoldingItemMappingContext);
		}
	}
}

void ADarkChamberCharacter::ServerTrowItem_Implementation()
{
	if (CurrentlySelectedInventoryItem != InventoryMaxSize)
	{
		AActor* ActorToThrow = Inventory[CurrentlySelectedInventoryItem];
		if (ActorToThrow)
		{
			FDetachmentTransformRules rules(EDetachmentRule::KeepWorld, true);
			ActorToThrow->DetachFromActor(rules);
			//ActorToThrow->SetActorEnableCollision(true);
			AItem* item = Cast<AItem>(ActorToThrow);
			//FVector Start = GetFirstPersonCameraComponent()->GetComponentLocation();
			//FVector End = Start + GetFirstPersonCameraComponent()->GetComponentRotation().Vector() * 1000.0f;
			FVector direction = GetFirstPersonCameraComponent()->GetForwardVector();
			item->ServerThrowItem(1000, direction);
			Inventory[CurrentlySelectedInventoryItem] = nullptr;
		}
	}
}

int ADarkChamberCharacter::GetavailableInventorySlot()
{
	for (int i = 0; i < InventoryMaxSize; i++)
	{
		if (Inventory[i] == nullptr)
		{
			return i;
		}
	}
	return InventoryMaxSize + 1;
}


void ADarkChamberCharacter::MakeItemsInvisible(AItem* item)
{
	for (int i = 0; i < InventoryMaxSize; i++)
	{
		if (Inventory[i] != item && Inventory[i] != nullptr)
		{
			AActor* TActor = Cast<AActor>((Inventory[i]));
			TActor->SetActorHiddenInGame(true);
		}
		else if (Inventory[i] == item)
		{
			AActor* TActor = Cast<AActor>((Inventory[i]));
			TActor->SetActorHiddenInGame(false);
		}
	}
}

void ADarkChamberCharacter::TakeDamage_Implementation()
{
}

void ADarkChamberCharacter::ActivateJumpScare_Implementation()
{
}


//TRAP ATTACKS INTERFACE
void ADarkChamberCharacter::SetupStimulusSource()
{
	StimulusSource = CreateDefaultSubobject<UAIPerceptionStimuliSourceComponent>(TEXT("Stimulus Source"));
	if (StimulusSource)
	{
		StimulusSource->RegisterForSense(TSubclassOf<UAISense_Sight>());
		StimulusSource->RegisterWithPerceptionSystem();
	}
}


void ADarkChamberCharacter::PlayerDead_Implementation()
{
	//FString CurrentLevelName = UGameplayStatics::GetCurrentLevelName(GetWorld());
	//UGameplayStatics::OpenLevel(GetWorld(), FName("Level_1"));
	SetActorLocation(PlayerStartLocation);
	PlayerHealth->CurrentHealth = 3;
}

void ADarkChamberCharacter::SpawnItems_Implementation(int number)
{
	FVector Location(this->GetActorLocation().X + 20, this->GetActorLocation().Y, this->GetActorLocation().Z);
	FRotator Rotation(0.0f, 0.0f, 0.0f);
	FActorSpawnParameters SpawnInfo;
	GetWorld()->SpawnActor<AActor>(Wood, Location, Rotation);
	GetWorld()->SpawnActor<AActor>(Batery, Location, Rotation);
	if (number == 1)
	{
		GetWorld()->SpawnActor<AActor>(TeslaCoil, Location, Rotation);
	}
	else if (number == 2)
	{
		GetWorld()->SpawnActor<AActor>(GasCannister, Location, Rotation);
	}
	if (number == 3)
	{
		GetWorld()->SpawnActor<AActor>(Shovel, Location, Rotation);
	}
}

void ADarkChamberCharacter::TogleHealthAndStamina_Implementation()
{
	if (!HealthCheatIsOn)
	{
		PlayerHealth->CurrentHealth = 10000000;
		PlayerHealth->CurrentStamina = 10000000;
		HealthCheatIsOn = true;
	}
	else if (HealthCheatIsOn)
	{
		PlayerHealth->CurrentHealth = PlayerHealth->MaxHealth;
		PlayerHealth->CurrentStamina = PlayerHealth->MaxStamina;
		HealthCheatIsOn = false;
	}
}

void ADarkChamberCharacter::Move(const FInputActionValue& Value)
{
	MovementVectorr = Value.Get<FVector2D>();
	if (Controller != nullptr && canMove)
	{
		AddMovementInput(GetActorForwardVector(), MovementVectorr.Y);
		AddMovementInput(GetActorRightVector(), MovementVectorr.X);
	}
	MoveServer(MovementVectorr);
}

void ADarkChamberCharacter::MoveServer_Implementation(FVector2D VectorMove)
{
	// add movement 
	MovementVectorr = VectorMove;
}

void ADarkChamberCharacter::setCanMove_Implementation()
{
	canMove = true;
}


void ADarkChamberCharacter::Look(const FInputActionValue& Value)
{
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// add yaw and pitch input to controller
		AddControllerYawInput(LookAxisVector.X);
		AddControllerPitchInput(LookAxisVector.Y);
		ServerLookUpdate(GetFirstPersonCameraComponent()->GetComponentRotation());
	}
}

void ADarkChamberCharacter::ServerLookUpdate_Implementation(FRotator rotation)
{
	GetFirstPersonCameraComponent()->SetWorldRotation(rotation);
}

void ADarkChamberCharacter::Sprint_Implementation(const FInputActionValue& Value)
{
	//&& !bIsCrouched
	if (canMove)
	{
		IsSprinting = true;
		GetCharacterMovement()->MaxWalkSpeed = DefaultWalkingSpeed * 1.3f;
	}
}

void ADarkChamberCharacter::StopSprint_Implementation(const FInputActionValue& Value)
{
	IsSprinting = false;
	GetCharacterMovement()->MaxWalkSpeed = 450.f;
}


void ADarkChamberCharacter::Crouchh(const FInputActionValue& Value)
{
}


void ADarkChamberCharacter::EletricAttack_Implementation()
{
	canMove = false;
	FTimerHandle TimerHandle;
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &ADarkChamberCharacter::setCanMove, 5.0f, false, 5);
	if (PlayerHealth->ReduceHealth(1))PlayerDead();
}


void ADarkChamberCharacter::HoleAttack_Implementation()
{
	canMove = false;
	FTimerHandle TimerHandle;
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &ADarkChamberCharacter::setCanMove, 7.0f, false, 5);
}

void ADarkChamberCharacter::FireAttack_Implementation()
{
	if (PlayerHealth->ReduceHealth(1))PlayerDead();
}


void ADarkChamberCharacter::RequestInteractionWith_Implementation(AActor* ObjectToInteract,
                                                                  AActor* InteractionInstigator)
{
	InteractWithActor();
	//canMove = true;
	IInteractInterface* TempIInteract = Cast<IInteractInterface>(ObjectToInteract);
	if (!TempIInteract)
		return;

	TempIInteract->Interact(this);

	//canMove = true;
}
