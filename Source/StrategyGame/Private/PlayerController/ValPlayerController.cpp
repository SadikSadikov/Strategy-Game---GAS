// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerController/ValPlayerController.h"
#include "EnhancedInputSubsystems.h"

AValPlayerController::AValPlayerController()
{
	bReplicates = true;
}

void AValPlayerController::BeginPlay()
{
	Super::BeginPlay();

	check(ValContext);

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	check(Subsystem);

	Subsystem->AddMappingContext(ValContext, 0);

	FInputModeGameAndUI InputMode;
	InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputMode.SetHideCursorDuringCapture(false);
	SetInputMode(InputMode);

}
