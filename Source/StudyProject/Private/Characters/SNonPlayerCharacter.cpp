// SNonPlayerCharacter.cpp


#include "Characters/SNonPlayerCharacter.h"
#include "Controllers/SAIController.h"
#include "gameframework/charactermovementcomponent.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Animations/SAnimInstance.h"
#include "Characters/SRPGCharacter.h"
#include "Components/CapsuleComponent.h"
#include "Components/SStatComponent.h"
#include "Components/SWidgetComponent.h"
#include "UI/StudyUserWidget.h"
#include "UI/SW_HPBar.h"
#include "Game/SPlayerState.h"
#include "Engine/EngineTypes.h"
#include "Engine/DamageEvents.h"


ASNonPlayerCharacter::ASNonPlayerCharacter()
{
    PrimaryActorTick.bCanEverTick = false;

    AIControllerClass = ASAIController::StaticClass();
    AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
    // ASNonPlayerCharacter는 레벨에 배치되거나 새롭게 생성되면 SAIController의 빙의가 자동으로 진행됨.

    WidgetComponent = CreateDefaultSubobject<USWidgetComponent>(TEXT("WidgetComponent"));
    WidgetComponent->SetupAttachment(GetRootComponent());
    WidgetComponent->SetRelativeLocation(FVector(0.f, 0.f, 150.f));
    WidgetComponent->SetWidgetSpace(EWidgetSpace::Screen);
    WidgetComponent->SetDrawSize(FVector2D(300.0f, 100.0f));
    WidgetComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void ASNonPlayerCharacter::BeginPlay()
{
    Super::BeginPlay();

    if (false == IsPlayerControlled())
    {
        bUseControllerRotationYaw = false;

        GetCharacterMovement()->bOrientRotationToMovement = false;
        GetCharacterMovement()->bUseControllerDesiredRotation = true;
        GetCharacterMovement()->RotationRate = FRotator(0.f, 480.f, 0.f);

        GetCharacterMovement()->MaxWalkSpeed = 300.f;
    }

    USAnimInstance* AnimInstance = Cast<USAnimInstance>(GetMesh()->GetAnimInstance());
    if (true == ::IsValid(AnimInstance) && false == AnimInstance->OnMontageEnded.IsAlreadyBound(this, &ThisClass::OnAttackAnimMontageEnded))
    {
        AnimInstance->OnMontageEnded.AddDynamic(this, &ThisClass::OnAttackAnimMontageEnded);
    }

}

float ASNonPlayerCharacter::TakeDamage(float Damage, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
    float FinalDamageAmount = Super::TakeDamage(Damage, DamageEvent, EventInstigator, DamageCauser);

   /* CurrentHP = FMath::Clamp(CurrentHP - FinalDamageAmount, 0.f, MaxHP);

    if (CurrentHP < KINDA_SMALL_NUMBER)
    {
        ASRPGCharacter* DamageCauserCharacter = Cast<ASRPGCharacter>(DamageCauser);

        if (true == ::IsValid(DamageCauserCharacter))
        {
            DamageCauserCharacter->SetCurrentEXP(DamageCauserCharacter->GetCurrentEXP() + 5);
        }
        CurrentHP = 0.f;

        bIsDead = true;
        GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
        GetCharacterMovement()->SetMovementMode(EMovementMode::MOVE_None);
        ASAIController* AIController = Cast<ASAIController>(GetController());
        if (true == ::IsValid(AIController))
        {
            AIController->EndAI();
        }
    }*/

    if (StatComponent->GetCurrentHP() < KINDA_SMALL_NUMBER)
    {
        /*ASRPGCharacter* DamageCauserCharacter = Cast<ASRPGCharacter>(DamageCauser);
        if (true == ::IsValid(DamageCauserCharacter))
        {
            DamageCauserCharacter->SetCurrentEXP(DamageCauserCharacter->GetCurrentEXP() + 5);
        }*/

        if (true == ::IsValid(LastHitBy))
        {
            ASCharacter* DamageCauserCharacter = Cast<ASCharacter>(LastHitBy->GetPawn());
            if (true == ::IsValid(DamageCauserCharacter))
            {
                ASPlayerState* PS = Cast<ASPlayerState>(DamageCauserCharacter->GetPlayerState());
                if (true == ::IsValid(PS))
                {
                    PS->SetCurrentEXP(PS->GetCurrentEXP() + 20.f);
                }
            }
        }

        ASAIController* AIController = Cast<ASAIController>(GetController());
        if (true == ::IsValid(AIController))
        {
            AIController->EndAI();
        }
    }

    return FinalDamageAmount;
}

void ASNonPlayerCharacter::SetWidget(UStudyUserWidget* InStudyUserWidget)
{
    USW_HPBar* HPBarWidget = Cast<USW_HPBar>(InStudyUserWidget);
    if (true == ::IsValid(HPBarWidget))
    {
        HPBarWidget->SetMaxHP(StatComponent->GetMaxHP());
        HPBarWidget->InitializeHPBarWidget(StatComponent);
        StatComponent->OnCurrentHPChangeDelegate.AddDynamic(HPBarWidget, &USW_HPBar::OnCurrentHPChange);
    }
}

void ASNonPlayerCharacter::Attack()
{
    FHitResult HitResult;
    FCollisionQueryParams Params(NAME_None, false, this);

    bool bResult = GetWorld()->SweepSingleByChannel(
        HitResult,
        GetActorLocation(),
        GetActorLocation() + AttackRange,
        FQuat::Identity,
        ECollisionChannel::ECC_EngineTraceChannel2,
        FCollisionShape::MakeSphere(AttackRadius),
        Params
    );

    if (true == bResult)
    {
        if (true == ::IsValid(HitResult.GetActor()))
        {
            //UKismetSystemLibrary::PrintString(this, FString::Printf(TEXT("[NPC] Hit Actor Name: %s"), *HitResult.GetActor()->GetName()));

            ASCharacter* PlayerCharacter = Cast<ASCharacter>(HitResult.GetActor());
            if (true == ::IsValid(PlayerCharacter))
            {
                PlayerCharacter->TakeDamage(10.f, FDamageEvent(), GetController(), this);
            }
        }
    }

#pragma region CollisionDebugDrawing

    USAnimInstance* AnimInstance = Cast<USAnimInstance>(GetMesh()->GetAnimInstance());
    if (true == ::IsValid(AnimInstance))
    {
        AnimInstance->PlayAttackAnimMontage();
        bIsAttacking = true;
        if (false == AnimInstance->OnMontageEnded.IsAlreadyBound(this, &ThisClass::OnAttackAnimMontageEnded))
        {
            AnimInstance->OnMontageEnded.AddDynamic(this, &ThisClass::OnAttackAnimMontageEnded);
        }
    }

#pragma region CollisionDebugDrawing
    FVector TraceVec = GetActorForwardVector() * AttackRange;
    FVector Center = GetActorLocation() + TraceVec * 0.5f;
    float HalfHeight = AttackRange * 0.5f + AttackRadius;
    FQuat CapsuleRot = FRotationMatrix::MakeFromZ(TraceVec).ToQuat();
    FColor DrawColor = true == bResult ? FColor::Green : FColor::Red;
    float DebugLifeTime = 5.f;

    DrawDebugCapsule(
        GetWorld(),
        Center,
        HalfHeight,
        AttackRadius,
        CapsuleRot,
        DrawColor,
        false,
        DebugLifeTime
    );
#pragma endregion
}

void ASNonPlayerCharacter::OnAttackAnimMontageEnded(UAnimMontage* Montage, bool bIsInterrupt)
{
    bIsAttacking = false;
}