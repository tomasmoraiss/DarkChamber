// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_CanAttackPlayer.h"

UBTService_CanAttackPlayer::UBTService_CanAttackPlayer()
{
	NodeName = TEXT("Attack player");
}

void UBTService_CanAttackPlayer::OnBecomeRelevant(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::OnBecomeRelevant(OwnerComp, NodeMemory);
}
