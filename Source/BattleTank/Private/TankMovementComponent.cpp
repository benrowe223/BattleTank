// Fill out your copyright notice in the Description page of Project Settings.

#include "TankMovementComponent.h"
#include "TankTrack.h"

void UTankMovementComponent::Initialize(UTankTrack * LeftTrackToSet, UTankTrack * RightTrackToSet)
{


	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
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
