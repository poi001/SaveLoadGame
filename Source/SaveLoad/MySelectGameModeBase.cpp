// Fill out your copyright notice in the Description page of Project Settings.


#include "MySelectGameModeBase.h"
#include "MySelectPlayerController.h"

AMySelectGameModeBase::AMySelectGameModeBase()
{
	PlayerControllerClass = AMySelectPlayerController::StaticClass();
}