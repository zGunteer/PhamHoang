// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseActor.h"

// Sets default values
ABaseActor::ABaseActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
	RootComponent = StaticMesh;

	StaticMesh->SetCollisionProfileName(TEXT("Pawn"));
	StaticMesh->SetSimulatePhysics(true);

	static ConstructorHelpers::FObjectFinder<UMaterial>GetWhiteMaterial(TEXT("Material'/Game/StarterContent/Materials/M_Basic_Wall.M_Basic_Wall'"));
		if (GetWhiteMaterial.Succeeded())
		{
			WhiteMaterial = GetWhiteMaterial.Object;
		}

	static ConstructorHelpers::FObjectFinder<UMaterial>GetBlackMaterial(TEXT("Material'/Game/StarterContent/Blueprints/Assets/M_LightStage_Skybox_Master.M_LightStage_Skybox_Master'"));
		if (GetBlackMaterial.Succeeded())
		{
			BlackMaterial = GetBlackMaterial.Object;
		}

}

// Called when the game starts or when spawned
void ABaseActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABaseActor::SetSelected()
{
	
}

void ABaseActor::SetDeselected()
{

}

void ABaseActor::MoveActor(FVector MoveLocation)
{
	SetActorLocation(MoveLocation);
}

