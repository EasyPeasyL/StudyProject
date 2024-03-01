// SLobbyLevelUI.h

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Game/SPlayerStateSave.h"
#include "SLobbyLevelUI.generated.h"

/**
 *
 */

UCLASS()
class STUDYPROJECT_API USLobbyLevelUI : public UUserWidget
{
    GENERATED_BODY()

protected:
    virtual void NativeConstruct() override;

private:
    UFUNCTION()
    void OnRedTeamButtonClicked();

    UFUNCTION()
    void OnBlueTeamButtonClicked();

    UFUNCTION()
    void OnSubmitButtonClicked();

    void SaveInitializedSaveData();

protected:
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = USLobbyLevelUI, Meta = (AllowPrivateAccess, BindWidget))
    TObjectPtr<class UButton> RedTeamButton;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = USLobbyLevelUI, Meta = (AllowPrivateAccess, BindWidget))
    TObjectPtr<class UButton> BlueTeamButton;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = USLobbyLevelUI, Meta = (AllowPrivateAccess, BindWidget))
    TObjectPtr<class UEditableText> EditPlayerName;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = USLobbyLevelUI, Meta = (AllowPrivateAccess, BindWidget))
    TObjectPtr<class UButton> SubmitButton;

    TWeakObjectPtr<class USkeletalMeshComponent> CurrentSkeletalMeshComponent;

    FString PlayerName = TEXT("DefaultPlayerName");

    ETeamType SelectedTeamType = ETeamType::Red;

};