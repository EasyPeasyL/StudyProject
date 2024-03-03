#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "SPlayerController.generated.h"

/**
 *
 */
UCLASS()
class STUDYPROJECT_API ASPlayerController : public APlayerController
{
    GENERATED_BODY()

public:
    ASPlayerController();

    class USHUD* GetHUDWidget() const { return HUDWidget; };

    void ToggleMenu();

protected:
    virtual void BeginPlay() override;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = ASPlayerController, Meta = (AllowPrivateAccess))
    TSubclassOf<class UUserWidget> MenuUIClass;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = ASPlayerController, Meta = (AllowPrivateAccess))
    TObjectPtr<class UUserWidget> MenuUIInstance;

    bool bIsMenuOn = false;

private:
    UPROPERTY();
    TObjectPtr<class USHUD> HUDWidget;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "ASPlayerController", Meta = (AllowPrivateAccess));
    TSubclassOf<class USHUD> HUDWidgetClass;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = ASPlayerController, Meta = (AllowPrivateAccess))
    TSubclassOf<class UUserWidget> CrosshairUIClass;
};

