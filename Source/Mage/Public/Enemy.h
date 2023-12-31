// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Enemy.generated.h"

UCLASS()
class MAGE_API AEnemy : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	float MaxHP;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	float CurrentHp;

	UFUNCTION(BlueprintCallable)
	void UpdateHP(float NewHp);
	
	void Die();
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;
	
	UPROPERTY(EditAnywhere)
	class UEnemyHPWidget* HPWidget;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class UEnemyHPWidget> HPWidgetFactory;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	class UWidgetComponent* HPComp;
	
};
