// SW_Bar.cpp


#include "UI/SW_Bar.h"
#include "Components/ProgressBar.h"
#include "Characters/SNonPlayerCharacter.h"
#include "Components/SStatComponent.h"

USW_Bar::USW_Bar(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) // 반드시 필요한 코드. 위젯 구현 할 때 꼭 넣어줘야함.
{
}

void USW_Bar::SetMaxFigure(float InMaxFigure)
{
    if (InMaxFigure < KINDA_SMALL_NUMBER)
    {
        MaxFigure = 0.f;
        return;
    }

    MaxFigure = InMaxFigure;
}

void USW_Bar::NativeConstruct()
{
    Super::NativeConstruct();

    Bar = Cast<UProgressBar>(GetWidgetFromName("BarWidget"));
    // 하드코딩으로 위젯과 속성을 바인드하는 방법. 추후에 쉽게 바인딩 하는 방법 소개 예정.
    check(nullptr != Bar);
}