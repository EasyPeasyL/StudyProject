// StudyProjectEditor.Target.cs

using UnrealBuildTool;
using System.Collections.Generic;
using System;

public class StudyProjectEditorTarget : TargetRules
{
    public StudyProjectEditorTarget(TargetInfo Target) : base(Target)
    {
        Type = TargetType.Editor;
        DefaultBuildSettings = BuildSettingsVersion.V2;
        IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_3;
        ExtraModuleNames.Add("StudyProject");
        ExtraModuleNames.Add("StudyProjectSettings");
    }
}