// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "BugController.generated.h"

/**
 * 
 */
UCLASS()
class MAGE_API ABugController : public AAIController
{
	GENERATED_BODY()
public:
	virtual void OnPossess(APawn* InPawn) override;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	class UBehaviorTree* BehaviorTree;
};
