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
    // CDO의 Name 속성에 저장됨.
    // 중단점을 걸어보면 언리얼 에디터가 실행되기 전에 호출됨을 알 수 있음.

}

void USGameInstance::Init()
{
    Super::Init(); // 엔진 업데이트 루틴을 지키기 위해서, 언리얼 엔지니어가 작성한 코드가 먼저 실행되게끔 하기 위함.

    UE_LOG(LogTemp, Log, TEXT("Init() has been called."));

    UKismetSystemLibrary::PrintString(GetWorld(), TEXT("Init() has been called."));

    UClass* RuntimeClassInfo = GetClass();
    UClass* CompiletimeClassInfo = StaticClass();

    //check(RuntimeClassInfo != CompiletimeClassInfo); 주석 풀어서 결과 확인 필요.
    //ensure(RuntimeClassInfo != CompiletimeClassInfo);
    //ensureMsgf(RuntimeClassInfo != CompiletimeClassInfo, TEXT("Intentional Error"));

    UE_LOG(LogTemp, Log, TEXT("Class Name: %s"), *RuntimeClassInfo->GetName());

    Name = TEXT("USGameInstance Object");
    // CDO를 통해 생성된 개체의 Name 속성에 새롭게 대입되는 값.

    UE_LOG(LogTemp, Log, TEXT("USGameInstance::Name: %s"), *(GetClass()->GetDefaultObject<USGameInstance>()->Name));
    UE_LOG(LogTemp, Log, TEXT("USGameInstance::Name: %s"), *Name);

    USUnrealObjectClass* USObject1 = NewObject<USUnrealObjectClass>();
    // 언리얼은 이런식으로 new 키워드를 안쓰고 NewObject<>() API를 사용해야 함.

    UE_LOG(LogTemp, Log, TEXT("USObject1's Name: %s"), *USObject1->GetName());
    // 우리가 정의한 Getter()

    FProperty* NameProperty = USUnrealObjectClass::StaticClass()->FindPropertyByName(TEXT("Name"));
    // 프로퍼티 시스템을 활용한 Getter()

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