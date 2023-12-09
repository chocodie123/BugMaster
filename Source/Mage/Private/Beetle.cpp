// Fill out your copyright notice in the Description page of Project Settings.


#include "Beetle.h"

#include "Components/CapsuleComponent.h"
#include "Engine/DamageEvents.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/KismetSystemLibrary.h"


ABeetle::ABeetle()
{
	ConstructorHelpers::FObjectFinder<USkeletalMesh> ThisMesh(TEXT("/Script/Engine.SkeletalMesh'/Game/Resource/Beetles/Mesh/Beetle1.Beetle1'"));
	if(ThisMesh.Succeeded())
	{
		GetMesh()->SetSkeletalMesh(ThisMesh.Object);

		GetMesh()->SetRelativeTransform(FTransform(FRotator(0,-90,0),
			FVector(0,0,-90),FVector(3)));
	}

	GetCapsuleComponent()->SetCapsuleHalfHeight(40);
	GetCapsuleComponent()->SetCapsuleRadius(25);
	
	Projectile = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile"));
	Projectile->MaxSpeed = 800;
	Projectile->InitialSpeed = 800;
	Projectile->Bounciness = true;
	Projectile->Velocity = FVector(1.f,0,1.2f);

	InitialLifeSpan = 10;
}

void ABeetle::BeginPlay()
{
	Super::BeginPlay();
	
}

float ABeetle::GroundAttackAnim()
{
	return PlayAnimMontage(GroundAttackMontage);		
}

void ABeetle::GroundAttack()
{
	TArray<FHitResult> Hits;
	UE_LOG(LogTemp,Warning,TEXT("2"));
	bool bTraceHit = UKismetSystemLibrary::SphereTraceMulti(GetWorld(),GetActorLocation(),GetActorLocation(),150,TraceTypeQuery1,
		false,TArray<AActor*>(),EDrawDebugTrace::ForOneFrame,Hits,true);

	if(bTraceHit)
	{
	UE_LOG(LogTemp,Warning,TEXT("3"));
		for (const auto Item : Hits)
		{
			UE_LOG(LogTemp,Warning,TEXT("4"));
			if (ACharacter* Character = Cast<ACharacter>(Item.GetActor()))
			{
				UE_LOG(LogTemp,Warning,TEXT("5"));
				Cast<ACharacter>(Item.GetActor())->LaunchCharacter(FVector(20,0,100),false,false);
				Item.GetActor()->TakeDamage(20,FDamageEvent(),nullptr,nullptr);
			}
		}
		
	}
}
