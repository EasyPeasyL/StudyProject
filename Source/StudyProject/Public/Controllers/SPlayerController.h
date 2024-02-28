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

protected:
    virtual void BeginPlay() override;

private:
    UPROPERTY();
    TObjectPtr<class USHUD> HUDWidget;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "ASPlayerController", Meta = (AllowPrivateAccess));
    TSubclassOf<class USHUD> HUDWidgetClass;
};

