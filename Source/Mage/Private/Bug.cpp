// Fill out your copyright notice in the Description page of Project Settings.


#include "Bug.h"

// Sets default values
ABug::ABug()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABug::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABug::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABug::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

