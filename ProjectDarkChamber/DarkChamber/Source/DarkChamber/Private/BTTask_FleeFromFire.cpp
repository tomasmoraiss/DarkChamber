// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_FleeFromFire.h"

#include "Monster.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTTask_FleeFromFire::UBTTask_FleeFromFire(FObjectInitializer const& ObjectInitializer) :
	UBTTask_BlackboardBase{ObjectInitializer}
{
	NodeName = TEXT("Flee from fire");
}

EBTNodeResult::Type UBTTask_FleeFromFire::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	return Super::ExecuteTask(OwnerComp, NodeMemory);
}
