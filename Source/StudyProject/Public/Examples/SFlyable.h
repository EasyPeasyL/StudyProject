// SFlyable.h

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "SFlyable.generated.h"

UINTERFACE(MinimalAPI)
class USFlyable : public UInterface
{
    GENERATED_BODY()
};

/**
 *
 */
class STUDYPROJECT_API ISFlyable
{
    GENERATED_BODY()

public:
    virtual void Fly() = 0; // ISFlyable에서 구현해도 되고 안해도됨. 안하는게 국룰.

};