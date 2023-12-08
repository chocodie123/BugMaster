// Fill out your copyright notice in the Description page of Project Settings.


#include "BugController.h"

void ABugController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	if(BehaviorTree)
	{
		RunBehaviorTree(BehaviorTree);
	}
}
