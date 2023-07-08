// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MyPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class SAVELOAD_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	AMyPlayerController();

	virtual void OnPossess(APawn* aPawn) override;



protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = UI)
		TSubclassOf<class UMySaveWidget> SaveWidgetClass;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = UI)
		TSubclassOf<class UMyEnterOrDeleteWidget> EnterOrDeleteWidgetClass;

private:
	class UMySaveWidget* SaveWidget;
	class UMyEnterOrDeleteWidget* EnterOrDeleteWidget;

	FInputModeGameOnly GameInputMode;	//게임모드
	FInputModeUIOnly UIInputMode;		//UI모드

public:
	void OnSaveWidget();
	void OnEnterOrDeleteWidget();
	void OffSaveWidget();
	void OffEnterOrDeleteWidget();

	void ChangeInputMode(bool bGameMode);
};
