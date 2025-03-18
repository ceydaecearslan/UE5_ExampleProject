// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseClasses/HUD/ExampleHUD.h"

#include "UI/HUD/HUDWidget.h"

void AExampleHUD::BeginPlay()
{
	Super::BeginPlay();

	if (HUDWidgetClass)
	{
		UHUDWidget* HUDWidget = CreateWidget<UHUDWidget>(GetWorld(), HUDWidgetClass);

		if (HUDWidget)
		{
			HUDWidget->AddToViewport();
		}
	}
}
