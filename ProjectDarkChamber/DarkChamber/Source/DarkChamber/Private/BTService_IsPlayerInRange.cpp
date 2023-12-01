// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_IsPlayerInRange.h"
#include "Monster_AIController.h"
#include "Monster.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTService_IsPlayerInRange::UBTService_IsPlayerInRange()
{
	bNotifyBecomeRelevant = true;
	NodeName = TEXT("Player is in range");
}

void UBTService_IsPlayerInRange::OnBecomeRelevant(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	auto const * const Controller = Cast<AMonster_AIController>(OwnerComp.GetAIOwner());
	auto * const Monster = Cast<AMonster>(Controller->GetPawn());
	auto * const Player = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
	Monster->TargetedPlayer = Cast<ADarkChamberCharacter>(Player);
	//Write true or false to the blackboard key depending on whether or not the player is in range
	OwnerComp.GetBlackboardComponent()->SetValueAsBool(GetSelectedBlackboardKey(), Monster->GetDistanceTo(Monster->TargetedPlayer) <= MeleeRange);
	if(Monster->GetDistanceTo(Monster->TargetedPlayer) <= MeleeRange)
	{
		OwnerComp.GetBlackboardComponent()->SetValueAsBool(GetSelectedBlackboardKey(), true);
	}else
	{
		OwnerComp.GetBlackboardComponent()->SetValueAsBool(GetSelectedBlackboardKey(), false);
	}
	
	Super::OnBecomeRelevant(OwnerComp, NodeMemory);
}
