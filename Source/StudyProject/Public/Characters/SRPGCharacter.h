// SRPGCharacter.h

#pragma once

#include "CoreMinimal.h"
#include "SCharacter.h"
#include "InputActionValue.h"
#include "SRPGCharacter.generated.h"

UCLASS()
class STUDYPROJECT_API ASRPGCharacter : public ASCharacter
{
    GENERATED_BODY()

    friend class UAN_CheckHit;

public:
    ASRPGCharacter();

    virtual void BeginPlay() override;

    float GetForwardInputValue() const { return ForwardInputValue; }

    float GetRightInputValue() const { return RightInputValue; }

    UFUNCTION()
    void OnAttackMontageEnded(UAnimMontage* Montage, bool bInterrupted);

    virtual float TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

    //float GetMaxEXP() const { return MaxEXP; }

    //float GetCurrentEXP() const { return CurrentEXP; }

    //void SetMaxEXP(float InMaxEXP) { MaxEXP = InMaxEXP; }

    //void SetCurrentEXP(float InCurrentEXP);

protected:
    virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

private:
    void Move(const FInputActionValue& InValue);

    void Look(const FInputActionValue& InValue);

    void Attack(const FInputActionValue& InValue);

    void Attack2(const FInputActionValue& InValue);

    void Attack3(const FInputActionValue& InValue);

    void Attack4(const FInputActionValue& InValue);

    void Utility(const FInputActionValue& InValue);

    UFUNCTION()
    void CheckHit();

    void BeginCombo();

    UFUNCTION()
    void CheckCanNextCombo();

    UFUNCTION()
    void EndCombo(class UAnimMontage* InAnimMontage, bool bInterrupted);

    UFUNCTION()
    void OnCurrentLevelChanged(int32 InOldCurrentLevel, int32 InNewCurrentLevel);

    UFUNCTION()
    void OnAssetLoaded();

    void Menu(const FInputActionValue& InValue);

private:
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ASRPGCharacter", Meta = (AllowPrivateAccess))
    TObjectPtr<class USInputConfigData> PlayerCharacterInputConfigData;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ASRPGCharacter", Meta = (AllowPrivateAccess))
    TObjectPtr<class UInputMappingContext> PlayerCharacterInputMappingContext;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "ASRPGCharacter", Meta = (AllowPrivateAccess = true))
    float ForwardInputValue;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "ASRPGCharacter", Meta = (AllowPrivateAccess = true))
    float RightInputValue;

    uint8 bIsAttacking : 1;

    FString AttackAnimMontageSectionName = FString(TEXT("Attack2"));

    int32 MaxComboCount = 3;

    int32 CurrentComboCount = 0;

    bool bIsAttackKeyPressed = false;
    // 에디터에서 관리되거나 시리얼라이즈 될 필요 없으므로 그냥 bool 자료형 사용.

    float AttackRange = 200.f;

    float AttackRadius = 50.f;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ASRPGCharacter", Meta = (AllowPrivateAccess))
    TObjectPtr<class UParticleSystemComponent> ParticleSystemComponent;

    //UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ASRPGCharacter", Meta = (AllowPrivateAccess))
    //float MaxEXP = 10;

    //UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ASRPGCharacter", Meta = (AllowPrivateAccess))
    //float CurrentEXP = 0;

    FSoftObjectPath CurrentPlayerCharacterMeshPath = FSoftObjectPath();

    TSharedPtr<struct FStreamableHandle> AssetStreamableHandle = nullptr;

};  