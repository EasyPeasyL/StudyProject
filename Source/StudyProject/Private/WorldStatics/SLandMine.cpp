// SLandMine.cpp


#include "WorldStatics/SLandMine.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"

ASLandMine::ASLandMine()
{
    PrimaryActorTick.bCanEverTick = true;

    BodyBoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BodyBoxComponent"));
    SetRootComponent(BodyBoxComponent);

    BodyStaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BodyStaticMeshComponent"));
    BodyStaticMeshComponent->SetupAttachment(GetRootComponent());
}

void ASLandMine::BeginPlay()
{
    Super::BeginPlay();

    UKismetSystemLibrary::PrintString(this, FString::Printf(TEXT("ASLandMine::BeginPlay() has been called.")));
}

void ASLandMine::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}