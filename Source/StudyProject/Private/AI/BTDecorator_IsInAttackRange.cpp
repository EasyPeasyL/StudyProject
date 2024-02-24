// BTDecorator_IsInAttackRange.cpp


#include "AI/BTDecorator_IsInAttackRange.h"
#include "Controllers/SAIController.h"
#include "Characters/SNonPlayerCharacter.h"
#include "Characters/SCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"

const float UBTDecorator_IsInAttackRange::AttackRange(200.f);

UBTDecorator_IsInAttackRange::UBTDecorator_IsInAttackRange()
{
    NodeName = TEXT("IsInAttackRange");
}

bool UBTDecorator_IsInAttackRange::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
    bool bResult = Super::CalculateRawConditionValue(OwnerComp, NodeMemory);

    ASAIController* AIC = Cast<ASAIController>(OwnerComp.GetAIOwner());
    if (true == ::IsValid(AIC))
    {
        ASNonPlayerCharacter* NPC = Cast<ASNonPlayerCharacter>(AIC->GetPawn());
        if (true == ::IsValid(NPC))
        {
            ASCharacter* TargetPlayerCharacter = Cast<ASCharacter>(OwnerComp.GetBlackboardComponent()->GetValueAsObject(ASAIController::TargetActorKey));
            if (true == ::IsValid(TargetPlayerCharacter))
            {
                return bResult = (NPC->GetDistanceTo(TargetPlayerCharacter) <= AttackRange);
            }
        }
    }

    return bResult = false;
}