// SMenuUI.h

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SMenuUI.generated.h"

/**
 *
 */
UCLASS()
class STUDYPROJECT_API USMenuUI : public UUserWidget
{
    GENERATED_BODY()

protected:
    virtual void NativeConstruct() override;

    UFUNCTION()
    void OnResumeGameButtonClicked();

    UFUNCTION()
    void OnReturnTitleButtonClicked();

    UFUNCTION()
    void OnExitGameButtonClicked();

private:
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = USMenuWidget, meta = (AllowPrivateAccess, BindWidget))
    TObjectPtr<class UButton> ResumeGameButton;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = USMenuWidget, meta = (AllowPrivateAccess, BindWidget))
    TObjectPtr<class UButton> ReturnTitleButton;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = USMenuWidget, meta = (AllowPrivateAccess, BindWidget))
    TObjectPtr<class UButton> ExitGameButton;

};