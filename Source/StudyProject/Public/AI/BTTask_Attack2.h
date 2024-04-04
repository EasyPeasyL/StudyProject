// BTTask_Attack2.h

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_Attack2.generated.h"

/**
 *
 */
UCLASS()
class STUDYPROJECT_API UBTTask_Attack2 : public UBTTaskNode
{
    GENERATED_BODY()

public:
    UBTTask_Attack2();

protected:
    virtual void TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;

private:
    virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

};