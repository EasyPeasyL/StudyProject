// SUnrealObjectClass.cpp

#include "SUnrealObjectClass.h" // 해당 헤더 파일을 포함합니다.

// USUnrealObjectClass 클래스의 생성자 정의입니다.
USUnrealObjectClass::USUnrealObjectClass()
{
    Name = TEXT("USUnrealObjectClass CDO"); // Name 멤버 변수를 초기화합니다.
}

// HelloUnreal 함수의 정의입니다.
void USUnrealObjectClass::HelloUnreal()
{
    // Unreal Engine 로그를 출력합니다. LogTemp는 로그의 카테고리로, 로그 수준에 따라 다르게 처리될 수 있습니다.
    // Log는 로그의 수준을 나타내며, TEXT 매크로를 사용하여 문자열 리터럴을 정의합니다.
    UE_LOG(LogTemp, Log, TEXT("USUnrealObjectClass::HelloUnreal() has been called."));
}
