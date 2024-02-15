// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ValPlayerController.generated.h"

class UInputMappingContext;
class UInputAction;
struct FInputActionValue;

UCLASS()
class STRATEGYGAME_API AValPlayerController : public APlayerController
{
	GENERATED_BODY()

public:

	AValPlayerController();

protected:

	virtual void BeginPlay() override;

	virtual void SetupInputComponent() override;


private:

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputMappingContext> ValContext;

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> MoveAction;

	void Move(const FInputActionValue& ActionValue);

	
};
