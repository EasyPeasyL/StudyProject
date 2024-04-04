// BTTask_Utility.h

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_Utility.generated.h"

/**
 *
 */
UCLASS()
class STUDYPROJECT_API UBTTask_Utility : public UBTTaskNode
{
    GENERATED_BODY()

public:
    UBTTask_Utility();

protected:
    virtual void TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;

private:
    virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

};