// AN_CheckHit.h

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "AN_CheckHit.generated.h"

/**
 *
 */
UCLASS()
class STUDYPROJECT_API UAN_CheckHit : public UAnimNotify
{
    GENERATED_BODY()

private:
    virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference);

};