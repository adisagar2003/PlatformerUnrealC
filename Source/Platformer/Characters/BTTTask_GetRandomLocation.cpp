// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTTask_GetRandomLocation.h"
#include "NavigationSystem.h"
#include "Kismet/GameplayStatics.h"
#include "AI/Navigation/NavigationTypes.h"
#include "Math/Vector.h"
#include "Engine/Engine.h"
#include "BehaviorTree/BlackboardData.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BrainComponent.h"
#include "BehaviorTree/Services/BTService_BlackboardBase.h"


EBTNodeResult::Type UBTTTask_GetRandomLocation::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	// get navmesh data
	// generate random location from the navmesh data
	// set blackboard key "Random Location"
	if (auto* const NavMeshData = UNavigationSystemV1::GetNavigationSystem(GetWorld()))
	{
		// get owning actor to get the location
		if (auto* const Enemy = OwnerComp.GetOwner())
		{
			FVector EnemyLocation= Enemy->GetActorLocation();
			ULevel* CurrentLevel = GetWorld()->GetCurrentLevel();
			ANavigationData* NavMeshAbstractData = NavMeshData->GetAbstractNavData();
			FNavLocation ResultLocation = FNavLocation();
			NavMeshData->GetRandomPointInNavigableRadius(EnemyLocation, 15.0f, ResultLocation,NavMeshAbstractData);
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Your Message"));

			return EBTNodeResult::Succeeded;
		}
		else
		{
			return EBTNodeResult::Failed;
		}
	}
	else
	{
		return EBTNodeResult::Failed;
	}

}