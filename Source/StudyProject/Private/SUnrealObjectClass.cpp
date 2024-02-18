// SUnrealObjectClass.cpp


#include "SUnrealObjectClass.h"

USUnrealObjectClass::USUnrealObjectClass()
{
    Name = TEXT("USUnrealObjectClass CDO");
}

void USUnrealObjectClass::HelloUnreal()
{
    UE_LOG(LogTemp, Log, TEXT("USUnrealObjectClass::HelloUnreal() has been called."));
}