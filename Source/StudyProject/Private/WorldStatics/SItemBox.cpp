// SItemBox.cpp


#include "WorldStatics/SItemBox.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Particles/ParticleSystemComponent.h"

ASItemBox::ASItemBox()
{
    PrimaryActorTick.bCanEverTick = false;

    BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
    SetRootComponent(BoxComponent);
    BoxComponent->SetBoxExtent(FVector(40.0f, 42.0f, 30.0f));
    BoxComponent->OnComponentBeginOverlap.AddDynamic(this, &ASItemBox::OnOverlapBegin);
    BoxComponent->SetCollisionProfileName(FName("Trigger"));

    StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
    StaticMeshComponent->SetupAttachment(GetRootComponent());
    StaticMeshComponent->SetRelativeLocation(FVector(0.0f, -3.5f, -30.0f));
    StaticMeshComponent->SetCollisionProfileName(TEXT("NoCollision"));
    /*
    static ConstructorHelpers::FObjectFinder<UStaticMesh> BoxMesh(TEXT("오브젝트 패스"));
    if (BoxMesh.Object)
    {
        StaticMeshComponent->SetStaticMesh(BoxMesh.Object);
    }
    */

    ParticleSystemComponent = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ParticleSystemComponent"));
    ParticleSystemComponent->SetupAttachment(GetRootComponent());
    ParticleSystemComponent->SetAutoActivate(false);
    /*
    static ConstructorHelpers::FObjectFinder<UParticleSystem> EffectTemplate(TEXT("오브젝트 패스"));
    if (EffectTemplate.Object)
    {
        ParticleSystemComponent->SetTemplate(EffectTemplate.Object);
        ParticleSystemComponent->bAutoActivate = false;
    }
    */

    //BoxComponent->SetCollisionProfileName(FName("Trigger"));
    BoxComponent->SetCollisionProfileName(FName(TEXT("SItemBox")));

}

void ASItemBox::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepHitResult)
{
    ParticleSystemComponent->Activate(true);
    StaticMeshComponent->SetHiddenInGame(true);
    SetActorEnableCollision(false);
    ParticleSystemComponent->OnSystemFinished.AddDynamic(this, &ASItemBox::OnEffectFinish);
}

void ASItemBox::OnEffectFinish(UParticleSystemComponent* ParticleSystem)
{
    Destroy();
}