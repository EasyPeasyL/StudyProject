// SPlayerController.cpp

#include "Controllers/SPlayerController.h"
#include "UI/SHUD.h"
#include "Game/SPlayerState.h"
#include "Components/SStatComponent.h"
#include "Characters/SRPGCharacter.h"

ASPlayerController::ASPlayerController()
{
    PrimaryActorTick.bCanEverTick = true;
    // 액터의 Tick이 돌아야 입력도 처리할 수 있음.
}

void ASPlayerController::BeginPlay()
{
    Super::BeginPlay();

    FInputModeGameOnly InputModeGameOnly;
    SetInputMode(InputModeGameOnly);

    if (true == ::IsValid(HUDWidgetClass))
    {
        HUDWidget = CreateWidget<USHUD>(this, HUDWidgetClass);
        if (true == ::IsValid(HUDWidget))
        {
            HUDWidget->AddToViewport();

            ASPlayerState* SPlayerState = GetPlayerState<ASPlayerState>();
            if (true == ::IsValid(SPlayerState))
            {
                HUDWidget->BindPlayerState(SPlayerState);
            }

            ASCharacter* PC = GetPawn<ASCharacter>();
            if (true == ::IsValid(PC))
            {
                USStatComponent* StatComponent = PC->GetStatComponent();
                if (true == ::IsValid(StatComponent))
                {
                    HUDWidget->BindStatComponent(StatComponent);
                }
            }
        }
    }
}