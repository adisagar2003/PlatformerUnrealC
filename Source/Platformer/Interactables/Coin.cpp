// Fill out your copyright notice in the Description page of Project Settings.


#include "Coin.h"
#include "../Characters/MiniWizard.h"
#include "Kismet/GameplayStatics.h"
#include "Components/SphereComponent.h"

// Sets default values
ACoin::ACoin()
{
	SphereCollider->OnComponentBeginOverlap.AddDynamic(this, &ACoin::OnCollisionEnterFunction);
	PlayerCharacter = Cast<AMiniWizard>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
	
}

void ACoin::OnCollisionEnterFunction(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Super::OnCollisionEnterFunction(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);
	//Adding function of another class MiniWizard.cpp

	// Check if player character is pointing to something to or not (performance issue)
	if (!PlayerCharacter)
	{
		PlayerCharacter = Cast<AMiniWizard>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
	}

	// If successful casting is present, add coin
	if (PlayerCharacter != nullptr)
	{
		PlayerCharacter->AddCoin();
		Destroy();
	}

}