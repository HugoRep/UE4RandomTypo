// Fill out your copyright notice in the Description page of Project Settings.

#include "RandomTextWidget.h"
#include "TimerManager.h"
#include "MultiLineEditableText.h"
#include "ScrollBox.h"
#include "TextBlock.h"
#include "EditableText.h"
#include "UObject.h"
#include "RandomTypo.h"
#include "Kismet/GameplayStatics.h"
#include "RandomTypo.h"
#include <RandomTypo.h>
#include "RandomTypoEffect.h"



void URandomTextWidget::NativeConstruct()
{
	Super::NativeConstruct();

	//CharText = Text.GetCharArray().GetData();
	
	RandomText = Cast<UMultiLineEditableText>(GetWidgetFromName(TEXT("RandomText")));
	InpuText = Cast<UEditableText>(GetWidgetFromName(TEXT("InpuText")));
	ScrollBox = Cast<UScrollBox>(GetWidgetFromName(TEXT("ScrollBoxVar")));
	
	//RandomText->SetText(FText::FromString(Text));
	if (InpuText)
	{
		InpuText->OnTextCommitted.AddDynamic(this, &URandomTextWidget::OnTextCommit);
	}
	PC = Cast<APlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	
	PC->bShowMouseCursor = true;
	PC->bEnableClickEvents = true;
	PC->bEnableMouseOverEvents = true;
}


void URandomTextWidget::OnTextCommit(const FText& Text, ETextCommit::Type CommitMethod)
{
	

	switch (CommitMethod)
	{
	case ETextCommit::Type::OnCleared:
	{
		UE_LOG(LogTemp, Warning, TEXT("OnCleared "));
		InpuText->SetUserFocus(PC);
	}
	break;
	case ETextCommit::Type::OnEnter:
	{
	
		UE_LOG(LogTemp, Warning, TEXT("OnEnter"));
		AddMessage(InpuText->GetText());
		InpuText->SetText(FText::FromString(TEXT("")));
	}
	break;
	case ETextCommit::Type::OnUserMovedFocus:
	{

	}
	break;

	}

	
}
void URandomTextWidget::AddMessage(const FText& Text)
{
	UE_LOG(LogTemp, Warning, TEXT("Log message"));
	if (ScrollBox)
	{
		UTextBlock* NewBlock = NewObject<UTextBlock>(ScrollBox);
		//UTextBlock* NewBlock = ConstructObject<UTextBlock>(UTextBlock::StaticClass());
		
		if (NewBlock)
		{
			UE_LOG(LogTemp, Warning, TEXT("Log message"));

			NewBlock->SetText(Text);
			NewBlock->Font.Size = 20;
			NewBlock->SetColorAndOpacity(FSlateColor(FLinearColor::White));
			NewBlock->SetShadowColorAndOpacity(FLinearColor::Black);
			//NewBlock.widg

			ScrollBox->AddChild(NewBlock);
			ScrollBox->ScrollToEnd();
			
			UObject* textObj = Cast<UObject>(NewBlock);
			

			ARandomTypoEffect* obj = NewObject<ARandomTypoEffect>();
			obj->RandomTypeStart(textObj, *Text.ToString(), 0.03f);
			//obj->TimerDelegate = 
			//RandomTypoEffect::RandomTypeStart(textObj, *Text.ToString(), 0.03f);			
		}
	}
}
