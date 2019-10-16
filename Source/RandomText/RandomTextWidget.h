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

	UFUNCTION()
	void RandomTypeStart(UObject* textObj, FString text, float Speed);

	UFUNCTION(BlueprintCallable)
	void OnTextCommit(const FText& Text, ETextCommit::Type CommitMethod);

	UFUNCTION()
	void AddMessage(const FText& Text);

	
	
	FTimerDelegate TimerDel;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class APlayerController* MyController;

private:
	FTimerHandle ObjectCheckTimer;

	int CurrentCount;

	int CurrentTypoCount;

	//TCHAR* CharText;
	
	//FString Text = "TEST RandomTypo .......";

	int TextLen;

	float Speed;

	FString AppendRandomText = "";

	FString ReturnValue = "";

	FString GetRandom();

	FString CharAt(FString Str, int n, FString chageString);

	UFUNCTION()
	void TimerEvent(UObject* TextObject, FString Text);

	float randRange(int min, int max);
};
