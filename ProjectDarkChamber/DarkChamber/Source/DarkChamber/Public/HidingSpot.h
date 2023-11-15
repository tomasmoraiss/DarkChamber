// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DarkChamber/InteractInterface.h"
#include "GameFramework/Actor.h"
#include "HidingSpot.generated.h"

UCLASS()
class DARKCHAMBER_API AHidingSpot : public AActor, public IInteractInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHidingSpot();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void Interact(AActor* ActorInteracting);

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	USceneComponent* SceneComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* HidingSpotMesh;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* LeaveLocation;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool isHiding;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	AActor* currentActorHiding;
};
