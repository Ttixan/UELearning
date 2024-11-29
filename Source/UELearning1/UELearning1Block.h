// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UELearning1Block.generated.h"

UCLASS()
class UELEARNING1_API AUELearning1Block : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AUELearning1Block();
	void AddHitTimes();
	int32 GetHitTimes() const { return HitTimes; }
	bool GetIsImportantTarget() const { return bIsImportantTarget; }
	void ChangeImportance() { bIsImportantTarget = true; }

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	int32 HitTimes;
	bool bIsImportantTarget;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* BlockMesh;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Block Properties")
	int32 PointValue;
	//UFUNCTION()
	//void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
};
