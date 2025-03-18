// Fill out your copyright notice in the Description page of Project Settings.


#include "ExampleProject/Public/BaseClasses/PlayerController/ExamplePlayerController.h"

void AExamplePlayerController::BeginPlay()
{
	Super::BeginPlay();
	SetInputMode(FInputModeGameOnly());
}
