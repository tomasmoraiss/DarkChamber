// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_FleeFromFire.h"

#include "Monster.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"

UBTTask_FleeFromFire::UBTTask_FleeFromFire(FObjectInitializer const& ObjectInitializer) :
	UBTTask_BlackboardBase{ObjectInitializer}
{
	NodeName = TEXT("Flee from fire");
}

EBTNodeResult::Type UBTTask_FleeFromFire::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	//Get target location from Blackboard via Monster controller
	if(auto* const controller = Cast<AMonster_AIController>(OwnerComp.GetAIOwner()))
	{
		auto const PatrolPointLocation = OwnerComp.GetBlackboardComponent()->GetValueAsVector((GetSelectedBlackboardKey()));

		//Move to target location
		UAIBlueprintHelperLibrary::SimpleMoveToLocation(controller, PatrolPointLocation);

		//Finish task with success
		FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
		return EBTNodeResult::Succeeded;
	}
	return EBTNodeResult::Failed;
}
