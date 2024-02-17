// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/ValBaseCharacter.h"
#include "ValPlayer.generated.h"

class USpringArmComponent;
class UCameraComponent;

UCLASS()
class STRATEGYGAME_API AValPlayer : public AValBaseCharacter
{
	GENERATED_BODY()

public:

	AValPlayer();

	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState();


protected:

	UPROPERTY(VisibleAnywhere, Category = "Camera")
	USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, Category = "Camera")
	UCameraComponent* Camera;
	
};
