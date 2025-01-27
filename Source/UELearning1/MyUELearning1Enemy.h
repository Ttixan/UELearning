// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UELearning1Character.h"
#include "MyUELearning1Enemy.generated.h"

/**
 * 
 */
//DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDead, AUELearning1Character*, PickUpCharacter);


UCLASS()
class UELEARNING1_API AMyUELearning1Enemy : public AUELearning1Character
{
	GENERATED_BODY()
public:
	/** Delegate to whom anyone can subscribe to receive this event */
	//UPROPERTY(BlueprintAssignable, Category = "Interaction")
	//FOnDead FOnDead;

	void AddHitTimes();
	int32 GetHitTimes() const { return HitTimes; }

protected:
	//virtual void BeginPlay() override;
	int32 HitTimes;
};
