# UE4RandomTypo

ARandomTypoEffect *objActor = GetWorld()->SpawnActor<ARandomTypoEffect>();

선언 생성
objActor->RandomTypeStart(*Text.ToString(), 0.05f);

//타이포 변경 이벤트 
objActor->RandomTypoChaged.BindUObject(this, &URandomTextWidget::RandomTypoChanged , TextObj);
AActor* actorObj = Cast<AActor>(objActor);


//타이포 변경 완료 이벤트
objActor->RandomTypoCompleted.BindUObject(this, &URandomTextWidget::RandomTypoCompleted, TextObj , actorObj);
