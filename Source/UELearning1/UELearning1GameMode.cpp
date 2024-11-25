// Copyright Epic Games, Inc. All Rights Reserved.

#include "UELearning1GameMode.h"
#include "UELearning1Character.h"
#include "UObject/ConstructorHelpers.h"

AUELearning1GameMode::AUELearning1GameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
