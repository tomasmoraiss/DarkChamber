// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DarkChamber/DarkChamberCharacter.h"
#include "DarkChamber/InteractInterface.h"
#include "Engine/StaticMeshActor.h"
#include "GameFramework/Actor.h"
#include "Trap.generated.h"

UCLASS()
class DARKCHAMBER_API ATrap : public AActor, public IInteractInterface
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

	void Build();
	void AddItem();
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
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta=(MustImplement="ItemToSpawExample"))
	TSubclassOf<AActor> TrapAfterBuild;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta=(MustImplement="ItemToSpawExample"))
	TSubclassOf<AActor> TrapAfterBuildEletric;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta=(MustImplement="ItemToSpawExample"))
	TSubclassOf<AActor> TrapAfterBuildFire;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta=(MustImplement="ItemToSpawExample"))
	TSubclassOf<AActor> TrapAfterBuildHole;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta=(MustImplement="CharacterExample"))
	AActor* Character;
};
