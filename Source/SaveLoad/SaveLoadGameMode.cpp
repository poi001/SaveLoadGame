// Copyright Epic Games, Inc. All Rights Reserved.

#include "SaveLoadGameMode.h"
#include "SaveLoadCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "MyPlayerController.h"
#include "MyGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "MySaveGame.h"

ASaveLoadGameMode::ASaveLoadGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
		PlayerControllerClass = AMyPlayerController::StaticClass();
	}

}

void ASaveLoadGameMode::PostLogin(APlayerController* NewController)
{
	Super::PostLogin(NewController);


}

void ASaveLoadGameMode::BeginPlay()
{
	Super::BeginPlay();
	
	auto MyGameInstance = Cast<UMyGameInstance>(GetGameInstance());
	FString SlotName = MyGameInstance->SlotName;
	if (UGameplayStatics::DoesSaveGameExist(SlotName, 0))
	{
		auto LoadGameInstance = Cast<UMySaveGame>(UGameplayStatics::LoadGameFromSlot(SlotName, 0));
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("%f %f %f"),
			LoadGameInstance->SaveLocation.X, LoadGameInstance->SaveLocation.Y, LoadGameInstance->SaveLocation.Z));
		if (LoadGameInstance != nullptr) GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Load Success"));
		auto MyPlayerCharacter = Cast<ASaveLoadCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
		MyPlayerCharacter->SetActorLocationAndRotation(LoadGameInstance->SaveLocation, LoadGameInstance->SaveRotator);
	}
	else
	{
		auto SaveGameInstance = Cast<UMySaveGame>(UGameplayStatics::CreateSaveGameObject(UMySaveGame::StaticClass()));
		if (UGameplayStatics::SaveGameToSlot(SaveGameInstance, SlotName, 0))
		{
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Save Success"));
		}
	}
}