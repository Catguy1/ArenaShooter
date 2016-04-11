// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "ArenaShooter.h"
#include "ArenaShooterGameMode.h"
#include "ArenaShooterHUD.h"
#include "ArenaShooterCharacter.h"

AArenaShooterGameMode::AArenaShooterGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AArenaShooterHUD::StaticClass();
}
