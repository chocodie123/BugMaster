// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy.h"
#include "EnemyHPWidget.h"
#include "Blueprint/UserWidget.h"
#include "Components/WidgetComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/KismetSystemLibrary.h"

// Sets default values
AEnemy::AEnemy()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
	HPComp = CreateDefaultSubobject<UWidgetComponent>(TEXT("HPComp"));
	HPComp->SetupAttachment(RootComponent);
	HPComp->SetRelativeLocation(FVector(0,0,90));
	HPComp->SetVisibility(false);
	
}

// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();
	
	
	
}

// Called every frame
void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if(HPComp)
	{
		HPComp->SetRelativeRotation(UKismetMathLibrary::FindLookAtRotation(GetActorLocation(),GetWorld()->GetFirstPlayerController()->PlayerCameraManager->K2_GetActorLocation())+FRotator(0,90,0));
	}

}

// Called to bind functionality to input
void AEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AEnemy::UpdateHP(const float NewHp)
{
	CurrentHp += NewHp;
}

void AEnemy::Die()
{
	
}

float AEnemy::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator,
                         AActor* DamageCauser)
{
	const float ActualDamage = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);

	CurrentHp -= ActualDamage;
	if(HPComp->GetUserWidgetObject())
	{
		FTimerHandle Handle;
		GetWorldTimerManager().SetTimer(Handle,[this]()
		{
			HPComp->SetVisibility(false);
			
		},1.5f,false);
		HPComp->SetVisibility(true);
		Cast<UEnemyHPWidget>(HPComp->GetUserWidgetObject())->UpdateHP(CurrentHp,MaxHP);
	}
	
	if(CurrentHp<=0)
	{
		Die();
		
	}
	
	return ActualDamage;
	
}

