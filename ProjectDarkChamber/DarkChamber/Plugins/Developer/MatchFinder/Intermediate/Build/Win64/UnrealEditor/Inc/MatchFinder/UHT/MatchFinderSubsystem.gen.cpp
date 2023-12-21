// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MatchFinder/Public/MatchFinderSubsystem.h"
#include "../../Source/Runtime/Engine/Classes/Engine/GameInstance.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMatchFinderSubsystem() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_UGameInstanceSubsystem();
	MATCHFINDER_API UClass* Z_Construct_UClass_UMatchFinderSubsystem();
	MATCHFINDER_API UClass* Z_Construct_UClass_UMatchFinderSubsystem_NoRegister();
	MATCHFINDER_API UEnum* Z_Construct_UEnum_MatchFinder_EMatchFinderSubsystemState();
	MATCHFINDER_API UEnum* Z_Construct_UEnum_MatchFinder_EMatchFindingProgress();
	MATCHFINDER_API UFunction* Z_Construct_UDelegateFunction_MatchFinder_OnGameFindCanceled__DelegateSignature();
	MATCHFINDER_API UFunction* Z_Construct_UDelegateFunction_MatchFinder_OnGameFindStarted__DelegateSignature();
	MATCHFINDER_API UFunction* Z_Construct_UDelegateFunction_MatchFinder_OnGameFindStateUpdate__DelegateSignature();
	MATCHFINDER_API UFunction* Z_Construct_UDelegateFunction_MatchFinder_OnGameFound__DelegateSignature();
	MATCHFINDER_API UFunction* Z_Construct_UDelegateFunction_MatchFinder_OnMatchFindingFailed__DelegateSignature();
	UPackage* Z_Construct_UPackage__Script_MatchFinder();
