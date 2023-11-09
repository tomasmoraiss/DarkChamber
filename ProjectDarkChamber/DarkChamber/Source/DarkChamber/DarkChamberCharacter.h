// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include"InteractInterface.h"
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "UObject/WeakInterfacePtr.h"
#include "DarkChamberCharacter.generated.h"


class AItem;
class UInputComponent;
class USkeletalMeshComponent;
class USceneComponent;
class UCameraComponent;
class UAnimMontage;
class USoundBase;

UCLASS(config=Game)
class ADarkChamberCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Pawn mesh: 1st person view (arms; seen only by self) */
	UPROPERTY(VisibleDefaultsOnly, Category=Mesh)
	USkeletalMeshComponent* Mesh1P;

	/** First person camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FirstPersonCameraComponent;

	/** MappingContext */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input, meta=(AllowPrivateAccess = "true"))
	class UInputMappingContext* DefaultMappingContext;

	/** Jump Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input, meta=(AllowPrivateAccess = "true"))
	class UInputAction* JumpAction;

	/** Move Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input, meta=(AllowPrivateAccess = "true"))
	class UInputAction* MoveAction;

	/** Sprint Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input, meta=(AllowPrivateAccess = "true"))
	class UInputAction* SprintAction;
	

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input, meta=(AllowPrivateAccess = "true"))
	float RunningSpeedMultiplier;
	

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input, meta=(AllowPrivateAccess = "true"))
	float DefaultWalkingSpeed;
	

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* CrouchAction;
	

public:
	ADarkChamberCharacter();

protected:
	virtual void BeginPlay();
	UFUNCTION(BlueprintCallable,Category="Interact")
	void InteractWithActor();
	UFUNCTION(BlueprintCallable,Category="Interact")
	void ConstantLineTraceToCheckObjectsForward();
	

public:
	
	virtual void Tick(float DeltaSeconds) override;
	/** Look Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* LookAction;
	//** Interact Input Action*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta=(AllowPrivateAccess = "true"))
	class UInputAction* InteractAction;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta=(AllowPrivateAccess = "true"))
	class UInputAction* DelayedInteractAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Inventory", meta=(AllowPrivateAccess = "true"))
	AItem* Item1;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Inventory", meta=(AllowPrivateAccess = "true"))
	AItem* Item2;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Inventory", meta=(AllowPrivateAccess = "true"))
	AItem* Item3;
	
	//Temporary inventory
	TArray<AItem*> Inventory= { nullptr, nullptr , nullptr };
	UPROPERTY(EditInstanceOnly,BlueprintReadOnly,meta=(MustImplement="InteractableExample"))
	int CurrentlySelectedInventoryItem;

	
	
	//Lock the look function
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta=(AllowPrivateAccess = "true"))
	bool canMove;

	//Store actor Interface to activate later
	TWeakInterfacePtr<IInteractInterface> InteractInterface ;

	AActor* currentInteractableActor;

protected:
	/** Called for movement input */
	void Move(const FInputActionValue& Value);

	/** Called for looking input */
	void Look(const FInputActionValue& Value);

	void Sprint(const FInputActionValue& Value);

	void StopSprint(const FInputActionValue& Value);

	void Crouchh(const FInputActionValue& Value);

	

	

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(UInputComponent* InputComponent) override;
	// End of APawn interface

public:
	/** Returns Mesh1P subobject **/
	USkeletalMeshComponent* GetMesh1P() const { return Mesh1P; }
	/** Returns FirstPersonCameraComponent subobject **/
	UCameraComponent* GetFirstPersonCameraComponent() const { return FirstPersonCameraComponent; }

	/** Called for Interact input */
	void InteractTriggered(const FInputActionValue& Value);
	void InteractCanceledOrCompleted(const FInputActionValue& Value);
	void InteractStarted(const FInputActionValue& Value);

	
};

