// SPlayerController.cpp

#include "Controllers/SPlayerController.h"

ASPlayerController::ASPlayerController()
{
    PrimaryActorTick.bCanEverTick = true;
}

void ASPlayerController::PostInitializeComponents()
{
    UE_LOG(LogTemp, Warning, TEXT("       Start ASPlayerController::PostInitializeComponents()"));
    Super::PostInitializeComponents(); // �θ� Ŭ������ PostInitializeComponents() �Լ� ȣ��
    UE_LOG(LogTemp, Warning, TEXT("       End   ASPlayerController::PostInitializeComponents()"));
}

void ASPlayerController::PlayerTick(float DeltaSeconds)
{
    static bool bOnce = false;
    if (false == bOnce)
    {
        UE_LOG(LogTemp, Warning, TEXT("       Start ASPlayerController::PlayerTick()"));
    }
    Super::PlayerTick(DeltaSeconds); // �θ� Ŭ������ PlayerTick() �Լ� ȣ��
    if (false == bOnce)
    {
        UE_LOG(LogTemp, Warning, TEXT("       End   ASPlayerController::PlayerTick()"));
        bOnce = true;
    }
}

void ASPlayerController::SetupInputComponent()
{
    UE_LOG(LogTemp, Warning, TEXT("       Start ASPlayerController::SetupInputComponent()"));
    Super::SetupInputComponent(); // �θ� Ŭ������ SetupInputComponent() �Լ� ȣ��
    UE_LOG(LogTemp, Warning, TEXT("       End   ASPlayerController::SetupInputComponent()"));
}

void ASPlayerController::OnPossess(APawn* aPawn)
{
    UE_LOG(LogTemp, Warning, TEXT("       Start ASPlayerController::OnPossess(ASPlayerPawn)"));
    Super::OnPossess(aPawn); // �θ� Ŭ������ OnPossess() �Լ� ȣ��
    UE_LOG(LogTemp, Warning, TEXT("       End   ASPlayerController::OnPossess(ASPlayerPawn)"));
}

void ASPlayerController::OnUnPossess()
{
    UE_LOG(LogTemp, Warning, TEXT("       Start ASPlayerController::OnUnPossess()"));
    Super::OnUnPossess(); // �θ� Ŭ������ OnUnPossess() �Լ� ȣ��
    UE_LOG(LogTemp, Warning, TEXT("       End   ASPlayerController::OnUnPossess()"));
}

void ASPlayerController::BeginPlay()
{
    UE_LOG(LogTemp, Warning, TEXT("       Start ASPlayerController::BeginPlay()"));
    Super::BeginPlay(); // �θ� Ŭ������ BeginPlay() �Լ� ȣ��
    UE_LOG(LogTemp, Warning, TEXT("       End   ASPlayerController::BeginPlay()"));
}

void ASPlayerController::EndPlay(EEndPlayReason::Type EndPlayReason)
{
    UE_LOG(LogTemp, Warning, TEXT("       Start ASPlayerController::EndPlay()"));
    Super::EndPlay(EndPlayReason); // �θ� Ŭ������ EndPlay() �Լ� ȣ��
    UE_LOG(LogTemp, Warning, TEXT("       End   ASPlayerController::EndPlay()"));
}
