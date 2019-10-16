// Fill out your copyright notice in the Description page of Project Settings.


#include "RandomTypoEffect.h"
#include "TimerManager.h"
#include "UObject.h"
#include "TextBlock.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"


ARandomTypoEffect::ARandomTypoEffect()
{
	UE_LOG(LogTemp, Warning, TEXT("teste"));
}

ARandomTypoEffect::~ARandomTypoEffect()
{

}

void ARandomTypoEffect::RandomTypeStart(UObject* TextObj, FString Text, float Speed)
{
	UE_LOG(LogTemp, Warning, TEXT("----------------------------RandomTypeStart----------------------------"));
	Speed = 0.08f;
	RandomTypoCount = 0;
	CompleteTypoCount = 0;

	TextLength = Text.Len();

	//TimerDelegate.BindUFunction(this, FName("TimerEvent"), TextObj, Text);
	//GetWorld()->GetTimerManager().SetTimer(TimerHandler, TimerDelegate, Speed, true);

	/*UKismetSystemLibrary::K2_SetTimerDelegate(FTimerDynamicDelegate::BindUFunction(this, &ARandomTypoEffect::TimerEvent), Speed, true);*/
		//GetWorld()->GetTimerManager().SetTimer(TimerHandler,
	//	this, BindLambda( FTimerDelegate::CreateLambda( []() {
	//})), Speed, true);
}

FString ARandomTypoEffect::GetRandom()
{
	FString vaild = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890`-=[]\',./~!@#$%^&*()_+{}|:<>?";
	FString rtnStr = (&vaild.GetCharArray()[FMath::RandRange(0, vaild.Len() - 1)]);
	return FString(1, &rtnStr[0]);
}

FString ARandomTypoEffect::CharAt(FString str, int n, FString ChangeStr)
{
	str.RemoveAt(n, 1);
	str.InsertAt(n, ChangeStr);
	return str;
}

//void RandomTypoEffect::TimerEvent(UObject* TextObject, FString Text)
void ARandomTypoEffect::TimerEvent()
{

	//UE_LOG(LogTemp, Warning, TEXT("TimerEvent"));

	//if (RandomTypoCount >= TextLength)
	//{
	//	if (CompleteTypoCount >= TextLength)
	//	{
	//		GetWorld()->GetTimerManager().ClearTimer(TimerHandler);
	//		AppendRandomTypo = "";
	//	}
	//	else
	//	{
	//		FString rsvStr = "";
	//		rsvStr.AppendChar(Text.GetCharArray()[CompleteTypoCount]);
	//		for (int i = CompleteTypoCount; i < TextLength; ++i)
	//		{
	//			if (i == CompleteTypoCount)
	//			{
	//				AppendRandomTypo = CharAt(AppendRandomTypo, CompleteTypoCount, *rsvStr);
	//			}
	//			else
	//			{
	//				AppendRandomTypo = CharAt(AppendRandomTypo, i, *GetRandom());
	//			}
	//		}
	//	}
	//	CompleteTypoCount++;
	//}
	//else
	//{
	//	AppendRandomTypo.Append(FString("X"));
	//	RandomTypoCount++;
	//}
}

float ARandomTypoEffect::randRange(int min, int max)
{
	return FMath::Rand()* (max - min + 1) + min;
}