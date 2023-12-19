// Fill out your copyright notice in the Description page of Project Settings.


#include "WizardAnimInstance.h"

void UWizardAnimInstance::NativeInitializeAnimation()
{
	if (Pawn == nullptr)
	{
		Pawn = TryGetPawnOwner();

	}
}

void UWizardAnimInstance::UpdateAnimInstance()
{
	if (Pawn == nullptr)
	{

	}

	if (Pawn)
	{
		FVector Speed = Pawn->GetVelocity();
		FVector LateralSpeed = FVector(Speed.X, Speed.Y, 0.f);
		MovementSpeed = LateralSpeed.Size();
		if (MovementSpeed > 4.0f)
		{
			isWalking = true;
		}

	}

}