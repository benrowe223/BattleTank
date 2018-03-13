// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto ControlledTank = Cast<ATank>(GetPawn());
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();

	if (!PlayerTank) { return; }

	if (PlayerTank)
	{
		MoveToActor(
			PlayerTank, 
			AcceptanceRadius
			);//ToDo check radius is in cm


		// Aim towards the player
		ControlledTank->AimAt(PlayerTank->GetActorLocation());

		ControlledTank->Fire();
		// Fire if ready
	}
}
