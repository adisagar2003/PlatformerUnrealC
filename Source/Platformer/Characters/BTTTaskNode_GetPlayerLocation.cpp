// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTTaskNode_GetPlayerLocation.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"
#include "BehaviorTree/BlackboardComponent.h"


EBTNodeResult::Type UBTTTaskNode_GetPlayerLocation::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	// get player location
	if (auto* const Player = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0))
	{
		if (Player)
		{
			FVector PlayerLocation = Player->GetActorLocation();
			// set blackboard key
		
			OwnerComp.GetBlackboardComponent()->SetValueAsVector(FName("PlayerLocation"), PlayerLocation);
			return EBTNodeResult::Succeeded;
		}
		else {
			return EBTNodeResult::Failed;
		}

		
	}

	return EBTNodeResult::Failed;
	
}