// Copyright Epic Games, Inc. All Rights Reserved.

#include "UELearning1Projectile.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/SphereComponent.h"
#include "UELearning1GameMode.h"
#include "UELearning1Block.h"
#include "Kismet/GameplayStatics.h"

AUELearning1Projectile::AUELearning1Projectile() 
{
	// Use a sphere as a simple collision representation
	CollisionComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	CollisionComp->InitSphereRadius(5.0f);
	CollisionComp->BodyInstance.SetCollisionProfileName("Projectile");
	CollisionComp->OnComponentHit.AddDynamic(this, &AUELearning1Projectile::OnHit);		// set up a notification for when this component hits something blocking

	// Players can't walk on it
	CollisionComp->SetWalkableSlopeOverride(FWalkableSlopeOverride(WalkableSlope_Unwalkable, 0.f));
	CollisionComp->CanCharacterStepUpOn = ECB_No;

	// Set as root component
	RootComponent = CollisionComp;

	// Use a ProjectileMovementComponent to govern this projectile's movement
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileComp"));
	ProjectileMovement->UpdatedComponent = CollisionComp;
	ProjectileMovement->InitialSpeed = 3000.f;
	ProjectileMovement->MaxSpeed = 3000.f;
	ProjectileMovement->bRotationFollowsVelocity = true;
	ProjectileMovement->bShouldBounce = true;

	// Die after 3 seconds by default
	InitialLifeSpan = 3.0f;
}

void AUELearning1Projectile::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
//{
//	// Only add impulse and destroy projectile if we hit a physics
//	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr) && OtherComp->IsSimulatingPhysics())
//	{
//		OtherComp->AddImpulseAtLocation(GetVelocity() * 100.0f, GetActorLocation());
//
//		Destroy();
//	}
//}
{

    if (OtherActor != nullptr && OtherActor != this && OtherComp != nullptr)
    {
        // if block
        if (OtherActor->IsA(AUELearning1Block::StaticClass()))
        {
            // gamemode for counter
            AUELearning1GameMode* GameMode = Cast<AUELearning1GameMode>(UGameplayStatics::GetGameMode(this));

            if (AUELearning1Block* HitBlock = Cast< AUELearning1Block>(OtherActor)) {
                int32 ScoreToAdd = HitBlock->GetIsImportantTarget() ? GameMode->X * 2 : GameMode->X;
                if (GameMode)
                {
                    GameMode->AddScore(ScoreToAdd);
                    //UE_LOG(LogTemp, Log, TEXT("What to add: %d"), ScoreToAdd);

                }
                if (HitBlock->GetHitTimes() < 1) 
                {
                    // scale the block
                    FVector NewScale = HitBlock->GetActorScale3D() * GameMode->Y;
                    HitBlock->SetActorScale3D(NewScale);
                    HitBlock->AddHitTimes();
                }
                else 
                {
                    // destroy the block
                    HitBlock->Destroy();
                }
            }
            
        }
        else if (OtherComp->IsSimulatingPhysics())
        {
            // physical impulse
            OtherComp->AddImpulseAtLocation(GetVelocity() * 100.0f, GetActorLocation());
        }

        // destroy
        Destroy();
    }
}