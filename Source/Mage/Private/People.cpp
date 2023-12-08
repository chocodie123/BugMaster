// Fill out your copyright notice in the Description page of Project Settings.


#include "People.h"

APeople::APeople()
{
	ConstructorHelpers::FObjectFinder<USkeletalMesh> ThisMesh(TEXT("/Script/Engine.SkeletalMesh'/Game/Resource/Scanned3DPeoplePack/RP_Character/rp_eric_rigged_001_ue4/rp_eric_rigged_001_ue4.rp_eric_rigged_001_ue4'"));
	if(ThisMesh.Succeeded())
	{
		GetMesh()->SetSkeletalMesh(ThisMesh.Object);
		GetMesh()->SetRelativeTransform(FTransform(FRotator(0,-90,0),
			FVector(0,0,-90),FVector(1)));
	}
	
	
}

void APeople::BeginPlay()
{
	Super::BeginPlay();
}

void APeople::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
