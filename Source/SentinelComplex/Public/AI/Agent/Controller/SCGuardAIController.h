// Copyright Kyle Cuss and Cuss Programming

#pragma once

#include "CoreMinimal.h"
#include "Runtime/AIModule/Classes/AIController.h"
#include "SCGuardAIController.generated.h"

class ASCGuardCharacter;

UCLASS()
class SENTINELCOMPLEX_API ASCGuardAIController : public AAIController
{
	GENERATED_BODY()

public:
	ASCGuardAIController();

protected:

	virtual void BeginPlay() override;
	virtual void OnPossess(APawn* InPawn) override;
	virtual void OnUnPossess() override;
	
private:
	TObjectPtr<ASCGuardCharacter> ControlledGuardCharacter;
	
};