// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DarkChamber/InteractInterface.h"
#include "GameFramework/Actor.h"
#include "DoorTest.generated.h"

UCLASS()
class DARKCHAMBER_API ADoorTest : public AActor, public IInteractInterface
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
	void Interact(); 
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	 bool isOpen;

};
