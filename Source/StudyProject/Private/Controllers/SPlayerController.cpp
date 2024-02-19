// SPlayerController.cpp

#include "Controllers/SPlayerController.h"

ASPlayerController::ASPlayerController()
{
    PrimaryActorTick.bCanEverTick = true;
}

void ASPlayerController::PostInitializeComponents()
{
    UE_LOG(LogTemp, Warning, TEXT("       Start ASPlayerController::PostInitializeComponents()"));
    Super::PostInitializeComponents(); // 부모 클래스의 PostInitializeComponents() 함수 호출
    UE_LOG(LogTemp, Warning, TEXT("       End   ASPlayerController::PostInitializeComponents()"));
}

void ASPlayerController::PlayerTick(float DeltaSeconds)
{
    static bool bOnce = false;
    if (false == bOnce)
    {
        UE_LOG(LogTemp, Warning, TEXT("       Start ASPlayerController::PlayerTick()"));
    }
    Super::PlayerTick(DeltaSeconds); // 부모 클래스의 PlayerTick() 함수 호출
    if (false == bOnce)
    {
        UE_LOG(LogTemp, Warning, TEXT("       End   ASPlayerController::PlayerTick()"));
        bOnce = true;
    }
}

void ASPlayerController::SetupInputComponent()
{
    UE_LOG(LogTemp, Warning, TEXT("       Start ASPlayerController::SetupInputComponent()"));
    Super::SetupInputComponent(); // 부모 클래스의 SetupInputComponent() 함수 호출
    UE_LOG(LogTemp, Warning, TEXT("       End   ASPlayerController::SetupInputComponent()"));
}

void ASPlayerController::OnPossess(APawn* aPawn)
{
    UE_LOG(LogTemp, Warning, TEXT("       Start ASPlayerController::OnPossess(ASPlayerPawn)"));
    Super::OnPossess(aPawn); // 부모 클래스의 OnPossess() 함수 호출
    UE_LOG(LogTemp, Warning, TEXT("       End   ASPlayerController::OnPossess(ASPlayerPawn)"));
}

void ASPlayerController::OnUnPossess()
{
    UE_LOG(LogTemp, Warning, TEXT("       Start ASPlayerController::OnUnPossess()"));
    Super::OnUnPossess(); // 부모 클래스의 OnUnPossess() 함수 호출
    UE_LOG(LogTemp, Warning, TEXT("       End   ASPlayerController::OnUnPossess()"));
}

void ASPlayerController::BeginPlay()
{
    UE_LOG(LogTemp, Warning, TEXT("       Start ASPlayerController::BeginPlay()"));
    Super::BeginPlay(); // 부모 클래스의 BeginPlay() 함수 호출
    UE_LOG(LogTemp, Warning, TEXT("       End   ASPlayerController::BeginPlay()"));
}

void ASPlayerController::EndPlay(EEndPlayReason::Type EndPlayReason)
{
    UE_LOG(LogTemp, Warning, TEXT("       Start ASPlayerController::EndPlay()"));
    Super::EndPlay(EndPlayReason); // 부모 클래스의 EndPlay() 함수 호출
    UE_LOG(LogTemp, Warning, TEXT("       End   ASPlayerController::EndPlay()"));
}
