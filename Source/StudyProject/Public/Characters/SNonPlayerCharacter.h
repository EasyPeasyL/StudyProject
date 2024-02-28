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

public:
    ASNonPlayerCharacter();

    virtual void BeginPlay() override;

    bool IsNowAttacking() const { return bIsAttacking; }

    virtual float TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

    virtual void SetWidget(class UStudyUserWidget* InStudyUserWidget) override;

private:
    void Attack();

    UFUNCTION()
    void OnAttackAnimMontageEnded(class UAnimMontage* Montage, bool bIsInterrupt);

private:
    float AttackRange = 200.f;

    float AttackRadius = 50.f;

    bool bIsAttacking = false;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ASNonPlayerCharacter", Meta = (AllowPrivateAccess))
    TObjectPtr<class USWidgetComponent> WidgetComponent;

};