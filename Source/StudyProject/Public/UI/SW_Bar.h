// SW_Bar.h

#pragma once

#include "CoreMinimal.h"
#include "UI/StudyUserWidget.h"
#include "SW_Bar.generated.h"

/**
 *
 */
UCLASS()
class STUDYPROJECT_API USW_Bar : public UStudyUserWidget
{
    GENERATED_BODY()

public:
    USW_Bar(const FObjectInitializer& ObjectInitializer);
    // 만약 Widget 클래스에서 생성자에 로직을 작성한다면 꼭 이 생성자를 선언/정의해줘야함.

    void SetMaxFigure(float InMaxFigure);

protected:
    virtual void NativeConstruct() override;

protected:
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "USW_Bar")
    TObjectPtr<class UProgressBar> Bar;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "USW_Bar")
    float MaxFigure;

};