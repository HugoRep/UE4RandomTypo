// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class RANDOMTYPO_API ARandomTypoEffect : public AActor
{
public:
	ARandomTypoEffect();
	~ARandomTypoEffect();

public:
	void RandomTypeStart(UObject* textObj, FString text, float Speed = 0.03f);

private:
	//Text Random Typo ~ 
	FString GetRandom();

	FString CharAt(FString str, int n, FString ChangeStr);

	UFUNCTION()
	void TimerEvent();
	//void TimerEvent(UObject * TextObject, FString Text);

	float randRange(int min, int max);

private:

	FTimerHandle TimerHandler;

	FTimerDelegate TimerDelegate;

	//���� �ؽ�Ʈ ī��Ʈ
	int RandomTypoCount;

	//�ؽ�Ʈ �ϼ� ī��Ʈ;
	int CompleteTypoCount;

	//�ؽ�Ʈ ��ü ����
	int TextLength;

	FString AppendRandomTypo = "";
};
