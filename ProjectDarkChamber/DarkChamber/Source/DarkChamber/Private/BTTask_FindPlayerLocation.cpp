// Fill out your copyright notice in the Description page of Project Settings.

#include "BTTask_FindPlayerLocation.h"
#include "AIController.h"
#include "Monster.h"
#include "NavigationSystem.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "DarkChamber/DarkChamberCharacter.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"

UBTTask_FindPlayerLocation::UBTTask_FindPlayerLocation(FObjectInitializer const& ObjectInitializer) :
	UBTTask_BlackboardBase{ObjectInitializer}
{
	NodeName = TEXT("Find Player Location");
}

EBTNodeResult::Type UBTTask_FindPlayerLocation::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) 
{
	auto const * const Controller = OwnerComp.GetAIOwner();

	TArray<AActor*> PlayerArray;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ADarkChamberCharacter::StaticClass(), PlayerArray);

	// Check if there are any players
	if (PlayerArray.Num() > 0)
	{
		float ClosestDistance = MAX_FLT;
		ADarkChamberCharacter* ClosestPlayer = nullptr;

		auto* Monster = Cast<AMonster>(Controller->GetPawn());
		FVector MonsterLocation = Monster->GetActorLocation();

		// Iterate over all players to find the closest one
		for (AActor* PlayerActor : PlayerArray)
		{
			auto* Player = Cast<ADarkChamberCharacter>(PlayerActor);

			// Calculate the distance between the AI and the player
			float Distance = FVector::Dist(MonsterLocation, Player->GetActorLocation());

			// Update the closest player if the current player is closer
			if (Distance < ClosestDistance)
			{
				ClosestDistance = Distance;
				ClosestPlayer = Player;
			}
		}

		if (ClosestPlayer)
		{
			Monster->TargetedPlayer = ClosestPlayer;

			// Get Player location as origin
			auto const PlayerLocation = ClosestPlayer->GetActorLocation();

			if (SearchRandom)
			{
				FNavLocation Location;

				// Get the navigation system and create a random location near the player
				if (auto const* NavSystem = UNavigationSystemV1::GetCurrent(GetWorld()))
				{
					// Try to get a random location near the player
					if (NavSystem->GetRandomPointInNavigableRadius(PlayerLocation, SearchRadius, Location))
					{
						OwnerComp.GetBlackboardComponent()->SetValueAsVector(GetSelectedBlackboardKey(), Location.Location);
						FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
						return EBTNodeResult::Succeeded;
					}
				}
			}
			else
			{
				OwnerComp.GetBlackboardComponent()->SetValueAsVector(GetSelectedBlackboardKey(), PlayerLocation);
				FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
				return EBTNodeResult::Succeeded;
			}
		}
	}

	return EBTNodeResult::Failed;
}
