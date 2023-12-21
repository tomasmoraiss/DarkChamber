// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MatchFinderServerManager/Public/MatchmadeInstanceSubsystem.h"
#include "../../Source/Runtime/Engine/Classes/Engine/GameInstance.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMatchmadeInstanceSubsystem() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_UGameInstanceSubsystem();
	MATCHFINDERSERVERMANAGER_API UClass* Z_Construct_UClass_UMatchmadeInstanceSubsystem();
	MATCHFINDERSERVERMANAGER_API UClass* Z_Construct_UClass_UMatchmadeInstanceSubsystem_NoRegister();
	UPackage* Z_Construct_UPackage__Script_MatchFinderServerManager();
// End Cross Module References
	void UMatchmadeInstanceSubsystem::StaticRegisterNativesUMatchmadeInstanceSubsystem()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UMatchmadeInstanceSubsystem);
	UClass* Z_Construct_UClass_UMatchmadeInstanceSubsystem_NoRegister()
	{
		return UMatchmadeInstanceSubsystem::StaticClass();
	}
	struct Z_Construct_UClass_UMatchmadeInstanceSubsystem_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UMatchmadeInstanceSubsystem_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UGameInstanceSubsystem,
		(UObject* (*)())Z_Construct_UPackage__Script_MatchFinderServerManager,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMatchmadeInstanceSubsystem_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "MatchmadeInstanceSubsystem.h" },
		{ "ModuleRelativePath", "Public/MatchmadeInstanceSubsystem.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UMatchmadeInstanceSubsystem_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMatchmadeInstanceSubsystem>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UMatchmadeInstanceSubsystem_Statics::ClassParams = {
		&UMatchmadeInstanceSubsystem::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UMatchmadeInstanceSubsystem_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UMatchmadeInstanceSubsystem_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UMatchmadeInstanceSubsystem()
	{
		if (!Z_Registration_Info_UClass_UMatchmadeInstanceSubsystem.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UMatchmadeInstanceSubsystem.OuterSingleton, Z_Construct_UClass_UMatchmadeInstanceSubsystem_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UMatchmadeInstanceSubsystem.OuterSingleton;
	}
	template<> MATCHFINDERSERVERMANAGER_API UClass* StaticClass<UMatchmadeInstanceSubsystem>()
	{
		return UMatchmadeInstanceSubsystem::StaticClass();
	}
	UMatchmadeInstanceSubsystem::UMatchmadeInstanceSubsystem() {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UMatchmadeInstanceSubsystem);
	UMatchmadeInstanceSubsystem::~UMatchmadeInstanceSubsystem() {}
	struct Z_CompiledInDeferFile_FID_ProjectDarkChamber_DarkChamber_Plugins_Developer_MatchFinderServerManager_Source_MatchFinderServerManager_Public_MatchmadeInstanceSubsystem_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ProjectDarkChamber_DarkChamber_Plugins_Developer_MatchFinderServerManager_Source_MatchFinderServerManager_Public_MatchmadeInstanceSubsystem_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UMatchmadeInstanceSubsystem, UMatchmadeInstanceSubsystem::StaticClass, TEXT("UMatchmadeInstanceSubsystem"), &Z_Registration_Info_UClass_UMatchmadeInstanceSubsystem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UMatchmadeInstanceSubsystem), 1376096820U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ProjectDarkChamber_DarkChamber_Plugins_Developer_MatchFinderServerManager_Source_MatchFinderServerManager_Public_MatchmadeInstanceSubsystem_h_2788852532(TEXT("/Script/MatchFinderServerManager"),
		Z_CompiledInDeferFile_FID_ProjectDarkChamber_DarkChamber_Plugins_Developer_MatchFinderServerManager_Source_MatchFinderServerManager_Public_MatchmadeInstanceSubsystem_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ProjectDarkChamber_DarkChamber_Plugins_Developer_MatchFinderServerManager_Source_MatchFinderServerManager_Public_MatchmadeInstanceSubsystem_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
