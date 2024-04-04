// SNonPlayerCharacter.h

#pragma once

#include "CoreMinimal.h"
#include "SCharacter.h"
#include "SNonPlayerCharacter.generated.h"

UCLASS()
class STUDYPROJECT_API ASNonPlayerCharacter : public ASCharacter
{
    GENERATED_BODY()

    friend class UBTTask_Attack;
    friend class UBTTask_Attack2;
    friend class UBTTask_Attack3;
    friend class UBTTask_Attack4;
    friend class UBTTask_Utility;
    friend class UAN_CheckHit;

public:
    ASNonPlayerCharacter();

    virtual void BeginPlay() override;

    bool IsNowAttacking() const { return bIsAttacking; }

    virtual float TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

    virtual void SetWidget(class UStudyUserWidget* InStudyUserWidget) override;

private:
    void Attack();
    void Attack2();
    void Attack3();
    void Attack4();
    void Utility();

    UFUNCTION()
    void CheckHit();

    UFUNCTION()
    void OnAttackAnimMontageEnded(class UAnimMontage* Montage, bool bIsInterrupt);

private:
    float AttackRange = 1150.f;

    float AttackRadius = 50.f;

    bool bIsAttacking = false;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ASNonPlayerCharacter", Meta = (AllowPrivateAccess))
    TObjectPtr<class USWidgetComponent> WidgetComponent;

};