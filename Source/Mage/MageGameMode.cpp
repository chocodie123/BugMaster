// Copyright Epic Games, Inc. All Rights Reserved.

#include "MageGameMode.h"

#include "Beetle.h"
#include "MageCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/ConstructorHelpers.h"



AMageGameMode::AMageGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
	MainGameBugInfo = CreateDefaultSubobject<UBugInfo>(TEXT("BugInfo"));
}

void AMageGameMode::CardSelect(int32 CardNum)
{
	switch (CardNum)
	{
	case 1 : MainGameBugInfo->bFlying = true;
		break;
	}
}

void AMageGameMode::SpawnBeetle(FTransform Transform)
{
	ABeetle* SpawnBeetles = GetWorld()->SpawnActor<ABeetle>(BeetleFactory,Transform);
	// if(SpawnBeetles->BugInfoComponent && MainGameBugInfo)
	// SpawnBeetles->BugInfoComponent->bFlying = MainGameBugInfo->bFlying;
}


