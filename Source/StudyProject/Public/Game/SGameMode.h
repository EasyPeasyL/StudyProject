// SGameMode.h

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SGameMode.generated.h"

/**
 *
 */
UCLASS()
class STUDYPROJECT_API ASGameMode : public AGameModeBase
{
    GENERATED_BODY()

public:
    ASGameMode();

    // 맵을 초기화할 때 호출되는 함수.
    virtual void InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage) override;

    // 게임 상태를 초기화할 때 호출되는 함수.
    virtual void InitGameState() override;

    // 로그인 이전에 호출되는 함수.
    virtual void PreLogin(const FString& Options, const FString& Address, const FUniqueNetIdRepl& UniqueId, FString& ErrorMessage) override;

    // 새로운 플레이어가 로그인할 때 호출되는 함수.
    virtual APlayerController* Login(UPlayer* NewPlayer, ENetRole InRemoteRole, const FString& Portal, const FString& Options, const FUniqueNetIdRepl& UniqueId, FString& ErrorMessage) override;

    // 플레이어가 게임에 로그인된 후 호출되는 함수.
    virtual void PostLogin(APlayerController* NewPlayer) override;

    // 컴포넌트 초기화가 완료된 후 호출되는 함수.
    virtual void PostInitializeComponents() override;
};
