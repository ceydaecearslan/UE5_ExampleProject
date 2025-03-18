// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseClasses/PlayerState/ExamplePlayerState.h"

#include "GameplayAbilitySystem/PlayerAttributeSet.h"

AExamplePlayerState::AExamplePlayerState()
{
	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	AbilitySystemComponent->SetIsReplicated(true);

	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	AttributeSet = CreateDefaultSubobject<UPlayerAttributeSet>(TEXT("AttributeSet"));
}

UAbilitySystemComponent* AExamplePlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

UPlayerAttributeSet* AExamplePlayerState::GetAttributeSet() const
{
	return AttributeSet;
}

bool AExamplePlayerState::IsAlive() const
{
	return GetHealth() > 0.0f;
}

float AExamplePlayerState::GetHealth() const
{
	return AttributeSet->GetHealth();
}

float AExamplePlayerState::GetMaxHealth() const
{
	return AttributeSet->GetMaxHealth();
}

float AExamplePlayerState::GetHealthRegenRate() const
{
	return AttributeSet->GetHealthRegenRate();
}

float AExamplePlayerState::GetStamina() const
{
	return AttributeSet->GetStamina();
}

float AExamplePlayerState::GetMaxStamina() const
{
	return AttributeSet->GetMaxStamina();
}

float AExamplePlayerState::GetStaminaRegenRate() const
{
	return AttributeSet->GetStaminaRegenRate();
}

float AExamplePlayerState::GetMana() const
{
	return AttributeSet->GetMana();
}

float AExamplePlayerState::GetMaxMana() const
{
	return AttributeSet->GetMaxMana();
}

float AExamplePlayerState::GetManaRegenRate() const
{
	return AttributeSet->GetManaRegenRate();
}

float AExamplePlayerState::GetMoveSpeed() const
{
	return AttributeSet->GetMoveSpeed();
}

void AExamplePlayerState::BeginPlay()
{
	Super::BeginPlay();

	if (AbilitySystemComponent)
	{
		HealthChangedDelegateHandle = AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AttributeSet->GetHealthAttribute()).AddUObject(this, &AExamplePlayerState::HealthChanged);
		MaxHealthChangedDelegateHandle = AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AttributeSet->GetMaxHealthAttribute()).AddUObject(this, &AExamplePlayerState::MaxHealthChanged);
		HealthRegenRateChangedDelegateHandle = AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AttributeSet->GetHealthRegenRateAttribute()).AddUObject(this, &AExamplePlayerState::HealthRegenRateChanged);
		StaminaChangedDelegateHandle = AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AttributeSet->GetStaminaAttribute()).AddUObject(this, &AExamplePlayerState::StaminaChanged);
		MaxStaminaChangedDelegateHandle = AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AttributeSet->GetMaxStaminaAttribute()).AddUObject(this, &AExamplePlayerState::MaxStaminaChanged);
		StaminaRegenRateChangedDelegateHandle = AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AttributeSet->GetStaminaRegenRateAttribute()).AddUObject(this, &AExamplePlayerState::StaminaRegenRateChanged);
		ManaChangedDelegateHandle = AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AttributeSet->GetManaAttribute()).AddUObject(this, &AExamplePlayerState::ManaChanged);
		MaxManaChangedDelegateHandle = AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AttributeSet->GetMaxManaAttribute()).AddUObject(this, &AExamplePlayerState::MaxManaChanged);
		ManaRegenRateChangedDelegateHandle = AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AttributeSet->GetManaRegenRateAttribute()).AddUObject(this, &AExamplePlayerState::ManaRegenRateChanged);
	}
}
void AExamplePlayerState::HealthChanged(const FOnAttributeChangeData & Data)
{
	float Health = Data.NewValue;
	// If the player died, handle death
	if (!IsAlive()) // && !AbilitySystemComponent->HasMatchingGameplayTag(DeadTag))
	{
		// Call die function
	}
}

void AExamplePlayerState::MaxHealthChanged(const FOnAttributeChangeData & Data)
{
	float MaxHealth = Data.NewValue;
}

void AExamplePlayerState::HealthRegenRateChanged(const FOnAttributeChangeData & Data)
{
	float HealthRegenRate = Data.NewValue;
}

void AExamplePlayerState::StaminaChanged(const FOnAttributeChangeData & Data)
{
	float Stamina = Data.NewValue;

	// Update the HUD
	// Handled in the UI itself using the AsyncTaskAttributeChanged node as an example how to do it in Blueprint
}

void AExamplePlayerState::MaxStaminaChanged(const FOnAttributeChangeData & Data)
{
	float MaxStamina = Data.NewValue;
}

void AExamplePlayerState::StaminaRegenRateChanged(const FOnAttributeChangeData & Data)
{
	float StaminaRegenRate = Data.NewValue;
}

void AExamplePlayerState::ManaChanged(const FOnAttributeChangeData & Data)
{
	float Mana = Data.NewValue;
	// Update the HUD
	// Handled in the UI itself using the AsyncTaskAttributeChanged node as an example how to do it in Blueprint
}

void AExamplePlayerState::MaxManaChanged(const FOnAttributeChangeData & Data)
{
	float MaxMana = Data.NewValue;

}

void AExamplePlayerState::ManaRegenRateChanged(const FOnAttributeChangeData & Data)
{
	float ManaRegenRate = Data.NewValue;
}