// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ValPlayerController.generated.h"

class UInputMappingContext;

UCLASS()
class STRATEGYGAME_API AValPlayerController : public APlayerController
{
	GENERATED_BODY()

public:

	AValPlayerController();

protected:

	virtual void BeginPlay() override;

private:

	TObjectPtr<UInputMappingContext> ValContext;

	
};
