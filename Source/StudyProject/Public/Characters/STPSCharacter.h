// STPSCharacter.h

#pragma once

#include "CoreMinimal.h"
#include "Characters/SCharacter.h"
#include "InputActionValue.h"
#include "STPSCharacter.generated.h"

UCLASS()
class STUDYPROJECT_API ASTPSCharacter : public ASCharacter
{
    GENERATED_BODY()

public:
    ASTPSCharacter();

    virtual void Tick(float DeltaSeconds) override;

    virtual void BeginPlay() override;

    float GetForwardInputValue() const { return ForwardInputValue; }

    float GetRightInputValue() const { return RightInputValue; }

    float GetCurrentAimPitch() const { return CurrentAimPitch; }

    float GetCurrentAimYaw() const { return CurrentAimYaw; }

    virtual float TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

protected:
    virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

private:
    void Move(const FInputActionValue& InValue);

    void Look(const FInputActionValue& InValue);

    void Attack(const FInputActionValue& InValue);

    void Fire();

    void StartIronSight(const FInputActionValue& InValue);

    void EndIronSight(const FInputActionValue& InValue);

    void ToggleTrigger(const FInputActionValue& InValue);

    void StartFire(const FInputActionValue& InValue);

    void StopFire(const FInputActionValue& InValue);

    UFUNCTION()
    void OnHittedRagdollRestoreTimerElapsed();

    void SpawnLandMine(const FInputActionValue& InValue);

private:
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "ASTPSCharacter", meta = (AllowPrivateAccess))
    TObjectPtr<USkeletalMeshComponent> WeaponSkeletalMeshComponent;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ASTPSCharacter", meta = (AllowPrivateAccess))
    TObjectPtr<class USInputConfigData> PlayerCharacterInputConfigData;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ASTPSCharacter", meta = (AllowPrivateAccess))
    TObjectPtr<class UInputMappingContext> PlayerCharacterInputMappingContext;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "ASTPSCharacter", meta = (AllowPrivateAccess = true))
    float ForwardInputValue;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "ASTPSCharacter", meta = (AllowPrivateAccess = true))
    float RightInputValue;

    float TargetFOV = 70.f;

    float CurrentFOV = 70.f;

    bool bIsTriggerToggle = false;

    UPROPERTY(EditDefaultsOnly, Category = "ASTPSCharacter", Meta = (AllowPrivateAccess))
    float FirePerMinute = 600;

    FTimerHandle BetweenShotsTimer;

    float TimeBetweenFire;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = ASPlayerCharacter, Meta = (AllowPrivateAccess = true))
    TObjectPtr<class UAnimMontage> RifleFireAnimMontage;

    float CurrentAimPitch = 0.f;

    float CurrentAimYaw = 0.f;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = ASPlayerCharacter, Meta = (AllowPrivateAccess = true))
    TSubclassOf<class UCameraShakeBase> FireShake;

    FTimerHandle HittedRagdollRestoreTimer;

    FTimerDelegate HittedRagdollRestoreTimerDelegate;

    float TargetRagDollBlendWeight = 0.f;

    float CurrentRagDollBlendWeight = 0.f;

    bool bIsNowRagdollBlending = false;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = ASPlayerCharacter, Meta = (AllowPrivateAccess = true))
    TSubclassOf<class AActor> LandMineClass;
};