// Fill out your copyright notice in the Description page of Project Settings.


#include "Skel.h"

// Sets default values
ASkel::ASkel()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
}

// Called when the game starts or when spawned
void ASkel::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASkel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASkel::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

UBehaviorTree* ASkel::GetBehaviorTree()
{
	return Tree;
}

