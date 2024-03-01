// SPlayerState.cpp

#include "Game/SPlayerState.h"
#include "Game/SGameInstance.h"
#include "Kismet/GameplayStatics.h"
//#include "Game/SPlayerStateSave.h"
#include "GameFramework/GameModeBase.h"

FString ASPlayerState::SaveSlotName(TEXT("PlayerCharacter0"));


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

    //USPlayerStateSave* PlayerStateSave = Cast<USPlayerStateSave>(UGameplayStatics::LoadGameFromSlot(SaveSlotName, 0));
    //if (false == ::IsValid(PlayerStateSave))
    //{
    //    PlayerStateSave = GetMutableDefault<USPlayerStateSave>();
    //    // Mutable은 수정 가능하다는 의미.
    //}

    //SetPlayerName(PlayerStateSave->PlayerCharacterName);
    //SetCurrentLevel(PlayerStateSave->CurrentLevel);
    //SetCurrentEXP(PlayerStateSave->CurrentEXP);

    //AGameModeBase* GM = UGameplayStatics::GetGameMode(this);
    //if (true == ::IsValid(GM))
    //{
    //    FString SavedTypeString = UGameplayStatics::ParseOption(GM->OptionsString, FString(TEXT("Saved")));
    //    if (true == SavedTypeString.Equals("true"))
    //    {
    //        USPlayerStateSave* PlayerStateSave = Cast<USPlayerStateSave>(UGameplayStatics::LoadGameFromSlot(SaveSlotName, 0));
    //        if (false == ::IsValid(PlayerStateSave))
    //        {
    //            PlayerStateSave = GetMutableDefault<USPlayerStateSave>();
    //        }

    //        SetPlayerName(PlayerStateSave->PlayerCharacterName);
    //        SetCurrentLevel(PlayerStateSave->CurrentLevel);
    //        SetCurrentEXP(PlayerStateSave->CurrentEXP);
    //    }
    //    else
    //    {
    //        SetPlayerName(TEXT("DefaultPlayerName"));
    //        SetCurrentLevel(1);
    //        SetCurrentEXP(0.f);
    //    }
    //}

    USPlayerStateSave* PlayerStateSave = Cast<USPlayerStateSave>(UGameplayStatics::LoadGameFromSlot(SaveSlotName, 0));
    if (false == ::IsValid(PlayerStateSave))
    {
        PlayerStateSave = GetMutableDefault<USPlayerStateSave>();
    }

    SetPlayerName(PlayerStateSave->PlayerCharacterName);
    SetCurrentLevel(PlayerStateSave->CurrentLevel);
    SetCurrentEXP(PlayerStateSave->CurrentEXP);
    SetCurrentTeamType(PlayerStateSave->TeamType);

    SavePlayerState();
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

    SavePlayerState();
}

void ASPlayerState::SavePlayerState()
{
    USPlayerStateSave* PlayerStateSave = NewObject<USPlayerStateSave>();
    PlayerStateSave->PlayerCharacterName = GetPlayerName();
    PlayerStateSave->CurrentLevel = GetCurrentLevel();
    PlayerStateSave->CurrentEXP = GetCurrentEXP();

    if (true == UGameplayStatics::SaveGameToSlot(PlayerStateSave, SaveSlotName, 0))
    {
        UKismetSystemLibrary::PrintString(this, FString::Printf(TEXT("Saved.")));
    }
}
