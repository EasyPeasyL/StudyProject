// SFlyable.h

#pragma once

#include "CoreMinimal.h" // Unreal Engine Core 기능을 사용하기 위한 헤더 파일을 포함합니다.
#include "UObject/Interface.h" // 인터페이스 클래스를 사용하기 위한 헤더 파일을 포함합니다.
#include "SFlyable.generated.h" // 자동 생성된 헤더 파일을 포함합니다.

USTRUCT() // 구조체 선언을 위한 매크로입니다.
struct FBirdData // FBirdData 구조체를 선언합니다.
{
    GENERATED_BODY() // Unreal Engine 4 코드 생성 시스템에게 코드 생성을 하라고 지시합니다.

public:
    FBirdData() {} // 기본 생성자입니다.

    // 이름과 ID를 인자로 받는 생성자입니다.
    FBirdData(const FString& InName, int32 InID)
        : Name(InName)
        , ID(InID)
    {
    }

    // 직렬화를 위한 연산자 오버로딩입니다.
    friend FArchive& operator<<(FArchive& Ar, FBirdData& InBirdData)
    {
        Ar << InBirdData.Name;
        Ar << InBirdData.ID;
        return Ar;
    }

    UPROPERTY() // 해당 멤버 변수가 에디터 상에서 어디에서든 접근 가능함을 나타냅니다.
        FString Name = TEXT("DefaultBirdName"); // 새의 이름을 나타내는 변수입니다.

    UPROPERTY() // 해당 멤버 변수가 에디터 상에서 어디에서든 접근 가능함을 나타냅니다.
        int32 ID = 0; // 새의 ID를 나타내는 변수입니다.
};

UINTERFACE(MinimalAPI) // 최소한의 API를 갖는 인터페이스를 선언하기 위한 매크로입니다.
class USFlyable : public UInterface // USFlyable 인터페이스를 선언하고 UInterface를 상속합니다.
{
    GENERATED_BODY() // Unreal Engine 4 코드 생성 시스템에게 코드 생성을 하라고 지시합니다.
};

/**
 *
 */
class STUDYPROJECT_API ISFlyable // ISFlyable 인터페이스 클래스를 선언합니다.
{
    GENERATED_BODY() // Unreal Engine 4 코드 생성 시스템에게 코드 생성을 하라고 지시합니다.

public:
    virtual void Fly() = 0; // ISFlyable에서 구현해도 되고 안해도됨. 안하는게 국룰.
    // Fly 함수를 순수 가상 함수로 선언합니다.
    // ISFlyable 인터페이스를 구현하는 클래스에서 반드시 구현해야 합니다.
    // Fly 함수의 내용은 ISFlyable 인터페이스를 구현하는 클래스마다 다를 수 있습니다.
};
