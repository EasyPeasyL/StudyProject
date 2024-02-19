// SPigeon.cpp

#include "Examples/SPigeon.h" // SPigeon 헤더 파일을 포함합니다.

// USPigeon 클래스의 생성자 정의입니다.
USPigeon::USPigeon()
{
    Name = TEXT("SPigeonCDO"); // Name 멤버 변수를 초기화합니다.
    ID = 0; // ID 멤버 변수를 초기화합니다.
}

// Fly 함수의 정의입니다.
void USPigeon::Fly()
{
    // Unreal Engine 로그를 사용하여 비둘기가 비행하는 것을 출력합니다.
    UE_LOG(LogTemp, Log, TEXT("%s is now flying."), *Name);
}

// Serialize 함수의 정의입니다.
void USPigeon::Serialize(FArchive& Ar)
{
    Super::Serialize(Ar); // 부모 클래스의 Serialize 함수를 호출합니다.

    Ar << Name; // 이름을 아카이브에 직렬화합니다.
    Ar << ID; // ID를 아카이브에 직렬화합니다.
}
