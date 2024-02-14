// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/ValBaseAnimInstance.h"
#include "Character/ValBaseCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

void UValBaseAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	Character = Cast<AValBaseCharacter>(TryGetPawnOwner());
}

void UValBaseAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	if (Character == nullptr)
	{
		Character = Cast<AValBaseCharacter>(TryGetPawnOwner());
	}

	if (Character == nullptr) return;

	FVector Velocity = Character->GetCharacterMovement()->Velocity;
	Velocity.Z = 0.f;
	GroundSpeed = Velocity.Size();

	bIsInAir = Character->GetCharacterMovement()->IsFalling();



}
