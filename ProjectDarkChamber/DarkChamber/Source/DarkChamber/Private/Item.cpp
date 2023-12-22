// Fill out your copyright notice in the Description page of Project Settings.


#include "Item.h"


#include "Monster.h"
#include "Monster_AIController.h"
#include "NoiseBubble.h"
#include "Components/SphereComponent.h"
#include "Components/WidgetComponent.h"
#include "DarkChamber/DarkChamberCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "Net/UnrealNetwork.h"
#include "Perception/AIPerceptionStimuliSourceComponent.h"
#include "Perception/AISense_Hearing.h"

// Sets default values

void AItem::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AItem, IsOwned);
	DOREPLIFETIME(AItem, ItemWidget);
}

AItem::AItem()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true; 
	IsOwned = false;

	RootComponent = CreateDefaultSubobject<USceneComponent>("Root");
	ItemMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
	ItemMesh->SetIsReplicated(true);
	ItemMesh->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	InteractionRangeSphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("Actor Can Interact Range"));
	InteractionRangeSphereComponent->InitSphereRadius(500.f);
	InteractionRangeSphereComponent->AttachToComponent(ItemMesh, FAttachmentTransformRules::KeepRelativeTransform);

	ItemWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("Item Widget"));
	ItemWidget->SetDrawSize(FVector2d(200, 200));
	ItemWidget->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	ItemWidget->SetVisibility(false);

	SetupStimulusSource();
}

// Called when the game starts or when spawned	
void AItem::BeginPlay()
{
	Super::BeginPlay();

	FScriptDelegate DelegateOverlapBegin;
	FScriptDelegate DelegateOverlapEnd;

	DelegateOverlapBegin.BindUFunction(this, "OnOverlapBegin");
	DelegateOverlapEnd.BindUFunction(this, "OnOverlapEnd");

	if (DelegateOverlapBegin.IsBound() && DelegateOverlapEnd.IsBound() && InteractionRangeSphereComponent)
	{
		InteractionRangeSphereComponent->OnComponentBeginOverlap.Add(DelegateOverlapBegin);
		InteractionRangeSphereComponent->OnComponentEndOverlap.Add(DelegateOverlapEnd);
	}
}

// Called every frame
void AItem::Tick(float DeltaTime)
{
	UStaticMeshComponent* mesh = this->FindComponentByClass<UStaticMeshComponent>();
	Super::Tick(DeltaTime);
	if (IsValid(ItemWidget) && IsValid(TargetActor) && ItemWidget->IsVisible() && !IsOwned)
	{
		ItemWidget->SetWorldRotation(
			UKismetMathLibrary::FindLookAtRotation(ItemMesh->GetComponentLocation(), TargetActor->GetActorLocation()));

		ItemWidget->SetWorldLocation(InteractionRangeSphereComponent->GetComponentLocation() + FVector(0, 0, 50));

		//float opacity = 1-(UE::Geometry::Distance(this->GetActorLocation(), TargetActor->GetActorLocation())/InteractionRangeSphereComponent->GetScaledSphereRadius());
		//ItemWidget->GetWidgetClass().GetDefaultObject()->SetRenderOpacity(opacity);
		//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("Alpha -> %f"), o));
	}
}

void AItem::Interact(AActor* ActorInteracting)
{
	InteractGetItem(ActorInteracting);
}

void AItem::InteractGetItem_Implementation(AActor* ActorInteracting)
{
	if (!IsOwned)
	{
		GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Green, "Interact with Item");

		ItemWidget->SetVisibility(false);
		ADarkChamberCharacter* character = Cast<ADarkChamberCharacter>(ActorInteracting);
		int ItemSlot = character->GetavailableInventorySlot();
		if (ItemSlot < character->InventoryMaxSize)
		{
			IsOwned = true;
			
			character->Inventory.Insert(this, ItemSlot);
			character->MakeItemsInvisible(this);
			character->CurrentlySelectedInventoryItem = ItemSlot;
			DisableComponentsSimulatePhysics();
			SetActorEnableCollision(false);
			UStaticMeshComponent* mesh = this->FindComponentByClass<UStaticMeshComponent>();
			mesh->AttachToComponent(character->ItemPlaceHolderMeshComponent,
			                        FAttachmentTransformRules::SnapToTargetNotIncludingScale);

			character->CurrentItemHeld = this;
			MulticastAddAndDisableItem(character);
		}
		else
		{
			GEngine->AddOnScreenDebugMessage(-10, 1.f, FColor::Blue, "inventory is full");
		}
	}
}

