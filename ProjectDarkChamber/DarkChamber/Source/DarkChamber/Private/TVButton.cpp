// Fill out your copyright notice in the Description page of Project Settings.


#include "TVButton.h"

#include "Components/SceneCaptureComponent2D.h"
#include "DarkChamber/InteractInterface.h"
#include "Net/UnrealNetwork.h"

void ATVButton::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION( ATVButton, currentCamera, COND_SimulatedOnly );
}

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
		RequestNextCamera();
		ActivateCamera(Cameras[currentCamera]);
	}
}

void ATVButton::OnMonsterAttack()
{
	GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, "DID");
	ToggleCamerasCaptureOFF();
	FTimerHandle TimerHandle;
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &ATVButton::ToggleCamerasCaptureON, 7.0f, false, 3);
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

void ATVButton::CurrentCameraRepNotify()
{
	ActivateCamera(Cameras[currentCamera]);
	
}

void ATVButton::RequestNextCamera()
{
	currentCamera = FMath::Wrap(currentCamera+1, 0, Cameras.Num() - 1);
}

void ATVButton::ToggleCamerasCaptureON()
{
	for (ASceneCapture2D* Camera : Cameras)
	{
		Camera->GetCaptureComponent2D()->bCaptureEveryFrame = true;
	}
}

void ATVButton::ToggleCamerasCaptureOFF()
{
	for (ASceneCapture2D* Camera : Cameras)
	{
		Camera->GetCaptureComponent2D()->bCaptureEveryFrame = false;
	}
}
