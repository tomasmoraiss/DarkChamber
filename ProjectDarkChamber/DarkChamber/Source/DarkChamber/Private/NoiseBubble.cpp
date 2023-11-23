// Fill out your copyright notice in the Description page of Project Settings.


#include "NoiseBubble.h"

// Sets default values
ANoiseBubble::ANoiseBubble()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ANoiseBubble::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ANoiseBubble::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

