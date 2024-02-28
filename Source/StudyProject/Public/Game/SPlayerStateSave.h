// SPlayerStateSave.h

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "SPlayerStateSave.generated.h"

/**
 *
 */
UCLASS()
class STUDYPROJECT_API USPlayerStateSave : public USaveGame
{
    GENERATED_BODY()

public:
    USPlayerStateSave();

    UPROPERTY()
    FString PlayerCharacterName;

    UPROPERTY()
    int32 CurrentLevel;

    UPROPERTY()
    float CurrentEXP;

};