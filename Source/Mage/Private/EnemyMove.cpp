// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyMove.h"

#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"


EBTNodeResult::Type UEnemyMove::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	const EBTNodeResult::Type Result = EBTNodeResult::Failed;

	if(OwnerComp.GetAIOwner() && OwnerComp.GetAIOwner()->GetPawn())
	{
		
		UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
		AActor* TargetActor = Cast<AActor>(BlackboardComp->GetValueAsObject("Target"));

		
		if(TargetActor)
		{
	
			OwnerComp.GetAIOwner()->MoveToActor(TargetActor,10);
			return EBTNodeResult::Succeeded;
		}
		
	}
	
	return Result;
}
