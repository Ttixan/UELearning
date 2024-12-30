// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameStateBase.h"

void AMyGameStateBase::AddScore(int32 ScoreToAdd)
{
    TeamAScore += ScoreToAdd;
}

// This function is required through the replicated specifier in the UPROPERTY macro and is declared by it
void AMyGameStateBase::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);

    //DOREPLIFETIME(ATestGameState, TeamAScore);
    //DOREPLIFETIME(ATestGameState, TeamBScore);
}
