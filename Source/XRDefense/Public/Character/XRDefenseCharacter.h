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

	virtual void SetHighLightOn();
	virtual void SetHighLightOff();


protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnyWhere)
	EObjectType objectType;

	UPROPERTY(VisibleAnyWhere)
	UStaticMeshComponent* CharacterFloorMesh;

	UPROPERTY(EditAnyWhere)
	UStaticMesh* DefenseCircle;

	UPROPERTY(EditAnyWhere)
	UStaticMesh* OffenceCircle;

	UPROPERTY(EditAnyWhere)
	UStaticMesh* NoneCircle;

	FVector FloorMeshFirstStartPosition;

	UPROPERTY(VisibleAnyWhere)
	bool bIsHighlighted;

	void SetHighlightStencilValue();
	void SetDefaultStencilValue();

	void SetFloorMeshPosition(float DeltaTime);

public:	
	
	FORCEINLINE virtual bool GetIsHighlighted() override { return bIsHighlighted; }
	FORCEINLINE virtual FVector GetLocation() override { return GetActorLocation(); }
	FORCEINLINE virtual void SetLocation(FVector position) {SetActorLocation(position);}

};
