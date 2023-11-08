// Fill out your copyright notice in the Description page of Project Settings.


#include "Item.h"
#include "Blueprint/UserWidget.h"
#include "Components/SphereComponent.h"

// Sets default values
AItem::AItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ItemMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
	
	InteractionRangeSphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("Actor Can Interact Range"));
	InteractionRangeSphereComponent->InitSphereRadius(500.f);
	InteractionRangeSphereComponent->AttachToComponent(ItemMesh, FAttachmentTransformRules::KeepRelativeTransform);
	
}

// Called when the game starts or when spawned
void AItem::BeginPlay()
{
	Super::BeginPlay();
	

	FScriptDelegate Delegate;
	Delegate.BindUFunction(this, "OnOverlapBegin");
	if(Delegate.IsBound() && InteractionRangeSphereComponent)
	{
		InteractionRangeSphereComponent->OnComponentBeginOverlap.Add(Delegate);
	}

	
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

void AItem::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	GEngine->AddOnScreenDebugMessage(-1,1,FColor::Purple,"Enter Interact Area");
}

void AItem::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	GEngine->AddOnScreenDebugMessage(-1,1,FColor::Purple,"Exit Interact Area");
}
