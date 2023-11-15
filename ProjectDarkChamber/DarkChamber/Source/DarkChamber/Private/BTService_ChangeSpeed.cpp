// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_ChangeSpeed.h"

#include "Monster.h"
#include "Monster_AIController.h"
#include "GameFramework/CharacterMovementComponent.h"

UBTService_ChangeSpeed::UBTService_ChangeSpeed()
{
	bNotifyBecomeRelevant = true;
	NodeName = TEXT("Change speed");
}

void UBTService_ChangeSpeed::OnBecomeRelevant(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::OnBecomeRelevant(OwnerComp, NodeMemory);
	//Get Monster's Controller
	if(auto* const controller = Cast<AMonster_AIController>(OwnerComp.GetAIOwner()))
	{
		if(auto* const monster = Cast<AMonster>(controller->GetPawn()))
		{
			monster->GetCharacterMovement()->MaxWalkSpeed = Speed;
		}
	}
}
