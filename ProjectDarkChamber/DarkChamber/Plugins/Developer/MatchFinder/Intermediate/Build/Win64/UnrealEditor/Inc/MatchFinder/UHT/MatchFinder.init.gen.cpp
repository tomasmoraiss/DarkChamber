// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMatchFinder_init() {}
	MATCHFINDER_API UFunction* Z_Construct_UDelegateFunction_MatchFinder_OnGameFindCanceled__DelegateSignature();
	MATCHFINDER_API UFunction* Z_Construct_UDelegateFunction_MatchFinder_OnGameFindStarted__DelegateSignature();
	MATCHFINDER_API UFunction* Z_Construct_UDelegateFunction_MatchFinder_OnGameFindStateUpdate__DelegateSignature();
	MATCHFINDER_API UFunction* Z_Construct_UDelegateFunction_MatchFinder_OnGameFound__DelegateSignature();
	MATCHFINDER_API UFunction* Z_Construct_UDelegateFunction_MatchFinder_OnMatchFindingFailed__DelegateSignature();
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_MatchFinder;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_MatchFinder()
	{
		if (!Z_Registration_Info_UPackage__Script_MatchFinder.OuterSingleton)
		{
			static UObject* (*const SingletonFuncArray[])() = {
				(UObject* (*)())Z_Construct_UDelegateFunction_MatchFinder_OnGameFindCanceled__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_MatchFinder_OnGameFindStarted__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_MatchFinder_OnGameFindStateUpdate__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_MatchFinder_OnGameFound__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_MatchFinder_OnMatchFindingFailed__DelegateSignature,
			};
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/MatchFinder",
				SingletonFuncArray,
				UE_ARRAY_COUNT(SingletonFuncArray),
				PKG_CompiledIn | 0x00000000,
				0x4083613E,
				0xE327006B,
				METADATA_PARAMS(nullptr, 0)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_MatchFinder.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_MatchFinder.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_MatchFinder(Z_Construct_UPackage__Script_MatchFinder, TEXT("/Script/MatchFinder"), Z_Registration_Info_UPackage__Script_MatchFinder, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x4083613E, 0xE327006B));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
