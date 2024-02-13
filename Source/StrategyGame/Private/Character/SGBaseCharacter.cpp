// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/SGBaseCharacter.h"


ASGBaseCharacter::ASGBaseCharacter()
{
 	
	PrimaryActorTick.bCanEverTick = false;

	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	Weapon->SetupAttachment(GetMesh(), FName("WeaponSocket"));
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);

}


void ASGBaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}


