// Fill out your copyright notice in the Description page of Project Settings.


#include "MyHUD.h"
#include "RandomTextWidget.h"

void AMyHUD::BeginPlay()
{

	FSoftClassPath RegisterWidgetClass_BP_PATH(TEXT("WidgetBlueprint'/Game/bp/BP_RandomText.BP_RandomText_C'"));


	UClass* RegisterWidgetClass_BP = RegisterWidgetClass_BP_PATH.TryLoadClass<URandomTextWidget>();

	if (RegisterWidgetClass_BP)
	{
		RegisterWidget = CreateWidget<URandomTextWidget>(GetWorld(), RegisterWidgetClass_BP);
		if (RegisterWidget)
		{
			RegisterWidget->AddToViewport();
		}
	}
}
