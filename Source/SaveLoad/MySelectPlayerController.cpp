// Fill out your copyright notice in the Description page of Project Settings.


#include "MySelectPlayerController.h"
#include "MySelectWidget.h"

AMySelectPlayerController::AMySelectPlayerController()
{
	static ConstructorHelpers::FClassFinder<UMySelectWidget> UI_SELECTWIDGET(TEXT("/Game/Widget/BP_SelectWidget.BP_SelectWidget_C"));
	if (UI_SELECTWIDGET.Succeeded()) SelectWidgetClass = UI_SELECTWIDGET.Class;
}

void AMySelectPlayerController::OnPossess(APawn* aPawn)
{
	Super::OnPossess(aPawn);

	SelectWidget = CreateWidget<UMySelectWidget>(this, SelectWidgetClass);
}

void AMySelectPlayerController::BeginPlay()
{
	Super::BeginPlay();

	FInputModeGameOnly InputMode;
	SetInputMode(InputMode);

	FInputModeUIOnly UIInputMode;
	SetInputMode(UIInputMode);

	SelectWidget->AddToViewport();
	bShowMouseCursor = true;
}

