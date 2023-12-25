// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBTTask_FindPlayerLocation.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"
#include "AI/Navigation/NavigationTypes.h"
#include "NavigationSystem.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardData.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"



	
EBTNodeResult::Type UMyBTTask_FindPlayerLocation::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	// get player character
	if (auto* const Player = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0))
	{
		FVector const PlayerLocation = Player->GetActorLocation();
		
		if (SearchRandom)
		{
			FNavLocation Loc;

			// get the navigation system and get random location 
			if (auto* const NavigationSystem = UNavigationSystemV1::GetCurrent(GetWorld()))
			{
				// try to get random location near player 
				if (NavigationSystem->GetRandomPointInNavigableRadius(PlayerLocation
					, SearchRadius, Loc))
				{
					OwnerComp.GetBlackboardComponent()->SetValueAsVector(FName("RandomLocation"), Loc.Location);
					return EBTNodeResult::Succeeded;
				}
			}
			else
			{
				OwnerComp.GetBlackboardComponent()->SetValueAsVector(FName("RandomLocation"), PlayerLocation);
				return EBTNodeResult::Succeeded;
			}
		}
	}
	return EBTNodeResult::Failed;
}
