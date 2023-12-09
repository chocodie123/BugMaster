// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "BeetleAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class MAGE_API UBeetleAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
public:

	virtual void NativeInitializeAnimation() override;
	
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

	
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	bool bIsFly;
	
	UFUNCTION()
	void AnimNotify_BeetleGroundAttack();
};
