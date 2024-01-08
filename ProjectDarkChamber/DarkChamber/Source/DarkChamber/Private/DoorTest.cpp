// Fill out your copyright notice in the Description page of Project Settings.


#include "DoorTest.h"

#include "Statue.h"
#include "Kismet/GameplayStatics.h"
#include "Perception/AIPerceptionStimuliSourceComponent.h"
#include "Perception/AISense_Hearing.h"

class UAISense_Hearing;
// Sets default values
ADoorTest::ADoorTest()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	isOpen = false;

	doorOpenType = EOpenType::Interaction;
	isOpen = reverse;

	SetupStimulusSource();
}

// Called when the game starts or when spawned
void ADoorTest::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ADoorTest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ADoorTest::Activate_Implementation()
{
	Interact(this);
}

void ADoorTest::OnInteractHoverBegin(AActor* ActorToInteractWith)
{
	IInteractInterface::OnInteractHoverBegin(ActorToInteractWith);
}

void ADoorTest::OnInteractHoverEnd(AActor* ActorToInteractWith)
{
	IInteractInterface::OnInteractHoverEnd(ActorToInteractWith);
}

void ADoorTest::PlaySoundEffectServer_Implementation()
{
	UGameplayStatics::PlaySoundAtLocation(this, OpeningSoundEffect, GetActorLocation());
}

void ADoorTest::Interact_Implementation(AActor* ActorInteracting)
{
	UAISense_Hearing::ReportNoiseEvent(this, GetActorLocation(), 1.f, this, 0, "Door Noise");
	isOpen = !isOpen;
	PlaySoundEffectServer();
}

void ADoorTest::OpenDoorWithStatues()
{	
	for (int i = 0; i < StatuesToBeUsed.Num(); i++)
	{
		if (!Cast<AStatue>(StatuesToBeUsed[i])->StatueFacingCorrectDirection)
		{
			return;
		}
	}
	ChangeDoorState();
}



void ADoorTest::SetupStimulusSource()
{
	StimulusSource = CreateDefaultSubobject<UAIPerceptionStimuliSourceComponent>(TEXT("Stimulus Source"));
	if (StimulusSource)
	{
		StimulusSource->RegisterForSense(TSubclassOf<UAISense_Hearing>());
		StimulusSource->RegisterWithPerceptionSystem();
	}
}

void ADoorTest::ChangeDoorState_Implementation()
{
	isOpen = !isOpen;
}
