// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/HealthComponent.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	Health = 100.0f;
	MaxHealth = 100.0f;
	// ...
}

// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UHealthComponent::SetHealth(float healthValue)
{
	Health = FMath::Clamp(healthValue, 0.f, healthValue);
}

float UHealthComponent::PawnTakesDamage(float Damage)
{
	if(Damage > 0.f)
	{
		float damageApplied = GetHealth() - Damage;
		SetHealth(damageApplied);
	}

	return Damage;
}

