// Fill out your copyright notice in the Description page of Project Settings.


#include "Trap.h"

#include "EnhancedInputSubsystems.h"
#include "DarkChamber/DarkChamberCharacter.h"


// Sets default values
ATrap::ATrap()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	TrapAfterBuild = this->GetClass();
	HasAllItems = false;
	NumberWhereInventoryIs = 0;
}

// Called when the game starts or when spawned
void ATrap::BeginPlay()
{
	Super::BeginPlay();
}

void ATrap::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	Inventory.Insert(Item1, 0);
	Inventory.Insert(Item2, 1);
	Inventory.Insert(Item3, 2);
}

// Called every frame
void ATrap::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ATrap::Interact()
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
	// TODO: Remove this cast, this variable type should just be a character as it can be downcasted to an AActor*
	// Note: I'm assuming Inventory is a TArray here (or at least it should be as we set this to have the right max number ahead of time)
	ADarkChamberCharacter* TCharacter = Cast<ADarkChamberCharacter>(Character);
	if (!TCharacter || !TCharacter->Inventory.IsValidIndex(TCharacter->CurrentlySelectedInventoryItem))
	{
		return;
	}

	ItemsPlaced[NumberWhereInventoryIs] = TCharacter->Inventory[TCharacter->CurrentlySelectedInventoryItem];
	if (NumberWhereInventoryIs + 1 < 3)NumberWhereInventoryIs++;
	HasAllItems = IsItemsPlacedFull();
	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Black,
	                                 FString::Printf(TEXT("Bool: %s"), HasAllItems ? TEXT("true") : TEXT("false")));
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
	return true;
}
