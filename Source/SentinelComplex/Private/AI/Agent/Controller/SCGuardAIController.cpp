// Copyright Kyle Cuss and Cuss Programming


#include "AI/Agent/Controller/SCGuardAIController.h"

#include "Characters/SCGuardCharacter.h"
#include "SentinelComplex/SentinelComplex.h"


ASCGuardAIController::ASCGuardAIController()
{
	PrimaryActorTick.bStartWithTickEnabled = false;
	PrimaryActorTick.bCanEverTick = false;
}

void ASCGuardAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	
	ASCGuardCharacter* LocalControlledCharacter = Cast<ASCGuardCharacter>(InPawn);
	
	if (!IsValid(LocalControlledCharacter))
	{
		UE_LOG(LogSCAI,	Error, TEXT("[%s] Failed to possess expected ASCGuardCharacter. Pawn: %s Class: %s"), 
			*GetName(), *GetNameSafe(InPawn), *GetNameSafe(InPawn ? InPawn->GetClass() : nullptr));
		
		ControlledGuardCharacter = nullptr;
		return;
	}
	
	ControlledGuardCharacter = LocalControlledCharacter;
}

void ASCGuardAIController::OnUnPossess()
{
	ControlledGuardCharacter = nullptr;
	
	Super::OnUnPossess();
}


