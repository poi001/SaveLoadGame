// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MySelectWidget.generated.h"

/**
 * 
 */
UCLASS()
class SAVELOAD_API UMySelectWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	virtual void NativeConstruct() override;

	class UButton* Select1;
	class UButton* Select2;
	class UButton* Select3;

	UFUNCTION()
		void OnSelect1Clicked();
	UFUNCTION()
		void OnSelect2Clicked();
	UFUNCTION()
		void OnSelect3Clicked();

	void LoadGame(FString SlotName);
	void OnTextChanged();
};
