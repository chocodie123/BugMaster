// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemy.h"
#include "People.generated.h"

/**
 * 
 */
UCLASS()
class MAGE_API APeople : public AEnemy
{
	GENERATED_BODY()

public:
	APeople();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
