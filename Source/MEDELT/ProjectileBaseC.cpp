// Fill out your copyright notice in the Description page of Project Settings.



#include "ProjectileBaseC.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Particles/ParticleSystemComponent.h"
#include "Particles/ParticleSystem.h"

// Sets default values
AProjectileBaseC::AProjectileBaseC()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CapsuleComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleCollision"));
	RootComponent = CapsuleComp; 
	//CapsuleComp->OnComponentHit.AddDynamic(this, &AProjectileBaseC::OnHit);

	ParticleSystem =  CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ParticleSystem"));
	ParticleSystem->SetupAttachment(RootComponent);

	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile Movement")); 

}
// Called when the game starts or when spawned
void AProjectileBaseC::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AProjectileBaseC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


}

void AProjectileBaseC::NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	
}



