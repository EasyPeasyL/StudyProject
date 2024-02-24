// BTTask_TurnToTarget.cpp


#include "AI/BTTask_TurnToTarget.h"
#include "Controllers/SAIController.h"
#include "Characters/SNonPlayerCharacter.h"
#include "Characters/SCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTTask_TurnToTarget::UBTTask_TurnToTarget()
{
    NodeName = TEXT("TurnToTargetActor");
}

EBTNodeResult::Type UBTTask_TurnToTarget::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    EBTNodeResult::Type Result = Super::ExecuteTask(OwnerComp, NodeMemory);

    ASAIController* AIC = Cast<ASAIController>(OwnerComp.GetAIOwner());
    if (true == ::IsValid(AIC))
    {
        ASNonPlayerCharacter* NPC = Cast<ASNonPlayerCharacter>(AIC->GetPawn());
        if (true == ::IsValid(NPC))
        {
            if (ASCharacter* TargetPC = Cast<ASCharacter>(OwnerComp.GetBlackboardComponent()->GetValueAsObject(AIC->TargetActorKey)))
            {
                FVector LookVector = TargetPC->GetActorLocation() - NPC->GetActorLocation();
                LookVector.Z = 0.f;
                FRotator TargetRotation = FRotationMatrix::MakeFromX(LookVector).Rotator();
                NPC->SetActorRotation(FMath::RInterpTo(NPC->GetActorRotation(), TargetRotation, GetWorld()->GetDeltaSeconds(), 2.f));

                return Result = EBTNodeResult::Succeeded;
            }
        }
    }

    return Result = EBTNodeResult::Failed;
}