// Copyright Kyle Cuss and Cuss Programming


#include "AI/Agent/Patrol/Tasks/BTTask_SelectPatrolPoint.h"

#include "AI/Agent/Patrol/SCPatrolRoute.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "SentinelComplex/SentinelComplex.h"
#include "AIController.h"

namespace PatrolPointMemory
{
	struct FSCSelectPatrolPointMemory
	{
		int32 NextPatrolPointIndex = 0;
		bool bIsPatrolPointSelected = false;
	};
}

UBTTask_SelectPatrolPoint::UBTTask_SelectPatrolPoint()
{
	NodeName = TEXT("Select Patrol Point");

	PatrolRouteKey.AddObjectFilter(
		this,
		GET_MEMBER_NAME_CHECKED(
			UBTTask_SelectPatrolPoint,
			PatrolRouteKey),
		ASCPatrolRoute::StaticClass());

	PatrolLocationKey.AddVectorFilter(
		this,
		GET_MEMBER_NAME_CHECKED(
			UBTTask_SelectPatrolPoint,
			PatrolLocationKey));
}

EBTNodeResult::Type UBTTask_SelectPatrolPoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UBlackboardComponent* BlackboardComponent = OwnerComp.GetBlackboardComponent();
	
	if (!IsValid(BlackboardComponent))
	{
		UE_LOG(LogSCAI, Error, TEXT("[%s] Select Patrol Point failed: Behavior Tree has no valid Blackboard component."),
			*GetNameSafe(OwnerComp.GetAIOwner()));

		return EBTNodeResult::Failed;
	}
	
	ASCPatrolRoute* PatrolRoute = Cast<ASCPatrolRoute>(BlackboardComponent->GetValueAsObject(PatrolRouteKey.SelectedKeyName));

	if (!IsValid(PatrolRoute))
	{
		return EBTNodeResult::Failed;
	}

	const int32 NumPatrolPoints = PatrolRoute->GetNumPatrolPoints();

	if (NumPatrolPoints <= 0)
	{
		return EBTNodeResult::Failed;
	}

	PatrolPointMemory::FSCSelectPatrolPointMemory* Memory = reinterpret_cast<PatrolPointMemory::FSCSelectPatrolPointMemory*>(NodeMemory);
	
	if (!Memory->bIsPatrolPointSelected)
	{
		Memory->bIsPatrolPointSelected = true;
		Memory->NextPatrolPointIndex = FMath::RandRange(0, NumPatrolPoints - 1);
	}

	if (Memory->NextPatrolPointIndex < 0 || Memory->NextPatrolPointIndex >= NumPatrolPoints)
	{
		Memory->NextPatrolPointIndex = 0;
	}

	const int32 SelectedPointIndex = Memory->NextPatrolPointIndex;

	FVector PatrolLocation;

	if (!PatrolRoute->GetPatrolPointLocation(SelectedPointIndex,PatrolLocation))
	{
		UE_LOG(LogSCAI, Error, TEXT("[%s] Select Patrol Point failed: Route '%s' could not resolve point index %d."),
			*GetNameSafe(OwnerComp.GetAIOwner()), *GetNameSafe(PatrolRoute), SelectedPointIndex);

		return EBTNodeResult::Failed;
	}

	BlackboardComponent->SetValueAsVector(PatrolLocationKey.SelectedKeyName, PatrolLocation);

	Memory->NextPatrolPointIndex = (SelectedPointIndex + 1) % NumPatrolPoints;

	return EBTNodeResult::Succeeded;
}

uint16 UBTTask_SelectPatrolPoint::GetInstanceMemorySize() const
{
	return sizeof(PatrolPointMemory::FSCSelectPatrolPointMemory);
}

void UBTTask_SelectPatrolPoint::InitializeMemory(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory,
	EBTMemoryInit::Type InitType) const
{
	Super::InitializeMemory(OwnerComp, NodeMemory, InitType);
	
	InitializeNodeMemory<PatrolPointMemory::FSCSelectPatrolPointMemory>(NodeMemory, InitType);
}
