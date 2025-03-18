// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlayerControllerBase.h"
#include "ExamplePlayerController.generated.h"

/**
 * 
 */
UCLASS()
class EXAMPLEPROJECT_API AExamplePlayerController : public APlayerControllerBase
{
	GENERATED_BODY()

public:
	
protected:
	
	virtual void BeginPlay() override;

};
