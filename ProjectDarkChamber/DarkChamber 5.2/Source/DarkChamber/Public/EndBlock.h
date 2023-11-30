// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/WidgetComponent.h"
#include "DarkChamber/InteractInterface.h"
#include "GameFramework/Actor.h"
#include "EndBlock.generated.h"

UCLASS()
class DARKCHAMBER_API AEndBlock : public AActor,public IInteractInterface
{
	GENERATED_BODY()
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	
	
public:	
	// Sets default values for this actor's properties
	AEndBlock();
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UFUNCTION(Server,Reliable)
	void Interact(AActor* ActorInteracting) override;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite,Replicated)
	UWidgetComponent* ItemWidget;
	
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* ItemMesh;

};
