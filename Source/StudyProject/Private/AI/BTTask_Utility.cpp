// BTTask_Utility.cpp


#include "AI/BTTask_Utility.h"
#include "Controllers/SAIController.h"
#include "Characters/SNonPlayerCharacter.h"

UBTTask_Utility::UBTTask_Utility()
{
    bNotifyTick = true;
    NodeName = TEXT("Utility");
}

void UBTTask_Utility::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
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

EBTNodeResult::Type UBTTask_Utility::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    EBTNodeResult::Type Result = Super::ExecuteTask(OwnerComp, NodeMemory);

    ASAIController* AIC = Cast<ASAIController>(OwnerComp.GetAIOwner());
    if (true == ::IsValid(AIC))
    {
        ASNonPlayerCharacter* NPC = Cast<ASNonPlayerCharacter>(AIC->GetPawn());
        if (true == ::IsValid(NPC))
        {
            NPC->Utility();
        }
    }

    return EBTNodeResult::InProgress;
}