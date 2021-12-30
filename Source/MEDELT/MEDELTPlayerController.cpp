// Copyright Epic Games, Inc. All Rights Reserved.

#include "TurretBaseC.h"
#include "MEDELTPlayerController.h"

AMEDELTPlayerController::AMEDELTPlayerController()
{
	bShowMouseCursor = true;
	bEnableClickEvents = true;
	bEnableTouchEvents = true;
	DefaultMouseCursor = EMouseCursor::Crosshairs;
}

/*void AMEDELTPlayerController::SetupInputComponent() 
{
    // Always call this.
    Super::SetupInputComponent();
	if (InputComponent)
    	InputComponent->BindAction("Shoot", IE_Pressed, this, &AMEDELTPlayerController::Shoot);
}*/

/*void AMEDELTPlayerController::Shoot()
{
	//GEngine->AddOnScreenDebugMessage(1, 1, FColor::Yellow, FString(TEXT("Fire")));
	GetA
	//MyTurret->Fire();
}*/
