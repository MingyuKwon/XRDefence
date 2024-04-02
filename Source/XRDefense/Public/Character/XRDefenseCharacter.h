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
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void SetOutLineOn();
	virtual void SetOutLineOff();


protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnyWhere)
	EObjectType objectType;

	UPROPERTY(VisibleAnyWhere)
	bool bIsHighlighted;

public:	
	
	FORCEINLINE virtual bool GetIsHighlighted() override { return bIsHighlighted; }
	FORCEINLINE virtual FVector GetLocation() override { return GetActorLocation(); }
	FORCEINLINE virtual void SetLocation(FVector position) {SetActorLocation(position);}

};
