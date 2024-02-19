// SPlayerPawn.cpp

#include "Characters/SPlayerPawn.h"

ASPlayerPawn::ASPlayerPawn()
{
    PrimaryActorTick.bCanEverTick = true; // ��ü�� ƽ�� �� �ֵ��� ����
}

void ASPlayerPawn::PostInitializeComponents()
{
    // ��ü�� ���� ��Ұ� �ʱ�ȭ�� �� ȣ��Ǵ� �Լ�
    UE_LOG(LogTemp, Log, TEXT("Start ASPlayerPawn::PostInitializeComponents()"));
    Super::PostInitializeComponents(); // �θ� Ŭ������ PostInitializeComponents �Լ� ȣ��
    UE_LOG(LogTemp, Log, TEXT("End ASPlayerPawn::PostInitializeComponents()"));
}

void ASPlayerPawn::PossessedBy(AController* NewController)
{
    // �÷��̾� ��Ʈ�ѷ��� ���� �ش� ��ü�� �����Ǿ��� �� ȣ��Ǵ� �Լ�
    UE_LOG(LogTemp, Log, TEXT("Start ASPlayerPawn::PossessedBy(ASPlayerController)"));
    Super::PossessedBy(NewController); // �θ� Ŭ������ PossessedBy �Լ� ȣ��
    UE_LOG(LogTemp, Log, TEXT("End ASPlayerPawn::PossessedBy(ASPlayerController)"));
}

void ASPlayerPawn::UnPossessed()
{
    // ��ü�� �÷��̾� ��Ʈ�ѷ��κ��� ���� ������ �� ȣ��Ǵ� �Լ�
    UE_LOG(LogTemp, Log, TEXT("Start ASPlayerPawn::UnPossessed()"));
    Super::UnPossessed(); // �θ� Ŭ������ UnPossessed �Լ� ȣ��
    UE_LOG(LogTemp, Log, TEXT("End ASPlayerPawn::UnPossessed()"));
}

void ASPlayerPawn::Tick(float DeltaSeconds)
{
    // �� �����Ӹ��� ȣ��Ǵ� �Լ�
    static bool bOnce = false;
    if (!bOnce)
    {
        UE_LOG(LogTemp, Log, TEXT("Start ASPlayerPawn::Tick()"));
        bOnce = true;
    }

    Super::Tick(DeltaSeconds); // �θ� Ŭ������ Tick �Լ� ȣ��

    if (bOnce)
    {
        UE_LOG(LogTemp, Log, TEXT("End ASPlayerPawn::Tick()"));
    }
}

void ASPlayerPawn::EndPlay(EEndPlayReason::Type EndPlayReason)
{
    // ��ü�� �÷��̸� ������ �� ȣ��Ǵ� �Լ�
    UE_LOG(LogTemp, Log, TEXT("Start ASPlayerPawn::EndPlay()"));
    Super::EndPlay(EndPlayReason); // �θ� Ŭ������ EndPlay �Լ� ȣ��
    UE_LOG(LogTemp, Log, TEXT("End ASPlayerPawn::EndPlay()"));
}

void ASPlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    // �÷��̾� �Է� ���� ��Ҹ� �����ϴ� �Լ�
    UE_LOG(LogTemp, Log, TEXT("Start ASPlayerPawn::SetupPlayerInputComponent(PlayerInputComponent)"));
    Super::SetupPlayerInputComponent(PlayerInputComponent); // �θ� Ŭ������ SetupPlayerInputComponent �Լ� ȣ��
    UE_LOG(LogTemp, Log, TEXT("End ASPlayerPawn::SetupPlayerInputComponent(PlayerInputComponent)"));
}

void ASPlayerPawn::BeginPlay()
{
    // ��ü�� ������ ��ġ�ǰ� �ʱ�ȭ�� ���Ŀ� ȣ��Ǵ� �Լ�
    UE_LOG(LogTemp, Log, TEXT("Start ASPlayerPawn::BeginPlay()"));
    Super::BeginPlay(); // �θ� Ŭ������ BeginPlay �Լ� ȣ��
    UE_LOG(LogTemp, Log, TEXT("End ASPlayerPawn::BeginPlay()"));
}
