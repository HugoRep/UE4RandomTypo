// Fill out your copyright notice in the Description page of Project Settings.


#include "RandomTypoEffect.h"
#include "TimerManager.h"
//#include "MultiLineEditableText.h"
//#include "ScrollBox.h"
//#include "TextBlock.h"
//#include "EditableText.h"
#include "UObject.h"
#include "TextBlock.h"
#include "Kismet/GameplayStatics.h"



RandomTypoEffect::RandomTypoEffect()
{
	UE_LOG(LogTemp, Warning, TEXT("teste"));
}

RandomTypoEffect::~RandomTypoEffect()
{

}

void RandomTypoEffect::RandomTypeStart(UObject* TextObj, FString Text, float Speed)
{
	UE_LOG(LogTemp, Warning, TEXT("----------------------------RandomTypeStart----------------------------"));
	Speed = 0.08f;
	RandomTypoCount = 0;
	CompleteTypoCount = 0;

	TextLength = Text.Len();
	TimerDelegate.BindUFunction(this, FName("TimerEvent"), TextObj, Text);
	GetWorld()->GetTimerManager().SetTimer(TimerHandler, TimerDelegate, Speed, true);
}

FString RandomTypoEffect::GetRandom()
{
	FString vaild = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890`-=[]\',./~!@#$%^&*()_+{}|:<>?";
	FString rtnStr = (&vaild.GetCharArray()[FMath::RandRange(0, vaild.Len() - 1)]);
	return FString(1, &rtnStr[0]);
}

FString RandomTypoEffect::CharAt(FString str, int n, FString ChangeStr)
{
	str.RemoveAt(n, 1);
	str.InsertAt(n, ChangeStr);
	return str;
}



void RandomTypoEffect::TimerEvent(UObject* TextObject, FString Text)
{
	if (RandomTypoCount >= TextLength)
	{
		if (CompleteTypoCount >= TextLength)
		{
			GetWorld()->GetTimerManager().ClearTimer(TimerHandler);
			AppendRandomTypo = "";
		}
		else
		{
			FString rsvStr = "";
			rsvStr.AppendChar(Text.GetCharArray()[CompleteTypoCount]);
			for (int i = CompleteTypoCount; i < TextLength; ++i)
			{
				if (i == CompleteTypoCount)
				{
					AppendRandomTypo = CharAt(AppendRandomTypo, CompleteTypoCount, *rsvStr);
				}
				else
				{
					AppendRandomTypo = CharAt(AppendRandomTypo, i, *GetRandom());
				}
			}
			/*UTextBlock* textBlock = Cast<UTextBlock>(TextObject);
			textBlock->SetText(FText::FromString(AppendRandomTypo));*/
		}
		CompleteTypoCount++;
	}
	else
	{
		//UTextBlock* textBlock = Cast<UTextBlock>(TextObject);
		AppendRandomTypo.Append(FString("X"));
		RandomTypoCount++;
	}

	//UE_LOG(LogTemp, Warning, TEXT("%s"), *AppendRandomTypo);
}

float RandomTypoEffect::randRange(int min, int max)
{
	return FMath::Rand()* (max - min + 1) + min;
}