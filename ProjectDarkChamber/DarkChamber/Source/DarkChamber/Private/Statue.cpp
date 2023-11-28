// Fill out your copyright notice in the Description page of Project Settings.


#include "Statue.h"

// Sets default values
AStatue::AStatue()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>("Root");
	ItemMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
	ItemMesh->SetIsReplicated(true);
	ItemMesh->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	canInteract = true;
	CorrectFacingDirection = EDirection::Front;
	
}

// Called when the game starts or when spawned
void AStatue::BeginPlay()
{
	Super::BeginPlay();
	if(doorToBeTested != nullptr)
		doorToBeTested->StatuesToBeUsed.Push(this);
}

// Called every frame
void AStatue::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AStatue::CheckStatueDirection()
{
	if(CorrectFacingDirection == (EDirection)CurrentFacingDirection)
	{
		StatueFacingCorrectDirection = true;
		doorToBeTested->OpenDoorWithStatues();
	}
	else
	{
		StatueFacingCorrectDirection = false;
	}
}

void AStatue::Interact_Implementation(AActor* ActorInteracting)
{
	if(doorToBeTested != nullptr)
	{
		CurrentFacingDirection = CurrentFacingDirection+1;
		if((EDirection)CurrentFacingDirection == EDirection::MAX)
		{
			CurrentFacingDirection = (uint8)EDirection::Front;
		}
			
		CheckStatueDirection();
	}
}
