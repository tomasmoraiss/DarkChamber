// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthComponent.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	// Set this actor to call Tick() every frame
	PrimaryComponentTick.bCanEverTick = true;

	// Default values for health
	MaxHealth = 100.0f;
	CurrentHealth = MaxHealth;
}

void UHealthComponent::ReduceHealth(float Amount)
{
	if (Amount > 0.0f)
	{
		CurrentHealth -= Amount;
		CurrentHealth = FMath::Max(CurrentHealth, 0.0f);
		
		//GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red,FString::Printf(TEXT("Health reduced by %f. Current Health: %f/%f"), Amount, CurrentHealth, MaxHealth));
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Invalid amount. Please provide a positive value."));
	}
}

void UHealthComponent::AddHealth(float Amount)
{
	if (Amount > 0.0f)
	{
		CurrentHealth += Amount;
		CurrentHealth = FMath::Min(CurrentHealth, MaxHealth);

		UE_LOG(LogTemp, Warning, TEXT("Health added by %f. Current Health: %f/%f"), Amount, CurrentHealth, MaxHealth);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Invalid amount. Please provide a positive value."));
	}
}

float UHealthComponent::GetCurrentHealth() const
{
	return CurrentHealth;
}

// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
}


// Called every frame
void UHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                     FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}
