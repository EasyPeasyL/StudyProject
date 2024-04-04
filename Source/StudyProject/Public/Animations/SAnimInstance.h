// SAnimInstance.h

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "SAnimInstance.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnCheckHitDelegate);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnCheckCanNextComboDelegate);

/**
 *
 */
UCLASS()
class STUDYPROJECT_API USAnimInstance : public UAnimInstance
{
    GENERATED_BODY()

    friend class ASRPGCharacter;
    friend class ASNonPlayerCharacter;

public:
    USAnimInstance();

    virtual void NativeInitializeAnimation() override;

    virtual void NativeUpdateAnimation(float DeltaSeconds) override;

private:
    void PlayAttackAnimMontage();

    void PlayAttackAnimMontage2();

    void PlayAttackAnimMontage3();

    void PlayAttackAnimMontage4();

    void PlayUtilityAnimMontage();

    UFUNCTION()
    void AnimNotify_CheckHit();

    UFUNCTION()
    void AnimNotify_CheckCanNextCombo();

    UFUNCTION()
    void OnCharacterDeath();

protected:
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "USAnimInstance")
    float CurrentSpeed;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "USAnimInstance")
    FVector Velocity;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "USAnimInstance")
    uint8 bIsFalling : 1;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "USAnimInstance")
    uint8 bIsCrouching : 1;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "USAnimInstance", Meta = (AllowPrivateAccess))
    TObjectPtr<class UAnimMontage> AttackAnimMontage;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "USAnimInstance", Meta = (AllowPrivateAccess))
    TObjectPtr<class UAnimMontage> AttackAnimMontage2;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "USAnimInstance", Meta = (AllowPrivateAccess))
    TObjectPtr<class UAnimMontage> AttackAnimMontage3;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "USAnimInstance", Meta = (AllowPrivateAccess))
    TObjectPtr<class UAnimMontage> AttackAnimMontage4;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "USAnimInstance", Meta = (AllowPrivateAccess))
    TObjectPtr<class UAnimMontage> UtilityAnimMontage;

    FOnCheckHitDelegate OnCheckHitDelegate;

    FOnCheckCanNextComboDelegate OnCheckCanNextComboDelegate;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "USAnimInstance", Meta = (AllowPrivateAccess))
    uint8 bIsDead : 1;


};