// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

UCLASS()
class XRDEFENSE_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere)
	class UProjectileMovementComponent* ProjectileMovement;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* BulletMesh;

private:
	UPROPERTY(EditAnywhere)
	float shotSpeed;

	float BulletDamage = 0.f;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void SetTarget(AActor* Target);
	void SetDamage(float Damage);
};
