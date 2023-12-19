// Fill out your copyright notice in the Description page of Project Settings.


#include "TVButton.h"

#include "Components/SceneCaptureComponent2D.h"
#include "DarkChamber/InteractInterface.h"

// Sets default values
ATVButton::ATVButton()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ATVButton::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ATVButton::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ATVButton::Interact(AActor* ActorInteracting)
{
	IInteractInterface::Interact(ActorInteracting);
	if (Cameras.Num() > 0)
	{
		if (currentCamera == Cameras.Num() - 1) currentCamera = 0;
		else currentCamera++;

		ActivateCamera(Cameras[currentCamera]);
	}
}

void ATVButton::ActivateCamera(ASceneCapture2D* camera)
{
	for (int i = 0; i < Cameras.Num(); i++)
	{
		if (Cameras[i] == camera)
		{
			Cameras[i]->GetCaptureComponent2D()->bCaptureEveryFrame = true;
		}
		else
		{
			Cameras[i]->GetCaptureComponent2D()->bCaptureEveryFrame = false;
		}
	}
}
