// SPigeon.cpp


#include "Examples/SPigeon.h"

USPigeon::USPigeon()
{
    Name = TEXT("Pigeon");
}

void USPigeon::Fly()
{
    UE_LOG(LogTemp, Log, TEXT("%s is now flying."), *Name);
}