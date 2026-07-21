// Copyright Kyle Cuss and Cuss Programming


#include "SentinelComplex/Public/AI/Agent/Controller/SCGuardAIController.h"

#include "Characters/SCGuardCharacter.h"
#include "SentinelComplex/SentinelComplex.h"


ASCGuardAIController::ASCGuardAIController()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ASCGuardAIController::BeginPlay()
{
	Super::BeginPlay();
	
}

void ASCGuardAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	
	ASCGuardCharacter* LocalControlledCharacter = Cast<ASCGuardCharacter>(InPawn);
	
	if (!IsValid(LocalControlledCharacter))
	{
		UE_LOG(LogSCAI, Warning, TEXT("LocalControlledCharacter is not valid"));
		ControlledGuardCharacter = nullptr;
		return;
	}
	
	ControlledGuardCharacter = LocalControlledCharacter;
	UE_LOG(LogSCAI, Warning, TEXT("LocalControlledCharacter is valid"));
}

void ASCGuardAIController::OnUnPossess()
{
	ControlledGuardCharacter = nullptr;
	
	Super::OnUnPossess();
}


