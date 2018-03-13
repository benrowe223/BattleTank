// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
Tank Track is used to set max driving force and apply forces
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
	
	
public:

	UFUNCTION(BlueprintCallable, Category = Input)
		void SetThrottle(float Throttle);

	//track force in nutons
	UPROPERTY(EditDefaultsOnly)
		float TrackMaxDrivingForce = 40000;

};
