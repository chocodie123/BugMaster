// Fill out your copyright notice in the Description page of Project Settings.


#include "BeetleAnimInstance.h"

#include "Beetle.h"
#include "BugInfo.h"


void UBeetleAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
}

void UBeetleAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	ABeetle* OwnerBeetle = Cast<ABeetle>(TryGetPawnOwner());
	if(OwnerBeetle)
	{
		if (OwnerBeetle->BugInfoComponent && OwnerBeetle->BugInfoComponent->bFlying)
		{
			bIsFly = true;
		}
		else
		{
			bIsFly = false;
		}
	}

}

void UBeetleAnimInstance::AnimNotify_BeetleGroundAttack() const
{
	Cast<ABeetle>(TryGetPawnOwner())->GroundAttack();
}

