// Copyright Kyle Cuss and Cuss Programming

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SCGuardCharacter.generated.h"

class ASCPatrolRoute;

UCLASS()
class SENTINELCOMPLEX_API ASCGuardCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ASCGuardCharacter();
	
	ASCPatrolRoute* GetPatrolRoute() const;
	
private:
	UPROPERTY(EditInstanceOnly, Category = "AI|Patrol")
	TWeakObjectPtr<ASCPatrolRoute> PatrolRoute;

};
