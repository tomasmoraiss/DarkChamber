// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "UObject/ObjectMacros.h"
#include "Templates/SubclassOf.h"
#include "Templates/Casts.h"
#include "UObject/Interface.h"
#include "Interface_AssetUserData.generated.h"

class UAssetUserData;

/** Interface for assets/objects that can own UserData **/
UINTERFACE(MinimalApi, meta=(CannotImplementInterfaceInBlueprint))
class UInterface_AssetUserData : public UInterface
{
	GENERATED_UINTERFACE_BODY()
};

class IInterface_AssetUserData
{
	GENERATED_IINTERFACE_BODY()

	virtual void AddAssetUserData(UAssetUserData* InUserData) {}

	virtual UAssetUserData* GetAssetUserDataOfClass(TSubclassOf<UAssetUserData> InUserDataClass)
	{
		return nullptr;
	}

	virtual const TArray<UAssetUserData*>* GetAssetUserDataArray() const
	{
		return nullptr;
	}

	template<typename T>
	T* GetAssetUserData()
	{
		return Cast<T>( GetAssetUserDataOfClass(T::StaticClass()) );
	}

	template<typename T>
	T* GetAssetUserDataChecked()
	{
		return CastChecked<T>(GetAssetUserDataOfClass(T::StaticClass()));
	}

	virtual void RemoveUserDataOfClass(TSubclassOf<UAssetUserData> InUserDataClass) {}

};

#if UE_ENABLE_INCLUDE_ORDER_DEPRECATED_IN_5_2
#include "CoreMinimal.h"
#endif
