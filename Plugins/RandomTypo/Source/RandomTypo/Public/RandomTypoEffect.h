// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class RANDOMTYPO_API RandomTypoEffect : public AActor
{
public:
	RandomTypoEffect();
	~RandomTypoEffect();

public:
	void RandomTypeStart(UObject* textObj, FString text, float Speed = 0.03f);

private:
	//Text Random Typo ~ 
	FString GetRandom();

	FString CharAt(FString str, int n, FString ChangeStr);

	void TimerEvent(UObject * TextObject, FString Text);

	float randRange(int min, int max);

private:

	FTimerHandle TimerHandler;

	FTimerDelegate TimerDelegate;

	//랜덤 텍스트 카운트
	int RandomTypoCount;

	//텍스트 완성 카운트;
	int CompleteTypoCount;

	//텍스트 전체 길이
	int TextLength;

	FString AppendRandomTypo = "";




};
