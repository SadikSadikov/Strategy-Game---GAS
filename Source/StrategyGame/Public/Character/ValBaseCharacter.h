// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ValBaseCharacter.generated.h"

UCLASS(Abstract)
class STRATEGYGAME_API AValBaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	
	AValBaseCharacter();

protected:
	
	virtual void BeginPlay() override;

	TObjectPtr<USkeletalMeshComponent> Weapon;

private:



};
