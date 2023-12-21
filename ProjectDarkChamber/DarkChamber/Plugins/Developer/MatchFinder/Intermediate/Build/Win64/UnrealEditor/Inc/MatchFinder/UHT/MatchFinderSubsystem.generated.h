// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "MatchFinderSubsystem.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
enum class EMatchFinderSubsystemState : uint8;
enum class EMatchFindingProgress : uint8;
#ifdef MATCHFINDER_MatchFinderSubsystem_generated_h
#error "MatchFinderSubsystem.generated.h already included, missing '#pragma once' in MatchFinderSubsystem.h"
#endif
#define MATCHFINDER_MatchFinderSubsystem_generated_h

#define FID_ProjectDarkChamber_DarkChamber_Plugins_Developer_MatchFinder_Source_MatchFinder_Public_MatchFinderSubsystem_h_33_DELEGATE \
MATCHFINDER_API void FOnGameFindStarted_DelegateWrapper(const FMulticastScriptDelegate& OnGameFindStarted);


#define FID_ProjectDarkChamber_DarkChamber_Plugins_Developer_MatchFinder_Source_MatchFinder_Public_MatchFinderSubsystem_h_34_DELEGATE \
MATCHFINDER_API void FOnGameFindCanceled_DelegateWrapper(const FMulticastScriptDelegate& OnGameFindCanceled);


#define FID_ProjectDarkChamber_DarkChamber_Plugins_Developer_MatchFinder_Source_MatchFinder_Public_MatchFinderSubsystem_h_35_DELEGATE \
MATCHFINDER_API void FOnGameFound_DelegateWrapper(const FMulticastScriptDelegate& OnGameFound, const FString& IPnPort, const FString& AdditionalParams);


#define FID_ProjectDarkChamber_DarkChamber_Plugins_Developer_MatchFinder_Source_MatchFinder_Public_MatchFinderSubsystem_h_37_DELEGATE \
MATCHFINDER_API void FOnGameFindStateUpdate_DelegateWrapper(const FMulticastScriptDelegate& OnGameFindStateUpdate, const FString& State);


#define FID_ProjectDarkChamber_DarkChamber_Plugins_Developer_MatchFinder_Source_MatchFinder_Public_MatchFinderSubsystem_h_39_DELEGATE \
MATCHFINDER_API void FOnMatchFindingFailed_DelegateWrapper(const FMulticastScriptDelegate& OnMatchFindingFailed, const FString& Reason);


#define FID_ProjectDarkChamber_DarkChamber_Plugins_Developer_MatchFinder_Source_MatchFinder_Public_MatchFinderSubsystem_h_51_SPARSE_DATA
#define FID_ProjectDarkChamber_DarkChamber_Plugins_Developer_MatchFinder_Source_MatchFinder_Public_MatchFinderSubsystem_h_51_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execSlowTickFromTimerCallback); \
	DECLARE_FUNCTION(execGetMatchFindingProgress); \
	DECLARE_FUNCTION(execGetCurrentState); \
	DECLARE_FUNCTION(execCancelRequest); \
	DECLARE_FUNCTION(execRequestGame);


#define FID_ProjectDarkChamber_DarkChamber_Plugins_Developer_MatchFinder_Source_MatchFinder_Public_MatchFinderSubsystem_h_51_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execSlowTickFromTimerCallback); \
	DECLARE_FUNCTION(execGetMatchFindingProgress); \
	DECLARE_FUNCTION(execGetCurrentState); \
	DECLARE_FUNCTION(execCancelRequest); \
	DECLARE_FUNCTION(execRequestGame);


#define FID_ProjectDarkChamber_DarkChamber_Plugins_Developer_MatchFinder_Source_MatchFinder_Public_MatchFinderSubsystem_h_51_ACCESSORS
#define FID_ProjectDarkChamber_DarkChamber_Plugins_Developer_MatchFinder_Source_MatchFinder_Public_MatchFinderSubsystem_h_51_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUMatchFinderSubsystem(); \
	friend struct Z_Construct_UClass_UMatchFinderSubsystem_Statics; \