// End Cross Module References
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EMatchFinderSubsystemState;
	static UEnum* EMatchFinderSubsystemState_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EMatchFinderSubsystemState.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EMatchFinderSubsystemState.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_MatchFinder_EMatchFinderSubsystemState, (UObject*)Z_Construct_UPackage__Script_MatchFinder(), TEXT("EMatchFinderSubsystemState"));
		}
		return Z_Registration_Info_UEnum_EMatchFinderSubsystemState.OuterSingleton;
	}
	template<> MATCHFINDER_API UEnum* StaticEnum<EMatchFinderSubsystemState>()
	{
		return EMatchFinderSubsystemState_StaticEnum();
	}
	struct Z_Construct_UEnum_MatchFinder_EMatchFinderSubsystemState_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_MatchFinder_EMatchFinderSubsystemState_Statics::Enumerators[] = {
		{ "EMatchFinderSubsystemState::Idle", (int64)EMatchFinderSubsystemState::Idle },
		{ "EMatchFinderSubsystemState::FindingMatch", (int64)EMatchFinderSubsystemState::FindingMatch },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_MatchFinder_EMatchFinderSubsystemState_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Comment", "// TODO: Move This To A Separate Header File\n// Auxiliary Enumerations\n" },
		{ "FindingMatch.Name", "EMatchFinderSubsystemState::FindingMatch" },
		{ "Idle.Name", "EMatchFinderSubsystemState::Idle" },
		{ "ModuleRelativePath", "Public/MatchFinderSubsystem.h" },
		{ "ToolTip", "TODO: Move This To A Separate Header File\nAuxiliary Enumerations" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_MatchFinder_EMatchFinderSubsystemState_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_MatchFinder,
		nullptr,
		"EMatchFinderSubsystemState",
		"EMatchFinderSubsystemState",
		Z_Construct_UEnum_MatchFinder_EMatchFinderSubsystemState_Statics::Enumerators,
		UE_ARRAY_COUNT(Z_Construct_UEnum_MatchFinder_EMatchFinderSubsystemState_Statics::Enumerators),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(Z_Construct_UEnum_MatchFinder_EMatchFinderSubsystemState_Statics::Enum_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UEnum_MatchFinder_EMatchFinderSubsystemState_Statics::Enum_MetaDataParams))
	};
	UEnum* Z_Construct_UEnum_MatchFinder_EMatchFinderSubsystemState()
	{
		if (!Z_Registration_Info_UEnum_EMatchFinderSubsystemState.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EMatchFinderSubsystemState.InnerSingleton, Z_Construct_UEnum_MatchFinder_EMatchFinderSubsystemState_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EMatchFinderSubsystemState.InnerSingleton;
	}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EMatchFindingProgress;
	static UEnum* EMatchFindingProgress_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EMatchFindingProgress.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EMatchFindingProgress.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_MatchFinder_EMatchFindingProgress, (UObject*)Z_Construct_UPackage__Script_MatchFinder(), TEXT("EMatchFindingProgress"));
		}
		return Z_Registration_Info_UEnum_EMatchFindingProgress.OuterSingleton;
	}
	template<> MATCHFINDER_API UEnum* StaticEnum<EMatchFindingProgress>()
	{
		return EMatchFindingProgress_StaticEnum();
	}
	struct Z_Construct_UEnum_MatchFinder_EMatchFindingProgress_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_MatchFinder_EMatchFindingProgress_Statics::Enumerators[] = {
		{ "EMatchFindingProgress::Idle", (int64)EMatchFindingProgress::Idle },
		{ "EMatchFindingProgress::CreatingConnection", (int64)EMatchFindingProgress::CreatingConnection },
		{ "EMatchFindingProgress::LoggingIn", (int64)EMatchFindingProgress::LoggingIn },
		{ "EMatchFindingProgress::RequestingGame", (int64)EMatchFindingProgress::RequestingGame },
		{ "EMatchFindingProgress::Complete", (int64)EMatchFindingProgress::Complete },
		{ "EMatchFindingProgress::ConnectionFailed", (int64)EMatchFindingProgress::ConnectionFailed },
		{ "EMatchFindingProgress::LoginFailed", (int64)EMatchFindingProgress::LoginFailed },
		{ "EMatchFindingProgress::FindingFailed", (int64)EMatchFindingProgress::FindingFailed },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_MatchFinder_EMatchFindingProgress_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Complete.Name", "EMatchFindingProgress::Complete" },
		{ "ConnectionFailed.Name", "EMatchFindingProgress::ConnectionFailed" },
		{ "CreatingConnection.Name", "EMatchFindingProgress::CreatingConnection" },
		{ "FindingFailed.Name", "EMatchFindingProgress::FindingFailed" },
		{ "Idle.Name", "EMatchFindingProgress::Idle" },
		{ "LoggingIn.Name", "EMatchFindingProgress::LoggingIn" },
		{ "LoginFailed.Name", "EMatchFindingProgress::LoginFailed" },
		{ "ModuleRelativePath", "Public/MatchFinderSubsystem.h" },
		{ "RequestingGame.Name", "EMatchFindingProgress::RequestingGame" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_MatchFinder_EMatchFindingProgress_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_MatchFinder,
		nullptr,
		"EMatchFindingProgress",
		"EMatchFindingProgress",
		Z_Construct_UEnum_MatchFinder_EMatchFindingProgress_Statics::Enumerators,
		UE_ARRAY_COUNT(Z_Construct_UEnum_MatchFinder_EMatchFindingProgress_Statics::Enumerators),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(Z_Construct_UEnum_MatchFinder_EMatchFindingProgress_Statics::Enum_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UEnum_MatchFinder_EMatchFindingProgress_Statics::Enum_MetaDataParams))
	};
	UEnum* Z_Construct_UEnum_MatchFinder_EMatchFindingProgress()
	{
		if (!Z_Registration_Info_UEnum_EMatchFindingProgress.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EMatchFindingProgress.InnerSingleton, Z_Construct_UEnum_MatchFinder_EMatchFindingProgress_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EMatchFindingProgress.InnerSingleton;
	}
	struct Z_Construct_UDelegateFunction_MatchFinder_OnGameFindStarted__DelegateSignature_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_MatchFinder_OnGameFindStarted__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "Comment", "// Event Declarations\n" },
		{ "ModuleRelativePath", "Public/MatchFinderSubsystem.h" },
		{ "ToolTip", "Event Declarations" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_MatchFinder_OnGameFindStarted__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_MatchFinder, nullptr, "OnGameFindStarted__DelegateSignature", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_MatchFinder_OnGameFindStarted__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_MatchFinder_OnGameFindStarted__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_MatchFinder_OnGameFindStarted__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_MatchFinder_OnGameFindStarted__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void FOnGameFindStarted_DelegateWrapper(const FMulticastScriptDelegate& OnGameFindStarted)
{
	OnGameFindStarted.ProcessMulticastDelegate<UObject>(NULL);
}
	struct Z_Construct_UDelegateFunction_MatchFinder_OnGameFindCanceled__DelegateSignature_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_MatchFinder_OnGameFindCanceled__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/MatchFinderSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_MatchFinder_OnGameFindCanceled__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_MatchFinder, nullptr, "OnGameFindCanceled__DelegateSignature", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_MatchFinder_OnGameFindCanceled__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_MatchFinder_OnGameFindCanceled__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_MatchFinder_OnGameFindCanceled__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_MatchFinder_OnGameFindCanceled__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void FOnGameFindCanceled_DelegateWrapper(const FMulticastScriptDelegate& OnGameFindCanceled)
{
	OnGameFindCanceled.ProcessMulticastDelegate<UObject>(NULL);
}
	struct Z_Construct_UDelegateFunction_MatchFinder_OnGameFound__DelegateSignature_Statics
	{
		struct _Script_MatchFinder_eventOnGameFound_Parms
		{
			FString IPnPort;
			FString AdditionalParams;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_IPnPort;
		static const UECodeGen_Private::FStrPropertyParams NewProp_AdditionalParams;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_MatchFinder_OnGameFound__DelegateSignature_Statics::NewProp_IPnPort = { "IPnPort", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(_Script_MatchFinder_eventOnGameFound_Parms, IPnPort), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_MatchFinder_OnGameFound__DelegateSignature_Statics::NewProp_AdditionalParams = { "AdditionalParams", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(_Script_MatchFinder_eventOnGameFound_Parms, AdditionalParams), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_MatchFinder_OnGameFound__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_MatchFinder_OnGameFound__DelegateSignature_Statics::NewProp_IPnPort,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_MatchFinder_OnGameFound__DelegateSignature_Statics::NewProp_AdditionalParams,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_MatchFinder_OnGameFound__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/MatchFinderSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_MatchFinder_OnGameFound__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_MatchFinder, nullptr, "OnGameFound__DelegateSignature", nullptr, nullptr, sizeof(Z_Construct_UDelegateFunction_MatchFinder_OnGameFound__DelegateSignature_Statics::_Script_MatchFinder_eventOnGameFound_Parms), Z_Construct_UDelegateFunction_MatchFinder_OnGameFound__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_MatchFinder_OnGameFound__DelegateSignature_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_MatchFinder_OnGameFound__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_MatchFinder_OnGameFound__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_MatchFinder_OnGameFound__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_MatchFinder_OnGameFound__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void FOnGameFound_DelegateWrapper(const FMulticastScriptDelegate& OnGameFound, const FString& IPnPort, const FString& AdditionalParams)
{
	struct _Script_MatchFinder_eventOnGameFound_Parms
	{
		FString IPnPort;
		FString AdditionalParams;
	};
	_Script_MatchFinder_eventOnGameFound_Parms Parms;
	Parms.IPnPort=IPnPort;
	Parms.AdditionalParams=AdditionalParams;
	OnGameFound.ProcessMulticastDelegate<UObject>(&Parms);
}
	struct Z_Construct_UDelegateFunction_MatchFinder_OnGameFindStateUpdate__DelegateSignature_Statics
	{
		struct _Script_MatchFinder_eventOnGameFindStateUpdate_Parms
		{
			FString State;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_State;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_MatchFinder_OnGameFindStateUpdate__DelegateSignature_Statics::NewProp_State = { "State", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(_Script_MatchFinder_eventOnGameFindStateUpdate_Parms, State), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_MatchFinder_OnGameFindStateUpdate__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_MatchFinder_OnGameFindStateUpdate__DelegateSignature_Statics::NewProp_State,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_MatchFinder_OnGameFindStateUpdate__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/MatchFinderSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_MatchFinder_OnGameFindStateUpdate__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_MatchFinder, nullptr, "OnGameFindStateUpdate__DelegateSignature", nullptr, nullptr, sizeof(Z_Construct_UDelegateFunction_MatchFinder_OnGameFindStateUpdate__DelegateSignature_Statics::_Script_MatchFinder_eventOnGameFindStateUpdate_Parms), Z_Construct_UDelegateFunction_MatchFinder_OnGameFindStateUpdate__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_MatchFinder_OnGameFindStateUpdate__DelegateSignature_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_MatchFinder_OnGameFindStateUpdate__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_MatchFinder_OnGameFindStateUpdate__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_MatchFinder_OnGameFindStateUpdate__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_MatchFinder_OnGameFindStateUpdate__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void FOnGameFindStateUpdate_DelegateWrapper(const FMulticastScriptDelegate& OnGameFindStateUpdate, const FString& State)
{
	struct _Script_MatchFinder_eventOnGameFindStateUpdate_Parms
	{
		FString State;
	};
	_Script_MatchFinder_eventOnGameFindStateUpdate_Parms Parms;
	Parms.State=State;
	OnGameFindStateUpdate.ProcessMulticastDelegate<UObject>(&Parms);
}
	struct Z_Construct_UDelegateFunction_MatchFinder_OnMatchFindingFailed__DelegateSignature_Statics
	{
		struct _Script_MatchFinder_eventOnMatchFindingFailed_Parms
		{
			FString Reason;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_Reason;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_MatchFinder_OnMatchFindingFailed__DelegateSignature_Statics::NewProp_Reason = { "Reason", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(_Script_MatchFinder_eventOnMatchFindingFailed_Parms, Reason), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_MatchFinder_OnMatchFindingFailed__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_MatchFinder_OnMatchFindingFailed__DelegateSignature_Statics::NewProp_Reason,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_MatchFinder_OnMatchFindingFailed__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/MatchFinderSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_MatchFinder_OnMatchFindingFailed__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_MatchFinder, nullptr, "OnMatchFindingFailed__DelegateSignature", nullptr, nullptr, sizeof(Z_Construct_UDelegateFunction_MatchFinder_OnMatchFindingFailed__DelegateSignature_Statics::_Script_MatchFinder_eventOnMatchFindingFailed_Parms), Z_Construct_UDelegateFunction_MatchFinder_OnMatchFindingFailed__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_MatchFinder_OnMatchFindingFailed__DelegateSignature_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_MatchFinder_OnMatchFindingFailed__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_MatchFinder_OnMatchFindingFailed__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_MatchFinder_OnMatchFindingFailed__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_MatchFinder_OnMatchFindingFailed__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void FOnMatchFindingFailed_DelegateWrapper(const FMulticastScriptDelegate& OnMatchFindingFailed, const FString& Reason)
{
	struct _Script_MatchFinder_eventOnMatchFindingFailed_Parms
	{
		FString Reason;
	};
	_Script_MatchFinder_eventOnMatchFindingFailed_Parms Parms;
	Parms.Reason=Reason;
	OnMatchFindingFailed.ProcessMulticastDelegate<UObject>(&Parms);
}
	DEFINE_FUNCTION(UMatchFinderSubsystem::execSlowTickFromTimerCallback)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SlowTickFromTimerCallback();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UMatchFinderSubsystem::execGetMatchFindingProgress)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(EMatchFindingProgress*)Z_Param__Result=P_THIS->GetMatchFindingProgress();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UMatchFinderSubsystem::execGetCurrentState)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(EMatchFinderSubsystemState*)Z_Param__Result=P_THIS->GetCurrentState();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UMatchFinderSubsystem::execCancelRequest)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->CancelRequest();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UMatchFinderSubsystem::execRequestGame)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->RequestGame();
		P_NATIVE_END;
	}
	void UMatchFinderSubsystem::StaticRegisterNativesUMatchFinderSubsystem()
	{
		UClass* Class = UMatchFinderSubsystem::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "CancelRequest", &UMatchFinderSubsystem::execCancelRequest },
			{ "GetCurrentState", &UMatchFinderSubsystem::execGetCurrentState },
			{ "GetMatchFindingProgress", &UMatchFinderSubsystem::execGetMatchFindingProgress },
			{ "RequestGame", &UMatchFinderSubsystem::execRequestGame },
			{ "SlowTickFromTimerCallback", &UMatchFinderSubsystem::execSlowTickFromTimerCallback },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UMatchFinderSubsystem_CancelRequest_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMatchFinderSubsystem_CancelRequest_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/MatchFinderSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMatchFinderSubsystem_CancelRequest_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMatchFinderSubsystem, nullptr, "CancelRequest", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMatchFinderSubsystem_CancelRequest_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UMatchFinderSubsystem_CancelRequest_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMatchFinderSubsystem_CancelRequest()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMatchFinderSubsystem_CancelRequest_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UMatchFinderSubsystem_GetCurrentState_Statics
	{
		struct MatchFinderSubsystem_eventGetCurrentState_Parms
		{
			EMatchFinderSubsystemState ReturnValue;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UMatchFinderSubsystem_GetCurrentState_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UMatchFinderSubsystem_GetCurrentState_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(MatchFinderSubsystem_eventGetCurrentState_Parms, ReturnValue), Z_Construct_UEnum_MatchFinder_EMatchFinderSubsystemState, METADATA_PARAMS(nullptr, 0) }; // 559458488
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMatchFinderSubsystem_GetCurrentState_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMatchFinderSubsystem_GetCurrentState_Statics::NewProp_ReturnValue_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMatchFinderSubsystem_GetCurrentState_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMatchFinderSubsystem_GetCurrentState_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/MatchFinderSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMatchFinderSubsystem_GetCurrentState_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMatchFinderSubsystem, nullptr, "GetCurrentState", nullptr, nullptr, sizeof(Z_Construct_UFunction_UMatchFinderSubsystem_GetCurrentState_Statics::MatchFinderSubsystem_eventGetCurrentState_Parms), Z_Construct_UFunction_UMatchFinderSubsystem_GetCurrentState_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMatchFinderSubsystem_GetCurrentState_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMatchFinderSubsystem_GetCurrentState_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UMatchFinderSubsystem_GetCurrentState_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMatchFinderSubsystem_GetCurrentState()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMatchFinderSubsystem_GetCurrentState_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UMatchFinderSubsystem_GetMatchFindingProgress_Statics
	{
		struct MatchFinderSubsystem_eventGetMatchFindingProgress_Parms
		{
			EMatchFindingProgress ReturnValue;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UMatchFinderSubsystem_GetMatchFindingProgress_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UMatchFinderSubsystem_GetMatchFindingProgress_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(MatchFinderSubsystem_eventGetMatchFindingProgress_Parms, ReturnValue), Z_Construct_UEnum_MatchFinder_EMatchFindingProgress, METADATA_PARAMS(nullptr, 0) }; // 2538340586
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMatchFinderSubsystem_GetMatchFindingProgress_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMatchFinderSubsystem_GetMatchFindingProgress_Statics::NewProp_ReturnValue_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMatchFinderSubsystem_GetMatchFindingProgress_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMatchFinderSubsystem_GetMatchFindingProgress_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/MatchFinderSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMatchFinderSubsystem_GetMatchFindingProgress_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMatchFinderSubsystem, nullptr, "GetMatchFindingProgress", nullptr, nullptr, sizeof(Z_Construct_UFunction_UMatchFinderSubsystem_GetMatchFindingProgress_Statics::MatchFinderSubsystem_eventGetMatchFindingProgress_Parms), Z_Construct_UFunction_UMatchFinderSubsystem_GetMatchFindingProgress_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMatchFinderSubsystem_GetMatchFindingProgress_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMatchFinderSubsystem_GetMatchFindingProgress_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UMatchFinderSubsystem_GetMatchFindingProgress_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMatchFinderSubsystem_GetMatchFindingProgress()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMatchFinderSubsystem_GetMatchFindingProgress_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UMatchFinderSubsystem_RequestGame_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMatchFinderSubsystem_RequestGame_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/MatchFinderSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMatchFinderSubsystem_RequestGame_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMatchFinderSubsystem, nullptr, "RequestGame", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMatchFinderSubsystem_RequestGame_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UMatchFinderSubsystem_RequestGame_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMatchFinderSubsystem_RequestGame()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMatchFinderSubsystem_RequestGame_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UMatchFinderSubsystem_SlowTickFromTimerCallback_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMatchFinderSubsystem_SlowTickFromTimerCallback_Statics::Function_MetaDataParams[] = {
		{ "Comment", "// Private Functions\n" },
		{ "ModuleRelativePath", "Public/MatchFinderSubsystem.h" },
		{ "ToolTip", "Private Functions" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMatchFinderSubsystem_SlowTickFromTimerCallback_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMatchFinderSubsystem, nullptr, "SlowTickFromTimerCallback", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMatchFinderSubsystem_SlowTickFromTimerCallback_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UMatchFinderSubsystem_SlowTickFromTimerCallback_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMatchFinderSubsystem_SlowTickFromTimerCallback()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMatchFinderSubsystem_SlowTickFromTimerCallback_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UMatchFinderSubsystem);
	UClass* Z_Construct_UClass_UMatchFinderSubsystem_NoRegister()
	{
		return UMatchFinderSubsystem::StaticClass();
	}
	struct Z_Construct_UClass_UMatchFinderSubsystem_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnGameFindStartedEvent_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnGameFindStartedEvent;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnGameFindCanceledEvent_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnGameFindCanceledEvent;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnGameFoundEvent_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnGameFoundEvent;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnGameFindStateUpdateEvent_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnGameFindStateUpdateEvent;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnOnMatchFindingFailedEvent_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnOnMatchFindingFailedEvent;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MatchmakingServerIP_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_MatchmakingServerIP;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MatchmakingServerPort_MetaData[];
#endif
		static const UECodeGen_Private::FFInt16PropertyParams NewProp_MatchmakingServerPort;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UMatchFinderSubsystem_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UGameInstanceSubsystem,
		(UObject* (*)())Z_Construct_UPackage__Script_MatchFinder,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UMatchFinderSubsystem_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UMatchFinderSubsystem_CancelRequest, "CancelRequest" }, // 1004485097
		{ &Z_Construct_UFunction_UMatchFinderSubsystem_GetCurrentState, "GetCurrentState" }, // 2859174598
		{ &Z_Construct_UFunction_UMatchFinderSubsystem_GetMatchFindingProgress, "GetMatchFindingProgress" }, // 3987679179
		{ &Z_Construct_UFunction_UMatchFinderSubsystem_RequestGame, "RequestGame" }, // 1934847609
		{ &Z_Construct_UFunction_UMatchFinderSubsystem_SlowTickFromTimerCallback, "SlowTickFromTimerCallback" }, // 516780514
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMatchFinderSubsystem_Statics::Class_MetaDataParams[] = {
		{ "Comment", "// NOTE: As this contains important variables to serialize such as where to connect to and port, we keep this data saved\n//\x09\x09 in configuration files we can easily tweak, if changes are made in engine, they will be saved out, otherwise\n//\x09\x09 in editor change them in PROJECTDIR\\Saved\\Config\\WindowsEditor\\MatchFinderSubsystem.ini\n//\x09\x09 Worth noting this isn't a tracked file on github, so if you dont see it, just run the game once\n" },
		{ "IncludePath", "MatchFinderSubsystem.h" },
		{ "ModuleRelativePath", "Public/MatchFinderSubsystem.h" },
		{ "ToolTip", "NOTE: As this contains important variables to serialize such as where to connect to and port, we keep this data saved\n               in configuration files we can easily tweak, if changes are made in engine, they will be saved out, otherwise\n               in editor change them in PROJECTDIR\\Saved\\Config\\WindowsEditor\\MatchFinderSubsystem.ini\n               Worth noting this isn't a tracked file on github, so if you dont see it, just run the game once" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMatchFinderSubsystem_Statics::NewProp_OnGameFindStartedEvent_MetaData[] = {
		{ "Comment", "// Events\n" },
		{ "ModuleRelativePath", "Public/MatchFinderSubsystem.h" },
		{ "ToolTip", "Events" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UMatchFinderSubsystem_Statics::NewProp_OnGameFindStartedEvent = { "OnGameFindStartedEvent", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(UMatchFinderSubsystem, OnGameFindStartedEvent), Z_Construct_UDelegateFunction_MatchFinder_OnGameFindStarted__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_UMatchFinderSubsystem_Statics::NewProp_OnGameFindStartedEvent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UMatchFinderSubsystem_Statics::NewProp_OnGameFindStartedEvent_MetaData)) }; // 2797141401
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMatchFinderSubsystem_Statics::NewProp_OnGameFindCanceledEvent_MetaData[] = {
		{ "ModuleRelativePath", "Public/MatchFinderSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UMatchFinderSubsystem_Statics::NewProp_OnGameFindCanceledEvent = { "OnGameFindCanceledEvent", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(UMatchFinderSubsystem, OnGameFindCanceledEvent), Z_Construct_UDelegateFunction_MatchFinder_OnGameFindCanceled__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_UMatchFinderSubsystem_Statics::NewProp_OnGameFindCanceledEvent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UMatchFinderSubsystem_Statics::NewProp_OnGameFindCanceledEvent_MetaData)) }; // 3473294857
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMatchFinderSubsystem_Statics::NewProp_OnGameFoundEvent_MetaData[] = {
		{ "ModuleRelativePath", "Public/MatchFinderSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UMatchFinderSubsystem_Statics::NewProp_OnGameFoundEvent = { "OnGameFoundEvent", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(UMatchFinderSubsystem, OnGameFoundEvent), Z_Construct_UDelegateFunction_MatchFinder_OnGameFound__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_UMatchFinderSubsystem_Statics::NewProp_OnGameFoundEvent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UMatchFinderSubsystem_Statics::NewProp_OnGameFoundEvent_MetaData)) }; // 3862465789
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMatchFinderSubsystem_Statics::NewProp_OnGameFindStateUpdateEvent_MetaData[] = {
		{ "ModuleRelativePath", "Public/MatchFinderSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UMatchFinderSubsystem_Statics::NewProp_OnGameFindStateUpdateEvent = { "OnGameFindStateUpdateEvent", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(UMatchFinderSubsystem, OnGameFindStateUpdateEvent), Z_Construct_UDelegateFunction_MatchFinder_OnGameFindStateUpdate__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_UMatchFinderSubsystem_Statics::NewProp_OnGameFindStateUpdateEvent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UMatchFinderSubsystem_Statics::NewProp_OnGameFindStateUpdateEvent_MetaData)) }; // 3182450836
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMatchFinderSubsystem_Statics::NewProp_OnOnMatchFindingFailedEvent_MetaData[] = {
		{ "ModuleRelativePath", "Public/MatchFinderSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UMatchFinderSubsystem_Statics::NewProp_OnOnMatchFindingFailedEvent = { "OnOnMatchFindingFailedEvent", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(UMatchFinderSubsystem, OnOnMatchFindingFailedEvent), Z_Construct_UDelegateFunction_MatchFinder_OnMatchFindingFailed__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_UMatchFinderSubsystem_Statics::NewProp_OnOnMatchFindingFailedEvent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UMatchFinderSubsystem_Statics::NewProp_OnOnMatchFindingFailedEvent_MetaData)) }; // 2736280155
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMatchFinderSubsystem_Statics::NewProp_MatchmakingServerIP_MetaData[] = {
		{ "Comment", "// TODO: If these are ever exposed in the game, please make sure to update the worker\n" },
		{ "ModuleRelativePath", "Public/MatchFinderSubsystem.h" },
		{ "ToolTip", "TODO: If these are ever exposed in the game, please make sure to update the worker" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UMatchFinderSubsystem_Statics::NewProp_MatchmakingServerIP = { "MatchmakingServerIP", nullptr, (EPropertyFlags)0x0040000000004000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(UMatchFinderSubsystem, MatchmakingServerIP), METADATA_PARAMS(Z_Construct_UClass_UMatchFinderSubsystem_Statics::NewProp_MatchmakingServerIP_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UMatchFinderSubsystem_Statics::NewProp_MatchmakingServerIP_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMatchFinderSubsystem_Statics::NewProp_MatchmakingServerPort_MetaData[] = {
		{ "ModuleRelativePath", "Public/MatchFinderSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FFInt16PropertyParams Z_Construct_UClass_UMatchFinderSubsystem_Statics::NewProp_MatchmakingServerPort = { "MatchmakingServerPort", nullptr, (EPropertyFlags)0x0040000000004000, UECodeGen_Private::EPropertyGenFlags::UInt16, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(UMatchFinderSubsystem, MatchmakingServerPort), METADATA_PARAMS(Z_Construct_UClass_UMatchFinderSubsystem_Statics::NewProp_MatchmakingServerPort_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UMatchFinderSubsystem_Statics::NewProp_MatchmakingServerPort_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UMatchFinderSubsystem_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMatchFinderSubsystem_Statics::NewProp_OnGameFindStartedEvent,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMatchFinderSubsystem_Statics::NewProp_OnGameFindCanceledEvent,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMatchFinderSubsystem_Statics::NewProp_OnGameFoundEvent,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMatchFinderSubsystem_Statics::NewProp_OnGameFindStateUpdateEvent,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMatchFinderSubsystem_Statics::NewProp_OnOnMatchFindingFailedEvent,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMatchFinderSubsystem_Statics::NewProp_MatchmakingServerIP,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMatchFinderSubsystem_Statics::NewProp_MatchmakingServerPort,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UMatchFinderSubsystem_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMatchFinderSubsystem>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UMatchFinderSubsystem_Statics::ClassParams = {
		&UMatchFinderSubsystem::StaticClass,
		"MatchFinderSubsystem",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UMatchFinderSubsystem_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UMatchFinderSubsystem_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_UMatchFinderSubsystem_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UMatchFinderSubsystem_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UMatchFinderSubsystem()
	{
		if (!Z_Registration_Info_UClass_UMatchFinderSubsystem.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UMatchFinderSubsystem.OuterSingleton, Z_Construct_UClass_UMatchFinderSubsystem_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UMatchFinderSubsystem.OuterSingleton;
	}
	template<> MATCHFINDER_API UClass* StaticClass<UMatchFinderSubsystem>()
	{
		return UMatchFinderSubsystem::StaticClass();
	}
	UMatchFinderSubsystem::UMatchFinderSubsystem() {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UMatchFinderSubsystem);
	UMatchFinderSubsystem::~UMatchFinderSubsystem() {}
	struct Z_CompiledInDeferFile_FID_ProjectDarkChamber_DarkChamber_Plugins_Developer_MatchFinder_Source_MatchFinder_Public_MatchFinderSubsystem_h_Statics
	{
		static const FEnumRegisterCompiledInInfo EnumInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FEnumRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ProjectDarkChamber_DarkChamber_Plugins_Developer_MatchFinder_Source_MatchFinder_Public_MatchFinderSubsystem_h_Statics::EnumInfo[] = {
		{ EMatchFinderSubsystemState_StaticEnum, TEXT("EMatchFinderSubsystemState"), &Z_Registration_Info_UEnum_EMatchFinderSubsystemState, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 559458488U) },
		{ EMatchFindingProgress_StaticEnum, TEXT("EMatchFindingProgress"), &Z_Registration_Info_UEnum_EMatchFindingProgress, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2538340586U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ProjectDarkChamber_DarkChamber_Plugins_Developer_MatchFinder_Source_MatchFinder_Public_MatchFinderSubsystem_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UMatchFinderSubsystem, UMatchFinderSubsystem::StaticClass, TEXT("UMatchFinderSubsystem"), &Z_Registration_Info_UClass_UMatchFinderSubsystem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UMatchFinderSubsystem), 344086508U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ProjectDarkChamber_DarkChamber_Plugins_Developer_MatchFinder_Source_MatchFinder_Public_MatchFinderSubsystem_h_1870170122(TEXT("/Script/MatchFinder"),
		Z_CompiledInDeferFile_FID_ProjectDarkChamber_DarkChamber_Plugins_Developer_MatchFinder_Source_MatchFinder_Public_MatchFinderSubsystem_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ProjectDarkChamber_DarkChamber_Plugins_Developer_MatchFinder_Source_MatchFinder_Public_MatchFinderSubsystem_h_Statics::ClassInfo),
		nullptr, 0,
		Z_CompiledInDeferFile_FID_ProjectDarkChamber_DarkChamber_Plugins_Developer_MatchFinder_Source_MatchFinder_Public_MatchFinderSubsystem_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ProjectDarkChamber_DarkChamber_Plugins_Developer_MatchFinder_Source_MatchFinder_Public_MatchFinderSubsystem_h_Statics::EnumInfo));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
