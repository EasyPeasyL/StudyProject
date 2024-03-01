// SPlayerState.h

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "Game/SPlayerStateSave.h"
#include "SPlayerState.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnCurrentLevelChangedDelegate, int32, InOldCurrentLevel, int32, InNewCurrentLevel);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnCurrentEXPChangedDelegate, float, InOldCurrentEXP, float, InNewCurrentEXP);

UCLASS()
class STUDYPROJECT_API ASPlayerState : public APlayerState
{
    GENERATED_BODY()

public:
    ASPlayerState();

    void InitPlayerState();

    int32 GetMaxLevel() const { return MaxLevel; }

    int32 GetCurrentLevel() const { return CurrentLevel; }

    float GetMaxEXP() const { return MaxEXP; }

    float GetCurrentEXP() const { return CurrentEXP; }

    void SetCurrentLevel(int32 InCurrentLevel);

    void SetCurrentEXP(float InCurrentEXP);

    void SavePlayerState();

    ETeamType GetCurrentTeamType() const { return CurrentTeamType; }

    void SetCurrentTeamType(ETeamType InCurrentTeamType) { CurrentTeamType = InCurrentTeamType; }

public:
    FOnCurrentLevelChangedDelegate OnCurrentLevelChangedDelegate;

    FOnCurrentEXPChangedDelegate OnCurrentEXPChangedDelegate;

    static FString SaveSlotName;

private:
    UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = "USStatComponent", Meta = (AllowPrivateAccess = true))
    TObjectPtr<class USGameInstance> SGI;

    UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = "USStatComponent", Meta = (AllowPrivateAccess = true))
    int32 MaxLevel = 5;

    UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = "USStatComponent", Meta = (AllowPrivateAccess = true))
    int32 CurrentLevel = 1;

    UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = "USStatComponent", Meta = (AllowPrivateAccess = true))
    float MaxEXP = 150;

    UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = "USStatComponent", Meta = (AllowPrivateAccess = true))
    float CurrentEXP = 0;

    UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = "ASPlayerState", Meta = (AllowPrivateAccess))
    ETeamType CurrentTeamType = ETeamType::Red;

};