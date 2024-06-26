// AN_CheckHit.cpp


#include "Animations/AnimNotifies/AN_CheckHit.h"
#include "Characters/SRPGCharacter.h"
#include "Characters/SNonPlayerCharacter.h"

void UAN_CheckHit::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
    Super::Notify(MeshComp, Animation, EventReference);

    if (true == ::IsValid(MeshComp))
    {
        ASNonPlayerCharacter* AttackingCharacter = Cast<ASNonPlayerCharacter>(MeshComp->GetOwner());
        if (true == ::IsValid(AttackingCharacter))
        {
            AttackingCharacter->CheckHit();
        }
    }

    if (true == ::IsValid(MeshComp))
    {
        ASRPGCharacter* AttackingCharacter = Cast<ASRPGCharacter>(MeshComp->GetOwner());
        if (true == ::IsValid(AttackingCharacter))
        {
            AttackingCharacter->CheckHit();
        }
    }
}