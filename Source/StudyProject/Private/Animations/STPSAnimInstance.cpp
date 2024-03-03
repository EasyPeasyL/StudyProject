// STPSAnimInstance.cpp

#include "Animations/STPSAnimInstance.h"
#include "Characters/STPSCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetSystemLibrary.h"

USTPSAnimInstance::USTPSAnimInstance()
    : bIsDead(false)
{
}

void USTPSAnimInstance::NativeInitializeAnimation()
{
    Super::NativeInitializeAnimation();

    OwnerCharacter = Cast<ASTPSCharacter>(GetOwningActor());
    if (true == ::IsValid(OwnerCharacter))
    {
        MovementComponent = OwnerCharacter->GetCharacterMovement();
    }
}

void USTPSAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
    Super::NativeUpdateAnimation(DeltaSeconds);

    if (true == ::IsValid(MovementComponent) && true == ::IsValid(OwnerCharacter))
    {
        GroundSpeed = MovementComponent->GetMaxSpeed();

        // ASTPSCharacter::Move() 함수는 무조건 매 틱마다 호출되는 함수가 아님. 키보드 입력이 있을 시에만 매 틱마다 호출됨.
        // 즉, 키보드를 떼면 Move() 함수도 호출되지 않아서 ForwardInputValue가 갱신되지 않음.
        // 이때문에 아래와 같이 MovementComponent의 속도를 확인해서 속도가 있을 때만 키보드 입력을 그대로 사용함.

        float ForwardInputValue = fabs(MovementComponent->Velocity.X) * OwnerCharacter->GetForwardInputValue();
        float RightInputValue = fabs(MovementComponent->Velocity.Y) * OwnerCharacter->GetRightInputValue();
        float UpInputValue = MovementComponent->Velocity.Z;
        MoveInputWithMaxSpeed = FVector{ ForwardInputValue, RightInputValue, UpInputValue };

        float X = fabs(MoveInputWithMaxSpeed.X) < KINDA_SMALL_NUMBER ? 0.f : MoveInputWithMaxSpeed.X / fabs(MoveInputWithMaxSpeed.X);
        float Y = fabs(MoveInputWithMaxSpeed.Y) < KINDA_SMALL_NUMBER ? 0.f : MoveInputWithMaxSpeed.Y / fabs(MoveInputWithMaxSpeed.Y);
        float Z = fabs(MoveInputWithMaxSpeed.Z) < KINDA_SMALL_NUMBER ? 0.f : MoveInputWithMaxSpeed.Z / fabs(MoveInputWithMaxSpeed.Z);
        MoveInput = FVector{ X, Y, Z };

        bIsFalling = MovementComponent->IsFalling();

        ControlRotation.Pitch = OwnerCharacter->GetCurrentAimPitch();
        ControlRotation.Yaw = OwnerCharacter->GetCurrentAimYaw();
    }
}