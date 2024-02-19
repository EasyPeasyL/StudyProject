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
    ASPlayerController(); // 기본 생성자

    virtual void PostInitializeComponents() override;
    // 개체의 구성 요소가 초기화된 후 호출되는 함수.

    virtual void PlayerTick(float DeltaSeconds) override;
    // 플레이어 컨트롤러의 틱 함수. 매 프레임마다 호출됨.

protected:
    virtual void SetupInputComponent() override;
    // 플레이어 입력 구성 요소를 설정하는 함수.

    virtual void OnPossess(APawn* InPawn) override;
    // 플레이어 컨트롤러가 개체를 소유할 때 호출되는 함수.

    virtual void OnUnPossess() override;
    // 플레이어 컨트롤러가 개체를 소유 해제할 때 호출되는 함수.

    virtual void BeginPlay() override;
    // 플레이어 컨트롤러가 레벨에 배치되고 초기화된 직후에 호출되는 함수.

    virtual void EndPlay(EEndPlayReason::Type EndPlayReason) override;
    // 플레이어 컨트롤러가 플레이를 종료할 때 호출되는 함수.
};

