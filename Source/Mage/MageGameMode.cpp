// Copyright Epic Games, Inc. All Rights Reserved.

#include "MageGameMode.h"
#include "MageCharacter.h"
#include "UObject/ConstructorHelpers.h"

AMageGameMode::AMageGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
