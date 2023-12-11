// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ActivatableInterface.h"
//#include "Statue.h"
#include "DarkChamber/InteractInterface.h"
#include "GameFramework/Actor.h"
#include "DoorTest.generated.h"

UENUM(BlueprintType, Blueprintable)
enum class EOpenType : uint8
{
	Interaction = 0 UMETA(DisplayName = "Interaction"),
	Lever = 1 UMETA(DisplayName = "Lever"),
	Statue = 2 UMETA(DisplayName = "Statue"),
	Max
};

UCLASS()
class DARKCHAMBER_API ADoorTest : public AActor, public IInteractInterface, public IActivatableInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ADoorTest();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintNativeEvent)
	void Interact(AActor* ActorInteracting);

	UFUNCTION(BlueprintNativeEvent)
	void Activate();
	UFUNCTION()
	void OnInteractHoverBegin(AActor* ActorToInteractWith) override;
	UFUNCTION()
	void OnInteractHoverEnd(AActor* ActorToInteractWith) override;
	UFUNCTION(BlueprintCallable)
	void OpenDoorWithStatues();
	UFUNCTION(BlueprintNativeEvent)
	void ChangeDoorState();


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Variables")
	bool isOpen;
	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category="Variables")
	bool reverse;
	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category="Variables")
	EOpenType doorOpenType;
	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category="Variables")
	TArray<AActor*> StatuesToBeUsed;
};
