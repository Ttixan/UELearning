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
	int32 X; 

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Game Settings")
	float Y; 

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Game Settings")
	float T; 

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Game Settings")
	int32 N;

protected:
	virtual void BeginPlay() override;

private:

	int32 CurrentScore;

	FTimerHandle GameTimerHandle;

	void SetImportantTargets();

	void EndGame();
};



