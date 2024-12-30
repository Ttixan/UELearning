// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "MyPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class UELEARNING1_API AMyPlayerState : public APlayerState
{
	GENERATED_BODY()
	
public:
	AMyPlayerState();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player State")
	int32 CurrentScore;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player State")
	int32 CurrentBullet;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player State")
	int32 CurrentHealth;

	void AddScore(int32 ScoreToAdd);

	void AddBullet(int32 Num);

	void AddHealth(int32 Num);

	int32 GetCurrentScore() const;

	int32 GetCurrentBullet() const;

	int32 GetCurrentHealth() const;


protected: 
	

	virtual void BeginPlay() override;
};
