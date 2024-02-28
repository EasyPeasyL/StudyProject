// StudyUserWidget.h

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "StudyUserWidget.generated.h"

/**
 *
 */
UCLASS()
class STUDYPROJECT_API UStudyUserWidget : public UUserWidget
{
    GENERATED_BODY()

public:
    AActor* GetOwningActor() const { return OwningActor; }

    void SetOwningActor(AActor* InOwningActor) { OwningActor = InOwningActor; }

protected:
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = UStudyUserWidget)
    TObjectPtr<AActor> OwningActor;

};