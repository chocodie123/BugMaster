// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyController.h"
#include "Destination.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"

AEnemyController::AEnemyController()
{
	
}

void AEnemyController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	if(BehaviorTree)
	{
		RunBehaviorTree(BehaviorTree);
	}
	if(TargetClass)
	{
		GetBlackboardComponent()->SetValueAsObject("Target",UGameplayStatics::GetActorOfClass(GetWorld(),TargetClass));
	}
}
