// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/GameModeBase.h"
#include "ExampleGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class EXAMPLEPROJECT_API AExampleGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:

protected:

	virtual void BeginPlay() override;
	virtual void OnPostLogin(AController* NewPlayer) override;
	virtual void Logout(AController* Exiting) override;

private:
	
	UPROPERTY()
	TArray<AController*> AllPlayerControllers;
	
};
