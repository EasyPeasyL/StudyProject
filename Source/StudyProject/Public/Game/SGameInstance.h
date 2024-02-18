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

    UPROPERTY()
    TObjectPtr<class USPigeon> SerializedPigeon;
    // 클래스의 헤더 파일을 인클루드 하지 않고, 해당 클래스 이름 앞에 class 키워드를 적는 것을 전방선언이라 함.
    // 헤더 파일에서 다른 헤더 파일을 참조하면, 다른 헤더 파일이 수정되었을 때 이 헤더 파일도 함께 컴파일 됨.
    // 따라서 꼭 필요한 경우가 아니라면 헤더 파일에서 다른 헤더파일을 인클루드 하지 않고 전방선언을 활용함.

};



