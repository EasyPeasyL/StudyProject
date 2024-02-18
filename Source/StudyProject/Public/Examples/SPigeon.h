// SPigeon.h

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SFlyable.h" // 인클루드 구문은 항상 .generated.h 파일 위에 작성.
#include "SPigeon.generated.h"

/**
 *
 */
UCLASS()
class STUDYPROJECT_API USPigeon
    : public UObject
    , public ISFlyable
{
    GENERATED_BODY()

public:
    USPigeon();

    virtual void Fly() override;

private:
    UPROPERTY()
    FString Name;

};