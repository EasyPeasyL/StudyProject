// SPlayerPawn.h

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "SPlayerPawn.generated.h"

UCLASS()
class STUDYPROJECT_API ASPlayerPawn : public APawn
{
    GENERATED_BODY()

public:
    ASPlayerPawn(); // 기본 생성자

    virtual void PostInitializeComponents() override;
    // 언리얼의 Construction Script에 따라, CDO 생성 시점임. 우리가 생각하는 개체 생성 시점과 조금 다름. 
    // 개체의 구성 요소가 초기화된 후 호출되는 함수.
    // 즉, 개체가 생성된 직후에 호출됨.

    virtual void PossessedBy(AController* NewController) override;
    // 우리가 생각하는 개체 생성 시점 함수.
    // 플레이어 컨트롤러에 의해 해당 개체가 소유되었을 때 호출되는 함수.

    virtual void UnPossessed() override;
    // 개체가 플레이어 컨트롤러로부터 소유 해제될 때 호출되는 함수.

    virtual void Tick(float DeltaSeconds) override;
    // 매 프레임마다 호출되는 함수. 개체의 상태를 업데이트하는 데 사용됨.

    virtual void EndPlay(EEndPlayReason::Type EndPlayReason) override;
    // 개체가 플레이를 종료할 때 호출되는 함수.

protected:
    virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
    // 플레이어 입력 구성 요소를 설정하는 함수.
    // 이 함수를 통해 플레이어의 입력을 개체에 연결할 수 있음.

    virtual void BeginPlay() override;
    // 개체가 레벨에 배치되고 초기화된 직후에 호출되는 함수.
    // 즉, 게임 플레이가 시작되기 전에 호출됨.

};
