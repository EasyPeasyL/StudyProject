// SPlayerState.cpp

#include "Game/SPlayerState.h"
#include "Game/SGameInstance.h"
#include "Kismet/GameplayStatics.h"

ASPlayerState::ASPlayerState()
{

}

void ASPlayerState::InitPlayerState()
{
    SGI = Cast<USGameInstance>(GetWorld()->GetGameInstance());
    if (true == ::IsValid(SGI))
    {
        if (nullptr != SGI->GetCharacterStatDataTable() || nullptr != SGI->GetCharacterStatDataTableRow(1))
        {
            MaxLevel = SGI->GetCharacterStatDataTable()->GetRowMap().Num();
            CurrentLevel = 1;
            CurrentEXP = 0;
            MaxEXP = SGI->GetCharacterStatDataTableRow(1)->MaxEXP;
        }
    }
}

void ASPlayerState::SetCurrentLevel(int32 InCurrentLevel)
{
    int32 OldCurrentLevel = CurrentLevel;
    int32 ActualLevel = FMath::Clamp<int32>(InCurrentLevel, 1, MaxLevel);

    FSStatTableRow* RowData = SGI->GetCharacterStatDataTableRow(ActualLevel);
    if (nullptr != RowData)
    {
        CurrentLevel = ActualLevel;
        MaxEXP = RowData->MaxEXP;
        OnCurrentLevelChangedDelegate.Broadcast(OldCurrentLevel, CurrentLevel);
    }
}

void ASPlayerState::SetCurrentEXP(float InCurrentEXP)
{
    float OldCurrentEXP = CurrentEXP;
    CurrentEXP = FMath::Clamp<float>(InCurrentEXP, 0.f, MaxEXP);

    if (MaxEXP - KINDA_SMALL_NUMBER < CurrentEXP)
    {
        SetCurrentLevel(GetCurrentLevel() + 1);
        CurrentEXP = 0.f;
    }

    OnCurrentEXPChangedDelegate.Broadcast(OldCurrentEXP, CurrentEXP);
}