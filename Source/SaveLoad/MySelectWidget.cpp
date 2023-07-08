// Fill out your copyright notice in the Description page of Project Settings.


#include "MySelectWidget.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Kismet/GameplayStatics.h"
#include "MyGameInstance.h"

void UMySelectWidget::NativeConstruct()
{
	Super::NativeConstruct();

	Select1 = Cast<UButton>(GetWidgetFromName(TEXT("Button_Select1")));
	if(Select1 != nullptr) Select1->OnClicked.AddDynamic(this, &UMySelectWidget::OnSelect1Clicked);
	Select2 = Cast<UButton>(GetWidgetFromName(TEXT("Button_Select2")));
	if (Select2 != nullptr) Select2->OnClicked.AddDynamic(this, &UMySelectWidget::OnSelect2Clicked);
	Select3 = Cast<UButton>(GetWidgetFromName(TEXT("Button_Select3")));
	if (Select3 != nullptr) Select3->OnClicked.AddDynamic(this, &UMySelectWidget::OnSelect3Clicked);
}

void UMySelectWidget::OnSelect1Clicked()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Select1"));

	LoadGame(TEXT("SaveSlot1"));
}
void UMySelectWidget::OnSelect2Clicked()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Select2"));

	LoadGame(TEXT("SaveSlot2"));
}
void UMySelectWidget::OnSelect3Clicked()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Select3"));

	LoadGame(TEXT("SaveSlot3"));
}

void UMySelectWidget::LoadGame(FString SlotName)
{
	auto MyGameInstance = Cast<UMyGameInstance>(GetGameInstance());
	MyGameInstance->SlotName = SlotName;
	UGameplayStatics::OpenLevel(GetWorld(), TEXT("ThirdPersonMap"));
}