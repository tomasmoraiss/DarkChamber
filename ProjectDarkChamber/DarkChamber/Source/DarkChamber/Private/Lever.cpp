// Fill out your copyright notice in the Description page of Project Settings.


#include "Lever.h"

#include "DoorTest.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ALever::ALever()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ALever::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ALever::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ALever::Interact_Implementation(AActor* ActorInteracting)
{
	isOn  = !isOn;
	if(!DoorReference.IsEmpty())
	{
		for(int i = 0; i < DoorReference.Num(); i++)
		{
			IInteractInterface* InteractInterface = Cast<IInteractInterface>(DoorReference[i]);
			InteractInterface->Interact(this);
			IActivatableInterface* ActivatableInterface = Cast<IActivatableInterface>(DoorReference[i]);
			ActivatableInterface->Activate();
		}
	}
		
	UE_LOG(LogTemp, Warning, TEXT("Lever Activation"));
}

