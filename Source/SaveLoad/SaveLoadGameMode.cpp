// Copyright Epic Games, Inc. All Rights Reserved.

#include "SaveLoadGameMode.h"
#include "SaveLoadCharacter.h"
#include "UObject/ConstructorHelpers.h"

ASaveLoadGameMode::ASaveLoadGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
