// Fill out your copyright notice in the Description page of Project Settings.


#include "DoorTest.h"

// Sets default values
ADoorTest::ADoorTest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	isOpen = false;

}

// Called when the game starts or when spawned
void ADoorTest::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADoorTest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADoorTest::Interact_Implementation()
{
	isOpen = !isOpen;
	UE_LOG(LogTemp, Warning, TEXT("Door Activation"))
}

