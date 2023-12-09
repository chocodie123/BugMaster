// Fill out your copyright notice in the Description page of Project Settings.


#include "BeetleGroundAttack.h"

#include "AIController.h"
#include "Beetle.h"

EBTNodeResult::Type UBeetleGroundAttack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	EBTNodeResult::Type Result = EBTNodeResult::Failed;		
	APawn* AIPawn = OwnerComp.GetAIOwner()->GetPawn();
	ABeetle* AIBeetle = Cast<ABeetle>(AIPawn);
	if(AIBeetle)
	{
		UE_LOG(LogTemp,Warning,TEXT("1"));
		float Time = AIBeetle->GroundAttackAnim();
		FTimerHandle Handle;
		GetWorld()->GetTimerManager().SetTimer(Handle,[this]()
		{},Time,false);
		
		return EBTNodeResult::Succeeded;
	}
	
	return Result;
}
