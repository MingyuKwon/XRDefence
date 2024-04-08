#include "Battle/Projectile.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "GameFramework/Character.h"
#include "Components/SkeletalMeshComponent.h"

// Sets default values
AProjectile::AProjectile()
{
    PrimaryActorTick.bCanEverTick = true;

    BulletMesh = CreateDefaultSubobject<UStaticMeshComponent>(FName("Bullet Mesh"));

    ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(FName("Projectile Movement"));
    ProjectileMovement->bIsHomingProjectile = true;
    ProjectileMovement->HomingAccelerationMagnitude = 2000.f; // 유도 탄의 홈밍 가속도 설정

    ProjectileMovement->bRotationFollowsVelocity = true;
    ProjectileMovement->MaxSpeed = 10000.f;
    ProjectileMovement->InitialSpeed = 2000.f; // 초기 속도 설정
}

void AProjectile::SetTarget(AActor* Target)
{
    if (ProjectileMovement && Target)
    {
        // 타겟의 SkeletalMeshComponent 또는 StaticMeshComponent 등을 홈밍 타겟으로 설정
        UPrimitiveComponent* TargetComponent = Cast<UPrimitiveComponent>(Target->GetRootComponent());
        if (TargetComponent)
        {
            ProjectileMovement->HomingTargetComponent = TargetComponent;
        }
    }
}

void AProjectile::SetDamage(float Damage)
{
    BulletDamage = Damage;
}

void AProjectile::BeginPlay()
{
    Super::BeginPlay();
    // BeginPlay에서의 추가적인 로직 (필요한 경우)
}

void AProjectile::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    // Tick에서의 추가적인 로직 (필요한 경우)
}
