// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "XRDefense/XRDefense.h"
#include "CombatInterface.generated.h"


DECLARE_DELEGATE_OneParam(FOnAttackFinished, bool /* bSuccess */);


// This class does not need to be modified.
UINTERFACE(MinimalAPI, BlueprintType)
class UCombatInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class XRDEFENSE_API ICombatInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual EObjectType GetObjectType() = 0;
	virtual float GetAttackRange() = 0;

	virtual bool GetIsAttacking() = 0;
	virtual bool GetisDead() = 0;

	virtual AActor* GetCombatTarget() = 0;
	virtual void SetCombatTarget(AActor* target) = 0;

	virtual void Attack() = 0;


};
