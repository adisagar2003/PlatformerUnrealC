// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BehaviorTree/BehaviorTree.h"
#include "Skel.generated.h"

UCLASS()
class PLATFORMER_API ASkel : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASkel();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	class UAIPerceptionStimuliSourceComponent* StimulusSource;
	void SetupStimulusSource();
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UBehaviorTree* GetBehaviorTree();
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI", meta = (AllowPrivateAccess = "true"))
	class UBehaviorTree* Tree;
	


};
