// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interaction/ValEnemyHighlightInterface.h"
#include "Character/ValBaseCharacter.h"
#include "ValEnemy.generated.h"

/**
 * 
 */
UCLASS()
class STRATEGYGAME_API AValEnemy : public AValBaseCharacter, public IValEnemyHighlightInterface
{
	GENERATED_BODY()

public:

	virtual void Highlight() override;
	virtual void UnHighlight() override;
	
	UPROPERTY(BlueprintReadOnly)
	bool bHighlighted = false;
};
