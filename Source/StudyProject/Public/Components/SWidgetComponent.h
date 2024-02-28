// SWidgetComponent.h

#pragma once

#include "CoreMinimal.h"
#include "Components/WidgetComponent.h"
#include "SWidgetComponent.generated.h"

/**
 *
 */
UCLASS()
class STUDYPROJECT_API USWidgetComponent : public UWidgetComponent
{
    GENERATED_BODY()

public:
    virtual void InitWidget() override;

};