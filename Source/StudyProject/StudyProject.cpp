// Copyright Epic Games, Inc. All Rights Reserved.
// 해당 코드는 게임의 주 모듈을 정의하는 부분입니다.

// 저작권 표시 및 라이센스 정보입니다.
// Epic Games, Inc.에 대한 저작권을 표시하고, 모든 권리를 보유합니다.
// 이 코드의 복제, 수정, 배포 등은 Epic Games, Inc.의 허락을 받아야 합니다.

#include "StudyProject.h" // 게임의 헤더 파일을 포함합니다.
#include "Modules/ModuleManager.h" // 모듈 매니저 헤더 파일을 포함합니다.

// 게임의 주 모듈을 구현하는 매크로입니다.
// FDefaultGameModuleImpl 클래스를 사용하여 기본 게임 모듈을 구현합니다.
// 첫 번째 인자는 구현할 모듈 클래스, 두 번째 인자는 프로젝트의 이름, 세 번째 인자는 모듈의 이름입니다.
IMPLEMENT_PRIMARY_GAME_MODULE(FDefaultGameModuleImpl, StudyProject, "StudyProject");
