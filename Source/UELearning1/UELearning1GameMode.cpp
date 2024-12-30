// Copyright Epic Games, Inc. All Rights Reserved.

#include "UELearning1GameMode.h"
#include "UELearning1Character.h"
#include "MyPlayerState.h"
#include "UELearning1Block.h"
#include "TimerManager.h"
#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/GameStateBase.h"



AUELearning1GameMode::AUELearning1GameMode()
	: Super(), CurrentScore(0), X(20), Y(0.5f), T(30.0f), N(2), BulletNum(100), MaxHealth(100.0f)
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
void AUELearning1GameMode::AddScore(int32 ScoreToAdd)
{
	CurrentScore += ScoreToAdd;
	// print
	UE_LOG(LogTemp, Log, TEXT("CurrentScore: %d"), CurrentScore);
}

int32 AUELearning1GameMode::GetCurrentScore() const
{
	return CurrentScore;
}
void AUELearning1GameMode::StartGameTimer(float TimeLimit)
{
	GetWorldTimerManager().SetTimer(GameTimerHandle, this, &AUELearning1GameMode::EndGame, TimeLimit, false);
}

void AUELearning1GameMode::BeginPlay()
{
	Super::BeginPlay();
	StartGameTimer(T); // counter
	SetImportantTargets();
	UE_LOG(LogTemp, Log, TEXT("GameStart!"));
}

void AUELearning1GameMode::EndGame()
{
	// 获取所有玩家的 PlayerState
	int32 AllScore = 0;
	if (this->GameState)
	{
		for (APlayerState* PlayerState : this->GameState->PlayerArray)
		{
			AMyPlayerState* MyPlayerState = Cast<AMyPlayerState>(PlayerState);
			if (MyPlayerState)
			{
				AllScore += MyPlayerState->GetCurrentScore();
			}
		}
	}
	
	UE_LOG(LogTemp, Log, TEXT("Game End! Final Score: %d"), AllScore);

}

void AUELearning1GameMode::SetImportantTargets()
{
	TArray<AActor*> AllBlocks;

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AUELearning1Block::StaticClass(), AllBlocks);

	for (int32 i = 0; i < N; i++)
	{
		if (AllBlocks.Num() > 0)
		{
			int32 RandomIndex = FMath::RandRange(0, AllBlocks.Num() - 1);
			if (AUELearning1Block* ChooseBlock = Cast<AUELearning1Block>(AllBlocks[RandomIndex]))
			{
				ChooseBlock->ChangeImportance();
			}
			//UE_LOG(LogTemp, Log, TEXT("Important Index: %d"), RandomIndex);
			AllBlocks.RemoveAt(RandomIndex);
		}
	}
}

void AUELearning1GameMode::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);

	PlayerControllerList.Add(NewPlayer);
}
