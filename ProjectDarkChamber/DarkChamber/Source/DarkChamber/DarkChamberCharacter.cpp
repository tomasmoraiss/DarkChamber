// Copyright Epic Games, Inc. All Rights Reserved.

#include "DarkChamberCharacter.h"
#include "DarkChamberProjectile.h"
#include "Animation/AnimInstance.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"
#include"InteractInterface.h"
#include "GameFramework/CharacterMovementComponent.h"


//////////////////////////////////////////////////////////////////////////
// ADarkChamberCharacter

ADarkChamberCharacter::ADarkChamberCharacter()
{
	//character can move at start
	canMove = true;

	RunningSpeedMultiplier =1.5f;
	DefaultWalkingSpeed=GetCharacterMovement()->MaxWalkSpeed;
	
	//Last interacted actor
	
	
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
	//Mesh1P->SetRelativeRotation(FRotator(0.9f, -19.19f, 5.2f));
	Mesh1P->SetRelativeLocation(FVector(-30.f, 0.f, -150.f));

}

void ADarkChamberCharacter::BeginPlay()
{
	// Call the base class  
	Super::BeginPlay();

	//Add Input Mapping Context
	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}
}

void ADarkChamberCharacter::InteractWithActor()
{
	FVector Start = GetFirstPersonCameraComponent()->GetComponentLocation();
	FVector End = Start+GetFirstPersonCameraComponent()->GetComponentRotation().Vector()*500.0f;
	DrawDebugLine(GetWorld(),Start,End,FColor::Red,false,3.0f,0,2.0f);
	FHitResult HitResult;
	FCollisionQueryParams Params;
	Params.AddIgnoredActor(this);
	/*if(GetWorld()->LineTraceSingleByChannel(HitResult,Start,End,ECC_Visibility,Params))
	{
		InteractInterface = Cast<IInteractInterface>(HitResult.GetActor());
		if(InteractInterface.IsValid())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	InteractInterface = nullptr;
	return false;*/
}

void ADarkChamberCharacter::ConstantLineTraceToCheckObjectsForward()
{
	FVector Start = GetFirstPersonCameraComponent()->GetComponentLocation();
	FVector End = Start+GetFirstPersonCameraComponent()->GetComponentRotation().Vector()*500.0f;
	//DrawDebugLine(GetWorld(),Start,End,FColor::Purple,false,0.1f,0,2.0f);
	FHitResult HitResult;
	FCollisionQueryParams Params;
	Params.AddIgnoredActor(this);
	TWeakInterfacePtr<IInteractInterface> InteractInterfaceTemp;
	if(GetWorld()->LineTraceSingleByChannel(HitResult,Start,End,ECC_Visibility,Params))
	{
		InteractInterfaceTemp = Cast<IInteractInterface>(HitResult.GetActor());
		if(InteractInterfaceTemp.IsValid())
		{
			if(currentInteractableActor!=HitResult.GetActor())
			{
				// crreutn ne to onhover end
				//InteractInterface->OnInteracthoverEnd(this);
				currentInteractableActor = HitResult.GetActor();
				InteractInterface = Cast<IInteractInterface>(HitResult.GetActor());
				InteractInterface->OnInteractHoverBegin(this);
			}
		}
		else
		{
			if(InteractInterface!=nullptr)
			{
				GEngine->AddOnScreenDebugMessage(-1,1,FColor::Red,"INTERATEND1");
				InteractInterface->OnInteractHoverEnd(this);
				currentInteractableActor = nullptr;
				InteractInterface = nullptr;
			}
		}
	}
	else
	{
		// hoverned if i have an interaface
		// set interface to null
		if(InteractInterface!=nullptr)
		{
			GEngine->AddOnScreenDebugMessage(-1,1,FColor::Red,"INTERATEND2");
			InteractInterface->OnInteractHoverEnd(this);
			currentInteractableActor = nullptr;
			InteractInterface = nullptr;
		}
	}
}

void ADarkChamberCharacter::Tick(float DeltaSeconds)
{
	ConstantLineTraceToCheckObjectsForward();
	
	GEngine->AddOnScreenDebugMessage(-10,1.f,FColor::Purple,FString::Printf(TEXT("%f"), RunningSpeedMultiplier));
}


//////////////////////////////////////////////////////////////////////////// Input

void ADarkChamberCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		//Jumping
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &ACharacter::Jump);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);

		//Moving
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ADarkChamberCharacter::Move);

		//Running
		EnhancedInputComponent->BindAction(SprintAction, ETriggerEvent::Started, this, &ADarkChamberCharacter::Sprint);
		EnhancedInputComponent->BindAction(SprintAction, ETriggerEvent::Completed, this, &ADarkChamberCharacter::StopSprint);

		//Crouching	
		EnhancedInputComponent->BindAction(CrouchAction, ETriggerEvent::Triggered, this,&ADarkChamberCharacter::Crouchh);

		//Looking
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &ADarkChamberCharacter::Look);
		//interact
		EnhancedInputComponent->BindAction(InteractAction, ETriggerEvent::Started, this, &ADarkChamberCharacter::InteractStarted);
		EnhancedInputComponent->BindAction(InteractAction, ETriggerEvent::Canceled, this, &ADarkChamberCharacter::InteractCanceledOrCompleted);
		EnhancedInputComponent->BindAction(InteractAction, ETriggerEvent::Completed, this, &ADarkChamberCharacter::InteractCanceledOrCompleted);
		EnhancedInputComponent->BindAction(InteractAction, ETriggerEvent::Triggered, this, &ADarkChamberCharacter::InteractTriggered);

		EnhancedInputComponent->BindAction(DelayedInteractAction, ETriggerEvent::Triggered, this, &ADarkChamberCharacter::InteractTriggered);
	
		
	}
}

void ADarkChamberCharacter::InteractTriggered(const FInputActionValue& Value)
{
	GEngine->AddOnScreenDebugMessage(-1,1,FColor::Red,"TRIGGERED");
	
	//InteractWithActor();
	canMove = true;
	if(InteractInterface.IsValid())InteractInterface->Interact();
	canMove = true;
	
}

void ADarkChamberCharacter::InteractCanceledOrCompleted(const FInputActionValue& Value)
{
	canMove = true;
}

void ADarkChamberCharacter::InteractStarted(const FInputActionValue& Value)
{
	//canMove = false;

	//InteractWithActor();
	
}


void ADarkChamberCharacter::Move(const FInputActionValue& Value)
{
	if(canMove)
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

void ADarkChamberCharacter::Look(const FInputActionValue& Value)
{
	// input is a Vector2D
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
	if(canMove )
	{
		GEngine->AddOnScreenDebugMessage(-10,1.f,FColor::Red,FString::Printf(TEXT("%f"), RunningSpeedMultiplier));
		GetCharacterMovement()->MaxWalkSpeed = DefaultWalkingSpeed*1.3f;
	}
}

void ADarkChamberCharacter::StopSprint(const FInputActionValue& Value)
{
	GEngine->AddOnScreenDebugMessage(-1,1,FColor::Red,"StopSprinting");
	GetCharacterMovement()->MaxWalkSpeed = DefaultWalkingSpeed;
}

void ADarkChamberCharacter::Crouchh(const FInputActionValue& Value)
{
	
}
