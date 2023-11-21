// Fill out your copyright notice in the Description page of Project Settings.


#include "DarkChamber_PlayerController.h"

void ADarkChamber_PlayerController::BeginPlay()
{
	Super::BeginPlay();

	if(APawn* ControlledPawn = GetPawn())
	{
		RequestOwnershipOfPawn(ControlledPawn);	
	}
}

// Now we are technically on the server :D
void ADarkChamber_PlayerController::RequestOwnershipOfPawn_Implementation(APawn* PawnToTakeOwnershipOf)
{
	if(!PawnToTakeOwnershipOf)
		return;

	PawnToTakeOwnershipOf->SetOwner(this);
}
