// SUnrealObjectClass.h

#pragma once

#include "CoreMinimal.h" // Unreal Engine Core 기능을 사용하기 위한 헤더 파일을 포함합니다.
#include "UObject/NoExportTypes.h" // UObject 클래스를 사용하기 위한 헤더 파일을 포함합니다.
#include "SUnrealObjectClass.generated.h" // 자동 생성된 헤더 파일을 포함합니다.

/**
 *
 */
UCLASS()
class STUDYPROJECT_API USUnrealObjectClass : public UObject // USUnrealObjectClass 클래스가 UObject 클래스를 상속받음을 나타냅니다.
{
    GENERATED_BODY() // Unreal Engine 4 코드 생성 시스템에게 코드 생성을 하라고 지시합니다.

public:
    USUnrealObjectClass(); // 생성자 선언입니다.

    UFUNCTION() // 이 함수가 Blueprint에서 호출 가능하도록 지정합니다.
        void HelloUnreal(); // Unreal에서 사용할 함수입니다.

    const FString& GetName() const { return Name; } // Name 변수의 값을 반환하는 함수입니다.

public:
    UPROPERTY() // 해당 멤버 변수가 에디터 상에서 어디에서든 접근 가능함을 나타냅니다.
        FString Name; // 이름을 나타내는 변수입니다.
};
