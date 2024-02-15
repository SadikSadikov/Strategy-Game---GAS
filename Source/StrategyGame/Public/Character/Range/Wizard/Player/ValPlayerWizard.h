// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/Range/ValBaseRange.h"
#include "ValPlayerWizard.generated.h"

class USpringArmComponent; 
class UCameraComponent;

UCLASS()
class STRATEGYGAME_API AValPlayerWizard : public AValBaseRange
{
	GENERATED_BODY()

public:

	AValPlayerWizard();

protected:

private:

	UPROPERTY(VisibleAnywhere, Category = "Camera")
	USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, Category = "Camera")
	UCameraComponent* Camera;


	
};
