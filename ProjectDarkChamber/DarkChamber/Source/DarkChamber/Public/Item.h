// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/WidgetComponent.h"
#include "DarkChamber/InteractInterface.h"
#include "GameFramework/Actor.h"
#include "Item.generated.h"

UCLASS()
class DARKCHAMBER_API AItem : public AActor, public IInteractInterface
{
	GENERATED_BODY()
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

public:
	// Sets default values for this actor's properties
	AItem();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void Interact(AActor* ActorInteracting);
	UFUNCTION(Server, Reliable)
	void InteractGetItem(AActor* ActorInteracting);

	UFUNCTION(NetMulticast, Reliable)
	void MulticastAddAndDisableItem(class ADarkChamberCharacter* character);
	UFUNCTION(NetMulticast, Reliable)
	void MulticastAddAndEnableItem();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class USphereComponent* InteractionRangeSphereComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* ItemMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UWidgetComponent* ItemWidget;

	UFUNCTION()
	void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor,
	                    class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
	                    const FHitResult& SweepResult);

	UFUNCTION()
	void OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor,
	                  class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	//NOISE BUBBLE
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite,Category="noise")
	TSubclassOf<AActor> NoiseBubble;
	UFUNCTION()
	void NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp, bool bSelfMoved,
	               FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit) override;

	UPROPERTY()
	AActor* TargetActor;

	UPROPERTY(BlueprintReadOnly, Replicated)
	bool IsOwned;

	UPROPERTY(EditAnywhere, Category="Inventory")
	int itemNumber;
	//throwItem
	//UFUNCTION()
	//void ThrowItem(float force,FVector direction);

	UFUNCTION(Server, Reliable)
	void ServerThrowItem(float force, FVector direction);

	UFUNCTION()
	void CanCollide();
};
