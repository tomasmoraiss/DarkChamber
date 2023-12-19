// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DarkChamber/InteractInterface.h"
#include "Engine/SceneCapture2D.h"
#include "GameFramework/Actor.h"
#include "TVButton.generated.h"

UCLASS()
class DARKCHAMBER_API ATVButton : public AActor, public IInteractInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ATVButton();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category="cameras")
	TArray<ASceneCapture2D*> Cameras;
	int currentCamera = 0;
	void Interact(AActor* ActorInteracting) override;

	void ActivateCamera(ASceneCapture2D* camera);
};
