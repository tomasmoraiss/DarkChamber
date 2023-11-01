// Fill out your copyright notice in the Description page of Project Settings.


#include "ChairThatMoves.h"

// Sets default values
AChairThatMoves::AChairThatMoves()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AChairThatMoves::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AChairThatMoves::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AChairThatMoves::Interact(AActor* Actor)
{
	
}

