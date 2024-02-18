// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/ValAttributeSet.h"
#include "AbilitySystemComponent.h"
#include <Net/UnrealNetwork.h>

UValAttributeSet::UValAttributeSet()
{
}

void UValAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(UValAttributeSet, Health, COND_None, REPNOTIFY_Always);

	DOREPLIFETIME_CONDITION_NOTIFY(UValAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);

	DOREPLIFETIME_CONDITION_NOTIFY(UValAttributeSet, Mana, COND_None, REPNOTIFY_Always);

	DOREPLIFETIME_CONDITION_NOTIFY(UValAttributeSet, MaxMana, COND_None, REPNOTIFY_Always);
}

void UValAttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UValAttributeSet, Health, OldHealth);
}

void UValAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UValAttributeSet, MaxHealth, OldMaxHealth);
}

void UValAttributeSet::OnRep_Mana(const FGameplayAttributeData& OldMana) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UValAttributeSet, Mana, OldMana);
}

void UValAttributeSet::OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UValAttributeSet, MaxMana, OldMaxMana);
}
