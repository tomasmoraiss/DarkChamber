// Fill out your copyright notice in the Description page of Project Settings.


#include "EndBlock.h"

#include "Components/WidgetComponent.h"
#include "Net/UnrealNetwork.h"

// Sets default values

void AEndBlock::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AEndBlock, ItemWidget);
}

AEndBlock::AEndBlock()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>("Root");
	ItemMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
	ItemMesh->SetIsReplicated(true);
	ItemMesh->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	ItemWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("Item Widget"));
	ItemWidget->SetIsReplicated(true);
	ItemWidget->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	ItemWidget->SetVisibility(true);
}

// Called when the game starts or when spawned
void AEndBlock::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AEndBlock::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AEndBlock::Interact_Implementation(AActor* ActorInteracting)
{
	GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, "ENDED");
	ItemWidget->SetVisibility(true);
	ItemWidget->SetIsReplicated(true);
}


