// Fill out your copyright notice in the Description page of Project Settings.


#include "Skel_AIController.h"
#include "Skel.h"
#include "BehaviorTree/BehaviorTree.h"
#include "Perception/AISenseConfig_Sight.h"
#include "Perception/AIPerceptionComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Perception/AIPerceptionStimuliSourceComponent.h"




ASkel_AIController::ASkel_AIController(FObjectInitializer const& ObjectInitializer)
{
	SetupPerceptionSystem();
	SetupStimulusSource();
}

void ASkel_AIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	
	// Checking if blackboard and behaviour tree exists.
	if (ASkel* const npc = Cast<ASkel>(InPawn))
	{
		if (UBehaviorTree* const tree = npc->GetBehaviorTree())
		{
			UBlackboardComponent* b;
			UseBlackboard(tree->BlackboardAsset, b);
			Blackboard = b;
			RunBehaviorTree(tree);
		
		}
	}

}

void ASkel_AIController::SetupPerceptionSystem()
{
	SightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("Sight Config"));
	if (SightConfig)
	{
		SetPerceptionComponent(*CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("Perception Component")));
		SightConfig->SightRadius= 500.f;
		SightConfig->LoseSightRadius = SightConfig->SightRadius + 25.f;
		SightConfig->PeripheralVisionAngleDegrees = 90.f;
		SightConfig->SetMaxAge(5.f);
		SightConfig->AutoSuccessRangeFromLastSeenLocation = 520.0f;
		SightConfig->DetectionByAffiliation.bDetectEnemies = true;
		SightConfig->DetectionByAffiliation.bDetectFriendlies = true;
		SightConfig->DetectionByAffiliation.bDetectNeutrals = true;

		GetPerceptionComponent()->SetDominantSense(*SightConfig->GetSenseImplementation());
		// When enemy sees the player
		GetPerceptionComponent()->OnTargetPerceptionUpdated.AddDynamic(this, &ASkel_AIController::OnTargetDetected);
		GetPerceptionComponent()->ConfigureSense((*SightConfig));

	}
}

void ASkel_AIController::OnTargetDetected(AActor* Actor, FAIStimulus const Stimulus)
{
	// Setting the blackboard value of can see player to true
	if (auto* const Enemy = Cast<ASkel>(Actor))
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Some debug message! %s"), Stimulus.WasSuccessfullySensed());
		GetBlackboardComponent()->SetValueAsBool("CanSeePlayer", Stimulus.WasSuccessfullySensed());
	}
}

void ASkel_AIController::SetupStimulusSource()
{
	if (StimulusSource)
	{
		StimulusSource->RegisterForSense(TSubclassOf<UAISense_Sight>());
		StimulusSource->RegisterWithPerceptionSystem();
	}

}
