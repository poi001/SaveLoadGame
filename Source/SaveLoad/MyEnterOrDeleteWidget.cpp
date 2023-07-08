// Fill out your copyright notice in the Description page of Project Settings.


#include "MyEnterOrDeleteWidget.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Kismet/GameplayStatics.h"
#include "MyPlayerController.h"
#include "MyGameInstance.h"
#include "MySaveGame.h"
#include "SaveLoadCharacter.h"


void UMyEnterOrDeleteWidget::NativeConstruct()
{
	Super::NativeConstruct();

	Button_Cancel = Cast<UButton>(GetWidgetFromName(TEXT("Button_Cancel")));
	if (Button_Cancel != nullptr) Button_Cancel->OnClicked.AddDynamic(this, &UMyEnterOrDeleteWidget::OnCancelClicked);
	Button_Enter = Cast<UButton>(GetWidgetFromName(TEXT("Button_Enter")));
	if (Button_Enter != nullptr) Button_Enter->OnClicked.AddDynamic(this, &UMyEnterOrDeleteWidget::OnEnterClicked);
	Button_Save = Cast<UButton>(GetWidgetFromName(TEXT("Button_Save")));
	if (Button_Save != nullptr) Button_Save->OnClicked.AddDynamic(this, &UMyEnterOrDeleteWidget::OnSaveClicked);
	Button_Delete = Cast<UButton>(GetWidgetFromName(TEXT("Button_Delete")));
	if (Button_Delete != nullptr) Button_Delete->OnClicked.AddDynamic(this, &UMyEnterOrDeleteWidget::OnDeleteClicked);

	MyPlayerController = Cast<AMyPlayerController>(GetOwningPlayerPawn()->GetController());
	MyGameInstance = Cast<UMyGameInstance>(GetGameInstance());
}

void UMyEnterOrDeleteWidget::OnCancelClicked()
{
	RemoveFromParent();
}
void UMyEnterOrDeleteWidget::OnEnterClicked()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("OnEnterClicked"));

	MyGameInstance->SlotName = MyGameInstance->SlotName_Temp;
	UGameplayStatics::OpenLevel(GetWorld(), TEXT("ThirdPersonMap"));
}
void UMyEnterOrDeleteWidget::OnSaveClicked()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("OnSaveClicked"));
	
	auto SaveGameInstance = Cast<UMySaveGame>(UGameplayStatics::CreateSaveGameObject(UMySaveGame::StaticClass()));
	auto MyCharacter = Cast<ASaveLoadCharacter>(MyPlayerController->GetCharacter());
	SaveGameInstance->SaveLocation = MyCharacter->GetActorLocation();
	SaveGameInstance->SaveRotator = MyCharacter->GetActorRotation();
	if (UGameplayStatics::SaveGameToSlot(SaveGameInstance, MyGameInstance->SlotName_Temp, 0))
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Save Success"));
	}
	RemoveFromParent();
	
}
void UMyEnterOrDeleteWidget::OnDeleteClicked()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("OnDeleteClicked"));

	UGameplayStatics::DeleteGameInSlot(MyGameInstance->SlotName_Temp, 0);
	RemoveFromParent();
}