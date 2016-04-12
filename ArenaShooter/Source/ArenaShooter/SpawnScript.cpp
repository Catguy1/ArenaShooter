// Fill out your copyright notice in the Description page of Project Settings.

#include "ArenaShooter.h"
#include "SpawnScript.h"


// Sets default values
ASpawnScript::ASpawnScript()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASpawnScript::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASpawnScript::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

