// STorch.h

#pragma once

#include "CoreMinimal.h" // Unreal Engine Core 기능을 사용하기 위한 헤더 파일을 포함합니다.
#include "GameFramework/Actor.h" // AActor 클래스를 사용하기 위한 헤더 파일을 포함합니다.
#include "STorch.generated.h" // 자동 생성된 헤더 파일을 포함합니다.

UCLASS()
class STUDYPROJECT_API ASTorch : public AActor // ASTorch 클래스가 AActor 클래스를 상속받음을 나타냅니다.
{
    GENERATED_BODY() // Unreal Engine 4 코드 생성 시스템에게 코드 생성을 하라고 지시합니다.

public:
    ASTorch(); // 생성자 선언입니다.

    virtual void BeginPlay() override; // 부모 클래스인 AActor의 BeginPlay 함수를 재정의합니다.

    virtual void Tick(float DeltaSeconds) override; // 부모 클래스인 AActor의 Tick 함수를 재정의합니다.

private:
    UPROPERTY(VisibleAnywhere) // 해당 멤버 변수가 에디터 상에서 어디에서든 접근 가능함을 나타냅니다.
        TObjectPtr<class UBoxComponent> BoxComponent; // 박스 컴포넌트 객체에 대한 포인터입니다.

    UPROPERTY(VisibleAnywhere) // 해당 멤버 변수가 에디터 상에서 어디에서든 접근 가능함을 나타냅니다.
        TObjectPtr<class UStaticMeshComponent> BodyStaticMeshComponent; // 스태틱 메시 컴포넌트 객체에 대한 포인터입니다.

    UPROPERTY(VisibleAnywhere) // 해당 멤버 변수가 에디터 상에서 어디에서든 접근 가능함을 나타냅니다.
        TObjectPtr<class UPointLightComponent> PointLightComponent; // 포인트 라이트 컴포넌트 객체에 대한 포인터입니다.

    UPROPERTY(VisibleAnywhere) // 해당 멤버 변수가 에디터 상에서 어디에서든 접근 가능함을 나타냅니다.
        TObjectPtr<class UParticleSystemComponent> ParticleSystemComponent; // 파티클 시스템 컴포넌트 객체에 대한 포인터입니다.

    UPROPERTY(EditAnywhere, category = "ASTorch") // 에디터 상에서 편집 가능하며, ASTorch 카테고리로 그룹화됩니다.
        int32 ID; // 토치의 ID를 나타내는 변수입니다.

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "ASTorch", Meta = (AllowPrivateAccess)) // 에디터 상에서 편집 가능하며, 디폴트 값만 수정 가능하며, 블루프린트에서 읽고 쓰기 가능합니다. ASTorch 카테고리로 그룹화되며, private 접근이 허용됩니다.
        float RotationSpeed; // 토치의 회전 속도를 나타내는 변수입니다.
};
