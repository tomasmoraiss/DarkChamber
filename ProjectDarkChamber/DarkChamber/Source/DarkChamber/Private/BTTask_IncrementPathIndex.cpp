// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_IncrementPathIndex.h"

#include "Monster.h"
#include "Monster_AIController.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTTask_IncrementPathIndex::UBTTask_IncrementPathIndex(FObjectInitializer const& ObjectInitializer) :
	UBTTask_BlackboardBase{ObjectInitializer}
{
	NodeName = TEXT("Increment Path Index");
}

EBTNodeResult::Type UBTTask_IncrementPathIndex::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	//Get Monster AI Controller
	if(auto* const controller = Cast<AMonster_AIController>(OwnerComp.GetAIOwner()))
	{
		//Get Monster
		if(auto* const monster = Cast<AMonster>(controller->GetPawn()))
		{
			//Get blackboard
			if(auto* const BBComponent = OwnerComp.GetBlackboardComponent())
			{
				//Get number of patrol points and their min and max index
				auto const NumberOfPatrolPoints = monster->GetPatrolPath()->Num();
				auto const MinIndex = 0;
				auto const MaxIndex = NumberOfPatrolPoints - 1;
				auto Index = BBComponent->GetValueAsInt(GetSelectedBlackboardKey());

				//Change the direction if we are at the first or last index if we are in bidirectional mode
				
				/*if(bBiDirectional)
				{
					if(Index >= MaxIndex && Direction == EDirectionType::Forward)
					{
						Direction = EDirectionType::Reverse;
					}
					else if(Index == MinIndex && Direction == EDirectionType::Reverse)
					{
						Direction = EDirectionType::Forward;
					}
				}*/
				
				//Set new value of index on the Blackboard
				BBComponent->SetValueAsInt(GetSelectedBlackboardKey(), FMath::RandRange(MinIndex, MaxIndex));

				FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
				return EBTNodeResult::Succeeded;
			}
		}
	}
	return EBTNodeResult::Failed;
}
