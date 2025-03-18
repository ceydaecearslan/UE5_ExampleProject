// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CharacterBase.h"
#include "AbilitySystemInterface.h"
#include "GameplayAbilitySystem/PlayerAttributeSet.h"
#include "PlayerCharacter.generated.h"

class AExamplePlayerController;
struct FInputActionValue;
class UInputAction;
class UInputMappingContext;

UCLASS()
class EXAMPLEPROJECT_API APlayerCharacter : public ACharacterBase, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	
	APlayerCharacter();

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override
	{
		return AbilitySystemComponent;
	}
	
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const
	{
		return SpringArmComponent;
	}
	FORCEINLINE class UCameraComponent* GetFollowCamera() const
	{
		return CameraComponent;
	}

protected:
	
	virtual void BeginPlay() override;
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
	void Sprint(const FInputActionValue& Value);
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Initialize | Input")
	UInputMappingContext* DefaultMappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Initialize | Input")
	UInputAction* JumpAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Initialize | Input")
	UInputAction* MoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Initialize | Input")
	UInputAction* LookAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Initialize | Input")
	UInputAction* SprintAction;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	USpringArmComponent* SpringArmComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UCameraComponent* CameraComponent;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Initialize | GAS")
	TObjectPtr<UPlayerAttributeSet> AttributeSet;

private:
	
	UPROPERTY()
	TObjectPtr<AExamplePlayerController> PlayerController;

	bool bIsSprinting = false;
	
};
