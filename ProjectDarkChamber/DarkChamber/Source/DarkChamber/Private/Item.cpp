// Fill out your copyright notice in the Description page of Project Settings.


#include "Item.h"
#include "Components/SphereComponent.h"

// Sets default values
AItem::AItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AItem::BeginPlay()
{
	Super::BeginPlay();
	InteractionRangeSphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("Attacking Cullusion"));
	InteractionRangeSphereComponent->InitSphereRadius(150.f);
	InteractionRangeSphereComponent->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	
}

// Called every frame
void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

void AItem::Interact()
{
	GEngine->AddOnScreenDebugMessage(-1,1,FColor::Green,"Interact with Item");
}

