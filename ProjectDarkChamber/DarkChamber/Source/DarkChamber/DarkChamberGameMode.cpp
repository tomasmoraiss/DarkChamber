// Copyright Epic Games, Inc. All Rights Reserved.

#include "DarkChamberGameMode.h"
#include "DarkChamberCharacter.h"
#include "UObject/ConstructorHelpers.h"

ADarkChamberGameMode::ADarkChamberGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
