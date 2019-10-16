// Fill out your copyright notice in the Description page of Project Settings.

#include "RandomTextWidget.h"
#include "TimerManager.h"
#include "MultiLineEditableText.h"
#include "ScrollBox.h"
#include "TextBlock.h"
#include "EditableText.h"
#include "UObject.h"
#include "Kismet/GameplayStatics.h"



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

void URandomTextWidget::RandomTypeStart(UObject* textObj, FString text , float Speed = 0.03f)
{
	Speed = 0.08f;
	CurrentCount = 0;
	CurrentTypoCount = 0;

	TextLen = text.Len();
	TimerDel.BindUFunction(this, FName("TimerEvent"), textObj , text);
	//GetWorld()->GetTimerManager().SetTimer(ObjectCheckTimer, this, &URandomTextWidget::TimerEvent, Speed, true);
	GetWorld()->GetTimerManager().SetTimer(ObjectCheckTimer, TimerDel, Speed, true);
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
			
			
			ScrollBox->AddChild(NewBlock);
			ScrollBox->ScrollToEnd();
			
			UObject* textObj = Cast<UObject>(NewBlock);
			RandomTypeStart(textObj, *Text.ToString(), 0.03f);
			
		}
	}
}


FString URandomTextWidget::GetRandom() 
{
	FString vaild = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890`-=[]\',./~!@#$%^&*()_+{}|:<>?";
	FString rtnStr = (&vaild.GetCharArray()[FMath::RandRange(0, vaild.Len()-1)]);
	return FString(1, &rtnStr[0]);
}

FString URandomTextWidget::CharAt(FString Str , int n , FString ChangeString)
{
	Str.RemoveAt(n, 1);
	Str.InsertAt(n , ChangeString);	
	return Str;
}


void URandomTextWidget::TimerEvent(UObject* TextObject, FString Text)
{
	if (CurrentCount >= TextLen)
	{
		if (CurrentTypoCount >= TextLen)
		{
			GetWorld()->GetTimerManager().ClearTimer(ObjectCheckTimer);
			AppendRandomText = "";
		}
		else
		{
			FString rsvStr = "";
			rsvStr.AppendChar(Text.GetCharArray()[CurrentTypoCount]);
			for (int i = CurrentTypoCount; i < TextLen; ++i)
			{
				if (i == CurrentTypoCount)
				{
					AppendRandomText = CharAt(AppendRandomText, CurrentTypoCount, *rsvStr);
				}
				else
				{
					AppendRandomText = CharAt(AppendRandomText, i, *GetRandom());
				}
			}
			UTextBlock* textBlock = Cast<UTextBlock>(TextObject);
			//textBlock->SetText(FText::FromString("AAAA"));
			textBlock->SetText(FText::FromString(AppendRandomText));
		}
		CurrentTypoCount++;
	}
	else
	{
		UTextBlock* textBlock = Cast<UTextBlock>(TextObject);
		AppendRandomText.Append(FString("X"));
		textBlock->SetText(FText::FromString(AppendRandomText));
		CurrentCount++;
	}
	
}

float URandomTextWidget::randRange(int min , int max)
{
	return FMath::Rand()* (max - min + 1) + min;
}

