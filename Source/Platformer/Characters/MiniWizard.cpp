// Fill out your copyright notice in the Description page of Project Settings.


#include "MiniWizard.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
AMiniWizard::AMiniWizard()
{
	// set turn rates for input
		
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->TargetArmLength = 800.0f; // distance third person is from the camera
	SpringArm->bUsePawnControlRotation = true; // Rotate the arm based on the controller
	
	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;
	CoinCount = 0;
}

// Called when the game starts or when spawned
void AMiniWizard::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMiniWizard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMiniWizard::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveForward", this, &AMiniWizard::VerticalMovement);
	PlayerInputComponent->BindAxis("MoveRight", this, &AMiniWizard::HorizontalMovement);
	PlayerInputComponent->BindAxis("LookUpRate", this, &AMiniWizard::MouseVertical);
	PlayerInputComponent->BindAxis("TurnRate", this, &AMiniWizard::MouseHorizontal);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
}

void AMiniWizard::HorizontalMovement(float Value)
{
	if ((Controller != nullptr) && (Value != 0.0f))
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get right vector 
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		// add movement in that direction
		AddMovementInput(Direction, Value);
	}	
}

void AMiniWizard::VerticalMovement(float Value)
{
	if ((Controller != nullptr) && (Value != 0.0f))
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);

	}
}

void AMiniWizard::MouseVertical(float Value)
{// calculate delta for this frame from the rate information
	AddControllerPitchInput(Value * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

void AMiniWizard::MouseHorizontal(float Value)
{
	// calculate delta for this frame from the rate information
	AddControllerYawInput(Value * BaseTurnRate * GetWorld()->GetDeltaSeconds());

}

int AMiniWizard::GetCoinCount()
{
	return CoinCount;
}

void AMiniWizard::TakeCoins(int coin)
{
	CoinCount = CoinCount - coin;
}

void AMiniWizard::AddCoin()
{
	CoinCount += 1;
}