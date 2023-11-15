// Fill out your copyright notice in the Description page of Project Settings.


#include "Trap.h"

#include <unordered_set>

#include "iostream"
#include "EnhancedInputSubsystems.h"
#include "Item.h"
#include "DarkChamber/DarkChamberCharacter.h"


// Sets default values
ATrap::ATrap()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	HasAllItems = false;
	NumberWhereInventoryIs = 0;
}

// Called when the game starts or when spawned
void ATrap::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ATrap::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ATrap::Interact(AActor* ActorInteracting)
{
	GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Green, "Interactedd");
	if (HasAllItems)Build();
	else AddItem();
}

void ATrap::OnInteractHoverBegin(AActor* ActorToInteractWith)
{
	Character = ActorToInteractWith;
	APawn* InteractPawn = Cast<APawn>(ActorToInteractWith);
	if (APlayerController* PlayerController = Cast<APlayerController>(InteractPawn->Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<
			UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(InteractDelayedMappingContext, 0);
		}
	}
}

void ATrap::OnInteractHoverEnd(AActor* ActorToInteractWith)
{
	APawn* InteractPawn = Cast<APawn>(ActorToInteractWith);
	if (APlayerController* PlayerController = Cast<APlayerController>(InteractPawn->Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<
			UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->RemoveMappingContext(InteractDelayedMappingContext);
		}
	}
}

void ATrap::Build()
{
	GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, "BUILT");
	FVector Location(this->GetActorLocation().X, this->GetActorLocation().Y, this->GetActorLocation().Z + 50);
	FRotator Rotation(0.0f, 0.0f, 0.0f);
	FActorSpawnParameters SpawnInfo;
	GetWorld()->SpawnActor<AActor>(TrapAfterBuild, Location, Rotation);
}

void ATrap::AddItem()
{
	ADarkChamberCharacter* TCharacter = Cast<ADarkChamberCharacter>(Character);
	if (!TCharacter || !TCharacter->Inventory.IsValidIndex(TCharacter->CurrentlySelectedInventoryItem) || TCharacter->
		CurrentlySelectedInventoryItem > 5)
	{
		GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, "dont have item selected");
		return;
	}
	AItem* TItem = Cast<AItem>(TCharacter->Inventory[TCharacter->CurrentlySelectedInventoryItem]);
	if (CanIAddThisItemToTheTrap(TItem->itemNumber))
	{
		ItemsPlaced[NumberWhereInventoryIs] = TCharacter->Inventory[TCharacter->CurrentlySelectedInventoryItem];
		ItemsPlaced2[NumberWhereInventoryIs] = TCharacter->Inventory[TCharacter->CurrentlySelectedInventoryItem]->
			itemNumber;
		AActor* TActor = Cast<AActor>(TCharacter->Inventory[TCharacter->CurrentlySelectedInventoryItem]);
		TActor->Destroy();
		TCharacter->Inventory[TCharacter->CurrentlySelectedInventoryItem] = nullptr;
		TCharacter->CurrentlySelectedInventoryItem = 6;
		if (NumberWhereInventoryIs + 1 < 3)NumberWhereInventoryIs++;
		HasAllItems = IsItemsPlacedFull();
		GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Black,
		                                 FString::Printf(TEXT("Bool: %s"), HasAllItems ? TEXT("true") : TEXT("false")));
	}
	else GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, "This item dont go into the trap or is already innit");
}

bool ATrap::IsItemsPlacedFull()
{
	for (int i = 0; i < ItemsPlaced.Num(); i++)
	{
		if (ItemsPlaced[i] == nullptr)
		{
			return false;
		}
	}
	WhatTrapIsBuilt();
	return true;
}

bool ATrap::CanIAddThisItemToTheTrap(int n)
{
	if (n <= 5)
	{
		for (int i = 0; i < ItemsPlaced.Num(); i++)
		{
			if (ItemsPlaced[i] != nullptr)
			{
				if (ItemsPlaced[i]->itemNumber == n)
				{
					return false;
				}
			}
		}
		return true;
	}
	return false;
}

int ATrap::WhatTrapIsBuilt()
{
	TArray<int> trap1 = {1, 2, 3};
	TArray<int> trap2 = {1, 2, 4};
	TArray<int> trap3 = {1, 2, 5};
	std::unordered_multiset<int> Set1(ItemsPlaced2.GetData(), ItemsPlaced2.GetData() + ItemsPlaced2.Num());
	std::unordered_multiset<int> Set2(trap1.GetData(), trap1.GetData() + trap1.Num());
	std::unordered_multiset<int> Set3(trap2.GetData(), trap2.GetData() + trap2.Num());
	std::unordered_multiset<int> Set4(trap3.GetData(), trap3.GetData() + trap3.Num());

	if (Set1 == Set2)
	{
		TrapAfterBuild = TrapAfterBuildEletric;
		GEngine->AddOnScreenDebugMessage(-1, 3, FColor::Red, "Items are the same1");
		return 1;
	}
	else if (Set1 == Set3)
	{
		TrapAfterBuild = TrapAfterBuildFire;
		GEngine->AddOnScreenDebugMessage(-1, 3, FColor::Red, "Items are the same2");
		return 2;
	}
	else if (Set1 == Set4)
	{
		TrapAfterBuild = TrapAfterBuildHole;
		GEngine->AddOnScreenDebugMessage(-1, 3, FColor::Red, "Items are the same3");
		return 3;
	}
	else return 0;
}
