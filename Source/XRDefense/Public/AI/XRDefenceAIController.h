// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "XRDefenceAIController.generated.h"

/**
 * 
 */

class UBehaviorTreeComponent;


UCLASS()
class XRDEFENSE_API AXRDefenceAIController : public AAIController
{
	GENERATED_BODY()
	
public:
	AXRDefenceAIController();

protected:

	UPROPERTY()
	UBehaviorTreeComponent* BehaviorTreeComponent;
};
