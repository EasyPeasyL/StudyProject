// BTTask_Attack2.cpp


#include "AI/BTTask_Attack2.h"
#include "Controllers/SAIController.h"
#include "Characters/SNonPlayerCharacter.h"

UBTTask_Attack2::UBTTask_Attack2()
{
    bNotifyTick = true;
    NodeName = TEXT("Attack2");
}

void UBTTask_Attack2::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
    Super::TickTask(OwnerComp, NodeMemory, DeltaSeconds);

    ASAIController* AIC = Cast<ASAIController>(OwnerComp.GetAIOwner());
    if (true == ::IsValid(AIC))
    {
        ASNonPlayerCharacter* NPC = Cast<ASNonPlayerCharacter>(AIC->GetPawn());
        if (true == ::IsValid(NPC))
        {
            if (false == NPC->IsNowAttacking())
            {
                FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
            }
        }
    }
}

EBTNodeResult::Type UBTTask_Attack2::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    EBTNodeResult::Type Result = Super::ExecuteTask(OwnerComp, NodeMemory);

    ASAIController* AIC = Cast<ASAIController>(OwnerComp.GetAIOwner());
    if (true == ::IsValid(AIC))
    {
        ASNonPlayerCharacter* NPC = Cast<ASNonPlayerCharacter>(AIC->GetPawn());
        if (true == ::IsValid(NPC))
        {
            NPC->Attack2();
        }
    }

    return EBTNodeResult::InProgress;
}