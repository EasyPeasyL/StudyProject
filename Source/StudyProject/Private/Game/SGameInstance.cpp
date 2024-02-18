// SGameInstance.cpp


#include "Game/SGameInstance.h"
#include "Kismet/KismetSystemLibrary.h"
#include "SUnrealObjectClass.h"
#include "Examples/SFlyable.h"
#include "Examples/SPigeon.h"



USGameInstance::USGameInstance()
{
	UE_LOG(LogTemp, Log, TEXT("USGameInstance::USGameInstance() has been called."));

    Name = TEXT("USGameInstance Class Default Object");
    // CDO�� Name �Ӽ��� �����.
    // �ߴ����� �ɾ�� �𸮾� �����Ͱ� ����Ǳ� ���� ȣ����� �� �� ����.

}

void USGameInstance::Init()
{
    Super::Init(); // ���� ������Ʈ ��ƾ�� ��Ű�� ���ؼ�, �𸮾� �����Ͼ �ۼ��� �ڵ尡 ���� ����ǰԲ� �ϱ� ����.

    UE_LOG(LogTemp, Log, TEXT("Init() has been called."));

    UKismetSystemLibrary::PrintString(GetWorld(), TEXT("Init() has been called."));

    UClass* RuntimeClassInfo = GetClass();
    UClass* CompiletimeClassInfo = StaticClass();

    //check(RuntimeClassInfo != CompiletimeClassInfo); �ּ� Ǯ� ��� Ȯ�� �ʿ�.
    //ensure(RuntimeClassInfo != CompiletimeClassInfo);
    //ensureMsgf(RuntimeClassInfo != CompiletimeClassInfo, TEXT("Intentional Error"));

    UE_LOG(LogTemp, Log, TEXT("Class Name: %s"), *RuntimeClassInfo->GetName());

    Name = TEXT("USGameInstance Object");
    // CDO�� ���� ������ ��ü�� Name �Ӽ��� ���Ӱ� ���ԵǴ� ��.

    UE_LOG(LogTemp, Log, TEXT("USGameInstance::Name: %s"), *(GetClass()->GetDefaultObject<USGameInstance>()->Name));
    UE_LOG(LogTemp, Log, TEXT("USGameInstance::Name: %s"), *Name);

    USUnrealObjectClass* USObject1 = NewObject<USUnrealObjectClass>();
    // �𸮾��� �̷������� new Ű���带 �Ⱦ��� NewObject<>() API�� ����ؾ� ��.

    UE_LOG(LogTemp, Log, TEXT("USObject1's Name: %s"), *USObject1->GetName());
    // �츮�� ������ Getter()

    FProperty* NameProperty = USUnrealObjectClass::StaticClass()->FindPropertyByName(TEXT("Name"));
    // ������Ƽ �ý����� Ȱ���� Getter()

    FString CompiletimeUSObjectName;
    if (nullptr != NameProperty)
    {
        NameProperty->GetValue_InContainer(USObject1, &CompiletimeUSObjectName);
        UE_LOG(LogTemp, Log, TEXT("CompiletimeUSObjectName: %s"), *CompiletimeUSObjectName);
    }

    USObject1->HelloUnreal();

    UFunction* HelloUnrealFunction = USObject1->GetClass()->FindFunctionByName(TEXT("HelloUnreal"));
    if (nullptr != HelloUnrealFunction)
    {
        USObject1->ProcessEvent(HelloUnrealFunction, nullptr);
    }

}

void USGameInstance::Shutdown()
{
    Super::Shutdown();

    UE_LOG(LogTemp, Log, TEXT("USGameInstance::Shutdown() has been called."));
}