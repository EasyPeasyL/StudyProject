// SGameInstance.h

#pragma once

#include "CoreMinimal.h" // Unreal Engine Core 기능을 사용하기 위한 헤더 파일을 포함합니다.
#include "Engine/GameInstance.h" // UGameInstance 클래스를 사용하기 위한 헤더 파일을 포함합니다.
#include "SGameInstance.generated.h" // 자동 생성된 헤더 파일을 포함합니다.

/**
 *
 */
UCLASS()
class STUDYPROJECT_API USGameInstance : public UGameInstance // USGameInstance 클래스가 UGameInstance 클래스를 상속받음을 나타냅니다.
{
    GENERATED_BODY() // Unreal Engine 4 코드 생성 시스템에게 코드 생성을 하라고 지시합니다.

public:
    USGameInstance(); // 생성자 선언입니다.
    // 함수 시그니처에 커서를 두고 Ctrl + .을 누르면 정의를 간편하게 만들 수 있는 다이얼로그가 보임.

    virtual void Init() override; // 부모 클래스인 UGameInstance의 Init 함수를 재정의합니다.

    virtual void Shutdown() override; // 부모 클래스인 UGameInstance의 Shutdown 함수를 재정의합니다.

private:
    UPROPERTY() // 해당 멤버 변수가 에디터 상에서 어디에서든 접근 가능함을 나타냅니다.
        FString Name; // 이름을 나타내는 변수입니다.

    UPROPERTY() // 해당 멤버 변수가 에디터 상에서 어디에서든 접근 가능함을 나타냅니다.
        TObjectPtr<class USPigeon> SerializedPigeon; // USPigeon 클래스의 객체에 대한 포인터입니다.
    // 클래스의 헤더 파일을 인클루드 하지 않고, 해당 클래스 이름 앞에 class 키워드를 적는 것을 전방선언이라 합니다.
    // 헤더 파일에서 다른 헤더 파일을 참조하면, 다른 헤더 파일이 수정되었을 때 이 헤더 파일도 함께 컴파일됩니다.
    // 따라서 꼭 필요한 경우가 아니라면 헤더 파일에서 다른 헤더 파일을 인클루드 하지 않고 전방선언을 활용합니다.
};
