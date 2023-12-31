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
		//Finish task
		FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
		return EBTNodeResult::Succeeded;
	}

	auto const * const Controller = OwnerComp.GetAIOwner();
	auto* const Monster = Cast<AMonster>(Controller->GetPawn());
	//If the Monster supports the Combat Interface, call and execute the Attack function
	if(auto* const ICombat = Cast<ICombatInterface>(Monster))
	{
		if(auto* const Player = Cast<ADarkChamberCharacter>(Controller->GetPawn()))
		{
			
			Player->PlayerHealth->ReduceHealth(Monster->AttackDamage);
		}
		ICombat->Execute_MeleeAttack(Monster);
	}
	FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
	return EBTNodeResult::Type();
}


