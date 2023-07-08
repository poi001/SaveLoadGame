// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MySelectPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class SAVELOAD_API AMySelectPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	AMySelectPlayerController();

	virtual void OnPossess(APawn* aPawn) override;

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = UI)
		TSubclassOf<class UMySelectWidget> SelectWidgetClass;

private:
	class UMySelectWidget* SelectWidget;
};
