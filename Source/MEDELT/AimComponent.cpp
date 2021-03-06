// Fill out your copyright notice in the Description page of Project Settings.


#include "AimComponent.h"

// Sets default values for this component's properties
UAimComponent::UAimComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UAimComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UAimComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}


FVector UAimComponent::AimLocation(FVector InputLocation, FVector InputPos)
{
	FVector MyLocation = GetOwner()->GetActorLocation();
	FVector AimPos;
	AimPos.X = MyLocation.X;
	AimPos.Y = InputLocation.Y + (((GetOwner()->GetActorLocation().X - InputLocation.X) * (InputPos.Y - InputLocation.Y)) / (InputPos.X - InputLocation.X));
	AimPos.Z = InputLocation.Z + (((GetOwner()->GetActorLocation().X - InputLocation.X) * (InputPos.Z - InputLocation.Z)) / (InputPos.X - InputLocation.X));
	return AimPos;
}

