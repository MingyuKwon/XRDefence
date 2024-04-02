// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Character/XRDefenseCharacter.h"
#include "XRDefensePlayerController.generated.h"

/**
 * 
 */
UCLASS()
class XRDEFENSE_API AXRDefensePlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	virtual void Tick(float DeltaTime) override;
	virtual void SetupInputComponent() override;
protected:
	virtual void BeginPlay() override;


private:
	void TraceUnderMouse();

	void OnLeftClick();
	void OnLeftClickReleased();

	void LeftClickCheck(float DeltaTime);

	bool bIsLeftButtonPressed = false;
	FVector FromMouseToFloorTracingPoint;
	AActor* CurrentGrabActor = nullptr;

	IOutlineInterface* pastTarget = nullptr;
	IOutlineInterface* currentTarget = nullptr;

};
