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
	TArray<AActor*> PlayerCharacters;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ADarkChamberCharacter::StaticClass(), PlayerCharacters);

	// Iterate through all players and check if any are in range
	bool IsAnyPlayerInRange = false;
	for (AActor* Player : PlayerCharacters)
	{
		auto* PlayerCharacter = Cast<ADarkChamberCharacter>(Player);
		if (PlayerCharacter && Monster)
		{
			float DistanceToPlayer = Monster->GetDistanceTo(PlayerCharacter);
			if (DistanceToPlayer <= MeleeRange)
			{
				IsAnyPlayerInRange = true;
				break; // No need to check further, at least one player is in range
			}
		}
	}

	// Write true or false to the blackboard key based on whether any player is in range
	OwnerComp.GetBlackboardComponent()->SetValueAsBool(GetSelectedBlackboardKey(), IsAnyPlayerInRange);

	
	Super::OnBecomeRelevant(OwnerComp, NodeMemory);
}
