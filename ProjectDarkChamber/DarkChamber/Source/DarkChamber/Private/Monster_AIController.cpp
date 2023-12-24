// Fill out your copyright notice in the Description page of Project Settings.


#include "Monster_AIController.h"

#include "Monster.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "DarkChamber/DarkChamberCharacter.h"
#include "Navigation/PathFollowingComponent.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Hearing.h"
#include "Perception/AISenseConfig_Sight.h"

AMonster_AIController::AMonster_AIController(FObjectInitializer const& ObjectInitializer)
{
	SetupPerceptionSystem();
}



void AMonster_AIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	if(AMonster* const Monster = Cast<AMonster>(InPawn))
	{
		if(UBehaviorTree* const BTree = Monster->GetBehaviorTree())
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
		SetPerceptionComponent(*CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("Sight Perception Component")));
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
	HearingConfig = CreateDefaultSubobject<UAISenseConfig_Hearing>(TEXT("Hearing Config"));
	if(HearingConfig)
	{
		SetPerceptionComponent(*CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("Hearing Perception Component")));
		HearingConfig->HearingRange = 1000.f;
		HearingConfig->DetectionByAffiliation.bDetectEnemies = true;
		HearingConfig->DetectionByAffiliation.bDetectFriendlies = true;
		HearingConfig->DetectionByAffiliation.bDetectNeutrals = true;

		GetPerceptionComponent()->OnTargetPerceptionUpdated.AddDynamic(this, &AMonster_AIController::OnTargetHeard);
		GetPerceptionComponent()->ConfigureSense(*HearingConfig);
	}
}

void AMonster_AIController::OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult& Result)
{
	Super::OnMoveCompleted(RequestID, Result);

	if (Result.Code == EPathFollowingResult::Success)
	{
		// The MoveToLocation task succeeded, meaning the AI reached the destination
		GetBlackboardComponent()->SetValueAsBool("HeardItem", false);
	}
}

void AMonster_AIController::OnTargetDetect(AActor* Actor, FAIStimulus const Stimulus)
{
	if(auto const* Player = Cast<ADarkChamberCharacter>(Actor))
	{
		GetBlackboardComponent()->SetValueAsBool("CanSeePlayer", Stimulus.WasSuccessfullySensed());
	}
}

void AMonster_AIController::OnTargetHeard(AActor* Actor, FAIStimulus const Stimulus)
{
	GetBlackboardComponent()->SetValueAsBool("HeardItem", Stimulus.WasSuccessfullySensed());
	GetBlackboardComponent()->SetValueAsVector("NoiseLocation", Stimulus.StimulusLocation);

	if (UBehaviorTreeComponent* BTree = Cast<UBehaviorTreeComponent>(BrainComponent))
	{
		BTree->RestartLogic();
	}
	if (Stimulus.WasSuccessfullySensed())
	{
		// If AI heard something successfully, initiate movement
		if (AAIController* MyController = Cast<AAIController>(this))
		{
			FAIMoveRequest MoveRequest;
			MoveRequest.SetGoalLocation(Stimulus.StimulusLocation);
			MoveRequest.SetAcceptanceRadius(50.0f); // Adjust the radius as needed

			MyController->MoveTo(MoveRequest);
		}
	}
}

void AMonster_AIController::StopInvestigation()
{
	GetBlackboardComponent()->SetValueAsBool("HeardItem", false);
}


void AMonster_AIController::FleeFromFire(bool Value)
{
	GetBlackboardComponent()->SetValueAsBool("CanFleeFromFireTrap", Value);
}





