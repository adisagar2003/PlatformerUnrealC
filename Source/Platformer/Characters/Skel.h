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

	// Health and combat
	float Health;
	UFUNCTION(BlueprintCallable, Category=HealthAndCombat)
	void TakeDamage(float Damage);
	void Death();

	// Animations
	UPROPERTY(EditAnywhere, Category = Animations)
		class UAnimMontage* DeathAnimation;

	UPROPERTY(EditAnywhere, Category = Animations)
		class UAnimMontage* AttackAnim;

	// Collider for detection of range
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		bool IsPlayerInAttackRange;

	// Sphere Collider 
	UPROPERTY(EditAnywhere, Category = HealthAndCombat)
		class USphereComponent* SphereCollider;

	UFUNCTION(BlueprintCallable)
		void DisableAttackMode(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UBehaviorTree* GetBehaviorTree();
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI", meta = (AllowPrivateAccess = "true"))
	class UBehaviorTree* Tree;
	
private:
	void SetAttackMode(UPrimitiveComponent* OverlappedComponent,AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);


};
