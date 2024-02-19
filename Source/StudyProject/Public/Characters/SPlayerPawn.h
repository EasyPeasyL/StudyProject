// SPlayerPawn.h

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "SPlayerPawn.generated.h"

UCLASS()
class STUDYPROJECT_API ASPlayerPawn : public APawn
{
    GENERATED_BODY()

public:
    ASPlayerPawn(); // �⺻ ������

    virtual void PostInitializeComponents() override;
    // �𸮾��� Construction Script�� ����, CDO ���� ������. �츮�� �����ϴ� ��ü ���� ������ ���� �ٸ�. 
    // ��ü�� ���� ��Ұ� �ʱ�ȭ�� �� ȣ��Ǵ� �Լ�.
    // ��, ��ü�� ������ ���Ŀ� ȣ���.

    virtual void PossessedBy(AController* NewController) override;
    // �츮�� �����ϴ� ��ü ���� ���� �Լ�.
    // �÷��̾� ��Ʈ�ѷ��� ���� �ش� ��ü�� �����Ǿ��� �� ȣ��Ǵ� �Լ�.

    virtual void UnPossessed() override;
    // ��ü�� �÷��̾� ��Ʈ�ѷ��κ��� ���� ������ �� ȣ��Ǵ� �Լ�.

    virtual void Tick(float DeltaSeconds) override;
    // �� �����Ӹ��� ȣ��Ǵ� �Լ�. ��ü�� ���¸� ������Ʈ�ϴ� �� ����.

    virtual void EndPlay(EEndPlayReason::Type EndPlayReason) override;
    // ��ü�� �÷��̸� ������ �� ȣ��Ǵ� �Լ�.

protected:
    virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
    // �÷��̾� �Է� ���� ��Ҹ� �����ϴ� �Լ�.
    // �� �Լ��� ���� �÷��̾��� �Է��� ��ü�� ������ �� ����.

    virtual void BeginPlay() override;
    // ��ü�� ������ ��ġ�ǰ� �ʱ�ȭ�� ���Ŀ� ȣ��Ǵ� �Լ�.
    // ��, ���� �÷��̰� ���۵Ǳ� ���� ȣ���.

};
