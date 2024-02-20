// SViewCharacter.cpp


#include "Characters/SViewCharacter.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/Controller.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Inputs/SInputConfigData.h"

ASViewCharacter::ASViewCharacter()
{
    PrimaryActorTick.bCanEverTick = true;
}

void ASViewCharacter::BeginPlay()
{
    Super::BeginPlay();

    APlayerController* PlayerController = Cast<APlayerController>(GetController());
    if (true == ::IsValid(PlayerController))
    {
        UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer());
        if (true == ::IsValid(Subsystem))
        {
            Subsystem->AddMappingContext(PlayerCharacterInputMappingContext, 0);
        }
    }
}

void ASViewCharacter::PossessedBy(AController* NewController)
{
    Super::PossessedBy(NewController);

    //SetViewMode(EViewMode::BackView);
    SetViewMode(EViewMode::QuarterView);
}

void ASViewCharacter::SetViewMode(EViewMode InViewMode)
{
    if (CurrentViewMode == InViewMode)
    {
        return;
    }

    CurrentViewMode = InViewMode;

    switch (CurrentViewMode)
    {
    case EViewMode::BackView:
        SpringArmComponent->TargetArmLength = 400.f;
        SpringArmComponent->SetRelativeRotation(FRotator::ZeroRotator);
        // ControlRotation이 Pawn의 회전과 동기화 -> Pawn의 회전이 SprintArm의 회전 동기화. 이로 인해 SetRotation()이 무의미.

        bUseControllerRotationPitch = false;
        bUseControllerRotationYaw = false;
        bUseControllerRotationRoll = false;

        SpringArmComponent->bUsePawnControlRotation = true;
        SpringArmComponent->bDoCollisionTest = true;
        SpringArmComponent->bInheritPitch = true;
        SpringArmComponent->bInheritYaw = true;
        SpringArmComponent->bInheritRoll = false;

        GetCharacterMovement()->bOrientRotationToMovement = true;
        GetCharacterMovement()->bUseControllerDesiredRotation = false;
        GetCharacterMovement()->RotationRate = FRotator(0.f, 480.f, 0.f);

        break;
    case EViewMode::QuarterView:
        SpringArmComponent->TargetArmLength = 900.f;
        SpringArmComponent->SetRelativeRotation(FRotator(-45.f, 0.f, 0.f));

        bUseControllerRotationPitch = false;
        bUseControllerRotationYaw = true;
        bUseControllerRotationRoll = false;

        SpringArmComponent->bUsePawnControlRotation = false;
        SpringArmComponent->bDoCollisionTest = false;
        SpringArmComponent->bInheritPitch = false;
        SpringArmComponent->bInheritYaw = false;
        SpringArmComponent->bInheritRoll = false;

        break;
    case EViewMode::End:
        break;
    default:
        break;
    }
}

void ASViewCharacter::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);

    switch (CurrentViewMode)
    {
    case EViewMode::BackView:
        break;
    case EViewMode::QuarterView:
    {
        if (KINDA_SMALL_NUMBER < DirectionToMove.SizeSquared())
        {
            GetController()->SetControlRotation(FRotationMatrix::MakeFromX(DirectionToMove).Rotator());
            AddMovementInput(DirectionToMove);
            DirectionToMove = FVector::ZeroVector;
        }
        break;
    }
    case EViewMode::End:
        break;
    default:
        break;
    }
}

void ASViewCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
    {
        EnhancedInputComponent->BindAction(PlayerCharacterInputConfigData->MoveAction, ETriggerEvent::Triggered, this, &ASViewCharacter::Move);
        EnhancedInputComponent->BindAction(PlayerCharacterInputConfigData->LookAction, ETriggerEvent::Triggered, this, &ASViewCharacter::Look);
    }
}

void ASViewCharacter::Move(const FInputActionValue& InValue)
{
    FVector2D MovementVector = InValue.Get<FVector2D>();

    switch (CurrentViewMode)
    {
    case EViewMode::None:
        break;
    case EViewMode::BackView:
    { // Switch-Case 구문 내에서 Scope를 지정하면 해당 Scope 내에서 변수 선언이 가능해짐.
        const FRotator ControlRotation = GetController()->GetControlRotation();
        const FRotator ControlRotationYaw(0.f, ControlRotation.Yaw, 0.f);

        const FVector ForwardVector = FRotationMatrix(ControlRotationYaw).GetUnitAxis(EAxis::X);
        const FVector RightVector = FRotationMatrix(ControlRotationYaw).GetUnitAxis(EAxis::Y);

        AddMovementInput(ForwardVector, MovementVector.X);
        AddMovementInput(RightVector, MovementVector.Y);

        break;
    }
    case EViewMode::QuarterView:
        DirectionToMove.X = MovementVector.X;
        DirectionToMove.Y = MovementVector.Y;

        break;
    case EViewMode::End:
        break;
    default:
        AddMovementInput(GetActorForwardVector(), MovementVector.X);
        AddMovementInput(GetActorRightVector(), MovementVector.Y);
        break;
    }
}

void ASViewCharacter::Look(const FInputActionValue& InValue)
{
    FVector2D LookVector = InValue.Get<FVector2D>();

    switch (CurrentViewMode)
    {
    case EViewMode::BackView:
        AddControllerYawInput(LookVector.X);
        AddControllerPitchInput(LookVector.Y);
        break;
    case EViewMode::QuarterView:
        break;
    case EViewMode::End:
        break;
    default:
        break;
    }
}