// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/ValBaseCharacter.h"


AValBaseCharacter::AValBaseCharacter()
{
 	
	PrimaryActorTick.bCanEverTick = false;

	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	Weapon->SetupAttachment(GetMesh(), FName("WeaponSocket"));
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);

}

UAbilitySystemComponent* AValBaseCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComp;
}

void AValBaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}


