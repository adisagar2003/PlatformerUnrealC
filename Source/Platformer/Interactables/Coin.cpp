// Fill out your copyright notice in the Description page of Project Settings.


#include "Coin.h"
#include "Components/SphereComponent.h"

// Sets default values
ACoin::ACoin()
{
	SphereCollider->OnComponentBeginOverlap.AddDynamic(this, &ACoin::OnCollisionEnterFunction);
}

void ACoin::OnCollisionEnterFunction(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

}