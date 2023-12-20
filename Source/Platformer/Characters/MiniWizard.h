// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MiniWizard.generated.h"


UCLASS()
class PLATFORMER_API AMiniWizard : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMiniWizard();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Camera)
		class UCameraComponent* FollowCamera;  // Camera for third person character

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Camera)
		class USpringArmComponent* SpringArm;  // Camera springarm used for camera shake effects

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = CharacterMesh)
		class USkeletalMeshComponent* SkeletalMesh; // Skeletalmesh

	// Reference to UMG Asset in the editor //
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "Widgets")
	TSubclassOf<class UUserWidget> HUDOverlayAsset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
	class UUserWidget* HUDOverlay;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MouseControl)
		float BaseTurnRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MouseControl)
		float BaseLookUpRate;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Stats)
		int CoinCount;
	void HorizontalMovement(float Value);
	void VerticalMovement(float Value);
	void MouseVertical(float Value);
	void MouseHorizontal(float Value);
	UFUNCTION(BlueprintCallable)
		int GetCoinCount();
	UFUNCTION(BlueprintCallable)
		void TakeCoins(int coin);
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	UFUNCTION(BlueprintCallable)
		void AddCoin();
	
	
	
};
