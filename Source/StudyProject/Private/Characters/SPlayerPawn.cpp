// SPlayerPawn.cpp

#include "Characters/SPlayerPawn.h"

ASPlayerPawn::ASPlayerPawn()
{
    PrimaryActorTick.bCanEverTick = true; // 개체가 틱될 수 있도록 설정
}

void ASPlayerPawn::PostInitializeComponents()
{
    // 개체의 구성 요소가 초기화된 후 호출되는 함수
    UE_LOG(LogTemp, Log, TEXT("Start ASPlayerPawn::PostInitializeComponents()"));
    Super::PostInitializeComponents(); // 부모 클래스의 PostInitializeComponents 함수 호출
    UE_LOG(LogTemp, Log, TEXT("End ASPlayerPawn::PostInitializeComponents()"));
}

void ASPlayerPawn::PossessedBy(AController* NewController)
{
    // 플레이어 컨트롤러에 의해 해당 개체가 소유되었을 때 호출되는 함수
    UE_LOG(LogTemp, Log, TEXT("Start ASPlayerPawn::PossessedBy(ASPlayerController)"));
    Super::PossessedBy(NewController); // 부모 클래스의 PossessedBy 함수 호출
    UE_LOG(LogTemp, Log, TEXT("End ASPlayerPawn::PossessedBy(ASPlayerController)"));
}

void ASPlayerPawn::UnPossessed()
{
    // 개체가 플레이어 컨트롤러로부터 소유 해제될 때 호출되는 함수
    UE_LOG(LogTemp, Log, TEXT("Start ASPlayerPawn::UnPossessed()"));
    Super::UnPossessed(); // 부모 클래스의 UnPossessed 함수 호출
    UE_LOG(LogTemp, Log, TEXT("End ASPlayerPawn::UnPossessed()"));
}

void ASPlayerPawn::Tick(float DeltaSeconds)
{
    // 매 프레임마다 호출되는 함수
    static bool bOnce = false;
    if (!bOnce)
    {
        UE_LOG(LogTemp, Log, TEXT("Start ASPlayerPawn::Tick()"));
        bOnce = true;
    }

    Super::Tick(DeltaSeconds); // 부모 클래스의 Tick 함수 호출

    if (bOnce)
    {
        UE_LOG(LogTemp, Log, TEXT("End ASPlayerPawn::Tick()"));
    }
}

void ASPlayerPawn::EndPlay(EEndPlayReason::Type EndPlayReason)
{
    // 개체가 플레이를 종료할 때 호출되는 함수
    UE_LOG(LogTemp, Log, TEXT("Start ASPlayerPawn::EndPlay()"));
    Super::EndPlay(EndPlayReason); // 부모 클래스의 EndPlay 함수 호출
    UE_LOG(LogTemp, Log, TEXT("End ASPlayerPawn::EndPlay()"));
}

void ASPlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    // 플레이어 입력 구성 요소를 설정하는 함수
    UE_LOG(LogTemp, Log, TEXT("Start ASPlayerPawn::SetupPlayerInputComponent(PlayerInputComponent)"));
    Super::SetupPlayerInputComponent(PlayerInputComponent); // 부모 클래스의 SetupPlayerInputComponent 함수 호출
    UE_LOG(LogTemp, Log, TEXT("End ASPlayerPawn::SetupPlayerInputComponent(PlayerInputComponent)"));
}

void ASPlayerPawn::BeginPlay()
{
    // 개체가 레벨에 배치되고 초기화된 직후에 호출되는 함수
    UE_LOG(LogTemp, Log, TEXT("Start ASPlayerPawn::BeginPlay()"));
    Super::BeginPlay(); // 부모 클래스의 BeginPlay 함수 호출
    UE_LOG(LogTemp, Log, TEXT("End ASPlayerPawn::BeginPlay()"));
}
