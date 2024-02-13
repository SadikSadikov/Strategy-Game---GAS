// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SGBaseCharacter.generated.h"

UCLASS(Abstract)
class STRATEGYGAME_API ASGBaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	
	ASGBaseCharacter();

protected:
	
	virtual void BeginPlay() override;

	TObjectPtr<USkeletalMeshComponent> Weapon;

private:



};
