// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerController/ValPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Interaction/ValEnemyHighlightInterface.h"

AValPlayerController::AValPlayerController()
{
	bReplicates = true;
}

void AValPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

	CursorTrace();
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

void AValPlayerController::CursorTrace()
{
	FHitResult CursorHit;
	GetHitResultUnderCursor(ECollisionChannel::ECC_Visibility, false, CursorHit);

	if (!CursorHit.bBlockingHit) return;

	LastActor = ThisActor;
	ThisActor = Cast<IValEnemyHighlightInterface>(CursorHit.GetActor());

	/*
	* Line Trace under cursor. There are several scenarios
	* A. LastActor is null ThisActor is null
	*	- Do nothing
	* B. LastActor is null ThisActor is valid
	*	- Highlight ThisActor
	* C. LastActor is valid ThisActor is null
	*	- UnHighlight LastActor
	* D. Both actors are valid, but LastActor != ThisActor
	*	- UnHighlight LastActor and Highlight ThisActor
	* E. Both actors are valid, and LastActor == ThisActor
	*	- Do nothing
	*/

	if (LastActor == nullptr)
	{
		if (ThisActor != nullptr) 
		{
			// Case B
			ThisActor->Highlight();
		}

	}
	else //  LastActor is Valid
	{
		if (ThisActor == nullptr)
		{
			// Case C
			LastActor->UnHighlight();
		}
		else
		{
			if (LastActor != ThisActor)
			{
				// Case D
				LastActor->UnHighlight();
				ThisActor->Highlight();
			}
		}
	}
}
