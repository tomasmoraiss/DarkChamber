// Fill out your copyright notice in the Description page of Project Settings.


#include "Monster_AIController.h"

#include "Monster.h"

AMonster_AIController::AMonster_AIController(FObjectInitializer const& ObjectInitializer)
{
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
