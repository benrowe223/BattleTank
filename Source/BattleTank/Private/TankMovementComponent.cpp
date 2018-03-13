// Fill out your copyright notice in the Description page of Project Settings.

#include "TankMovementComponent.h"
#include "TankTrack.h"

void UTankMovementComponent::Initialize(UTankTrack * LeftTrackToSet, UTankTrack * RightTrackToSet)
{


	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
}

void UTankMovementComponent::RequestDirectMove(const FVector & MoveVelocity, bool bForceMaxSpeed)
{
	/* GetSAFENormal turns the vector location into a unit of one. IE the direction that is very far away, but in the direction that the AI tank can move, 
	this normalises this vector to a unit of one, so that each frame we can move the correct amount in a more natural way, second by second */
	auto TankForward = GetOwner()->GetActorForwardVector().GetSafeNormal();
	auto AIForwardIntention = MoveVelocity.GetSafeNormal(); 

	auto RotationThrowRequired = FVector::CrossProduct(TankForward, AIForwardIntention);
	



	/*
	This ensures a smooth transition between the tanks current direction and the intended direction. 
	it controls the speed of how fast to move when turning.
	This is acheived using the cosine function ( google for explination or see the c++ tutorial lesson 167 for an explination
	*/
	auto ThrowRequired = FVector::DotProduct(TankForward, AIForwardIntention);
	IntendMoveForwardBackward(ThrowRequired);
	IntendTurnLeftRight(RotationThrowRequired.Z);
	//UE_LOG(LogTemp, Warning, TEXT("%s Attempted Move Velocity: %s"), *Name, *MoveVelocity.ToString());
}


void UTankMovementComponent::IntendMoveForwardBackward(float Throw)
{
	if (!LeftTrack || !RightTrack)
	{
		UE_LOG(LogTemp, Error, TEXT("Movement component cannot set tracks. One of the tracks is null, please set this via blueprint"));
		return;
	}

	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);

	//TODO: prevent double speed due to dual control use
}

void UTankMovementComponent::IntendTurnLeftRight(float Throw)
{
	if (!LeftTrack || !RightTrack)
	{
		UE_LOG(LogTemp, Error, TEXT("Movement component cannot set tracks. One of the tracks is null, please set this via blueprint"));
		return;
	}

	LeftTrack->SetThrottle(-Throw);
	RightTrack->SetThrottle(Throw);
}
