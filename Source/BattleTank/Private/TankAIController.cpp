// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "TankAimingComponent.h"



void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();

	auto ControlledTank = GetPawn();

	if (!ensure(PlayerTank && ControlledTank)) { return; }

		MoveToActor(
			PlayerTank, 
			AcceptanceRadius
			);//ToDo check radius is in cm

		auto AimingComponent = ControlledTank->FindComponentByClass<UTankAimingComponent>();
		if (!ensure(AimingComponent)) { return; }
		// Aim towards the player
		AimingComponent->AimAt(PlayerTank->GetActorLocation());

		// Fire if ready

		AimingComponent->Fire();
}
