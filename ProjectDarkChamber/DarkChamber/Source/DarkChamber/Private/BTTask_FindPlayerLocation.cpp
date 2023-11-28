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
	//auto const * const Controller = OwnerComp.GetAIOwner();
	//Get Player character
	if(auto* Player = UGameplayStatics::GetPlayerCharacter(GetWorld(),0))
	{
		auto const * const Controller = OwnerComp.GetAIOwner();
		auto * const monster = Cast<AMonster>(Controller->GetPawn());
		monster->TargetedPlayer = Cast<ADarkChamberCharacter>(Player);
		//Get Player location as origin
		auto const PlayerLocation = Player->GetActorLocation();
		if(SearchRandom)
		{
			FNavLocation Location;

			//Get the navigation system and create a random location near the player
			if(auto const* NavSystem = UNavigationSystemV1::GetCurrent(GetWorld()))
			{
				//Try to get a random location near the player
				if(NavSystem->GetRandomPointInNavigableRadius(PlayerLocation, SearchRadius, Location))
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
	return EBTNodeResult::Failed;
}
