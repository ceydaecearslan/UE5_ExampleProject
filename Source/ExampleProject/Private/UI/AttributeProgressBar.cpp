// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/AttributeProgressBar.h"

#include "GameplayEffectTypes.h"
#include "AbilitySystemComponent.h"
#include "BaseClasses/Character/PlayerCharacter.h"
#include "Components/ProgressBar.h"

void UAttributeProgressBar::NativePreConstruct()
{
	Super::NativePreConstruct();
	
	if (ProgressBar)
	{
		ProgressBar->SetFillColorAndOpacity(BarColor);
	}
}

void UAttributeProgressBar::NativeConstruct()
{
	Super::NativeConstruct();
	
	APlayerCharacter* PlayerCharacter = Cast<APlayerCharacter>(GetOwningPlayerPawn());
	if (!PlayerCharacter) return;
	AbilitySystemComponent = PlayerCharacter->GetAbilitySystemComponent();
	if (!AbilitySystemComponent) return;
	BindToAbilitySystem();
	UpdateProgressBar();
}

void UAttributeProgressBar::BindUpdateProgressBar(const FOnAttributeChangeData& Data)
{
	UpdateProgressBar();
}

void UAttributeProgressBar::UpdateProgressBar()
{
	float NewValue = 0.0f;
	float MaxValue = 0.0f;

	NewValue = AbilitySystemComponent->GetNumericAttribute(Attribute);
	MaxValue = AbilitySystemComponent->GetNumericAttribute(MaxAttribute);
	
	if (ProgressBar && MaxValue > 0.0f)
	{
		ProgressBar->SetPercent(NewValue / MaxValue);
	}
}

void UAttributeProgressBar::BindToAbilitySystem()
{
	if (Attribute.IsValid())
	{
		AttributeChangeDelegateHandle = AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(Attribute).AddUObject(this, &UAttributeProgressBar::BindUpdateProgressBar);
	}
	if (MaxAttribute.IsValid())
	{
		AttributeChangeDelegateHandle = AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(MaxAttribute).AddUObject(this, &UAttributeProgressBar::BindUpdateProgressBar);
	}
}
