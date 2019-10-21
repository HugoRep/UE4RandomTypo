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
#include "RandomTypoEffect.h"



void URandomTextWidget::NativeConstruct()
{
	Super::NativeConstruct();

	RandomText = Cast<UMultiLineEditableText>(GetWidgetFromName(TEXT("RandomText")));
	InpuText = Cast<UEditableText>(GetWidgetFromName(TEXT("InpuText")));
	ScrollBox = Cast<UScrollBox>(GetWidgetFromName(TEXT("ScrollBoxVar")));
	
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
		InpuText->SetUserFocus(PC);
	}
	break;
	case ETextCommit::Type::OnEnter:
	{
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
	if (ScrollBox)
	{
		UTextBlock* NewBlock = NewObject<UTextBlock>(ScrollBox);
		UObject *TextObj = Cast<UObject>(NewBlock);
		if (NewBlock)
		{
			NewBlock->SetText(Text);
			NewBlock->Font.Size = 20;
			NewBlock->SetColorAndOpacity(FSlateColor(FLinearColor::White));
			NewBlock->SetShadowColorAndOpacity(FLinearColor::Black);
			ScrollBox->AddChild(NewBlock);
			ScrollBox->ScrollToEnd();
	
			ARandomTypoEffect *objActor = GetWorld()->SpawnActor<ARandomTypoEffect>();
			objActor->RandomTypeStart(*Text.ToString(), 0.05f , "X");

			objActor->RandomTypoChaged.BindUObject(this, &URandomTextWidget::RandomTypoChanged , TextObj);

			AActor* actorObj = Cast<AActor>(objActor);
			objActor->RandomTypoCompleted.BindUObject(this, &URandomTextWidget::RandomTypoCompleted, TextObj , actorObj);
		}
	}
}

void URandomTextWidget::RandomTypoChanged(const FString& Text , UObject* TextObj)
{
	UTextBlock *NewBlock = Cast<UTextBlock>(TextObj);
	NewBlock->SetText(FText::FromString(*Text));
}

void URandomTextWidget::RandomTypoCompleted(UObject* TextObj , AActor* obj)
{
	UTextBlock *NewBlock = Cast<UTextBlock>(TextObj);
	//NewBlock->RemoveFromParent();
	//obj->Destroy();	
}