// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/SGBaseAnimInstance.h"
#include "Character/SGBaseCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

void USGBaseAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	Character = Cast<ASGBaseCharacter>(TryGetPawnOwner());
}

void USGBaseAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	if (Character == nullptr)
	{
		Character = Cast<ASGBaseCharacter>(TryGetPawnOwner());
	}

	if (Character == nullptr) return;

	FVector Velocity = Character->GetCharacterMovement()->Velocity;
	Velocity.Z = 0.f;
	GroundSpeed = Velocity.Size();

	bIsInAir = Character->GetCharacterMovement()->IsFalling();



}
