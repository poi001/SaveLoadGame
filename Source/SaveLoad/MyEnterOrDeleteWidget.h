// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MyEnterOrDeleteWidget.generated.h"

/**
 * 
 */
UCLASS()
class SAVELOAD_API UMyEnterOrDeleteWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	virtual void NativeConstruct() override;
	
	class UButton* Button_Cancel;
	class UButton* Button_Enter;
	class UButton* Button_Save;
	class UButton* Button_Delete;

	class AMyPlayerController* MyPlayerController;
	class UMyGameInstance* MyGameInstance;

	UFUNCTION()
		void OnCancelClicked();
	UFUNCTION()
		void OnEnterClicked();
	UFUNCTION()
		void OnSaveClicked();
	UFUNCTION()
		void OnDeleteClicked();
};
