// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CameraObserver.h"
#include "DarkChamber/InteractInterface.h"
#include "Engine/SceneCapture2D.h"
#include "GameFramework/Actor.h"
#include "TVButton.generated.h"

UCLASS()
class DARKCHAMBER_API ATVButton : public AActor, public IInteractInterface, public ICameraObserver
{
	GENERATED_BODY()
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

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
	UPROPERTY(ReplicatedUsing=CurrentCameraRepNotify)
	int currentCamera = 0;
	virtual void Interact(AActor* ActorInteracting) override;
	virtual void OnMonsterAttack() override;

	void ActivateCamera(ASceneCapture2D* camera);

	UFUNCTION()
	void CurrentCameraRepNotify();

	UFUNCTION()
	void RequestNextCamera();
private:
	void ToggleCamerasCaptureOFF();
	void ToggleCamerasCaptureON();

	bool CanChangeView;
};
