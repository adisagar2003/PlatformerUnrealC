// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "MyBTTask_FindPlayerLocation.generated.h"

/**
 * 
 */
UCLASS()
class PLATFORMER_API UMyBTTask_FindPlayerLocation : public UBTTaskNode
{
	GENERATED_BODY()
public:

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

private:
	// Random navigation radius 
	UPROPERTY(EditAnywhere, Category = "Search", meta = (AllowPrivateAccess = "true"))
		bool SearchRandom = false; 

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Search", meta = (AllowPrivateAccess = "true"))
		float SearchRadius = 150.0f;
	

};
	