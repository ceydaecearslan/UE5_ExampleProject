// Fill out your copyright notice in the Description page of Project Settings.


#include "ExampleProject/Public/BaseClasses/GameMode/ExampleGameModeBase.h"

void AExampleGameModeBase::BeginPlay()
{
	Super::BeginPlay();
}

void AExampleGameModeBase::OnPostLogin(AController* NewPlayer)
{
	Super::OnPostLogin(NewPlayer);
	AllPlayerControllers.Add(NewPlayer);
}

void AExampleGameModeBase::Logout(AController* Exiting)
{
	Super::Logout(Exiting);
	AllPlayerControllers.Remove(Exiting);
}
