// Copyright Kyle Cuss and Cuss Programming


#include "AI/Agent/Controller/SCGuardAIController.h"

#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"
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
	
	if (!IsValid(BehaviorTreeAsset))
	{
		UE_LOG(LogSCAI, Error, TEXT("[%s] Cannot initialize AI: BehaviorTreeAsset is invalid."), *GetName());

		return;
	}
	
	UBlackboardComponent* BlackboardComponent = nullptr;
	if (!UseBlackboard(BehaviorTreeAsset->BlackboardAsset, BlackboardComponent))
	{
		UE_LOG(LogSCAI, Error, TEXT("[%s] Failed to initialize Blackboard."), *GetName());

		return;
	}
	
	BlackboardComponent->SetValueAsBool(TEXT("IsInitialized"), true);
	
	if (!RunBehaviorTree(BehaviorTreeAsset))
	{
		UE_LOG(LogSCAI, Error, TEXT("[%s] Failed to run BehaviorTree '%s.'"), *GetName(), *GetNameSafe(BehaviorTreeAsset));
		return;
	}
	
	ControlledGuardCharacter = LocalControlledCharacter;
}

void ASCGuardAIController::OnUnPossess()
{
	ControlledGuardCharacter = nullptr;
	
	Super::OnUnPossess();
}


