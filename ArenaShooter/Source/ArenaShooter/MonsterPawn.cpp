// Fill out your copyright notice in the Description page of Project Settings.

#include "ArenaShooter.h"
#include "DrawDebugHelpers.h"
#include "MonsterPawn.h"


// Sets default values
AMonsterPawn::AMonsterPawn()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AttackTimer = AttackSpeed;

}

AMonsterPawn::AMonsterPawn(float _Damage, float _AttackSpeed, float _Health)
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AttackTimer = AttackSpeed;
}

// Called when the game starts or when spawned
void AMonsterPawn::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AMonsterPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (AttackTimer <= 0)
	{
		Attack();
	}
	else
	{
		AttackTimer -= DeltaTime;
	}

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

void AMonsterPawn::Attack()
{
	FVector StartPoint = GetActorLocation();

	FRotator Rotation = FRotator(GetActorRotation().Pitch, GetActorRotation().Yaw + 90, GetActorRotation().Roll);

	FVector EndPoint = GetActorLocation() + (Rotation.Vector() * 100);

	FHitResult HitResult;

	DrawDebugLine(GetWorld(), StartPoint, EndPoint, FColor(255, 0, 0), true, -1.0f, 0, 10.0f);

	bool Hit = GetWorld()->LineTraceSingleByObjectType(HitResult, StartPoint, EndPoint, FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody), FCollisionQueryParams("ActionTrace", false, GetOwner()));

	if (Hit)
	{
		TSubclassOf<UDamageType> const ValidDamageTypeClass = TSubclassOf<UDamageType>(UDamageType::StaticClass());
		FDamageEvent DamageEvent(ValidDamageTypeClass);

		HitResult.Actor->TakeDamage(Damage, DamageEvent, GetController(), this);

		AttackTimer = AttackSpeed;
	}
}

