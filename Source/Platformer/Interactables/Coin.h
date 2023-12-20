// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../Interactables/Interactable.h"
#include "../Characters/MiniWizard.h"
#include "Coin.generated.h"

/**
 * 
 */
UCLASS()
class PLATFORMER_API ACoin : public AInteractable
{
	GENERATED_BODY()
		ACoin();
public:
		virtual void OnCollisionEnterFunction(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;
		AMiniWizard* PlayerCharacter;
};
