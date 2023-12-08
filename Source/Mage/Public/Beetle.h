// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Bug.h"
#include "Beetle.generated.h"

/**
 * 
 */
UCLASS()
class MAGE_API ABeetle : public ABug
{
	GENERATED_BODY()
public:
	ABeetle();
	virtual void BeginPlay() override;
	
	UPROPERTY(EditAnywhere)
	class UProjectileMovementComponent* Projectile;
};
