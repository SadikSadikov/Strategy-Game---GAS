// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerController/ValPlayerState.h"
#include "AbilitySystem/ValAbilitySystemComponent.h"
#include "AbilitySystem/ValAttributeSet.h"

AValPlayerState::AValPlayerState()
{
	NetUpdateFrequency = 100.f;

	AbilitySystemComp = CreateDefaultSubobject<UValAbilitySystemComponent>("AbilitySytemComponent");
	AbilitySystemComp->SetIsReplicated(true);
	AbilitySystemComp->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	AttributeSet = CreateDefaultSubobject<UValAttributeSet>("Attribute Set");
}

UAbilitySystemComponent* AValPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComp;
}
