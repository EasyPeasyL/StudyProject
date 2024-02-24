// StudyProject.Build.cs

using UnrealBuildTool;

public class StudyProject : ModuleRules
{
    public StudyProject(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] { 
            // InitialModules
            "Core", "CoreUObject", "Engine", "InputCore",

            // JsonModules
            "Json", "JsonUtilities",

            // Enhanced Input
            "EnhancedInput",

            // AI
            "NavigationSystem",
            "AIModule",
            "GameplayTasks"
             });

        PrivateDependencyModuleNames.AddRange(new string[] { });

    }
}