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

	Damage = 100;
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
	if (DamageCauser->GetClass() != GetClass())
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
	return 0;
}

void AMonsterPawn::Attack()
{
	FVector StartPoint = FVector(GetActorLocation().X, GetActorLocation().Y, GetActorLocation().Z) + 90;

	FRotator Rotation = FRotator(GetActorRotation().Pitch, GetActorRotation().Yaw + 90, GetActorRotation().Roll);

	FVector EndPoint = GetActorLocation() + (Rotation.Vector() * 200);

	TArray<FHitResult> HitResult = TArray<FHitResult>();

	DrawDebugLine(GetWorld(), StartPoint, EndPoint, FColor(255, 0, 0), true, -1.0f, 0, 10.0f);

	bool Hit = GetWorld()->LineTraceMultiByObjectType(HitResult, StartPoint, EndPoint, FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody), FCollisionQueryParams("ActionTrace", false, GetOwner()));

	if (Hit)
	{
		for (int i = 0; i < HitResult.Num(); i++)
		{
			TSubclassOf<UDamageType> const ValidDamageTypeClass = TSubclassOf<UDamageType>(UDamageType::StaticClass());
			FDamageEvent DamageEvent(ValidDamageTypeClass);

			HitResult[i].Actor->TakeDamage(Damage, DamageEvent, GetController(), this);

			AttackTimer = AttackSpeed;

		}
	}
}

