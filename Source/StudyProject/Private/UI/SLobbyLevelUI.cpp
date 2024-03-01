// SLobbyLevelUI.cpp


#include "UI/SLobbyLevelUI.h"
#include "SPlayerCharacterSettings.h"
#include "Characters/SCharacter.h"
#include "Components/Button.h"
#include "EngineUtils.h"
#include "Game/SGameInstance.h"
#include "Components/EditableText.h"
#include "Kismet/GameplayStatics.h"

void USLobbyLevelUI::NativeConstruct()
{
    Super::NativeConstruct();

    ACharacter* Character = Cast<ACharacter>(GetOwningPlayerPawn());
    CurrentSkeletalMeshComponent = Character->GetMesh();

    RedTeamButton.Get()->OnClicked.AddDynamic(this, &ThisClass::OnRedTeamButtonClicked);
    BlueTeamButton.Get()->OnClicked.AddDynamic(this, &ThisClass::OnBlueTeamButtonClicked);
    SubmitButton.Get()->OnClicked.AddDynamic(this, &ThisClass::OnSubmitButtonClicked);
}

void USLobbyLevelUI::OnRedTeamButtonClicked()
{
    const USPlayerCharacterSettings* CharacterSettings = GetDefault<USPlayerCharacterSettings>();
    if (true == ::IsValid(CharacterSettings))
    {
        FSoftObjectPath SkeletalMeshAssetPath = CharacterSettings->PlayerCharacterMeshPaths[0];

        if (USGameInstance* GI = GetWorld()->GetGameInstance<USGameInstance>())
        {
            if (USkeletalMesh* Asset = GI->StreamableManager.LoadSynchronous<USkeletalMesh>(SkeletalMeshAssetPath))
            {
                CurrentSkeletalMeshComponent->SetSkeletalMesh(Asset);

                SelectedTeamType = ETeamType::Red;
                SaveInitializedSaveData();
            }
        }
    }
}

void USLobbyLevelUI::OnBlueTeamButtonClicked()
{
    const USPlayerCharacterSettings* CharacterSettings = GetDefault<USPlayerCharacterSettings>();
    if (true == ::IsValid(CharacterSettings))
    {
        FSoftObjectPath SkeletalMeshAssetPath = CharacterSettings->PlayerCharacterMeshPaths[1];

        if (USGameInstance* GI = GetWorld()->GetGameInstance<USGameInstance>())
        {
            if (USkeletalMesh* Asset = GI->StreamableManager.LoadSynchronous<USkeletalMesh>(SkeletalMeshAssetPath))
            {
                CurrentSkeletalMeshComponent->SetSkeletalMesh(Asset);

                SelectedTeamType = ETeamType::Blue;
                SaveInitializedSaveData();
            }
        }
    }
}

void USLobbyLevelUI::OnSubmitButtonClicked()
{
    //FString PlayerName = EditPlayerName->GetText().ToString();
    PlayerName = EditPlayerName->GetText().ToString();
    if (PlayerName.Len() <= 0 || 10 <= PlayerName.Len())
    {
        return;
    }

    SaveInitializedSaveData();
    UGameplayStatics::OpenLevel(GetWorld(), TEXT("Loading"), true, FString(TEXT("NextLevel=Example?Saved=true")));
}

void USLobbyLevelUI::SaveInitializedSaveData()
{
    USPlayerStateSave* PlayerStateSave = NewObject<USPlayerStateSave>();
    PlayerStateSave->PlayerCharacterName = PlayerName;
    PlayerStateSave->CurrentLevel = 1;
    PlayerStateSave->CurrentEXP = 0.f;
    PlayerStateSave->TeamType = SelectedTeamType;

    if (true == UGameplayStatics::SaveGameToSlot(PlayerStateSave, TEXT("PlayerCharacter0"), 0))
    {
        UKismetSystemLibrary::PrintString(this, FString::Printf(TEXT("Saved.")));
    }
}