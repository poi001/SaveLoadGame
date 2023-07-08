// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SaveLoadGameMode.generated.h"

UCLASS(minimalapi)
class ASaveLoadGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ASaveLoadGameMode();

	virtual void PostLogin(APlayerController* NewController) override;

protected:
	virtual void BeginPlay() override;
};



