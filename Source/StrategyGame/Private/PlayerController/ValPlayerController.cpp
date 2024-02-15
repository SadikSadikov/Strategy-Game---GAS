// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerController/ValPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"

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

	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;

	FInputModeGameAndUI InputMode;
	InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputMode.SetHideCursorDuringCapture(true);
	SetInputMode(InputMode);

}

void AValPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);

	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AValPlayerController::Move);

}

void AValPlayerController::Move(const FInputActionValue& ActionValue)
{
	FVector2D InputAxisVector = ActionValue.Get<FVector2D>();

	FRotator Rotation = GetControlRotation();
	FRotator FowradRotation = FRotator(0, Rotation.Yaw, 0);

	FVector ForwardDirection = FRotationMatrix(FowradRotation).GetUnitAxis(EAxis::X);
	FVector RightDirection = FRotationMatrix(FowradRotation).GetUnitAxis(EAxis::Y);

	if (APawn* ControlledPawn = GetPawn<APawn>())
	{
		ControlledPawn->AddMovementInput(ForwardDirection, InputAxisVector.Y);
		ControlledPawn->AddMovementInput(RightDirection, InputAxisVector.X);
	}

}
