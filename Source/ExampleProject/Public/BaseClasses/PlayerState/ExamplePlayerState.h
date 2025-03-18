// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/PlayerState.h"
#include "ExamplePlayerState.generated.h"

struct FOnAttributeChangeData;
class UPlayerAttributeSet;
class UAbilitySystemComponent;
/**
 * 
 */
UCLASS()
class EXAMPLEPROJECT_API AExamplePlayerState : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:

	AExamplePlayerState();

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	UFUNCTION(BlueprintCallable)
	UPlayerAttributeSet* GetAttributeSet() const;

	UFUNCTION()
	bool IsAlive() const;

	UFUNCTION()
	float GetHealth() const;

	UFUNCTION()
	float GetMaxHealth() const;

	UFUNCTION()
	float GetHealthRegenRate() const;

	UFUNCTION()
	float GetStamina() const;

	UFUNCTION()
	float GetMaxStamina() const;

	UFUNCTION()
	float GetStaminaRegenRate() const;

	UFUNCTION()
	float GetMana() const;

	UFUNCTION()
	float GetMaxMana() const;

	UFUNCTION()
	float GetManaRegenRate() const;

	UFUNCTION()
	float GetMoveSpeed() const;

protected:

	UPROPERTY()
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY()
	TObjectPtr<UPlayerAttributeSet> AttributeSet;

	// FGameplayTag DeadTag;

	FDelegateHandle HealthChangedDelegateHandle;
	FDelegateHandle MaxHealthChangedDelegateHandle;
	FDelegateHandle HealthRegenRateChangedDelegateHandle;
	FDelegateHandle StaminaChangedDelegateHandle;
	FDelegateHandle MaxStaminaChangedDelegateHandle;
	FDelegateHandle StaminaRegenRateChangedDelegateHandle;
	FDelegateHandle ManaChangedDelegateHandle;
	FDelegateHandle MaxManaChangedDelegateHandle;
	FDelegateHandle ManaRegenRateChangedDelegateHandle;

	virtual void BeginPlay() override;

	virtual void HealthChanged(const FOnAttributeChangeData& Data);
	virtual void MaxHealthChanged(const FOnAttributeChangeData& Data);
	virtual void HealthRegenRateChanged(const FOnAttributeChangeData& Data);
	virtual void ManaChanged(const FOnAttributeChangeData& Data);
	virtual void MaxManaChanged(const FOnAttributeChangeData& Data);
	virtual void ManaRegenRateChanged(const FOnAttributeChangeData& Data);
	virtual void StaminaChanged(const FOnAttributeChangeData& Data);
	virtual void MaxStaminaChanged(const FOnAttributeChangeData& Data);
	virtual void StaminaRegenRateChanged(const FOnAttributeChangeData& Data);
	
};
