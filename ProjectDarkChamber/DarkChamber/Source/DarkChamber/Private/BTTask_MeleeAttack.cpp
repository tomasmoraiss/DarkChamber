// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_MeleeAttack.h"
#include "Monster_AIController.h"
#include "DarkChamber/DarkChamberCharacter.h"

UBTTask_MeleeAttack::UBTTask_MeleeAttack()
{
	NodeName = TEXT("Melee attack");
}

EBTNodeResult::Type UBTTask_MeleeAttack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	//if not in range, don't attack the player
	auto const OutOfRange = !OwnerComp.GetBlackboardComponent()->GetValueAsBool(GetSelectedBlackboardKey());

	if(OutOfRange)
	{
		OwnerComp.GetBlackboardComponent()->SetValueAsBool("CanAttack", false);
		//Finish task
		FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
		return EBTNodeResult::Succeeded;
	}
	auto const * const Controller = OwnerComp.GetAIOwner();
	auto* const Monster = Cast<AMonster>(Controller->GetPawn());
	//If the Monster supports the Combat Interface, call and execute the Attack function
	if(const auto* const ICombat = Cast<ICombatInterface>(Monster))
	{
		GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Green, "I attacked");
		ICombat->Execute_MeleeAttack(Monster);
	}
	FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
	return EBTNodeResult::Type();
}


