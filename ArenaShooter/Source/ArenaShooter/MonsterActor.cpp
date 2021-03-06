// Fill out your copyright notice in the Description page of Project Settings.

#include "ArenaShooter.h"
#include "MonsterActor.h"


// Sets default values
AMonsterActor::AMonsterActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMonsterActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMonsterActor::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	ACharacter * Player = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);

	FVector position = Player->GetActorLocation();
}

void AMonsterActor::Death()
{
	GetWorld()->RemoveActor(this, false);
}

