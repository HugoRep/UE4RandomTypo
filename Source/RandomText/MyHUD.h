// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "MyHUD.generated.h"

/**
 * 
 */
UCLASS()
class RANDOMTEXT_API AMyHUD : public AHUD
{
	GENERATED_BODY()

public:
	
	virtual void BeginPlay() override;

public:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class URandomTextWidget* RegisterWidget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class URandomTextWidget> RegisterWidgetClass;
	
};
