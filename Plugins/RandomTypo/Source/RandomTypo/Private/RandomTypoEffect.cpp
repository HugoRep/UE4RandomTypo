// Fill out your copyright notice in the Description page of Project Settings.


#include "RandomTypoEffect.h"
#include "UObject.h"
#include "TextBlock.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"

// Sets default values
ARandomTypoEffect::ARandomTypoEffect()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned

void ARandomTypoEffect::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARandomTypoEffect::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


void ARandomTypoEffect::RandomTypeStart(FString Text, float SpeedValue , FString StartStr)
{
	UE_LOG(LogTemp, Warning, TEXT("---------------------------- Random Type Start ----------------------------"));

	Speed = SpeedValue;
	RandomTypoCount = 0;
	CompleteTypoCount = 0;
	StartString = StartStr;
	RandomTypoStr = Text;
	TextLength = Text.Len();
	
	GetWorld()->GetTimerManager().SetTimer(TimerHandler, this, &ARandomTypoEffect::TimerEvent, Speed, true);
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

void ARandomTypoEffect::TimerEvent()
{
	if (RandomTypoCount >= TextLength)
	{
		if (CompleteTypoCount >= TextLength)
		{
			GetWorld()->GetTimerManager().ClearTimer(TimerHandler);
			RandomTypoCompleted.ExecuteIfBound();
		}
		else
		{
			FString rsvStr = "";
			rsvStr.AppendChar(RandomTypoStr.GetCharArray()[CompleteTypoCount]);
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
		}
		CompleteTypoCount++;
	}
	else
	{
		AppendRandomTypo.Append(FString(StartString));
		RandomTypoCount++;
	}
	
	RandomTypoChaged.ExecuteIfBound( *AppendRandomTypo);
}

float ARandomTypoEffect::randRange(int min, int max)
{
	return FMath::Rand()* (max - min + 1) + min;
}