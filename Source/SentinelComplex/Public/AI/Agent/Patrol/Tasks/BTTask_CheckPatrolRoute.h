// Copyright Kyle Cuss and Cuss Programming

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BTTask_CheckPatrolRoute.generated.h"

/**
 * 
 */
UCLASS()
class SENTINELCOMPLEX_API UBTTask_CheckPatrolRoute : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
	
public:
	UBTTask_CheckPatrolRoute();
	
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
