// Copyright Kyle Cuss and Cuss Programming

#include "SentinelComplex/Public/Characters/SCGuardCharacter.h"
#include "SentinelComplex/SentinelComplex.h"


ASCGuardCharacter::ASCGuardCharacter()
{
	PrimaryActorTick.bStartWithTickEnabled = false;
	PrimaryActorTick.bCanEverTick = false;
	SetReplicates(true);
}

void ASCGuardCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	UE_LOG(LogSCAI, Warning, TEXT("Name: %s"), *GetName());
	UE_LOG(LogSCAI, Warning, TEXT("Authority: %d"), HasAuthority());
	UE_LOG(LogSCAI, Warning, TEXT("Network Mode: %d"), GetNetMode());
	UE_LOG(LogSCAI, Warning, TEXT("Controller: %s"), *GetNameSafe(GetController()));
}


