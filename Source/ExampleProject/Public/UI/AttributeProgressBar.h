// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AttributeSet.h"
#include "Blueprint/UserWidget.h"
#include "AttributeProgressBar.generated.h"

struct FOnAttributeChangeData;
class UPlayerAttributeSet;
class UProgressBar;
/**
 * 
 */
UCLASS()
class EXAMPLEPROJECT_API UAttributeProgressBar : public UUserWidget
{
	GENERATED_BODY()

protected:

	virtual void NativePreConstruct() override;
	virtual void NativeConstruct() override;

	void BindUpdateProgressBar(const FOnAttributeChangeData& Data);
	void UpdateProgressBar();
	void BindToAbilitySystem();
	
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<UProgressBar> ProgressBar;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Initialize | Attribute")
	FGameplayAttribute Attribute;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Initialize | Attribute")
	FGameplayAttribute MaxAttribute;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Initialize | Widget")
	FLinearColor BarColor = FLinearColor::White;

	FDelegateHandle AttributeChangeDelegateHandle;

	FDelegateHandle MaxAttributeChangeDelegateHandle;

	UPROPERTY()
	UAbilitySystemComponent* AbilitySystemComponent;
	
};
