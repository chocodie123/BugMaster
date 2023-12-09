// Fill out your copyright notice in the Description page of Project Settings.


#include "BeetleAnimInstance.h"

#include "Beetle.h"


void UBeetleAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
}

void UBeetleAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
}

void UBeetleAnimInstance::AnimNotify_BeetleGroundAttack()
{
	Cast<ABeetle>(TryGetPawnOwner())->GroundAttack();
}

