// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "UELearning1GameMode.generated.h"

UCLASS(minimalapi)
class AUELearning1GameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AUELearning1GameMode();

	void AddScore(int32 ScoreToAdd);


	int32 GetCurrentScore() const;


	void StartGameTimer(float TimeLimit);

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Game Settings")
	TArray<APlayerController*> PlayerControllerList;


	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Game Settings")
	int32 X; 

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Game Settings")
	float Y; 

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Game Settings")
	float T; 

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Game Settings")
	int32 N;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Game Settings")
	int32 BulletNum;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Game Settings")
	float MaxHealth;

protected:
	virtual void BeginPlay() override;

	virtual void PostLogin(APlayerController* NewPlayer) override;

private:

	int32 CurrentScore;

	FTimerHandle GameTimerHandle;

	void SetImportantTargets();

	void EndGame();
};