void AItem::MulticastAddAndEnableItem_Implementation()
{
	UStaticMeshComponent* mesh = this->FindComponentByClass<UStaticMeshComponent>();
	mesh->SetSimulatePhysics(true);
	ItemWidget->SetVisibility(true);
	IsOwned = false;
	this->SetActorEnableCollision(true);
	GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Purple, "DID ENABLE");
}

void AItem::MulticastAddAndDisableItem_Implementation(ADarkChamberCharacter* character)
{
	character->MakeItemsInvisible(this);
	DisableComponentsSimulatePhysics();
	AttachToComponent(character->ItemPlaceHolderMeshComponent,
	                  FAttachmentTransformRules::SnapToTargetNotIncludingScale);
	this->SetActorEnableCollision(false);
}

void AItem::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
                           int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && (OtherActor != this) && OtherComp && !IsOwned)
	{
		//GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Purple, "Enter Interact Area");
		TargetActor = OtherActor;
		ItemWidget->SetVisibility(true);
	}
}

void AItem::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
                         int32 OtherBodyIndex)
{
	if (OtherActor && (OtherActor != this) && OtherComp && !IsOwned)
	{
		//GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Purple, "Exit Interact Area");
		ItemWidget->SetVisibility(false);
	}
}

void AItem::NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp, bool bSelfMoved,
                      FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	Super::NotifyHit(MyComp, Other, OtherComp, bSelfMoved, HitLocation, HitNormal, NormalImpulse, Hit);
	FRotator Rotation(0.0f, 0.0f, 0.0f);
	
	if (Other && Other->IsA(ADarkChamberCharacter::StaticClass()))
	{
		return;
	}

	if (!bHasPlayedSound)
	{
		UGameplayStatics::PlaySoundAtLocation(this, FallingSoundEffect, HitLocation);
		UAISense_Hearing::ReportNoiseEvent(this, HitLocation, 1.f, Other, 0, NAME_None);
		bHasPlayedSound = true;
	}
	FTimerHandle TimerHandle;
	GetWorld()->GetTimerManager().SetTimer(TimerHandle,this, &AItem::ResetSetPlayedSound, 1.0f, false, 5);
	
}	

void AItem::SetNoiseBubbleDestroy(AActor* bubble)
{
	bubble->Destroy();
}	

void AItem::ServerThrowItem_Implementation(float force, FVector direction)
{
	UStaticMeshComponent* mesh = this->FindComponentByClass<UStaticMeshComponent>();
	GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Purple, "DID trow");
	FVector location(0.f, 0.f, 400.f);

	this->SetActorLocation(this->GetActorLocation() * location);
	mesh->SetSimulatePhysics(true);
	FTimerHandle TimerHandle;
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &AItem::CanCollide, 5.0f, false, .05f);
	mesh->AddImpulse(direction * force * mesh->GetMass());
	ItemWidget->SetVisibility(true);
}

void AItem::CanCollide()
{
	this->SetActorEnableCollision(true);
	MulticastAddAndEnableItem();
}

void AItem::ResetSetPlayedSound()
{
	if(bHasPlayedSound)
	{
		bHasPlayedSound = false;
	}
}

void AItem::SetupStimulusSource()
{
	StimulusSource = CreateDefaultSubobject<UAIPerceptionStimuliSourceComponent>(TEXT("Stimulus Source"));
	if (StimulusSource)
	{
		StimulusSource->RegisterForSense(TSubclassOf<UAISense_Hearing>());
		StimulusSource->RegisterWithPerceptionSystem();
	}
}
