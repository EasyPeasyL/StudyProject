// SAnimInstance.cpp


#include "Animations/SAnimInstance.h"
#include "Characters/SRPGCharacter.h"
#include "Characters/SNonPlayerCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/SStatComponent.h"

USAnimInstance::USAnimInstance()
{
}

void USAnimInstance::NativeInitializeAnimation()
{
    Super::NativeInitializeAnimation();

    CurrentSpeed = 0.f;

    Velocity = FVector::ZeroVector;

    bIsFalling = false;

    bIsCrouching = false;

    bIsDead = false;

    ASCharacter* OwnerCharacter = Cast<ASCharacter>(TryGetPawnOwner());
    if (true == ::IsValid(OwnerCharacter))
    {
        USStatComponent* StatComponent = OwnerCharacter->GetStatComponent();
        if (true == ::IsValid(StatComponent))
        {
            if (false == StatComponent->OnOutOfCurrentHPDelegate.IsAlreadyBound(this, &ThisClass::OnCharacterDeath))
            {
                StatComponent->OnOutOfCurrentHPDelegate.AddDynamic(this, &ThisClass::OnCharacterDeath);
            }
        }
    }
}

void USAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
    Super::NativeUpdateAnimation(DeltaSeconds);

    ASCharacter* OwnerCharacter = Cast<ASCharacter>(TryGetPawnOwner());
    if (true == ::IsValid(OwnerCharacter))
    {
        UCharacterMovementComponent* CharacterMovementComponent = OwnerCharacter->GetCharacterMovement();
        if (true == ::IsValid(CharacterMovementComponent))
        {
            Velocity = CharacterMovementComponent->GetLastUpdateVelocity();
            CurrentSpeed = Velocity.Size();
            bIsFalling = CharacterMovementComponent->IsFalling();
            bIsCrouching = CharacterMovementComponent->IsCrouching();
            //bIsDead = OwnerCharacter->IsDead();
        }
    }
}

void USAnimInstance::PlayAttackAnimMontage()
{
    if (true == ::IsValid(AttackAnimMontage))
    {
        if (false == Montage_IsPlaying(AttackAnimMontage))
        {
            Montage_Play(AttackAnimMontage);
        }
    }
}

void USAnimInstance::PlayAttackAnimMontage2()
{
    if (true == ::IsValid(AttackAnimMontage2))
    {
        if (false == Montage_IsPlaying(AttackAnimMontage2))
        {
            Montage_Play(AttackAnimMontage2);
        }
    }
}

void USAnimInstance::PlayAttackAnimMontage3()
{
    if (true == ::IsValid(AttackAnimMontage3))
    {
        if (false == Montage_IsPlaying(AttackAnimMontage3))
        {
            Montage_Play(AttackAnimMontage3);
        }
    }
}

void USAnimInstance::PlayAttackAnimMontage4()
{
    if (true == ::IsValid(AttackAnimMontage4))
    {
        if (false == Montage_IsPlaying(AttackAnimMontage4))
        {
            Montage_Play(AttackAnimMontage4);
        }
    }
}

void USAnimInstance::PlayUtilityAnimMontage()
{
    if (true == ::IsValid(UtilityAnimMontage))
    {
        if (false == Montage_IsPlaying(UtilityAnimMontage))
        {
            Montage_Play(UtilityAnimMontage);
        }
    }
}

void USAnimInstance::AnimNotify_CheckHit()
{
    if (true == OnCheckHitDelegate.IsBound())
    {
        OnCheckHitDelegate.Broadcast();
    }
}

void USAnimInstance::AnimNotify_CheckCanNextCombo()
{
    if (true == OnCheckCanNextComboDelegate.IsBound())
    {
        OnCheckCanNextComboDelegate.Broadcast();
    }
}

void USAnimInstance::OnCharacterDeath()
{
    bIsDead = true;
}
