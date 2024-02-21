// SViewCharacter.h

#pragma once

#include "CoreMinimal.h"
#include "Characters/SCharacter.h"
#include "InputActionValue.h"
#include "SViewCharacter.generated.h"

UENUM()
enum class EViewMode : uint8
{
    None,
    BackView,
    QuarterView,
    End
};

UCLASS()
class STUDYPROJECT_API ASViewCharacter : public ASCharacter
{
    GENERATED_BODY()

public:
    ASViewCharacter();

    virtual void BeginPlay() override;

    virtual void PossessedBy(AController* NewController) override;

    void SetViewMode(EViewMode InViewMode);

    virtual void Tick(float DeltaSeconds) override;

protected:
    virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

private:
    void Move(const FInputActionValue& InValue);

    void Look(const FInputActionValue& InValue);

    void ChangeView(const FInputActionValue& InValue);

    float DestArmLength = 0.f;

    float ArmLengthChangeSpeed = 3.f;

    FRotator DestArmRotation = FRotator::ZeroRotator;

    float ArmRotationChangeSpeed = 10.f;

private:
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "SViewCharacter", Meta = (AllowPrivateAccess))
    TObjectPtr<class USInputConfigData> PlayerCharacterInputConfigData;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "SViewCharacter", Meta = (AllowPrivateAccess))
    TObjectPtr<class UInputMappingContext> PlayerCharacterInputMappingContext;

    EViewMode CurrentViewMode = EViewMode::None;
    // UPROPERTY() 매크로를 사용하지 않으므로, 초기화에 유념해야함.

    FVector DirectionToMove = FVector::ZeroVector;

};