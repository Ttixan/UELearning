// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
//#include "UnrealNetwork.h"
#include "GameFramework/GameStateBase.h"
#include "MyGameStateBase.generated.h"

/**
 * 
 */
UCLASS()
class UELEARNING1_API AMyGameStateBase : public AGameStateBase
{
	GENERATED_BODY()


	UPROPERTY(Replicated)
	int32 TeamAScore;

	UPROPERTY(Replicated)
	int32 TeamBScore;

	void AddScore(int32 ScoreToAdd);
};
