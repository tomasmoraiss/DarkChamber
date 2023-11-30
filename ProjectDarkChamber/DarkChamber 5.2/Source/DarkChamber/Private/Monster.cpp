// Fill out your copyright notice in the Description page of Project Settings.


#include "Monster.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
AMonster::AMonster()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	AttackDamage = 25;
}

// Called when the game starts or when spawned
void AMonster::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMonster::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMonster::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

UBehaviorTree* AMonster::GetBehaviorTree() const
{
	return BehaviorTree;
}

APatrolPath* AMonster::GetPatrolPath() const
{
	return PatrolPath;
}

int AMonster::MeleeAttack_Implementation()
{
	return ICombatInterface::MeleeAttack_Implementation();
}

int AMonster::ThrowItem_Implementation()
{
	return ICombatInterface::ThrowItem_Implementation();
}

void AMonster::FireAttack_Implementation()
{	
	GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, "FireAttack");
}

void AMonster::HoleAttack_Implementation()
{
	CharacterMovement->Deactivate();
	FTimerHandle TimerHandle;
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &AMonster::SetMovement, 7.0f, false, 5);
	GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, "HoleAttack");
}

void AMonster::EletricAttack_Implementation()
{
	CharacterMovement->Deactivate();
	FTimerHandle TimerHandle;
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &AMonster::SetMovement, 5.0f, false, 5);
	GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, "EletricAttack");
}

void AMonster::SetMovement()
{
	CharacterMovement->Activate();
}


