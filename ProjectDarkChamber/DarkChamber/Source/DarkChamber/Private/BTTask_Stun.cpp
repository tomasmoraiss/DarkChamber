// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_Stun.h"

#include "Monster.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTTask_Stun::UBTTask_Stun(FObjectInitializer const& ObjectInitializer) :
	UBTTask_BlackboardBase{ ObjectInitializer }
{
	NodeName = TEXT("Stun task");
}

EBTNodeResult::Type UBTTask_Stun::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	auto const* const Controller = OwnerComp.GetAIOwner();
	auto* const Monster = Cast<AMonster>(Controller->GetPawn());

	bool IsStunned = OwnerComp.GetBlackboardComponent()->GetValueAsBool(GetSelectedBlackboardKey());

	if (IsStunned)
	{
		FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
		return EBTNodeResult::Succeeded;
	}
	//If the Monster supports the Trap Interface, call and execute the Trap function
	if (const auto* const ITrap = Cast<ITrapDamageInterface>(Monster))
	{
		Monster->EletricAttack_Implementation();
	}
	return Super::ExecuteTask(OwnerComp, NodeMemory);
}
