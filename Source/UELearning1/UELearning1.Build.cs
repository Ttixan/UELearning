// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class UELearning1 : ModuleRules
{
	public UELearning1(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
