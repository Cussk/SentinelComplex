// Copyright Kyle Cuss and Cuss Programming

#include "SentinelComplex/Public/Characters/SCGuardCharacter.h"


ASCGuardCharacter::ASCGuardCharacter()
{
	PrimaryActorTick.bStartWithTickEnabled = false;
	PrimaryActorTick.bCanEverTick = false;
	SetReplicates(true);
}



