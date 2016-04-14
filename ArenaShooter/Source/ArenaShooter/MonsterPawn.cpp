// Fill out your copyright notice in the Description page of Project Settings.

#include "ArenaShooter.h"
#include "MonsterPawn.h"


// Sets default values
AMonsterPawn::AMonsterPawn()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMonsterPawn::BeginPlay()
{
	Super::BeginPlay();

	Health = 1200;

	

}

// Called every frame
void AMonsterPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector movement = FVector(10, 0, 0);

	SetActorRelativeLocation(movement*DeltaTime);
}

// Called to bind functionality to input
void AMonsterPawn::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

float AMonsterPawn::TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, class AActor* DamageCauser)
{
	const float ActualDamage = Super::TakeDamage(Damage, DamageEvent, EventInstigator, DamageCauser);
	if (ActualDamage > 0.f)
	{
		Health -= ActualDamage;
		// If the damage depletes our health set our lifespan to zero - which will destroy the actor  
		if (Health <= 0.f)
		{
			GetWorld()->DestroyActor(this);
			//SetLifeSpan(0.001f);
		}
	}

	return ActualDamage;
}

