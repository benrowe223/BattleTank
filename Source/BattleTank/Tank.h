#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h" // Put new includes above

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:



private:
	// Sets default values for this pawn's properties
	ATank();

	virtual void BeginPlay() override;
};