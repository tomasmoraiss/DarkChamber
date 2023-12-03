// Copyright Epic Games, Inc. All Rights Reserved.

#include "DarkChamberCharacter.h"

#include <iostream>

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
#include "Net/UnrealNetwork.h"
#include "Perception/AIPerceptionStimuliSourceComponent.h"
#include "Perception/AISense_Sight.h"


//////////////////////////////////////////////////////////////////////////
// ADarkChamberCharacter

void ADarkChamberCharacter::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ADarkChamberCharacter, Inventory);
	DOREPLIFETIME(ADarkChamberCharacter, CurrentlySelectedInventoryItem);
	DOREPLIFETIME(ADarkChamberCharacter, CurrentItemHeld);
	DOREPLIFETIME(ADarkChamberCharacter, ItemPlaceHolderMeshComponent);
	DOREPLIFETIME(ADarkChamberCharacter, PlayerHealth);
	DOREPLIFETIME(ADarkChamberCharacter, canMove);
}

ADarkChamberCharacter::ADarkChamberCharacter()
{
	//sprint stuff
	IsSprinting = false;
	SprintStaminaAddValue = 0.1f;
	SprintStaminaReduceValue = 0.2f;
	//character can move at start
	canMove = true;

	RunningSpeedMultiplier = 1.5f;
	DefaultWalkingSpeed = GetCharacterMovement()->MaxWalkSpeed;

	//Inventory Stuff
	CurrentlySelectedInventoryItem = 6;

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
}

void ADarkChamberCharacter::BeginPlay()
{
	// Call the base class  
	Super::BeginPlay();

	//Add Input Mapping Context
	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<
			UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}
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
	//DrawDebugLine(GetWorld(),Start,End,FColor::Purple,false,0.1f,0,2.0f);
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
		//Jumping
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
		EnhancedInputComponent->BindAction(InventorySelect1Action, ETriggerEvent::Triggered, this,
		                                   &ADarkChamberCharacter::SelectInventorySlot, 1);
		EnhancedInputComponent->BindAction(InventorySelect2Action, ETriggerEvent::Triggered, this,
		                                   &ADarkChamberCharacter::SelectInventorySlot, 2);
		EnhancedInputComponent->BindAction(InventorySelect3Action, ETriggerEvent::Triggered, this,
		                                   &ADarkChamberCharacter::SelectInventorySlot, 3);
		EnhancedInputComponent->BindAction(InventorySelect4Action, ETriggerEvent::Triggered, this,
		                                   &ADarkChamberCharacter::SelectInventorySlot, 4);
		EnhancedInputComponent->BindAction(InventorySelect5Action, ETriggerEvent::Triggered, this,
		                                   &ADarkChamberCharacter::SelectInventorySlot, 5);
		EnhancedInputComponent->BindAction(InventorySelect6Action, ETriggerEvent::Triggered, this,
		                                   &ADarkChamberCharacter::SelectInventorySlot, 6);
		//throw Actions
		EnhancedInputComponent->BindAction(HoldTrowAction, ETriggerEvent::Started, this,
		                                   &ADarkChamberCharacter::HoldTrowStarted);
		EnhancedInputComponent->BindAction(HoldTrowAction, ETriggerEvent::Completed, this,
		                                   &ADarkChamberCharacter::HoldTrowStop);
		EnhancedInputComponent->BindAction(HoldTrowAction, ETriggerEvent::Canceled, this,
		                                   &ADarkChamberCharacter::HoldTrowStop);
		EnhancedInputComponent->BindAction(TrowAction, ETriggerEvent::Started, this,
		                                   &ADarkChamberCharacter::ServerTrowItem);
	}
}

void ADarkChamberCharacter::InteractTriggered(const FInputActionValue& Value)
{
	RequestInteractionWith(currentInteractableActor, this);
}

void ADarkChamberCharacter::InteractCanceledOrCompleted(const FInputActionValue& Value)
{
	//canMove = true;
}

void ADarkChamberCharacter::InteractStarted(const FInputActionValue& Value)
{
	//canMove = false;

	//InteractWithActor();
}

void ADarkChamberCharacter::SelectInventorySlot_Implementation(int n)
{
	if (Inventory[n - 1] != nullptr)
	{
		CurrentlySelectedInventoryItem = n - 1;
		MakeItemsInvisible(Inventory[CurrentlySelectedInventoryItem]);
	}
	GEngine->AddOnScreenDebugMessage(-10, 1.f, FColor::Red,
	                                 FString::Printf(TEXT("Current Selected : %i"), CurrentlySelectedInventoryItem));
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
	AActor* ActorToThrow = Inventory[CurrentlySelectedInventoryItem];
	if (ActorToThrow)
	{
		FDetachmentTransformRules rules(EDetachmentRule::KeepWorld, true);
		ActorToThrow->DetachFromActor(rules);
		//ActorToThrow->SetActorEnableCollision(true);
		AItem* item = Cast<AItem>(ActorToThrow);
		FVector direction = GetFirstPersonCameraComponent()->GetForwardVector();
		item->ServerThrowItem(1000, direction);
		Inventory[CurrentlySelectedInventoryItem] = nullptr;
	}
}

int ADarkChamberCharacter::GetavailableInventorySlot()
{
	for (int i = 0; i < Inventory.Num(); i++)
	{
		if (Inventory[i] == nullptr)
		{
			GEngine->AddOnScreenDebugMessage(-10, 1.f, FColor::Blue,
			                                 FString::Printf(TEXT("available slot : %i"), i));
			return i;
		}
	}
	return 6;
}


void ADarkChamberCharacter::MakeItemsInvisible(AItem* item)
{
	for (int i = 0; i < Inventory.Num(); i++)
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


void ADarkChamberCharacter::Move(const FInputActionValue& Value)
{
	if (canMove)
	{
		// input is a Vector2D
		FVector2D MovementVector = Value.Get<FVector2D>();
		if (Controller != nullptr)
		{
			// add movement 
			AddMovementInput(GetActorForwardVector(), MovementVector.Y);
			AddMovementInput(GetActorRightVector(), MovementVector.X);
		}
	}
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
	}
}

void ADarkChamberCharacter::Sprint(const FInputActionValue& Value)
{
	//&& !bIsCrouched
	if (canMove)
	{
		IsSprinting = true;
		GEngine->AddOnScreenDebugMessage(-10, 1.f, FColor::Red, FString::Printf(TEXT("%f"), RunningSpeedMultiplier));
		GetCharacterMovement()->MaxWalkSpeed = DefaultWalkingSpeed * 1.3f;
	}
}

void ADarkChamberCharacter::StopSprint(const FInputActionValue& Value)
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
	GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, "EletricAttack");
	PlayerHealth->ReduceHealth(20);
}


void ADarkChamberCharacter::HoleAttack_Implementation()
{
	canMove = false;
	FTimerHandle TimerHandle;
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &ADarkChamberCharacter::setCanMove, 7.0f, false, 5);
	GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, "HoleAttack");
}

void ADarkChamberCharacter::FireAttack_Implementation()
{
	PlayerHealth->ReduceHealth(40);
	GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, "FireAttack");
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
