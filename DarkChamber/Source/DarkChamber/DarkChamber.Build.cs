// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class DarkChamber : ModuleRules
{
	public DarkChamber(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "EnhancedInput" });
	}
}
