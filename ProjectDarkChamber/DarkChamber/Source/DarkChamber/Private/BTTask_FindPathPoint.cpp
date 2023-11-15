// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_FindPathPoint.h"

#include "Monster.h"
#include "Monster_AIController.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTTask_FindPathPoint::UBTTask_FindPathPoint(FObjectInitializer const& ObjectInitializer) :
	UBTTask_BlackboardBase{ObjectInitializer}
{
	NodeName = TEXT("Find Path Point");
}

EBTNodeResult::Type UBTTask_FindPathPoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	//Get Monster controller
	if(auto* const controller = Cast<AMonster_AIController>(OwnerComp.GetAIOwner()))
	{
		//Get Blackboard component from the behavior tree
		if(auto* const BBComponent = OwnerComp.GetBlackboardComponent())
		{
			//Get the current patrol path index from the blackboard
			auto const Index = BBComponent->GetValueAsInt(GetSelectedBlackboardKey());

			//Get Monster
			if(auto* monster = Cast<AMonster>(controller->GetPawn()))
			{
				//Get the current patrol path vector from the Monster - this is local to the patrol path actor
				auto const Point = monster->GetPatrolPath()->GetPatrolPoint(Index);

				//Convert the local vector to a global point
				auto const GlobalPoint = monster->GetPatrolPath()->GetActorTransform().TransformPosition(Point);
				BBComponent->SetValueAsVector(PatrolPathVectorKey.SelectedKeyName, GlobalPoint);

				//Finish with success
				FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
				return EBTNodeResult::Succeeded;
			}
		}
	}
	return EBTNodeResult::Failed;
}
