// Copyright Kyle Cuss and Cuss Programming

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SCPatrolRoute.generated.h"

class USplineComponent;

UCLASS()
class SENTINELCOMPLEX_API ASCPatrolRoute : public AActor
{
	GENERATED_BODY()

public:
	ASCPatrolRoute();
	
	int GetNumPatrolPoints() const;
	bool GetPatrolPointLocation(int32 PointIndex, FVector& OutPoint) const;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Patrol")
	TObjectPtr<USplineComponent> PatrolSpline;
};
