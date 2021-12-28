// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/CapsuleComponent.h"
#include "Components/ArrowComponent.h"
#include "DrawDebugHelpers.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/KismetMathLibrary.h"
#include "ProjectileBaseC.h"
#include "AimComponent.h"
#include "MEDELTPlayerController.h"
#include "TurretBaseC.h"

// Sets default values
ATurretBaseC::ATurretBaseC()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	CapsuleComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule Collider")); //root dizine isim verme
	RootComponent = CapsuleComp; //root dizini belirleme

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base Mesh"));
	BaseMesh->SetupAttachment(RootComponent); 

	ProjectileSpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("Projectile Spawn Point")); 
	ProjectileSpawnPoint->SetupAttachment(BaseMesh); 

	Arrow = CreateDefaultSubobject<UArrowComponent>(TEXT("Arrow Component"));
	Arrow->SetupAttachment(RootComponent);

	MyAimComponent = CreateDefaultSubobject<UAimComponent>(TEXT("AimComponent"));
}

// Called when the game starts or when spawned
void ATurretBaseC::BeginPlay()
{
	Super::BeginPlay();
	AMEDELTPlayerController * MEDELTPlayerControllerRef = Cast<AMEDELTPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	BindToInput();
}

// Called every frame
void ATurretBaseC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	TArray<FHitResult> OutHits;
	FVector StartLocation;
	FVector EndLocation;
	FVector WorldLocation;
	FVector WorldDirection;
	UGameplayStatics::GetPlayerController(GetWorld(), 0)->DeprojectMousePositionToWorld(WorldLocation, WorldDirection);
	EndLocation = WorldDirection +(WorldDirection * 1000000);

	GetWorld()->LineTraceMultiByChannel(OutHits, StartLocation, EndLocation, ECC_Visibility);
	FVector InVec = MyAimComponent->AimLocation(WorldLocation, EndLocation) - Arrow->GetComponentLocation();
	UKismetMathLibrary::GetYawPitchFromVector(InVec, AimYaw, AimPitch);
	FRotator NewWorldRotation;
	NewWorldRotation.Roll = 0.f;
	NewWorldRotation.Yaw = AimPitch;
	NewWorldRotation.Pitch = AimYaw;
	Arrow->SetWorldRotation(NewWorldRotation, false, false);
}

void ATurretBaseC::BindToInput()
{
	InputComponent = NewObject<UInputComponent>(this);
    InputComponent->RegisterComponent();
    if (InputComponent)
    {
        // Bind inputs here
        // InputComponent->BindAction("Jump", IE_Pressed, this, &AUnrealisticPawn::Jump);
        // etc...
		InputComponent->BindAction("Fire", IE_Pressed, this, &ATurretBaseC::Fire);
        // Now hook up our InputComponent to one in a Player
        // Controller, so that input flows down to us
        EnableInput(Cast<AMEDELTPlayerController>(GetOwner()));
    }   
}

void ATurretBaseC::Fire()
{
	FVector SpawnLocation = ProjectileSpawnPoint->GetComponentLocation();
	FRotator SpawnRotation = ProjectileSpawnPoint->GetComponentRotation();
	AProjectileBaseC* Pro = GetWorld()->SpawnActor<AProjectileBaseC>(ProjectileClass, SpawnLocation, SpawnRotation);
	Pro->SetOwner(this); 
}

