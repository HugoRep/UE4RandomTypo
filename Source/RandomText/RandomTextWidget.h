// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

#include "RandomTextWidget.generated.h"

/**
 * 
 */
UCLASS()
class RANDOMTEXT_API URandomTextWidget : public UUserWidget
{
	GENERATED_BODY()


public:
	class UMultiLineEditableText* RandomText;

	class UEditableText* InpuText;

	class UScrollBox* ScrollBox;

	class APlayerController* PC;

	virtual void NativeConstruct() override;

	

	UFUNCTION(BlueprintCallable)
	void OnTextCommit(const FText& Text, ETextCommit::Type CommitMethod);

	UFUNCTION()
	void AddMessage(const FText& Text);

	void RandomTypoChanged(const FString & Text, UObject* TextObj);

	void RandomTypoCompleted(UObject* TextObj , AActor * obj);


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class APlayerController* MyController;

};
