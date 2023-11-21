// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "DarkChamber_PlayerController.generated.h"

/**
 * 
 */
UCLASS()
class DARKCHAMBER_API ADarkChamber_PlayerController : public APlayerController
{
	GENERATED_BODY()
public:

	virtual void BeginPlay() override;

	UFUNCTION(Server, Reliable)
	void RequestOwnershipOfPawn(APawn* PawnToTakeOwnershipOf);
	
};
