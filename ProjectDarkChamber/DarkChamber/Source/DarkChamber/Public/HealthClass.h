// HealthClass.h

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HealthClass.generated.h"

UCLASS()
class DARKCHAMBER_API AHealthClass : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AHealthClass();

	// Function to reduce health
	UFUNCTION(BlueprintCallable, Category = "Health")
	void ReduceHealth(float Amount);

	// Function to add health
	UFUNCTION(BlueprintCallable, Category = "Health")
	void AddHealth(float Amount);

	// Function to get current health
	UFUNCTION(BlueprintPure, Category = "Health")
	float GetCurrentHealth() const;

	// Maximum health
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Health")
	float MaxHealth;

	// Current health
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Health")
	float CurrentHealth;

protected:
	
};
