// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_MoveToNoiseLocation.h"

#include "Monster_AIController.h"
#include "NavigationSystem.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"

UBTTask_MoveToNoiseLocation::UBTTask_MoveToNoiseLocation()
{
	NodeName = TEXT("Move to Noise Location");
}

EBTNodeResult::Type UBTTask_MoveToNoiseLocation::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	auto* Controller = OwnerComp.GetAIOwner();
	if (Controller)
	{
			FVector TargetLocation = OwnerComp.GetBlackboardComponent()->GetValueAsVector(GetSelectedBlackboardKey());

			UNavigationSystemV1* NavSys = UNavigationSystemV1::GetCurrent(GetWorld());
			if (NavSys)
			{
				FNavLocation ResultLocation;
				if (NavSys->GetRandomPointInNavigableRadius(TargetLocation, 100.0f, ResultLocation))
				{
					UAIBlueprintHelperLibrary::SimpleMoveToLocation(Controller, TargetLocation);
					return EBTNodeResult::Succeeded;
				}
			}
	}
	OwnerComp.GetBlackboardComponent()->SetValueAsBool("HeardItem", false);
	return EBTNodeResult::Failed;
}
