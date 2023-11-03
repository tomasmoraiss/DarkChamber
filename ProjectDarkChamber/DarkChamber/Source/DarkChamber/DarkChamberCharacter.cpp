// Copyright Epic Games, Inc. All Rights Reserved.
#include"InteractInterface.h"
#include "DarkChamberCharacter.h"
#include "DarkChamberProjectile.h"
#include "Animation/AnimInstance.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"
#include "EnhancedInputSubsystems.h"


//////////////////////////////////////////////////////////////////////////
// ADarkChamberCharacter

ADarkChamberCharacter::ADarkChamberCharacter()
{
	// Character doesnt have a rifle at start
	bHasRifle = false;
	//character can move at start
	canMove = true;

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

bool ADarkChamberCharacter::InteractWithActor()
{
	UE_LOG(LogTemp, Warning,TEXT("OLA"));
	FVector Start = GetFirstPersonCameraComponent()->GetComponentLocation();
	FVector End = Start+GetFirstPersonCameraComponent()->GetComponentRotation().Vector()*500.0f;
	DrawDebugLine(GetWorld(),Start,End,FColor::Red,false,3.0f,0,2.0f);
	FHitResult HitResult;
	FCollisionQueryParams Params;
	Params.AddIgnoredActor(this);
	if(GetWorld()->LineTraceSingleByChannel(HitResult,Start,End,ECC_Visibility,Params))
	{
		InteractInterface = Cast<IInteractInterface>(HitResult.GetActor());
		if(InteractInterface.IsValid())
		{
			//InteractInterface->Interact();
			return true;
		}
		else
		{
			return false;
		}
	}
	return false;
	
	
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

		//Looking
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &ADarkChamberCharacter::Look);
		//interact
		EnhancedInputComponent->BindAction(InteractAction, ETriggerEvent::Started, this, &ADarkChamberCharacter::InteractStarted);
		EnhancedInputComponent->BindAction(InteractAction, ETriggerEvent::Canceled, this, &ADarkChamberCharacter::InteractCanceledOrCompleted);
		EnhancedInputComponent->BindAction(InteractAction, ETriggerEvent::Completed, this, &ADarkChamberCharacter::InteractCanceledOrCompleted);
		EnhancedInputComponent->BindAction(InteractAction, ETriggerEvent::Triggered, this, &ADarkChamberCharacter::InteractTriggered);
	
		
	}
}

void ADarkChamberCharacter::InteractTriggered(const FInputActionValue& Value)
{
	
	if(InteractInterface.IsValid())
		InteractInterface->Interact();
	canMove = true;
	
}

void ADarkChamberCharacter::InteractCanceledOrCompleted(const FInputActionValue& Value)
{
	canMove = true;
}

void ADarkChamberCharacter::InteractStarted(const FInputActionValue& Value)
{
	canMove = false;

	InteractWithActor();
	
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

void ADarkChamberCharacter::SetHasRifle(bool bNewHasRifle)
{
	bHasRifle = bNewHasRifle;
}

bool ADarkChamberCharacter::GetHasRifle()
{
	return bHasRifle;
}