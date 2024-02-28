// SGameMode.cpp

#include "Game/SGameMode.h"
#include "Controllers/SPlayerController.h"
#include "Characters/SPlayerPawn.h"
#include "Characters/SViewCharacter.h"
#include "Game/SPlayerState.h"



ASGameMode::ASGameMode()
{
    // 플레이어 컨트롤러 클래스를 설정합니다.
    PlayerControllerClass = ASPlayerController::StaticClass();
    // 기본 폰 클래스를 설정합니다.
    DefaultPawnClass = ASPlayerPawn::StaticClass();

    /*
    static ConstructorHelpers::FClassFinder<ASViewCharacter> DefaultPlayerCharacterClassRef(TEXT("오브젝트패스"));
    if (DefaultPlayerCharacterClassRef.Class)
    {
        DefaultPawnClass = DefaultPlayerCharacterClassRef.Class;
    }
    */

}

void ASGameMode::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
    // 게임을 초기화합니다.
    UE_LOG(LogTemp, Error, TEXT("         Start ASGameMode::InitGame()"));
    Super::InitGame(MapName, Options, ErrorMessage);
    UE_LOG(LogTemp, Error, TEXT("         End   ASGameMode::InitGame()"));
}

void ASGameMode::InitGameState()
{
    // 게임 상태를 초기화합니다.
    UE_LOG(LogTemp, Error, TEXT("         Start ASGameMode::InitGameState()"));
    Super::InitGameState();
    UE_LOG(LogTemp, Error, TEXT("         End   ASGameMode::InitGameState()"));
}

void ASGameMode::PostInitializeComponents()
{
    // 컴포넌트 초기화가 완료된 후 실행됩니다.
    UE_LOG(LogTemp, Error, TEXT("         Start ASGameMode::PostInitializeComponents()"));
    Super::PostInitializeComponents();
    UE_LOG(LogTemp, Error, TEXT("         End   ASGameMode::PostInitializeComponents()"));
}

void ASGameMode::PreLogin(const FString& Options, const FString& Address, const FUniqueNetIdRepl& UniqueId, FString& ErrorMessage)
{
    // 로그인 전에 실행됩니다.
    UE_LOG(LogTemp, Error, TEXT("         Start ASGameMode::PreLogin()"));
    Super::PreLogin(Options, Address, UniqueId, ErrorMessage);
    UE_LOG(LogTemp, Error, TEXT("         End   ASGameMode::PreLogin()"));
}

APlayerController* ASGameMode::Login(UPlayer* NewPlayer, ENetRole InRemoteRole, const FString& Portal, const FString& Options, const FUniqueNetIdRepl& UniqueId, FString& ErrorMessage)
{
    // 로그인을 처리합니다.
    UE_LOG(LogTemp, Error, TEXT("         Start ASGameMode::Login()"));
    APlayerController* PlayerController = Super::Login(NewPlayer, InRemoteRole, Portal, Options, UniqueId, ErrorMessage);
    UE_LOG(LogTemp, Error, TEXT("         End   ASGameMode::Login()"));

    return PlayerController;
}

void ASGameMode::PostLogin(APlayerController* NewPlayer)
{
    Super::PostLogin(NewPlayer);

    ASPlayerState* PlayerState = NewPlayer->GetPlayerState<ASPlayerState>();
    if (true == ::IsValid(PlayerState))
    {
        PlayerState->InitPlayerState();
    }
}