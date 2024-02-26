// SGameInstance.cpp

#include "Game/SGameInstance.h" // SGameInstance 헤더 파일을 포함합니다.
#include "SUnrealObjectClass.h" // SUnrealObjectClass 헤더 파일을 포함합니다.
#include "Examples/SFlyable.h" // SFlyable 헤더 파일을 포함합니다.
#include "Examples/SPigeon.h" // SPigeon 헤더 파일을 포함합니다.
#include "JsonObjectConverter.h" // JsonObjectConverter 헤더 파일을 포함합니다.
#include "UObject/SavePackage.h" // SavePackage 헤더 파일을 포함합니다.

// USGameInstance 클래스의 생성자 정의입니다.
USGameInstance::USGameInstance()
{
}

// Init 함수의 정의입니다.
void USGameInstance::Init()
{
    Super::Init(); // 부모 클래스의 Init 함수를 호출합니다.

    // 초기화 작업을 시작합니다.

    // 새로운 새 데이터를 생성하고 로그에 출력합니다.
    FBirdData SrcRawData(TEXT("Pigeon17"), 17);
    UE_LOG(LogTemp, Log, TEXT("[SrcRawData] Name: %s, ID: %d"), *SrcRawData.Name, SrcRawData.ID);

    // 저장할 디렉토리 경로를 결합하고 로그에 출력합니다.
    const FString SavedDir = FPaths::Combine(FPlatformMisc::ProjectDir(), TEXT("Saved"));
    UE_LOG(LogTemp, Log, TEXT("SavedDir: %s"), *SavedDir);

    // 저장할 파일의 경로를 결합하고 로그에 출력합니다.
    const FString RawDataFileName(TEXT("RawData.bin"));
    FString AbsolutePathForRawData = FPaths::Combine(*SavedDir, *RawDataFileName);
    UE_LOG(LogTemp, Log, TEXT("Relative path for saved file: %s"), *AbsolutePathForRawData);
    FPaths::MakeStandardFilename(AbsolutePathForRawData);
    UE_LOG(LogTemp, Log, TEXT("Absolute path for saved file: %s"), *AbsolutePathForRawData);

    // 파일에 데이터를 저장합니다.
    FArchive* RawFileWriterAr = IFileManager::Get().CreateFileWriter(*AbsolutePathForRawData);
    if (nullptr != RawFileWriterAr)
    {
        *RawFileWriterAr << SrcRawData;
        RawFileWriterAr->Close();
        delete RawFileWriterAr;
        RawFileWriterAr = nullptr;
    }

    // 파일에서 데이터를 읽어옵니다.
    FBirdData DstRawData;
    FArchive* RawFileReaderAr = IFileManager::Get().CreateFileReader(*AbsolutePathForRawData);
    if (nullptr != RawFileReaderAr)
    {
        *RawFileReaderAr << DstRawData;
        RawFileReaderAr->Close();
        delete RawFileReaderAr;
        RawFileReaderAr = nullptr;

        UE_LOG(LogTemp, Log, TEXT("[DstRawData] Name: %s, ID: %d"), *DstRawData.Name, DstRawData.ID);
    }

    // SerializedPigeon 객체를 생성하고 설정합니다.
    SerializedPigeon = NewObject<USPigeon>();
    SerializedPigeon->SetName(TEXT("Pigeon76"));
    SerializedPigeon->SetID(76);
    UE_LOG(LogTemp, Log, TEXT("[SerializedPigeon] Name: %s, ID: %d"), *SerializedPigeon->GetName(), SerializedPigeon->GetID());

    // 객체 데이터를 직렬화하고 파일에 저장합니다.
    const FString ObjectDataFileName(TEXT("ObjectData.bin"));
    FString AbsolutePathForObjectData = FPaths::Combine(*SavedDir, *ObjectDataFileName);
    FPaths::MakeStandardFilename(AbsolutePathForObjectData);

    TArray<uint8> BufferArray;
    FMemoryWriter MemoryWriterAr(BufferArray);
    SerializedPigeon->Serialize(MemoryWriterAr);

    TUniquePtr<FArchive> ObjectDataFileWriterAr = TUniquePtr<FArchive>(IFileManager::Get().CreateFileWriter(*AbsolutePathForObjectData));
    if (nullptr != ObjectDataFileWriterAr)
    {
        *ObjectDataFileWriterAr << BufferArray;
        ObjectDataFileWriterAr->Close();
        ObjectDataFileWriterAr = nullptr; //delete ObjectDataFileWriterAr; 와 같은 효과.
    }

    // 파일에서 객체 데이터를 읽어옵니다.
    TArray<uint8> BufferArrayFromObjectDataFile;
    TUniquePtr<FArchive> ObjectDataFileReaderAr = TUniquePtr<FArchive>(IFileManager::Get().CreateFileReader(*AbsolutePathForObjectData));
    if (nullptr != ObjectDataFileReaderAr)
    {
        *ObjectDataFileReaderAr << BufferArrayFromObjectDataFile;
        ObjectDataFileReaderAr->Close();
        ObjectDataFileReaderAr = nullptr;
    }

    // 메모리 리더를 사용하여 객체를 생성하고 역직렬화합니다.
    FMemoryReader MemoryReaderAr(BufferArrayFromObjectDataFile);
    USPigeon* Pigeon77 = NewObject<USPigeon>();
    Pigeon77->Serialize(MemoryReaderAr);
    UE_LOG(LogTemp, Log, TEXT("[Pigeon77] Name: %s, ID: %d"), *Pigeon77->GetName(), Pigeon77->GetID());

    // JSON 데이터를 파일에 저장합니다.
    const FString JsonDataFileName(TEXT("StudyJsonFile.txt"));
    FString AbsolutePathForJsonData = FPaths::Combine(*SavedDir, *JsonDataFileName);
    FPaths::MakeStandardFilename(AbsolutePathForJsonData);

    TSharedRef<FJsonObject> SrcJsonObject = MakeShared<FJsonObject>();
    FJsonObjectConverter::UStructToJsonObject(SerializedPigeon->GetClass(), SerializedPigeon, SrcJsonObject);

    FString JsonOutString;
    TSharedRef<TJsonWriter<TCHAR>> JsonWriterAr = TJsonWriterFactory<TCHAR>::Create(&JsonOutString);
    if (true == FJsonSerializer::Serialize(SrcJsonObject, JsonWriterAr))
    {
        FFileHelper::SaveStringToFile(JsonOutString, *AbsolutePathForJsonData);
    }

    // JSON 파일을 읽고 역직렬화합니다.
    FString JsonInString;
    FFileHelper::LoadFileToString(JsonInString, *AbsolutePathForJsonData);
    TSharedRef<TJsonReader<TCHAR>> JsonReaderAr = TJsonReaderFactory<TCHAR>::Create(JsonInString);

    TSharedPtr<FJsonObject> DstJsonObject;
    if (true == FJsonSerializer::Deserialize(JsonReaderAr, DstJsonObject))
    {
        USPigeon* Pigeon78 = NewObject<USPigeon>();
        if (true == FJsonObjectConverter::JsonObjectToUStruct(DstJsonObject.ToSharedRef(), Pigeon78->GetClass(), Pigeon78))
        {
            UE_LOG(LogTemp, Log, TEXT("[Pigeon78] Name: %s, ID: %d"), *Pigeon78->GetName(), Pigeon78->GetID());
        }
    }

}

// Shutdown 함수의 정의입니다.
void USGameInstance::Shutdown()
{
    Super::Shutdown(); // 부모 클래스의 Shutdown 함수를 호출합니다.
}
