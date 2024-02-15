// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "ValEnemyHighlightInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UValEnemyHighlightInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class STRATEGYGAME_API IValEnemyHighlightInterface
{
	GENERATED_BODY()

public:

	virtual void Highlight() = 0;
	virtual void UnHighlight() = 0;
};
