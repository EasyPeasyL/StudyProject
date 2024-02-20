// SPlayerPawn.cpp


#include "Characters/SPlayerPawn.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

ASPlayerPawn::ASPlayerPawn()
{
    PrimaryActorTick.bCanEverTick = false;

    float CharacterHalfHeight = 90.f;
    float CharacterRadius = 40.f;

#pragma region InitializeCapsuleComponent
    CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleComponent"));
    SetRootComponent(CapsuleComponent);
    CapsuleComponent->SetCapsuleHalfHeight(CharacterHalfHeight);
    CapsuleComponent->SetCapsuleRadius(CharacterRadius);
#pragma endregion

#pragma region InitializeSkeletalMesh
    SkeletalMeshComponent = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMeshComponent"));
    SkeletalMeshComponent->SetupAttachment(RootComponent);
    FVector PivotPosition(0.f, 0.f, -CharacterHalfHeight);
    FRotator PivotRotation(0.f, -90.f, 0.f);
    SkeletalMeshComponent->SetRelativeLocationAndRotation(PivotPosition, PivotRotation);
    //static ConstructorHelpers::FObjectFinder<USkeletalMesh> SkeletalMeshAsset(TEXT("오브젝트 패스"));
    //if (true == SkeletalMeshAsset.Succeeded())
    //{
    //    SkeletalMeshComponent->SetSkeletalMesh(SkeletalMeshAsset.Object);
    //}
//static ConstructorHelpers::FClassFinder<UAnimInstance> AnimInstanceClassInfo(TEXT("/Script/Engine.AnimBlueprint'/Game/StudyProject/Animations/AnimationBlueprints/ABP_PlayerPawn.ABP_PlayerPawn_C'"));
    static ConstructorHelpers::FClassFinder<UAnimInstance> AnimInstanceClassInfo(TEXT("'/Game/StudyProject/Animations/AnimationBlueprints/ABP_PlayerPawn.ABP_PlayerPawn_C'"));
    // 위 오브젝트 패스 대신, 작은 따옴표 안의 내용만으로도 가능함.
    if (true == AnimInstanceClassInfo.Succeeded())
    {
        SkeletalMeshComponent->SetAnimClass(AnimInstanceClassInfo.Class);
    }
#pragma endregion

#pragma region InitializeCamera
    SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
    SpringArmComponent->SetupAttachment(RootComponent);
    SpringArmComponent->TargetArmLength = 400.f;
    SpringArmComponent->SetRelativeRotation(FRotator(-15.f, 0.f, 0.f));

    CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
    CameraComponent->SetupAttachment(SpringArmComponent);
#pragma endregion

    FloatingPawnMovementComponent = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("FloatingPawnMovementComponent"));

}

void ASPlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    PlayerInputComponent->BindAxis(TEXT("UpDown"), this, &ThisClass::UpDown);
    PlayerInputComponent->BindAxis(TEXT("LeftRight"), this, &ThisClass::LeftRight);
}

void ASPlayerPawn::BeginPlay()
{
    Super::BeginPlay();

    /*SkeletalMeshComponent->SetAnimationMode(EAnimationMode::AnimationSingleNode);

    UAnimationAsset* AnimationAsset = LoadObject<UAnimationAsset>(SkeletalMeshComponent, TEXT("/Script/Engine.AnimSequence'/Game/AnimStarterPack/ThirdPersonWalk.ThirdPersonWalk'"));
    if (nullptr != AnimationAsset)
    {
        SkeletalMeshComponent->PlayAnimation(AnimationAsset, true);
    }*/
}

void ASPlayerPawn::UpDown(float InAxisValue)
{
    AddMovementInput(GetActorForwardVector(), InAxisValue);
}

void ASPlayerPawn::LeftRight(float InAxisValue)
{
    AddMovementInput(GetActorRightVector(), InAxisValue);
}
