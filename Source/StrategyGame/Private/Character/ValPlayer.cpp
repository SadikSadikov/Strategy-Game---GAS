// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/ValPlayer.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "PlayerController/ValPlayerState.h"
#include "AbilitySystem/ValAbilitySystemComponent.h"
#include "AbilitySystem/ValAttributeSet.h"

AValPlayer::AValPlayer()
{
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>("CameraBoom");
	CameraBoom->SetupAttachment(GetRootComponent());
	CameraBoom->bUsePawnControlRotation = false;
	CameraBoom->bEnableCameraLag = true;
	CameraBoom->TargetArmLength = 750.f;
	CameraBoom->SetWorldRotation(FRotator(-45.f, 0.f, 0.f));
	CameraBoom->bInheritPitch = false;
	CameraBoom->bInheritRoll = false;
	CameraBoom->bInheritYaw = false;


	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	Camera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	Camera->bUsePawnControlRotation = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 360.f, 0.f);

	/* TODO: Change bConstrainToPlane false..... */
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;
}

void AValPlayer::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	/* Init Ability Actor Info for Server */
	InitAbilityActorInfo();
}


void AValPlayer::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();
	/* Init Ability Actor Info for Client */
	InitAbilityActorInfo();
}

void AValPlayer::InitAbilityActorInfo()
{
	AValPlayerState* ValPlayerState = GetPlayerState<AValPlayerState>();
	check(ValPlayerState);

	ValPlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(ValPlayerState, this);
	AbilitySystemComp = ValPlayerState->GetAbilitySystemComponent();
	AttributeSet = ValPlayerState->GetAttributeSet();
}