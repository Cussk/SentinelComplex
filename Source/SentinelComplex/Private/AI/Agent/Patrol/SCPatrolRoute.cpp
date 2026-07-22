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

bool ASCPatrolRoute::GetPatrolPointLocation(int32 PointIndex, FVector& OutPoint) const
{
	if (GetNumPatrolPoints() == 0 || PointIndex > GetNumPatrolPoints() - 1) return false;
	OutPoint = PatrolSpline->GetLocationAtSplinePoint(PointIndex, ESplineCoordinateSpace::World);
	return true;
}

