// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PatrolPath.h"
#include "BehaviorTree/BehaviorTree.h"
#include "GameFramework/Character.h"
#include "CombatInterface.h"
#include "Monster_AIController.h"
#include "TrapDamageInterface.h"
#include "DarkChamber/DarkChamberCharacter.h"
#include "Monster.generated.h"


UCLASS()
class DARKCHAMBER_API AMonster : public ACharacter, public ICombatInterface, public ITrapDamageInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMonster();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UBehaviorTree* GetBehaviorTree() const;

	APatrolPath* GetPatrolPath() const;

	//For attacking the players
	virtual int MeleeAttack_Implementation() override;
	virtual int ThrowItem_Implementation() override;

	UFUNCTION(Server, Reliable)
	void EletricAttack() override;
	UFUNCTION(Server, Reliable)
	void FireAttack() override;
	UFUNCTION(Server, Reliable)
	void HoleAttack() override;

	void SetNotStunned();
	void SetStopFleeFromFire();

	AMonster* Monster;
	ADarkChamberCharacter* TargetedPlayer;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Melee Attack", meta = (AllowPrivateAccess = "true"))
		int AttackDamage;

	bool bIsStunned;

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI", meta = (AllowPrivateAccess = "true"))
		UBehaviorTree* BehaviorTree;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI", meta = (AllowPrivateAccess = "true"))
		APatrolPath* PatrolPath;


};
