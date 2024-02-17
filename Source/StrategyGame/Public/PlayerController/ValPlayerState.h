// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/PlayerState.h"
#include "ValPlayerState.generated.h"

class UAbilitySystemComponent;
class UAttributeSet;

UCLASS()
class STRATEGYGAME_API AValPlayerState : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:

	AValPlayerState();

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	UAttributeSet* GetAttributeSet() const { return AttributeSet; }


protected:

	TObjectPtr<UAbilitySystemComponent> AbilitySystemComp;
	TObjectPtr<UAttributeSet> AttributeSet;
	
};
