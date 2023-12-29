// Fill out your copyright notice in the Description page of Project Settings.


#include "Skel.h"
#include "Perception/AIPerceptionStimuliSourceComponent.h"
#include "Perception/AISense_Sight.h"
#include "Components/SphereComponent.h"

// Sets default values
ASkel::ASkel()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SetupStimulusSource();
	Health = 1.00f;
	SphereCollider = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	SphereCollider->OnComponentBeginOverlap.AddDynamic(this, &ASkel::SetAttackMode);
	SphereCollider->OnComponentEndOverlap.AddDynamic(this, &ASkel::DisableAttackMode);
	SphereCollider->AttachTo(RootComponent);
	SphereCollider->SetRelativeLocation(FVector(0.f, 0.f, 0.f));
}

void ASkel::SetupStimulusSource()
{
	StimulusSource = CreateDefaultSubobject<UAIPerceptionStimuliSourceComponent>(TEXT("Stimulus"));
	if (StimulusSource)
	{
		StimulusSource->RegisterForSense(TSubclassOf<UAISense_Sight>());
		StimulusSource->RegisterWithPerceptionSystem();
	}

}
// Called when the game starts or when spawned
void ASkel::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASkel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASkel::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


// When player enters the collider
void ASkel::SetAttackMode(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	IsPlayerInAttackRange = true;
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("Some debug message!"));
}

// Disable attack mode
void ASkel::DisableAttackMode(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	// Disable attack moe
	IsPlayerInAttackRange = false;
}

UBehaviorTree* ASkel::GetBehaviorTree()
{
	return Tree;
}


// Health and damage

void ASkel::TakeDamage(float Damage)
{
	Health = Health - Damage;
	if (Health < 0)
	{
		Death();
	}

}

void ASkel::Death()
{
	// Remove AI controls stop movement play death animation 
	
	if (DeathAnimation)
	{
		PlayAnimMontage(DeathAnimation);
	}

	Destroy();
}

