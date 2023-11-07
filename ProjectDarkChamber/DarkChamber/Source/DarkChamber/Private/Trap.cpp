// Fill out your copyright notice in the Description page of Project Settings.


#include "Trap.h"
#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"
#include "EnhancedInputComponent.h"

// Sets default values
ATrap::ATrap()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATrap::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ATrap::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ATrap::Interact()
{
	GEngine->AddOnScreenDebugMessage(-1,1,FColor::Green,"Interactedd");
}

void ATrap::OnInteractHoverBegin(AActor* ActorToInteractWith)
 {
	GEngine->AddOnScreenDebugMessage(-1,1,FColor::Green,"begin");
	APawn* InteractPawn= Cast<APawn>(ActorToInteractWith);
	 if (APlayerController* PlayerController = Cast<APlayerController>(InteractPawn->Controller))
	 {
	 	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
	 	{
	 		Subsystem->AddMappingContext(InteractDelayedMappingContext, 0);
	 	}
	 }
 }

void ATrap::OnInteractHoverEnd(AActor* ActorToInteractWith)
{
	GEngine->AddOnScreenDebugMessage(-1,1,FColor::Red,"ENDED");
	APawn* InteractPawn= Cast<APawn>(ActorToInteractWith);
	// UE_LOG(LogTemp,Warning,TEXT("ffwfewjbjgwhfwefkewbfehkbwhgw"))
	if (APlayerController* PlayerController = Cast<APlayerController>(InteractPawn->Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->RemoveMappingContext(InteractDelayedMappingContext);
			//Subsystem->AddMappingContext(InteractDefaultMappingContext,1);
			
		}
	}
}

	