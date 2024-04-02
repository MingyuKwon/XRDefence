
#include "Character/XRDefenseCharacter.h"
#include "XRDefense/XRDefense.h"
#include "Components/CapsuleComponent.h"

AXRDefenseCharacter::AXRDefenseCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	  
	// 전체적인 충격 감지 캡슐은 카메라와 부딪히지 않도록 함
	GetCapsuleComponent()->SetCollisionResponseToChannel(ECollisionChannel::ECC_Camera, ECollisionResponse::ECR_Ignore);

	// 몬스터 에셋은 충돌을 아예 없앰
	GetMesh()->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	GetMesh()->SetCollisionResponseToChannel(ECollisionChannel::ECC_Visibility, ECollisionResponse::ECR_Block);

	CharacterFloorMesh = CreateDefaultSubobject<UStaticMeshComponent>(FName("Floor Mesh"));
	CharacterFloorMesh->SetupAttachment(GetMesh());
}

void AXRDefenseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	// 초기에 어떤 테두리 색이 될 지 정함
	SetDefaultStencilValue();

	switch (objectType)
	{
	case EObjectType::EOT_NONE:
		if (NoneCircle)
		{
			CharacterFloorMesh->SetStaticMesh(NoneCircle);
		}
		break;
	case EObjectType::EOT_ATTACKER:
		if (OffenceCircle)
		{
			CharacterFloorMesh->SetStaticMesh(OffenceCircle);
		}
		break;
	case EObjectType::EOT_DEFENDER:
		if (DefenseCircle)
		{
			CharacterFloorMesh->SetStaticMesh(DefenseCircle);
		}
		break;
	}

	FloorMeshFirstStartPosition = CharacterFloorMesh->GetComponentLocation();

	GetMesh()->SetRenderCustomDepth(true);
	CharacterFloorMesh->SetRenderCustomDepth(true);
}


void AXRDefenseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	SetFloorMeshPosition(DeltaTime);
}

void AXRDefenseCharacter::SetFloorMeshPosition(float DeltaTime)
{
	FHitResult LinetraceResult;
	GetWorld()->LineTraceSingleByChannel(LinetraceResult, GetActorLocation(), GetActorLocation() + FVector::DownVector * TRACE_LENGTH, ECollisionChannel::ECC_FloorTraceChannel);

	if (LinetraceResult.bBlockingHit)
	{
		CharacterFloorMesh->SetWorldLocation(LinetraceResult.ImpactPoint + FVector::UpVector * 2.f);
	}
	else
	{
		CharacterFloorMesh->SetWorldLocation(FloorMeshFirstStartPosition);
	}
}

void AXRDefenseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AXRDefenseCharacter::SetHighLightOn()
{
	SetHighlightStencilValue();

	bIsHighlighted = true;
}

void AXRDefenseCharacter::SetHighLightOff()
{
	SetDefaultStencilValue();

	bIsHighlighted = false;
}

void AXRDefenseCharacter::SetHighlightStencilValue()
{
	GetMesh()->SetCustomDepthStencilValue(WHITE_STENCIL);
	CharacterFloorMesh->SetCustomDepthStencilValue(WHITE_STENCIL);

}

void AXRDefenseCharacter::SetDefaultStencilValue()
{
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

	GetMesh()->SetCustomDepthStencilValue(StencilValue);
	CharacterFloorMesh->SetCustomDepthStencilValue(StencilValue);

}



