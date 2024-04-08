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
    ProjectileMovement->HomingAccelerationMagnitude = 2000.f; // ���� ź�� Ȩ�� ���ӵ� ����

    ProjectileMovement->bRotationFollowsVelocity = true;
    ProjectileMovement->MaxSpeed = 10000.f;
    ProjectileMovement->InitialSpeed = 2000.f; // �ʱ� �ӵ� ����
}

void AProjectile::SetTarget(AActor* Target)
{
    if (ProjectileMovement && Target)
    {
        // Ÿ���� SkeletalMeshComponent �Ǵ� StaticMeshComponent ���� Ȩ�� Ÿ������ ����
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
    // BeginPlay������ �߰����� ���� (�ʿ��� ���)
}

void AProjectile::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    // Tick������ �߰����� ���� (�ʿ��� ���)
}
