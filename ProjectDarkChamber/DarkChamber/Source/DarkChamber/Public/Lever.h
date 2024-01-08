// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ActivatableInterface.h"
#include "DoorTest.h"
#include "DarkChamber/InteractInterface.h"
#include "GameFramework/Actor.h"
#include "Perception/AIPerceptionStimuliSourceComponent.h"
#include "Lever.generated.h"

UCLASS()
class DARKCHAMBER_API ALever : public AActor, public IInteractInterface,public IActivatableInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALever();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintNativeEvent)
	void Interact(AActor* ActorInteracting);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Variables")
	bool isOn;
	
	UPROPERTY(EditInstanceOnly,BlueprintReadOnly, Category="Variables")
	TArray<AActor*> DoorReference;

private:
	class UAIPerceptionStimuliSourceComponent* StimulusSource;
	void SetupStimulusSource();
	
};
	