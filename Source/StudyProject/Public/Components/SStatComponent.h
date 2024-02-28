// SStatComponent.h

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SStatComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnOutOfCurrentHPDelegate);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnCurrentHPChangeDelegate, float, InOldCurrentHP, float, InNewCurrentHP);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnMaxHPChangeDelegate, float, InOldMaxHP, float, InNewMaxHP);

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class STUDYPROJECT_API USStatComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    USStatComponent();

    virtual void BeginPlay() override;

    float GetMaxHP() const { return MaxHP; }

    void SetMaxHP(float InMaxHP);

    float GetCurrentHP() const { return CurrentHP; }

    void SetCurrentHP(float InCurrentHP);

public:
    FOnOutOfCurrentHPDelegate OnOutOfCurrentHPDelegate;

    FOnCurrentHPChangeDelegate OnCurrentHPChangeDelegate;

    FOnMaxHPChangeDelegate OnMaxHPChangeDelegate;

private:
    UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = "USStatComponent", Meta = (AllowPrivateAccess))
    TObjectPtr<class USGameInstance> GameInstance;

    UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = "USStatComponent", Meta = (AllowPrivateAccess))
    float MaxHP;

    UPROPERTY(Transient, VisibleInstanceOnly, BlueprintReadOnly, Category = "USStatComponent", Meta = (AllowPrivateAccess))
    float CurrentHP;

    UFUNCTION()
    void OnCurrentLevelChanged(int32 InOldCurrentLevel, int32 InNewCurrentLevel);

};