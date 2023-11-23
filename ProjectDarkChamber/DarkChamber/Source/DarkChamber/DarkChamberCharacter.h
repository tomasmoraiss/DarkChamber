// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include"InteractInterface.h"
#include "CoreMinimal.h"
#include "HealthClass.h"
#include "HealthComponent.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "TrapDamageInterface.h"
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
class ADarkChamberCharacter : public ACharacter,public ITrapDamageInterface
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

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input, meta=(AllowPrivateAccess = "true"))
	class UInputMappingContext* HoldingItemMappingContext;

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

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* InventorySelect1Action;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* InventorySelect2Action;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* InventorySelect3Action;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* InventorySelect4Action;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* InventorySelect5Action;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* InventorySelect6Action;

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
public:
	ADarkChamberCharacter();

protected:
	virtual void BeginPlay();
	UFUNCTION(BlueprintCallable, Category="Interact")
	void InteractWithActor();
	UFUNCTION(BlueprintCallable, Category="Interact")
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

	//trow inputs
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta=(AllowPrivateAccess = "true"))
	class UInputAction* HoldTrowAction;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta=(AllowPrivateAccess = "true"))
	class UInputAction* TrowAction;


	//Temporary inventory
	UPROPERTY(EditInstanceOnly, BlueprintReadOnly,Replicated)
	TArray<AItem*> Inventory = {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr};
	
	UPROPERTY(EditInstanceOnly, BlueprintReadOnly,Replicated)
	int CurrentlySelectedInventoryItem;

	UFUNCTION(BlueprintCallable, Category="Inventory")
	int GetavailableInventorySlot();

	//ItemPlaceHolderStuff

	UPROPERTY(EditAnywhere, BlueprintReadWrite,Replicated)
	UStaticMeshComponent* ItemPlaceHolderMeshComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite,Replicated)
	AActor* CurrentItemHeld;


	//Lock the look function

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta=(AllowPrivateAccess = "true"))
	bool canMove;

	//Store actor Interface to activate later
	TWeakInterfacePtr<IInteractInterface> InteractInterface;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	AActor* currentInteractableActor;

	//HEALTH STUFF
	UPROPERTY(EditAnywhere, BlueprintReadWrite,Replicated)
	UHealthComponent* PlayerHealth;

protected:
	/** Called for movement input */
	void Move(const FInputActionValue& Value);
	UFUNCTION(Server,Reliable)
	void setCanMove();
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
	UFUNCTION(Server,Reliable)
	void SelectInventorySlot(int n);
	void MakeItemsInvisible(AItem* item);
	//trowing functions
	void HoldTrowStarted();
	void HoldTrowStop();
	UFUNCTION(Server,Reliable)
	void ServerTrowItem();
	// Trap Damage Attacks
	UFUNCTION(Server,Reliable)
	void EletricAttack() override;
	UFUNCTION(Server,Reliable)
	void FireAttack() override;
	UFUNCTION(Server,Reliable)
	void HoleAttack() override;

	UFUNCTION(Server,Reliable)
	void RequestInteractionWith(AActor* ObjectToInteract,AActor* InteractionInstigator);
private:
	class UAIPerceptionStimuliSourceComponent* StimulusSource;
	void SetupStimulusSource();
};
