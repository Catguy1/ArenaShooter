// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "MonsterPawn.h"
#include "ArenaShooterProjectile.h"
#include "Components/ActorComponent.h"
#include "SpawnComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FSpawnDelegate);


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ARENASHOOTER_API USpawnComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	USpawnComponent();

	// Called when the game starts
	virtual void BeginPlay() override;

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	UPROPERTY(EditAnywhere)
		AActor * ActorToSpawn = nullptr;
	UPROPERTY(EditAnywhere)
		float SpawnTime;
	UPROPERTY(BlueprintAssignable)
		FSpawnDelegate spawn;

	float Timer;
};
