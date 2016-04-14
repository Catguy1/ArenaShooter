// Fill out your copyright notice in the Description page of Project Settings.

#include "ArenaShooter.h"
#include "SpawnComponent.h"


// Sets default values for this component's properties
USpawnComponent::USpawnComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void USpawnComponent::BeginPlay()
{
	Super::BeginPlay();

	Timer = SpawnTime;
	// ...

}


// Called every frame
void USpawnComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	AActor *a = ActorToSpawn;

	if (Timer <= 0)
	{
		//GetWorld()->SpawnActor<AActor>(GetOwner()->GetActorLocation(), GetOwner()->GetActorRotation());
		Timer = SpawnTime;
	}
	else
	{
		Timer -= DeltaTime;
	}

}

