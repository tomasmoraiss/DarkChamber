// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_Stun.h"

UBTTask_Stun::UBTTask_Stun()
{
	NodeName = TEXT("Stun task");
}

EBTNodeResult::Type UBTTask_Stun::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	
	return Super::ExecuteTask(OwnerComp, NodeMemory);
}
