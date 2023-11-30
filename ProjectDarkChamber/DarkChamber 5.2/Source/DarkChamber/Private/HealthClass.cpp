// HealthClass.cpp

#include "HealthClass.h"

// Sets default values
AHealthClass::AHealthClass()
{
	// Set this actor to call Tick() every frame
	PrimaryActorTick.bCanEverTick = true;

	// Default values for health
	MaxHealth = 100.0f;
	CurrentHealth = MaxHealth;
}

// Function to reduce health
void AHealthClass::ReduceHealth(float Amount)
{
	if (Amount > 0.0f)
	{
		CurrentHealth -= Amount;
		CurrentHealth = FMath::Max(CurrentHealth, 0.0f);

		UE_LOG(LogTemp, Warning, TEXT("Health reduced by %f. Current Health: %f/%f"), Amount, CurrentHealth, MaxHealth);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Invalid amount. Please provide a positive value."));
	}
}

// Function to add health
void AHealthClass::AddHealth(float Amount)
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

// Function to get current health
float AHealthClass::GetCurrentHealth() const
{
	return CurrentHealth;
}
