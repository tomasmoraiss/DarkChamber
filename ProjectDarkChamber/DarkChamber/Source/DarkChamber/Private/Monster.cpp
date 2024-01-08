// Fill out your copyright notice in the Description page of Project Settings.


#include "Monster.h"
#include "Monster_AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "DarkChamber/DarkChamberCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Net/UnrealNetwork.h"

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

void AMonster::OnMonsterAttack()
{
	Notify();
}

void AMonster::Attach(ICameraObserver* Observer)
{
	Observers.Add(Observer);
}

void AMonster::Detach(ICameraObserver* Observer)
{
}

void AMonster::Notify()
{
	for (ICameraObserver* Observer : Observers)
	{
		Observer->OnMonsterAttack();
	}
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


void AMonster::PlayRoarSoundEffect_Implementation()
{
	if (!AttackRoar)
	{
		return;
	}
	UGameplayStatics::PlaySoundAtLocation(this, AttackRoar, GetActorLocation());
}


int AMonster::MeleeAttack_Implementation()
{
	if (const auto* Player = TargetedPlayer)
	{
		if (Player->PlayerHealth->ReduceHealth(AttackDamage)&&!Player->HealthCheatIsOn)TargetedPlayer->PlayerDead();
		TargetedPlayer->TakeDamage();
	}
	PlayRoarSoundEffect();
	return ICombatInterface::MeleeAttack_Implementation();
}

void AMonster::RoarAttack_Implementation()
{
	PlayRoarSoundEffect();
	OnMonsterAttack();
}

void AMonster::FireAttack_Implementation()
{
	if (Controller && Controller->IsA(AMonster_AIController::StaticClass()))
	{
		if (AMonster_AIController* AIController = Cast<AMonster_AIController>(Controller))
		{
			if (!AIController || !GetWorld())
			{
				GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, "No Controller");
				return;
			}
			AIController->FleeFromFire(true);
			FTimerHandle TimerHandle;
			GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &AMonster::SetStopFleeFromFire, 7.0f, false, 3);
		}
	}
}

void AMonster::HoleAttack_Implementation()
{
	if (!GetMovementComponent() || !GetWorld())
	{
		return;
	}
	bIsStunned = true;
	GetMovementComponent()->SetActive(false);
	GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Green, "Stunned");
	FTimerHandle TimerHandle;
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &AMonster::SetNotStunned, 7.0f, false, 7);
}

void AMonster::EletricAttack_Implementation()
{
	if (!GetMovementComponent() || !GetWorld())
	{
		return;
	}
	bIsStunned = true;
	GetMovementComponent()->SetActive(false);
	GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Green, "Stunned");
	FTimerHandle TimerHandle;
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &AMonster::SetNotStunned, 7.0f, false, 5);
}

void AMonster::SetNotStunned()
{
	if (!GetMovementComponent())
	{
		return;
	}
	if (bIsStunned)
	{
		GetMovementComponent()->SetActive(true);
		bIsStunned = false;
	}
}

void AMonster::SetStopFleeFromFire()
{
	if (Controller && Controller->IsA(AMonster_AIController::StaticClass()))
	{
		AMonster_AIController* AIController = Cast<AMonster_AIController>(Controller);
		if (AIController)
		{
			AIController->FleeFromFire(false);
		}
	}
}




