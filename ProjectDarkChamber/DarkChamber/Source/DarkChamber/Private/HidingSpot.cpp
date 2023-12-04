// Fill out your copyright notice in the Description page of Project Settings.


#include "HidingSpot.h"

#include "Net/UnrealNetwork.h"


void AHidingSpot::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);


	DOREPLIFETIME(AHidingSpot, isHiding);
}

// Sets default values
AHidingSpot::AHidingSpot()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>("Root");

	HidingSpotMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Hiding Spot Mesh"));
	HidingSpotMesh->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	LeaveLocation = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Leave Location"));
	LeaveLocation->AttachToComponent(HidingSpotMesh, FAttachmentTransformRules::KeepRelativeTransform);
	isHiding = false;
	currentActorHiding = nullptr;
}

// Called when the game starts or when spawned
void AHidingSpot::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AHidingSpot::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AHidingSpot::Interact(AActor* ActorInteracting)
{
	if (isHiding && currentActorHiding == ActorInteracting)
	{
		ActorInteracting->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
		ActorInteracting->SetActorLocation(LeaveLocation->GetComponentLocation());
		ActorInteracting->SetActorEnableCollision(true);
		isHiding = false;
	}
	else if (!isHiding)
	{
		ActorInteracting->AttachToComponent(HidingSpotMesh, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
		ActorInteracting->SetActorEnableCollision(false);

		isHiding = true;
		currentActorHiding = ActorInteracting;
	}
}
