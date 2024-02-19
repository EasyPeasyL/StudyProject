// STorch.cpp

#include "WorldStatics/STorch.h" // STorch 헤더 파일을 포함합니다.
#include "Components/BoxComponent.h" // 박스 컴포넌트 헤더 파일을 포함합니다.
#include "Components/PointLightComponent.h" // 포인트 라이트 컴포넌트 헤더 파일을 포함합니다.
#include "Particles/ParticleSystemComponent.h" // 파티클 시스템 컴포넌트 헤더 파일을 포함합니다.

ASTorch::ASTorch()
{
    PrimaryActorTick.bCanEverTick = true; // 주기적으로 Tick 함수가 호출되도록 설정합니다.

    // Box 컴포넌트를 생성하고 루트 컴포넌트로 지정합니다.
    BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
    SetRootComponent(BoxComponent);

    // 바디 스태틱 메시 컴포넌트를 생성하고 Box 컴포넌트에 부착합니다.
    BodyStaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BodyStaticMeshComponent"));
    BodyStaticMeshComponent->SetupAttachment(GetRootComponent());
    BodyStaticMeshComponent->SetRelativeLocation(FVector(0.f, 0.f, -30.f));
    // Pillar_50x500 스태틱 메시를 불러와서 바디 스태틱 메시 컴포넌트에 설정합니다.
    static ConstructorHelpers::FObjectFinder<UStaticMesh> BodyStaticMesh(TEXT("/Script/Engine.StaticMesh'/Game/StarterContent/Architecture/Pillar_50x500.Pillar_50x500'"));
    // 경로 정보가 플레이 중에는 변경되지 않으므로, static 키워드 사용.
    if (true == BodyStaticMesh.Succeeded())
    {
        BodyStaticMeshComponent->SetStaticMesh(BodyStaticMesh.Object);
    }

    // 포인트 라이트 컴포넌트를 생성하고 Box 컴포넌트에 부착합니다.
    PointLightComponent = CreateDefaultSubobject<UPointLightComponent>(TEXT("PointLightComponent"));
    PointLightComponent->SetupAttachment(GetRootComponent());
    PointLightComponent->SetRelativeLocation(FVector(0.f, 0.f, 500.f));

    // 파티클 시스템 컴포넌트를 생성하고 Box 컴포넌트에 부착합니다.
    ParticleSystemComponent = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ParticleSystemComponent"));
    ParticleSystemComponent->SetupAttachment(GetRootComponent());
    ParticleSystemComponent->SetRelativeLocation(FVector(0.f, 0.f, 500.f));
    // 파이어 파티클 템플릿을 불러와서 파티클 시스템 컴포넌트에 설정합니다.
    static ConstructorHelpers::FObjectFinder<UParticleSystem> ParticleTemplate(TEXT("/Script/Engine.ParticleSystem'/Game/StarterContent/Particles/P_Fire.P_Fire'"));
    if (true == ParticleTemplate.Succeeded())
    {
        ParticleSystemComponent->SetTemplate(ParticleTemplate.Object);
    }
}

void ASTorch::BeginPlay()
{
    Super::BeginPlay(); // 부모 클래스의 BeginPlay 함수를 호출합니다.

    RotationSpeed = 300.f; // 회전 속도를 초기화합니다.
}

void ASTorch::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds); // 부모 클래스의 Tick 함수를 호출합니다.

    // Torch를 회전시키는 코드입니다.
    AddActorWorldRotation(FRotator(0.f, RotationSpeed * DeltaSeconds, 0.f));
}
