// Fill out your copyright notice in the Description page of Project Settings.


#include "MySaveWidget.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Kismet/GameplayStatics.h"
#include "MyPlayerController.h"
#include "MyGameInstance.h"


void UMySaveWidget::NativeConstruct()
{
	ExitButton = Cast<UButton>(GetWidgetFromName(TEXT("Button_Exit")));
	if (ExitButton != nullptr) ExitButton->OnClicked.AddDynamic(this, &UMySaveWidget::OnExitClicked);
	Button1 = Cast<UButton>(GetWidgetFromName(TEXT("Button_Save1")));
	if (Button1 != nullptr) Button1->OnClicked.AddDynamic(this, &UMySaveWidget::OnButton1Clicked);
	Button2 = Cast<UButton>(GetWidgetFromName(TEXT("Button_Save2")));
	if (Button2 != nullptr) Button2->OnClicked.AddDynamic(this, &UMySaveWidget::OnButton2Clicked);
	Button3 = Cast<UButton>(GetWidgetFromName(TEXT("Button_Save3")));
	if (Button3 != nullptr) Button3->OnClicked.AddDynamic(this, &UMySaveWidget::OnButton3Clicked);

	MyPlayerController = Cast<AMyPlayerController>(GetOwningPlayerPawn()->GetController());
	MyGameInstance = Cast<UMyGameInstance>(GetGameInstance());
}
void UMySaveWidget::OnExitClicked()
{
	MyPlayerController->OffSaveWidget();
}
void UMySaveWidget::OnButton1Clicked()
{
	MyGameInstance->SlotName_Temp = TEXT("SaveSlot1");
	MyPlayerController->OnEnterOrDeleteWidget();
}
void UMySaveWidget::OnButton2Clicked()
{
	MyGameInstance->SlotName_Temp = TEXT("SaveSlot2");
	MyPlayerController->OnEnterOrDeleteWidget();
}
void UMySaveWidget::OnButton3Clicked()
{
	MyGameInstance->SlotName_Temp = TEXT("SaveSlot3");
	MyPlayerController->OnEnterOrDeleteWidget();
}