// SPigeon.h

#pragma once

#include "CoreMinimal.h" // Unreal Engine Core 기능을 사용하기 위한 헤더 파일을 포함합니다.
#include "UObject/NoExportTypes.h" // NoExportTypes 클래스를 사용하기 위한 헤더 파일을 포함합니다.
#include "SFlyable.h" // 인클루드 구문은 항상 .generated.h 파일 위에 작성. // 인터페이스를 포함하는 헤더 파일은 항상 .generated.h 파일 위에 작성합니다.
#include "SPigeon.generated.h" // 자동 생성된 헤더 파일을 포함합니다.

/**
 *
 */
UCLASS()
class STUDYPROJECT_API USPigeon // USPigeon 클래스를 선언합니다.
    : public UObject // UObject 클래스를 상속합니다.
    , public ISFlyable // ISFlyable 인터페이스를 구현합니다.
{
    GENERATED_BODY() // Unreal Engine 4 코드 생성 시스템에게 코드 생성을 하라고 지시합니다.

public:
    USPigeon(); // 생성자 선언입니다.

    virtual void Fly() override; // ISFlyable 인터페이스의 Fly 함수를 구현합니다.

    const FString& GetName() const { return Name; } // 이름을 반환하는 함수입니다.

    void SetName(const FString& InName) { Name = InName; } // 이름을 설정하는 함수입니다.

    int32 GetID() const { return ID; } // ID를 반환하는 함수입니다.

    void SetID(int32 InID) { ID = InID; } // ID를 설정하는 함수입니다.

    virtual void Serialize(FArchive& Ar) override; // 직렬화 함수를 재정의합니다.

private:
    UPROPERTY() // 해당 멤버 변수가 에디터 상에서 어디에서든 접근 가능함을 나타냅니다.
        FString Name; // 이름을 나타내는 변수입니다.

    UPROPERTY() // 해당 멤버 변수가 에디터 상에서 어디에서든 접근 가능함을 나타냅니다.
        int32 ID; // ID를 나타내는 변수입니다.
};
