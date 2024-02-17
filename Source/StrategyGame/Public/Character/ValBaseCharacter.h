// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/Character.h"
#include "ValBaseCharacter.generated.h"

class UAbilitySystemComponent;
class UAttributeSet;

UCLASS(Abstract)
class STRATEGYGAME_API AValBaseCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	
	AValBaseCharacter();

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	UAttributeSet* GetAttributeSet() const { return AttributeSet; }

protected:
	
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USkeletalMeshComponent> Weapon;

	TObjectPtr<UAbilitySystemComponent> AbilitySystemComp;
	TObjectPtr<UAttributeSet> AttributeSet;

private:



};
