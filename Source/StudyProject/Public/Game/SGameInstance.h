// SGameInstance.h

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "SGameInstance.generated.h"

/**
 *
 */
UCLASS()
class STUDYPROJECT_API USGameInstance : public UGameInstance
{
    GENERATED_BODY()

public:
    USGameInstance();
    // 함수 시그니처에 커서를 두고 Ctrl + .을 누르면 정의를 간편하게 만들 수 있는 다이얼로그가 보임.

    virtual void Init() override;

    virtual void Shutdown() override;

private:
    UPROPERTY()
    FString Name;

};



