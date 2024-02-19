// SPlayerController.h

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "SPlayerController.generated.h"

/**
 * Custom player controller class.
 */
UCLASS()
class STUDYPROJECT_API ASPlayerController : public APlayerController
{
    GENERATED_BODY()

public:
    ASPlayerController(); // �⺻ ������

    virtual void PostInitializeComponents() override;
    // ��ü�� ���� ��Ұ� �ʱ�ȭ�� �� ȣ��Ǵ� �Լ�.

    virtual void PlayerTick(float DeltaSeconds) override;
    // �÷��̾� ��Ʈ�ѷ��� ƽ �Լ�. �� �����Ӹ��� ȣ���.

protected:
    virtual void SetupInputComponent() override;
    // �÷��̾� �Է� ���� ��Ҹ� �����ϴ� �Լ�.

    virtual void OnPossess(APawn* InPawn) override;
    // �÷��̾� ��Ʈ�ѷ��� ��ü�� ������ �� ȣ��Ǵ� �Լ�.

    virtual void OnUnPossess() override;
    // �÷��̾� ��Ʈ�ѷ��� ��ü�� ���� ������ �� ȣ��Ǵ� �Լ�.

    virtual void BeginPlay() override;
    // �÷��̾� ��Ʈ�ѷ��� ������ ��ġ�ǰ� �ʱ�ȭ�� ���Ŀ� ȣ��Ǵ� �Լ�.

    virtual void EndPlay(EEndPlayReason::Type EndPlayReason) override;
    // �÷��̾� ��Ʈ�ѷ��� �÷��̸� ������ �� ȣ��Ǵ� �Լ�.
};

