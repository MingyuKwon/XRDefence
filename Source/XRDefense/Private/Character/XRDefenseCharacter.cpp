
#include "Character/XRDefenseCharacter.h"
#include "XRDefense/XRDefense.h"
#include "Components/CapsuleComponent.h"

AXRDefenseCharacter::AXRDefenseCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	  
	GetMesh()->SetCollisionEnabled(ECollisionEnabled::NoCollision);

}

void AXRDefenseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	// 초기에 어떤 테두리 색이 될 지 정함
	int32 StencilValue = 0;
	switch (objectType)
	{
	case EObjectType::EOT_NONE:
		StencilValue = WHITE_STENCIL;
		break;
	case EObjectType::EOT_ATTACKER:
		StencilValue = RED_STENCIL;
		break;
	case EObjectType::EOT_DEFENDER:
		StencilValue = BLUE_STENCIL;
		break;
	}

	FString str = FString::Printf(TEXT("%d"), StencilValue);
	GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Red, *str);

	GetMesh()->SetCustomDepthStencilValue(StencilValue);


	SetOutLineOn();
}

void AXRDefenseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AXRDefenseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AXRDefenseCharacter::SetOutLineOn()
{
	GetMesh()->SetRenderCustomDepth(true);


	
}

void AXRDefenseCharacter::SetOutLineOff()
{
	GetMesh()->SetRenderCustomDepth(false);

}

