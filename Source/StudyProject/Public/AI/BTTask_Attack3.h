// BTTask_Attack3.h

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_Attack3.generated.h"

/**
 *
 */
UCLASS()
class STUDYPROJECT_API UBTTask_Attack3 : public UBTTaskNode
{
    GENERATED_BODY()

public:
    UBTTask_Attack3();

protected:
    virtual void TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;

private:
    virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

};