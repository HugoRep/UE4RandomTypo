# UE4RandomTypo


<img src="./Typo.png">

<<<<<<< HEAD
######ProjectName.Build.cs
=======
##Setting 
>>>>>>> d0944af35352ba2181bcba6b04c496cfeb780d66


## Add Random Typo


<<<<<<< HEAD
####PublicDependencyModuleNames.AddRange(new string[] { 
####"Core", "CoreUObject", "Engine", "InputCore", "RandomTypo" 
####});
=======

PublicDependencyModuleNames.AddRange(new string[] { 
"Core", "CoreUObject", "Engine", "InputCore", "RandomTypo" 
});
>>>>>>> d0944af35352ba2181bcba6b04c496cfeb780d66
  
 
  
####Text : 변경될 텍스트
####Speed : 랜덤 텍스트 모션 스피드
 ####RandomTypeStart(FString Text, float Speed)


####타이포 변경 델리게이트

####RandomTypoChaged

####타이포 변경 완료 델리게이트 

####RandomTypoCompleted



<<<<<<< HEAD

####EX)
=======
 
EX)
>>>>>>> d0944af35352ba2181bcba6b04c496cfeb780d66

####ARandomTypoEffect *objActor = GetWorld()->SpawnActor<ARandomTypoEffect>();
####objActor->RandomTypeStart(*Text.ToString(), 0.05f);
####AActor* actorObj = Cast<AActor>(objActor);  
####objActor->RandomTypoChaged.BindUObject(this, &URandomTextWidget::RandomTypoChanged , TextObj);
####objActor->RandomTypoCompleted.BindUObject(this, &URandomTextWidget::RandomTypoCompleted, TextObj , actorObj);
