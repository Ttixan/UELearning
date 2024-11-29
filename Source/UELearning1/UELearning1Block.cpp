// Fill out your copyright notice in the Description page of Project Settings.


#include "UELearning1Block.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "UELearning1Projectile.h"

// Sets default values
AUELearning1Block::AUELearning1Block()
    : Super(),HitTimes(0), bIsImportantTarget(false)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	//PrimaryActorTick.bCanEverTick = true;
    PrimaryActorTick.bCanEverTick = false;

    // block mesh
    BlockMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BlockMesh"));
    RootComponent = BlockMesh;

    // set to cube
    static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeMeshAsset(TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'")); // cube
    if (CubeMeshAsset.Succeeded())
    {
        BlockMesh->SetStaticMesh(CubeMeshAsset.Object); // mesh
    }

    // physical
    BlockMesh->SetSimulatePhysics(true);
    BlockMesh->SetNotifyRigidBodyCollision(true);
}

// Called when the game starts or when spawned
void AUELearning1Block::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AUELearning1Block::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void AUELearning1Block::AddHitTimes() {
    HitTimes++;
}

