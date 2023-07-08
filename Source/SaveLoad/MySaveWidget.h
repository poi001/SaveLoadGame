// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MySaveWidget.generated.h"

/**
 * 
 */
UCLASS()
class SAVELOAD_API UMySaveWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	virtual void NativeConstruct() override;

	UFUNCTION()
		void OnExitClicked();
	UFUNCTION()
		void OnButton1Clicked();
	UFUNCTION()
		void OnButton2Clicked();
	UFUNCTION()
		void OnButton3Clicked();
	
	class UButton* ExitButton;
	class UButton* Button1;
	class UButton* Button2;
	class UButton* Button3;

	class AMyPlayerController* MyPlayerController;
	class UMyGameInstance* MyGameInstance;
};
