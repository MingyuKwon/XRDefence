#include "Battle/Projectile.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "GameFramework/Character.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/CapsuleComponent.h"
#include "XRDefense/XRDefense.h"
#include "Kismet/GameplayStatics.h"
#include "Component/NotHitSelf_PMC.h"

// Sets default values
AProjectile::AProjectile()
{
    PrimaryActorTick.bCanEverTick = true;

    Capsule = CreateDefaultSubobject<UCapsuleComponent>(FName("Capsule collision"));
    RootComponent = Capsule;
    Capsule->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
    Capsule->SetCollisionObjectType(ECollisionChannel::ECC_BulletTraceChannel);
    Capsule->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
    Capsule->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Block);

    BulletMesh = CreateDefaultSubobject<UStaticMeshComponent>(FName("Bullet Mesh"));
    BulletMesh->SetupAttachment(Capsule);
    BulletMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
    BulletMesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);

    Projectile_Movement = CreateDefaultSubobject<UNotHitSelf_PMC>(FName("NoProjectile Movement"));
    Projectile_Movement->bIsHomingProjectile = true;
    Projectile_Movement->HomingAccelerationMagnitude = 2000.f; // ���� ź�� Ȩ�� ���ӵ� ����

    Projectile_Movement->bRotationFollowsVelocity = true;
    Projectile_Movement->MaxSpeed = 10000.f;
    Projectile_Movement->InitialSpeed = 2000.f; // �ʱ� �ӵ� ����
}

void AProjectile::SetTarget(AActor* Target)
{
    if (Projectile_Movement && Target)
    {
        // Ÿ���� SkeletalMeshComponent �Ǵ� StaticMeshComponent ���� Ȩ�� Ÿ������ ����
        UPrimitiveComponent* TargetComponent = Cast<UPrimitiveComponent>(Target->GetRootComponent());
        if (TargetComponent)
        {
            Projectile_Movement->HomingTargetComponent = TargetComponent;
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
    BulletDamage = 50;
}

void AProjectile::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
    AController* Controller = GetInstigator()->GetController();

    if (GetOwner() == OtherActor)
    {
        return;
    }

    UGameplayStatics::ApplyDamage(OtherActor, BulletDamage, Controller, this, UDamageType::StaticClass());
    Destroy();

}

void AProjectile::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    // Tick������ �߰����� ���� (�ʿ��� ���)
}
