// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Components/CapsuleComponent.h"
#include "Components/HealthComponent.h"
#include "BaseEnemyCharacter.generated.h"

class UHealthComponent;

UCLASS()
class JAMPROJECT02_API ABaseEnemyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseEnemyCharacter(const class FObjectInitializer& ObjectInitializer);

	UPROPERTY(EditAnywhere)
	UHealthComponent* HealthComponent;

	virtual void OnDeath();

	virtual float TakeDamage(float DamageTaken, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

	UPROPERTY(BlueprintReadOnly)
	bool bIsDying = false;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
