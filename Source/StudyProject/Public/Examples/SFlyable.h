// SFlyable.h

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "SFlyable.generated.h"

USTRUCT()
struct FBirdData
{
    GENERATED_BODY()

public:
    FBirdData() {}

    FBirdData(const FString& InName, int32 InID)
        : Name(InName)
        , ID(InID)
    {
    }

    friend FArchive& operator<<(FArchive& Ar, FBirdData& InBirdData)
    {
        Ar << InBirdData.Name;
        Ar << InBirdData.ID;
        return Ar;
    }

    UPROPERTY()
    FString Name = TEXT("DefaultBirdName");

    UPROPERTY()
    int32 ID = 0;

};

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