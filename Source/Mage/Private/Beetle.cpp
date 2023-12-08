// Fill out your copyright notice in the Description page of Project Settings.


#include "Beetle.h"

#include "Components/CapsuleComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Math/TransformCalculus3D.h"

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
