// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "SpawnScript.generated.h"

//DECLARE_DYNAMIC_MULTICAST_DELEGATE(FSpawnDelegate);

UCLASS()
class ARENASHOOTER_API ASpawnScript : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ASpawnScript();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

//private:
//	UPROPERTY(EditAnywhere)
//		AActor ActorToSpawn = nullptr;
//	UPROPERTY(EditAnywhere)
//		AActor ActorToSpawn = nullptr;
//	UPROPERTY(BlueprintAssignable)
//		FSpawnDelegate spawn;

};
