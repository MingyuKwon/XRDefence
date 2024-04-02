// Fill out your copyright notice in the Description page of Project Settings.


#include "Controller/XRDefensePlayerController.h"

void AXRDefensePlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	TraceUnderMouse();
}

void AXRDefensePlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAction("LeftClick", IE_Pressed, this, &AXRDefensePlayerController::OnLeftClick);
	InputComponent->BindAction("LeftClick", IE_Released, this, &AXRDefensePlayerController::OnLeftClickReleased);

}

void AXRDefensePlayerController::OnLeftClick()
{
	// 마우스 클릭 시 실행될 로직
	if (currentTarget && currentTarget->GetIsHighlighted())
	{
		FVector TargetLocation = currentTarget->GetLocation();

		currentTarget->SetLocation(TargetLocation + FVector::UpVector * 50.f);
	}

}

void AXRDefensePlayerController::OnLeftClickReleased()
{
	// 마우스 버튼이 놓여졌을 때 실행될 로직
	if (currentTarget && currentTarget->GetIsHighlighted())
	{
		FString str = FString::Printf(TEXT("OnLeftClickReleased"));
		GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Blue, *str);

	}

}

void AXRDefensePlayerController::BeginPlay()
{
	Super::BeginPlay();

	// 마우스 커서 활성화
	bShowMouseCursor = true;

	// 마우스 입력을 UI와 게임 모두에 사용하도록 설정
	bEnableClickEvents = true;
	bEnableMouseOverEvents = true;

	SetInputMode(FInputModeGameAndUI());
}


void AXRDefensePlayerController::TraceUnderMouse()
{
	FHitResult UnderMouseHitResult;
	GetHitResultUnderCursor(ECollisionChannel::ECC_Visibility, false, UnderMouseHitResult);

	// 마우스 아래에 아무것도 hit 하지 못했다면 그냥 넘어감
	if (!UnderMouseHitResult.bBlockingHit)
	{
		if (currentTarget)
		{
			currentTarget->SetOutLineOff();
		}
		return;
	}

	IOutlineInterface* TargetOutLineInterface = Cast<IOutlineInterface>(UnderMouseHitResult.GetActor());

	pastTarget = currentTarget;
	currentTarget = TargetOutLineInterface;

	if (pastTarget)
	{
		pastTarget->SetOutLineOff();
	}

	if (currentTarget)
	{
		currentTarget->SetOutLineOn();
	}

}
