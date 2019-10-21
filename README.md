# UE4 RandomTypo

<img src="./Gif_Sample.gif">

### 
### Setting ProjectName.Build.cs
### 
```
PublicDependencyModuleNames.AddRange(new string[] { 
"Core", "CoreUObject", "Engine", "InputCore", "RandomTypo" 
});
```

### RandomTypeStart(FString Text, float Speed, FString StartStr)

###### Text : 변경될 텍스트.
###### Speed : 랜덤 텍스트 모션 스피드.
###### StartStr : 초기 텍스트 입력값


##### 타이포 변경 델리게이트
###### RandomTypoChanged

##### 타이포 변경 완료 델리게이트

###### RandomTypoCompleted

### EX)

```ARandomTypoEffect *objActor = GetWorld()->SpawnActor<ARandomTypoEffect>();
objActor->RandomTypeStart(*Text.ToString(), 0.05f, "X" );
AActor* actorObj = Cast<AActor>(objActor);  
objActor->RandomTypoChaged.BindUObject(this, &URandomTextWidget::RandomTypoChanged , TextObj);
objActor->RandomTypoCompleted.BindUObject(this, &URandomTextWidget::RandomTypoCompleted, TextObj , actorObj);```

