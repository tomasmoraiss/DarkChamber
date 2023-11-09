// Fill out your copyright notice in the Description page of Project Settings.


#include "Item.h"
#include "Components/SphereComponent.h"
#include "Components/WidgetComponent.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
AItem::AItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	IsOwned = false;

	ItemMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
	
	InteractionRangeSphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("Actor Can Interact Range"));
	InteractionRangeSphereComponent->InitSphereRadius(2500.f);
	InteractionRangeSphereComponent->AttachToComponent(ItemMesh, FAttachmentTransformRules::KeepRelativeTransform);

	ItemWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("Item Widget"));
	ItemWidget->SetDrawSize(FVector2d(200,200));
	ItemWidget->AttachToComponent(ItemMesh, FAttachmentTransformRules::KeepRelativeTransform);
	ItemWidget->SetVisibility(false);
}

// Called when the game starts or when spawned	
void AItem::BeginPlay()
{
	Super::BeginPlay();
	

	FScriptDelegate DelegateOverlapBegin;
	FScriptDelegate DelegateOverlapEnd;
	
	DelegateOverlapBegin.BindUFunction(this, "OnOverlapBegin");
	DelegateOverlapEnd.BindUFunction(this, "OnOverlapEnd");

	if(DelegateOverlapBegin.IsBound() && DelegateOverlapEnd.IsBound() && InteractionRangeSphereComponent)
	{
		InteractionRangeSphereComponent->OnComponentBeginOverlap.Add(DelegateOverlapBegin);
		InteractionRangeSphereComponent->OnComponentEndOverlap.Add(DelegateOverlapEnd);
	}
}

// Called every frame
void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if(ItemWidget->IsVisible() && !IsOwned)
	{
		ItemWidget->SetWorldRotation(UKismetMathLibrary::FindLookAtRotation(this->GetActorLocation(), TargetActor->GetActorLocation()));
		//float opacity = 1-(UE::Geometry::Distance(this->GetActorLocation(), TargetActor->GetActorLocation())/InteractionRangeSphereComponent->GetScaledSphereRadius());
		//ItemWidget->GetWidgetClass().GetDefaultObject()->SetRenderOpacity(opacity);
		//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("Alpha -> %f"), o));
	}
}

void AItem::Interact()
{
	if(!IsOwned)
	{
		GEngine->AddOnScreenDebugMessage(-1,1,FColor::Green,"Interact with Item");
		IsOwned = true;
		ItemWidget->SetVisibility(false);
	}
}

void AItem::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && (OtherActor != this) && OtherComp && !IsOwned)
	{
		GEngine->AddOnScreenDebugMessage(-1,1,FColor::Purple,"Enter Interact Area");
		TargetActor = OtherActor;
		ItemWidget->SetVisibility(true);
	}
}

void AItem::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor && (OtherActor != this) && OtherComp && !IsOwned)
	{
		GEngine->AddOnScreenDebugMessage(-1,1,FColor::Purple,"Exit Interact Area");
		ItemWidget->SetVisibility(false);
	}
}
