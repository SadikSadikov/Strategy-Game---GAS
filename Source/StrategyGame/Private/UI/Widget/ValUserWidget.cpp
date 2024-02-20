// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widget/ValUserWidget.h"

void UValUserWidget::SetWidgetController(UObject* Controller)
{
	WidgetController = Controller;

	WidgetControllerSet();
}
