// SGameInstance.h

#pragma once

#include "CoreMinimal.h" // Unreal Engine Core ����� ����ϱ� ���� ��� ������ �����մϴ�.
#include "Engine/GameInstance.h" // UGameInstance Ŭ������ ����ϱ� ���� ��� ������ �����մϴ�.
#include "SGameInstance.generated.h" // �ڵ� ������ ��� ������ �����մϴ�.

/**
 *
 */
UCLASS()
class STUDYPROJECT_API USGameInstance : public UGameInstance // USGameInstance Ŭ������ UGameInstance Ŭ������ ��ӹ����� ��Ÿ���ϴ�.
{
    GENERATED_BODY() // Unreal Engine 4 �ڵ� ���� �ý��ۿ��� �ڵ� ������ �϶�� �����մϴ�.

public:
    USGameInstance(); // ������ �����Դϴ�.
    // �Լ� �ñ״�ó�� Ŀ���� �ΰ� Ctrl + .�� ������ ���Ǹ� �����ϰ� ���� �� �ִ� ���̾�αװ� ����.

    virtual void Init() override; // �θ� Ŭ������ UGameInstance�� Init �Լ��� �������մϴ�.

    virtual void Shutdown() override; // �θ� Ŭ������ UGameInstance�� Shutdown �Լ��� �������մϴ�.

private:
    UPROPERTY() // �ش� ��� ������ ������ �󿡼� ��𿡼��� ���� �������� ��Ÿ���ϴ�.
        FString Name; // �̸��� ��Ÿ���� �����Դϴ�.

    UPROPERTY() // �ش� ��� ������ ������ �󿡼� ��𿡼��� ���� �������� ��Ÿ���ϴ�.
        TObjectPtr<class USPigeon> SerializedPigeon; // USPigeon Ŭ������ ��ü�� ���� �������Դϴ�.
    // Ŭ������ ��� ������ ��Ŭ��� ���� �ʰ�, �ش� Ŭ���� �̸� �տ� class Ű���带 ���� ���� ���漱���̶� �մϴ�.
    // ��� ���Ͽ��� �ٸ� ��� ������ �����ϸ�, �ٸ� ��� ������ �����Ǿ��� �� �� ��� ���ϵ� �Բ� �����ϵ˴ϴ�.
    // ���� �� �ʿ��� ��찡 �ƴ϶�� ��� ���Ͽ��� �ٸ� ��� ������ ��Ŭ��� ���� �ʰ� ���漱���� Ȱ���մϴ�.
};