public: \
	DECLARE_CLASS(UMatchFinderSubsystem, UGameInstanceSubsystem, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/MatchFinder"), NO_API) \
	DECLARE_SERIALIZER(UMatchFinderSubsystem) \
	static const TCHAR* StaticConfigName() {return TEXT("MatchFinderSubsystem");} \



#define FID_ProjectDarkChamber_DarkChamber_Plugins_Developer_MatchFinder_Source_MatchFinder_Public_MatchFinderSubsystem_h_51_INCLASS \
private: \
	static void StaticRegisterNativesUMatchFinderSubsystem(); \
	friend struct Z_Construct_UClass_UMatchFinderSubsystem_Statics; \
public: \
	DECLARE_CLASS(UMatchFinderSubsystem, UGameInstanceSubsystem, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/MatchFinder"), NO_API) \
	DECLARE_SERIALIZER(UMatchFinderSubsystem) \
	static const TCHAR* StaticConfigName() {return TEXT("MatchFinderSubsystem");} \



#define FID_ProjectDarkChamber_DarkChamber_Plugins_Developer_MatchFinder_Source_MatchFinder_Public_MatchFinderSubsystem_h_51_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UMatchFinderSubsystem(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UMatchFinderSubsystem) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UMatchFinderSubsystem); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UMatchFinderSubsystem); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UMatchFinderSubsystem(UMatchFinderSubsystem&&); \
	NO_API UMatchFinderSubsystem(const UMatchFinderSubsystem&); \
public: \
	NO_API virtual ~UMatchFinderSubsystem();


#define FID_ProjectDarkChamber_DarkChamber_Plugins_Developer_MatchFinder_Source_MatchFinder_Public_MatchFinderSubsystem_h_51_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UMatchFinderSubsystem(); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UMatchFinderSubsystem(UMatchFinderSubsystem&&); \
	NO_API UMatchFinderSubsystem(const UMatchFinderSubsystem&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UMatchFinderSubsystem); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UMatchFinderSubsystem); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UMatchFinderSubsystem) \
	NO_API virtual ~UMatchFinderSubsystem();


#define FID_ProjectDarkChamber_DarkChamber_Plugins_Developer_MatchFinder_Source_MatchFinder_Public_MatchFinderSubsystem_h_48_PROLOG
#define FID_ProjectDarkChamber_DarkChamber_Plugins_Developer_MatchFinder_Source_MatchFinder_Public_MatchFinderSubsystem_h_51_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_ProjectDarkChamber_DarkChamber_Plugins_Developer_MatchFinder_Source_MatchFinder_Public_MatchFinderSubsystem_h_51_SPARSE_DATA \
	FID_ProjectDarkChamber_DarkChamber_Plugins_Developer_MatchFinder_Source_MatchFinder_Public_MatchFinderSubsystem_h_51_RPC_WRAPPERS \
	FID_ProjectDarkChamber_DarkChamber_Plugins_Developer_MatchFinder_Source_MatchFinder_Public_MatchFinderSubsystem_h_51_ACCESSORS \
	FID_ProjectDarkChamber_DarkChamber_Plugins_Developer_MatchFinder_Source_MatchFinder_Public_MatchFinderSubsystem_h_51_INCLASS \
	FID_ProjectDarkChamber_DarkChamber_Plugins_Developer_MatchFinder_Source_MatchFinder_Public_MatchFinderSubsystem_h_51_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_ProjectDarkChamber_DarkChamber_Plugins_Developer_MatchFinder_Source_MatchFinder_Public_MatchFinderSubsystem_h_51_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_ProjectDarkChamber_DarkChamber_Plugins_Developer_MatchFinder_Source_MatchFinder_Public_MatchFinderSubsystem_h_51_SPARSE_DATA \
	FID_ProjectDarkChamber_DarkChamber_Plugins_Developer_MatchFinder_Source_MatchFinder_Public_MatchFinderSubsystem_h_51_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_ProjectDarkChamber_DarkChamber_Plugins_Developer_MatchFinder_Source_MatchFinder_Public_MatchFinderSubsystem_h_51_ACCESSORS \
	FID_ProjectDarkChamber_DarkChamber_Plugins_Developer_MatchFinder_Source_MatchFinder_Public_MatchFinderSubsystem_h_51_INCLASS_NO_PURE_DECLS \
	FID_ProjectDarkChamber_DarkChamber_Plugins_Developer_MatchFinder_Source_MatchFinder_Public_MatchFinderSubsystem_h_51_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> MATCHFINDER_API UClass* StaticClass<class UMatchFinderSubsystem>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_ProjectDarkChamber_DarkChamber_Plugins_Developer_MatchFinder_Source_MatchFinder_Public_MatchFinderSubsystem_h


#define FOREACH_ENUM_EMATCHFINDERSUBSYSTEMSTATE(op) \
	op(EMatchFinderSubsystemState::Idle) \
	op(EMatchFinderSubsystemState::FindingMatch) 

enum class EMatchFinderSubsystemState : uint8;
template<> struct TIsUEnumClass<EMatchFinderSubsystemState> { enum { Value = true }; };
template<> MATCHFINDER_API UEnum* StaticEnum<EMatchFinderSubsystemState>();

#define FOREACH_ENUM_EMATCHFINDINGPROGRESS(op) \
	op(EMatchFindingProgress::Idle) \
	op(EMatchFindingProgress::CreatingConnection) \
	op(EMatchFindingProgress::LoggingIn) \
	op(EMatchFindingProgress::RequestingGame) \
	op(EMatchFindingProgress::Complete) \
	op(EMatchFindingProgress::ConnectionFailed) \
	op(EMatchFindingProgress::LoginFailed) \
	op(EMatchFindingProgress::FindingFailed) 

enum class EMatchFindingProgress : uint8;
template<> struct TIsUEnumClass<EMatchFindingProgress> { enum { Value = true }; };
template<> MATCHFINDER_API UEnum* StaticEnum<EMatchFindingProgress>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
