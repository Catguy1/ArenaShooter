// Fill out your copyright notice in the Description page of Project Settings.

#include "ArenaShooter.h"
#include "AnotherTest.h"


// Sets default values for this component's properties
UAnotherTest::UAnotherTest()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UAnotherTest::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UAnotherTest::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// ...
}

