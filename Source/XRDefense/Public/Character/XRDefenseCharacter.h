// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Interaction/OutlineInterface.h"

#include "XRDefenseCharacter.generated.h"


UCLASS()
class XRDEFENSE_API AXRDefenseCharacter : public ACharacter, public IOutlineInterface
{
	GENERATED_BODY()

public:
	AXRDefenseCharacter();

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnyWhere)
	EObjectType objectType;


public:	
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	virtual void SetOutLineOn();
	virtual void SetOutLineOff();

};
