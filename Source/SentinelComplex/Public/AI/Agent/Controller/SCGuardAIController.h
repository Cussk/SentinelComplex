// Copyright Kyle Cuss and Cuss Programming

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "SCGuardAIController.generated.h"

class ASCGuardCharacter;

UCLASS()
class SENTINELCOMPLEX_API ASCGuardAIController : public AAIController
{
	GENERATED_BODY()

public:
	ASCGuardAIController();

protected:
	virtual void OnPossess(APawn* InPawn) override;
	virtual void OnUnPossess() override;
	
private:
	UPROPERTY(Transient)
	TObjectPtr<ASCGuardCharacter> ControlledGuardCharacter;
	
};