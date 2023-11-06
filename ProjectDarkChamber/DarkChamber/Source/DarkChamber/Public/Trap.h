// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DarkChamber/InteractInterface.h"
#include "GameFramework/Actor.h"
#include "Trap.generated.h"

UCLASS()
class DARKCHAMBER_API ATrap : public AActor,public IInteractInterface
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

	void Interact() override;

	void OnInteractHoverBegin(AActor* ActorToInteractWith) override;

	void OnInteractHoverEnd(AActor* ActorToInteractWith) override;

	

};
