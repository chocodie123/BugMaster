// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "EnemyController.generated.h"

/**
 * 
 */
UCLASS()
class MAGE_API AEnemyController : public AAIController
{
	GENERATED_BODY()
public:
	AEnemyController();
	virtual void OnPossess(APawn* InPawn) override;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	class UBehaviorTree* BehaviorTree;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class ADestination> TargetClass;


};
