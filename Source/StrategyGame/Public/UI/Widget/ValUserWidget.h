// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ValUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class STRATEGYGAME_API UValUserWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable)
	void SetWidgetController(UObject* Controller);

	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UObject> WidgetController;


protected:

	UFUNCTION(BlueprintImplementableEvent)
	void WidgetControllerSet();
	
};
