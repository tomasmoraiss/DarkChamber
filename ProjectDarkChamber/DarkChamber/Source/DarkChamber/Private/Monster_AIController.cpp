// Fill out your copyright notice in the Description page of Project Settings.


#include "Monster_AIController.h"

#include "Monster.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "DarkChamber/DarkChamberCharacter.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"

AMonster_AIController::AMonster_AIController(FObjectInitializer const& ObjectInitializer)
{
	SetupPerceptionSystem();
}



void AMonster_AIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	if(AMonster* const monster = Cast<AMonster>(InPawn))
	{
		if(UBehaviorTree* const BTree = monster->GetBehaviorTree())
		{
			UBlackboardComponent* b;
			UseBlackboard(BTree->BlackboardAsset, b);
			Blackboard = b;
			RunBehaviorTree(BTree);
		}
	}
}

void AMonster_AIController::SetupPerceptionSystem()
{
	SightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("Sight Config"));
	if(SightConfig)
	{
		SetPerceptionComponent(*CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("Perception Component")));
		SightConfig->SightRadius = 1000.f;
		SightConfig->LoseSightRadius = SightConfig->SightRadius + 25.f;
		SightConfig->PeripheralVisionAngleDegrees = 180.f;
		SightConfig->SetMaxAge(5.f);
		SightConfig->DetectionByAffiliation.bDetectEnemies = true;
		SightConfig->DetectionByAffiliation.bDetectFriendlies = true;
		SightConfig->DetectionByAffiliation.bDetectNeutrals = true;
		
		GetPerceptionComponent()->SetDominantSense(*SightConfig->GetSenseImplementation());
		GetPerceptionComponent()->OnTargetPerceptionUpdated.AddDynamic(this, &AMonster_AIController::OnTargetDetect);
		GetPerceptionComponent()->ConfigureSense(*SightConfig);
	}
}

void AMonster_AIController::OnTargetDetect(AActor* Actor, FAIStimulus const Stimulus)
{
	if(auto const* Player = Cast<ADarkChamberCharacter>(Actor))
	{
		GetBlackboardComponent()->SetValueAsBool("CanSeePlayer", Stimulus.WasSuccessfullySensed());
	}
}

void AMonster_AIController::FleeFromFire(bool Value)
{
	GetBlackboardComponent()->SetValueAsBool("CanFleeFromFireTrap", Value);
}

void AMonster_AIController::NotifySoundItemFalling(FVector SoundLocation)
{
	UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, SoundLocation);
}

void AMonster_AIController::GetController()
{
	
}



