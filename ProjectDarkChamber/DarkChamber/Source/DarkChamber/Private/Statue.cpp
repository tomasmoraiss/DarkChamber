// Fill out your copyright notice in the Description page of Project Settings.


#include "Statue.h"

#include "Kismet/GameplayStatics.h"
#include "Perception/AISense_Hearing.h"


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

	SetupStimulusSource();
}

void AStatue::PlaySoundEffectServer_Implementation()
{
	if(!SoundEffect)
	{
		return;
	}
	UGameplayStatics::PlaySoundAtLocation(this, SoundEffect, GetActorLocation());
}


// Called when the game starts or when spawned
void AStatue::BeginPlay()
{
	Super::BeginPlay();
	if(!doorsToBeTested.IsEmpty())
		for(int i = 0; i < doorsToBeTested.Num(); i++)
		{
			doorsToBeTested[i]->StatuesToBeUsed.Push(this);
		}
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
		for (int i = 0; i < doorsToBeTested.Num(); i++)
		{
			doorsToBeTested[i]->OpenDoorWithStatues();
		}
	}
	else
	{
		StatueFacingCorrectDirection = false;
	}
}


void AStatue::Interact_Implementation(AActor* ActorInteracting)
{
	UAISense_Hearing::ReportNoiseEvent(this, GetActorLocation(), 1.f, this, 0.f,"Statue Noise");
	if(!doorsToBeTested.IsEmpty())
	{
		CurrentFacingDirection = CurrentFacingDirection+1;
		if((EDirection)CurrentFacingDirection == EDirection::MAX)
		{
			CurrentFacingDirection = (uint8)EDirection::Front;
		}
		CheckStatueDirection();
	}
	PlaySoundEffectServer();

}

void AStatue::SetupStimulusSource()
{
	StimulusSource = CreateDefaultSubobject<UAIPerceptionStimuliSourceComponent>(TEXT("Stimulus Source"));
	if (StimulusSource)
	{
		StimulusSource->RegisterForSense(TSubclassOf<UAISense_Hearing>());
		StimulusSource->RegisterWithPerceptionSystem();
	}
}


