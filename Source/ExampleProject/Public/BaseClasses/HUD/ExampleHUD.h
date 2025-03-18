// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/HUD.h"
#include "ExampleHUD.generated.h"

class UHUDWidget;
/**
 * 
 */
UCLASS()
class EXAMPLEPROJECT_API AExampleHUD : public AHUD
{
	GENERATED_BODY()

protected:

	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category= "Initialize | HUD")
	TSubclassOf<UHUDWidget> HUDWidgetClass;
	
};
