// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TimerManager.h"
#include "RandomTypoEffect.generated.h"

DECLARE_DELEGATE_OneParam(FRandomTypoChanged, const FString&)
DECLARE_DELEGATE(FRandomTypoCompleted)

UCLASS()
class RANDOMTYPO_API ARandomTypoEffect : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARandomTypoEffect();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	void RandomTypeStart(FString Text, float SpeedValue, FString StartStr);

	FRandomTypoChanged RandomTypoChaged;

	FRandomTypoCompleted RandomTypoCompleted;

private:

	FString GetRandom();

	FString CharAt(FString str, int n, FString ChangeStr);

	UFUNCTION()
	void TimerEvent();

	float randRange(int min, int max);
private:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	FTimerHandle TimerHandler;

	FTimerDelegate TimerDelegate;

	
	//���� �ؽ�Ʈ ī��Ʈ
	int RandomTypoCount;

	float Speed;

	//�ؽ�Ʈ �ϼ� ī��Ʈ;
	int CompleteTypoCount;

	//�ؽ�Ʈ ��ü ����
	int TextLength;

	FString RandomTypoStr;

	FString StartString;

	FString AppendRandomTypo;

};
