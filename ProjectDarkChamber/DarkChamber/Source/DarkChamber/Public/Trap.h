// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DarkChamber/DarkChamberCharacter.h"
#include "ActivatableInterface.h"
#include "DarkChamber/InteractInterface.h"
#include "Engine/StaticMeshActor.h"
#include "GameFramework/Actor.h"
#include "Trap.generated.h"

UCLASS()
class DARKCHAMBER_API ATrap : public AActor, public IInteractInterface, public IActivatableInterface
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input, meta=(AllowPrivateAccess = "true"))
	class UInputMappingContext* InteractDelayedMappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input, meta=(AllowPrivateAccess = "true"))
	class UInputMappingContext* InteractDefaultMappingContext;

public:
	// Sets default values for this actor's properties
	ATrap();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void Interact(AActor* ActorInteracting) override;

	void OnInteractHoverBegin(AActor* ActorToInteractWith) override;

	void OnInteractHoverEnd(AActor* ActorToInteractWith) override;

	void Activate() override;

	void Build();
	void AddItem(AActor* ActorInteracting);
	void SetTrapItemVisible(int n);
	bool IsItemsPlacedFull();
	bool CanIAddThisItemToTheTrap(int n);
	int WhatTrapIsBuilt();
	//boolean to check if its has all the items already
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, meta=(MustImplement="ItemToSpawExample"))
	bool HasAllItems;
	//array of items in the trap

	TArray<AItem*> ItemsPlaced = {nullptr, nullptr, nullptr};
	TArray<int> ItemsPlaced2 = {NULL, NULL, NULL};

	UPROPERTY(EditInstanceOnly, meta=(MustImplement="ItemToSpawExample"))
	int NumberWhereInventoryIs;
	//Item that will be spawned
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite,Category="inventory")
	TSubclassOf<AActor> TrapAfterBuild;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="inventory")
	TSubclassOf<AActor> TrapAfterBuildEletric;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite,Category="inventory")
	TSubclassOf<AActor> TrapAfterBuildFire;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite,Category="inventory")
	TSubclassOf<AActor> TrapAfterBuildHole;
	//character instance
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta=(MustImplement="CharacterExample"))
	AActor* Character;
	//BoxCollider
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool Built = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool Used = false;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool CanTakeDamage = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool Activated = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* ItemMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* TeslaCoil;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* Wood;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* Batery;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* GasCan;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* Spike;
	
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="BOX")
	FVector vector;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class UBoxComponent* InteractionRangeBoxComponent;

	UFUNCTION()
	virtual void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor,
	                    class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
	                    const FHitResult& SweepResult);

	UFUNCTION()
	virtual void OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor,
	                  class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UFUNCTION()
	virtual void EletricAttack();
	UFUNCTION()
	virtual void FireAttack();
	UFUNCTION()
	virtual void HoleAttack();
};
