// Copyright Kyle Cuss and Cuss Programming

#include "SentinelComplex/Public/Characters/SCGuardCharacter.h"

#include "GameFramework/CharacterMovementComponent.h"


ASCGuardCharacter::ASCGuardCharacter()
{
	PrimaryActorTick.bStartWithTickEnabled = false;
	PrimaryActorTick.bCanEverTick = false;
	SetReplicates(true);
	
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	UCharacterMovementComponent* Movement = GetCharacterMovement();
	Movement->bOrientRotationToMovement = true;
	Movement->bUseControllerDesiredRotation = false;
	Movement->RotationRate = FRotator(0.0f, 360.0f, 0.0f);
	Movement->MaxWalkSpeed = 220.0f;
	Movement->MaxAcceleration = 700.0f;
	Movement->BrakingDecelerationWalking = 700.0f;
	Movement->bRequestedMoveUseAcceleration = true;
}

ASCPatrolRoute* ASCGuardCharacter::GetPatrolRoute() const
{
	return PatrolRoute.Get();
}



