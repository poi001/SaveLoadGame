// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"
#include "MySaveWidget.h"
#include "MyEnterOrDeleteWidget.h"

AMyPlayerController::AMyPlayerController()
{
	static ConstructorHelpers::FClassFinder<UMySaveWidget> UI_SAVEWIDGET(TEXT("/Game/Widget/BP_SaveWidget.BP_SaveWidget_C"));
	if (UI_SAVEWIDGET.Succeeded()) SaveWidgetClass = UI_SAVEWIDGET.Class;
	static ConstructorHelpers::FClassFinder<UMyEnterOrDeleteWidget> UI_ENTERORDELEGATEWIDGET(TEXT("/Game/Widget/BP_EnterOrDeleteWidget.BP_EnterOrDeleteWidget_C"));
	if (UI_SAVEWIDGET.Succeeded()) EnterOrDeleteWidgetClass = UI_ENTERORDELEGATEWIDGET.Class;
}

void AMyPlayerController::OnPossess(APawn* aPawn)
{
	Super::OnPossess(aPawn);

	SaveWidget = CreateWidget<UMySaveWidget>(this, SaveWidgetClass);
	EnterOrDeleteWidget = CreateWidget<UMyEnterOrDeleteWidget>(this, EnterOrDeleteWidgetClass);
}

void AMyPlayerController::BeginPlay()
{
	Super::BeginPlay();

	FInputModeGameOnly InputMode;
	SetInputMode(InputMode);
}

void AMyPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAction(TEXT("Save"), EInputEvent::IE_Pressed, this, &AMyPlayerController::OnSaveWidget);
}

void AMyPlayerController::OnSaveWidget()
{
	SaveWidget->AddToViewport();
	ChangeInputMode(false);
}
void AMyPlayerController::OnEnterOrDeleteWidget()
{
	EnterOrDeleteWidget->AddToViewport();
	ChangeInputMode(false);
}
void AMyPlayerController::OffSaveWidget()
{
	SaveWidget->RemoveFromParent();
	ChangeInputMode(true);
}

void AMyPlayerController::ChangeInputMode(bool bGameMode)
{
	if (bGameMode)
	{
		SetInputMode(GameInputMode);	//GameMode
		bShowMouseCursor = false;
	}
	else
	{
		SetInputMode(UIInputMode);		//WidgetMode
		bShowMouseCursor = true;
	}
}