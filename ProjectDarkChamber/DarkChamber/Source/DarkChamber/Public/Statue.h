// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DoorTest.h"
#include "DarkChamber/InteractInterface.h"
#include "GameFramework/Actor.h"
#include "Statue.generated.h"

UENUM(BlueprintType)
enum class EDirection : uint8
{
	Front = 0 UMETA(DisplayName = "Front"),
	Right = 1 UMETA(DisplayName = "Right"),
	Back = 2 UMETA(DisplayName = "Back"),
	Left = 3 UMETA(DisplayName = "Left"),
	MAX
};

UCLASS()
class DARKCHAMBER_API AStatue : public AActor, public IInteractInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AStatue();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* ItemMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	uint8 CurrentFacingDirection;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category="Variables")
	EDirection CorrectFacingDirection;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool canInteract;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool StatueFacingCorrectDirection = false;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category="Variables")
	ADoorTest* doorToBeTested = nullptr;

	UFUNCTION(BlueprintNativeEvent)
	void Interact(AActor* ActorInteracting);

	UFUNCTION()
	void CheckStatueDirection();
};
