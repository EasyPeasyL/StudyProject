// SInputConfigData.h

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "SInputConfigData.generated.h"

/**
 *
 */
UCLASS()
class STUDYPROJECT_API USInputConfigData : public UDataAsset
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TObjectPtr<class UInputAction> MoveAction;

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TObjectPtr<class UInputAction> LookAction;

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TObjectPtr<class UInputAction> ChangeViewAction;

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TObjectPtr<class UInputAction> JumpAction;

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TObjectPtr<class UInputAction> AttackAction;

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TObjectPtr<class UInputAction> Attack2Action;

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TObjectPtr<class UInputAction> Attack3Action;

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TObjectPtr<class UInputAction> Attack4Action;

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TObjectPtr<class UInputAction> UtilityAction;

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TObjectPtr<class UInputAction> MenuAction;

};