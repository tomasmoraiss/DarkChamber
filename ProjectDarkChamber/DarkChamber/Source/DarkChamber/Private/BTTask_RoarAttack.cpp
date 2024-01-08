// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_RoarAttack.h"
#include "Monster_AIController.h"
#include "Monster.h"

class AMonster_AIController;

UBTTask_RoarAttack::UBTTask_RoarAttack()
{
	NodeName = TEXT("Roar Attack");
}

EBTNodeResult::Type UBTTask_RoarAttack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	const auto* const AIController = OwnerComp.GetAIOwner();
	if (!AIController)
	{
		return EBTNodeResult::Failed;
	}

	APawn* Monster = AIController->GetPawn();
	if (!Monster)
	{
		return EBTNodeResult::Failed;
	}

	// Implement random attack logic
	int32 RandomAttackIndex = FMath::RandRange(1, 20);
	
	if(RandomAttackIndex == 5)
	{
		if(AMonster* MonsterActor = Cast<AMonster>(Monster))
		{
			MonsterActor->RoarAttack_Implementation();
		}
	}
	return EBTNodeResult::Succeeded;
}
