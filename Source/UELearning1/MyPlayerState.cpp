// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerState.h"
#include "UELearning1GameMode.h"
#include "Kismet/GameplayStatics.h"

AMyPlayerState::AMyPlayerState()
{
	CurrentScore = 0;
	CurrentBullet = 0;
	CurrentHealth = 0;
}

void AMyPlayerState::BeginPlay()
{
	Super::BeginPlay();
	AUELearning1GameMode* GameMode = Cast<AUELearning1GameMode>(UGameplayStatics::GetGameMode(this));
    if (GameMode)
    {
        // ·ÃÎÊ PlayerState µÄÊôÐÔ
		CurrentBullet = GameMode->BulletNum;
		CurrentHealth = GameMode->MaxHealth;
    }
}

void AMyPlayerState::AddScore(int32 ScoreToAdd)
{
	CurrentScore += ScoreToAdd;
	// print
	UE_LOG(LogTemp, Log, TEXT("CurrentScore: %d"), CurrentScore);
}

void AMyPlayerState::AddBullet(int32 Num)
{
	CurrentBullet += Num;
}

void AMyPlayerState::AddHealth(int32 Num)
{
	CurrentHealth += Num;
}

int32 AMyPlayerState::GetCurrentScore() const
{
	return CurrentScore;
}

int32 AMyPlayerState::GetCurrentBullet() const
{
	return CurrentBullet;
}

int32 AMyPlayerState::GetCurrentHealth() const
{
	return CurrentHealth;
}


