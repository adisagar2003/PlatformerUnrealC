// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Perception/AIPerceptionTypes.h"
#include "Skel_AIController.generated.h"

/**
 * 
 */
UCLASS()
class PLATFORMER_API ASkel_AIController : public AAIController
{
	GENERATED_BODY()
public:
	explicit ASkel_AIController(FObjectInitializer const& ObjectInitializer);
protected:
	virtual void OnPossess(APawn* InPawn) override;
	// Setting up sight configuration 
	class UAISenseConfig_Sight* SightConfig;
	
	void SetupPerceptionSystem();

	UFUNCTION()
		void OnTargetDetected(AActor* Actor, FAIStimulus const Stimulus);

	class UAIPerceptionStimuliSourceComponent* StimulusSource;
	void SetupStimulusSource();

};
