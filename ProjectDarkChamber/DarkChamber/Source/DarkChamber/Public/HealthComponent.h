// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DARKCHAMBER_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHealthComponent();
	// Sets default values for this actor's properties

	// Function to reduce health
	UFUNCTION(BlueprintCallable, Category = "Health")
	bool ReduceHealth(int Amount);

	// Function to add health
	UFUNCTION(BlueprintCallable, Category = "Health")
	void AddHealth(float Amount);

	UFUNCTION(BlueprintCallable, Category = "Stamina")
	void ReduceStamina(float Amount);

	// Function to add health
	UFUNCTION(BlueprintCallable, Category = "Stamina")
	void AddStamina(float Amount);

	// Function to get current health
	UFUNCTION(BlueprintPure, Category = "Health")
	float GetCurrentHealth() const;

	// Function to get max stamina
	UFUNCTION(BlueprintPure, Category = "Stamina")
	float GetMaxStamina() const;
	
	// Function to get current stamina
	UFUNCTION(BlueprintPure, Category = "Stamina")
	float GetCurrentStamina() const;

	// Maximum health
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Health")
	int MaxHealth;

	// Current health
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Health")
	int CurrentHealth;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stamina")
	float MaxStamina;

	// Current health
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Stamina")
	float CurrentStamina;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
