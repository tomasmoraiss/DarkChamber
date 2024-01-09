// Fill out your copyright notice in the Description page of Project Settings.


#include "JumpScarableObject.h"

#include "Components/SphereComponent.h"
#include "DarkChamber/DarkChamberCharacter.h"

// Sets default values
AJumpScarableObject::AJumpScarableObject()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>("Root");
	ItemMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
	ItemMesh->SetIsReplicated(true);
	ItemMesh->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	InteractionRangeSphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("Actor Can Interact Range"));
	InteractionRangeSphereComponent->InitSphereRadius(150.f);
	InteractionRangeSphereComponent->AttachToComponent(ItemMesh, FAttachmentTransformRules::KeepRelativeTransform);
}

// Called when the game starts or when spawned
void AJumpScarableObject::BeginPlay()
{
	Super::BeginPlay();
	FScriptDelegate DelegateOverlapBegin;
	DelegateOverlapBegin.BindUFunction(this, "OnOverlapBegin");
	if (DelegateOverlapBegin.IsBound() && InteractionRangeSphereComponent)
	{
		InteractionRangeSphereComponent->OnComponentBeginOverlap.Add(DelegateOverlapBegin);
	}
}

// Called every frame
void AJumpScarableObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AJumpScarableObject::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
                                         UPrimitiveComponent* OtherComp,
                                         int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && (OtherActor != this) && OtherComp && canScare)
	{
		canScare = false;
		ADarkChamberCharacter* character;
		character = Cast<ADarkChamberCharacter>(OtherActor);
		character->ActivateJumpScare();
	}
}
