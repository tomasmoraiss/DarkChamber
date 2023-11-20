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
	auto const * const Monster = Cast<AMonster>(Controller->GetPawn());
	auto const * const Player = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
	//Write true or false to the blackboard key depending on whether or not the player is in range
	OwnerComp.GetBlackboardComponent()->SetValueAsBool(GetSelectedBlackboardKey(), Monster->GetDistanceTo(Player) <= MeleeRange);
	Super::OnBecomeRelevant(OwnerComp, NodeMemory);
}
