// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "SkelAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class PLATFORMER_API USkelAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
public:

	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

	virtual void NativeInitializeAnimation() override;

	UPROPERTY(BlueprintReadOnly)
		bool bIsInAir;

	UPROPERTY(BlueprintReadOnly)
		bool isWalking;

	UPROPERTY(BlueprintReadOnly)
		bool isFalling;

	UPROPERTY(BlueprintReadOnly)
		float MovementSpeed = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Movement)
		class APawn* Pawn;

	UFUNCTION(BlueprintCallable, Category = Animations)
		void UpdateAnimInstance();
	
};
