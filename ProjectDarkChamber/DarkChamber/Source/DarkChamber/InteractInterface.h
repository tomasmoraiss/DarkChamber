// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "InteractInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UInteractInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class DARKCHAMBER_API IInteractInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

// Interactor = some component that tracks with a raycast the object that you want to interact with, should live on a character
	// this should all be basically called from the interactor component, that fires a ray and keeps track the current target object that implements this interface
	// this should be called when the raycast first hits this target, to get anything to setup the interaction like a context mapping for input (delayed vs immediate button presses)
	virtual void OnInteractHoverBegin();

	// abstraction for when you start interacting in case there are components you want to search for specifically when youre starting the interaction
	virtual void OnInteractStart();

	// This is when the mapping happens
	virtual void Interact();
	
	// when the interaction ends happening
	virtual void OnInteractEnd();

	// inverse mirrored function so when you stop targeting this object you remove anything you added in the other (like context mappings)
	virtual void OnInteracthoverEnd();
	
};
