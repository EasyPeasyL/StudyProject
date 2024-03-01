// StudyProject.Target.cs

using UnrealBuildTool;
using System.Collections.Generic;
using System;

public class StudyProjectTarget : TargetRules
{
    public StudyProjectTarget(TargetInfo Target) : base(Target)
    {
        Type = TargetType.Game;
        DefaultBuildSettings = BuildSettingsVersion.V2;
        IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_3;
        ExtraModuleNames.Add("StudyProject");
        ExtraModuleNames.Add("StudyProjectSettings");
    }
}