// Copyright Kyle Cuss and Cuss Programming


#include "SentinelComplex/Public/Characters/SCGuardCharacter.h"
#include "SentinelComplex/SentinelComplex.h"


ASCGuardCharacter::ASCGuardCharacter()
{
	PrimaryActorTick.bStartWithTickEnabled = false;
	PrimaryActorTick.bCanEverTick = false;
	SetReplicates(true);
	
	if (HasAnyFlags(RF_ClassDefaultObject))
	{
		UE_LOG(LogTemp, Warning, TEXT("[%s] This instance IS the Class Default Object (CDO)."), *GetName());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("[%s] This instance is a normal runtime object (NOT the CDO)."), *GetName());
	}
}

void ASCGuardCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	UE_LOG(LogSCAI, Warning, TEXT("Name: %s"), *GetName());
	UE_LOG(LogSCAI, Warning, TEXT("Authority: %d"), HasAuthority());
	UE_LOG(LogSCAI, Warning, TEXT("Network Mode: %d"), GetNetMode());
	UE_LOG(LogSCAI, Warning, TEXT("Controller: %p"), GetController());
}


