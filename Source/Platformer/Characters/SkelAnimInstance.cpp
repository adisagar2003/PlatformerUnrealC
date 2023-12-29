// Fill out your copyright notice in the Description page of Project Settings.


#include "SkelAnimInstance.h"
#include "Skel.h"

void USkelAnimInstance::NativeInitializeAnimation()
{
	Pawn = TryGetPawnOwner();
	
}

void USkelAnimInstance::UpdateAnimInstance()
{
}

void USkelAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	// native update animation
	
	// set the movement speed according to pawn owners speed
	if (Pawn)
	{
		if (auto* const Enemy = Cast<ASkel>(Pawn))
		{
			MovementSpeed = Pawn->GetVelocity().Size();
				
		}
	}
}

