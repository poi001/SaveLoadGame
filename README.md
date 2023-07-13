# 게임을 저장하고 불러오는 시스템을 구현한 언리얼 C++ 프로젝트입니다.

## 유튜브 링크 ( 이미지를 누르면 유튜브로 넘어갑니다 )

[![Video Label](http://img.youtube.com/vi/q9yHCeeIFqo/0.jpg)](https://youtu.be/q9yHCeeIFqo)

## 중요한 코드

* `#include "Kismet/GameplayStatics.h"` : `UGameplayStatics`를 사용하기 위한 헤더파일

* `Cast<USaveGame>(UGameplayStatics::CreateSaveGameObject(USaveGame::StaticClass()))` : SaveGameInstance를 생성 코드

* `UGameplayStatics::SaveGameToSlot(SaveGameInstance, FString SlotName, int32 UserIndex)` : 지정한 SlotName에 SaveGameInstance를 저장하는 코드

* `UGameplayStatics::DeleteGameInSlot(FString SlotName, int32 UserIndex)` : SlotName에 있는 내용을 삭제하는 코드

* `Cast<UMySaveGame>(UGameplayStatics::LoadGameFromSlot(FString SlotName, int32 UserIndex))` : SlotName을 불러오는 코드

* `UGameplayStatics::DoesSaveGameExist(FString SlotName, int32 UserIndex)` : SlotName에 저장한 내용이 있는지 확인하는 코드 ( 리턴형은 bool이다 )
