// Copyright Kyle Cuss and Cuss Programming


#include "AI/Agent/Patrol/SCPatrolRoute.h"

#include "Components/SplineComponent.h"

ASCPatrolRoute::ASCPatrolRoute()
{
	PrimaryActorTick.bStartWithTickEnabled = false;
	PrimaryActorTick.bCanEverTick = false;
	
	PatrolSpline = CreateDefaultSubobject<USplineComponent>("PatrolSpline");
	SetRootComponent(PatrolSpline);
}

int ASCPatrolRoute::GetNumPatrolPoints() const
{
	return PatrolSpline->GetNumberOfSplinePoints();
}

bool ASCPatrolRoute::GetPatrolPointLocation(const int32 PointIndex, FVector& OutPoint) const
{
	const int32 NumPatrolPoints = GetNumPatrolPoints();
	if (NumPatrolPoints < 0 || PointIndex >= NumPatrolPoints)
	{
		return false;
	}
	
	OutPoint = PatrolSpline->GetLocationAtSplinePoint(PointIndex, ESplineCoordinateSpace::World);
	
	return true;
}

