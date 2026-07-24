// Copyright Kyle Cuss and Cuss Programming


#include "AI/Agent/Patrol/Tasks/BTTask_CheckPatrolRoute.h"

#include "AIController.h"
#include "AI/Agent/Patrol/SCPatrolRoute.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "SentinelComplex/SentinelComplex.h"

UBTTask_CheckPatrolRoute::UBTTask_CheckPatrolRoute()
{
	NodeName = TEXT("Check Patrol Route");
	
	BlackboardKey.AddObjectFilter(this, GET_MEMBER_NAME_CHECKED(UBTTask_CheckPatrolRoute, BlackboardKey), ASCPatrolRoute::StaticClass());
}

EBTNodeResult::Type UBTTask_CheckPatrolRoute::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	const UBlackboardComponent* BlackboardComponent = OwnerComp.GetBlackboardComponent();

	if (!IsValid(BlackboardComponent))
	{
		UE_LOG(LogSCAI, Error, TEXT("[%s] Check Patrol Route failed: Behavior Tree has no valid Blackboard component."),
			*GetNameSafe(OwnerComp.GetAIOwner()));

		return EBTNodeResult::Failed;
	}

	const ASCPatrolRoute* PatrolRoute = Cast<ASCPatrolRoute>(BlackboardComponent->GetValueAsObject(BlackboardKey.SelectedKeyName));

	if (!IsValid(PatrolRoute))
	{
		return EBTNodeResult::Failed;
	}

	return PatrolRoute->GetNumPatrolPoints() > 0 ? EBTNodeResult::Succeeded : EBTNodeResult::Failed;
}
