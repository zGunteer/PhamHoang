// Fill out your copyright notice in the Description page of Project Settings.


#include "ChessBoard.h"
#include "Pion.h"
#include "ChessPlayer.h"
#include "ChessController.h"

// Sets default values
AChessBoard::AChessBoard()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	RootComponent = BoxComponent;
	BoxComponent->InitBoxExtent(FVector(0, 0, 0));

	static ConstructorHelpers::FObjectFinder<UMaterial> Material(TEXT("Material'/Game/StarterContent/Blueprints/Assets/M_LightStage_Skybox_Master.M_LightStage_Skybox_Master'"));
	if (Material.Object != NULL)
	{
		LightMaterial = (UMaterial*)Material.Object;
	}
	
	static ConstructorHelpers::FObjectFinder<UMaterial> Material2(TEXT("Material'/Game/StarterContent/Materials/M_Basic_Wall.M_Basic_Wall'"));
	if (Material2.Object != NULL)
	{
		DarkMaterial = (UMaterial*)Material2.Object;
	}

	for (int tile = 0; tile < 64; tile++)
	{
		int XCoordinates = (tile % 8) * 103;
		int YCoordinates = (tile / 8) * 103;

		StaticMeshes.Add(CreateDefaultSubobject<UStaticMeshComponent>(*FString("Mesh" + FString::FromInt(tile))));
		StaticMeshes[tile]->SetupAttachment(BoxComponent);

		static ConstructorHelpers::FObjectFinder<UStaticMesh> StaticMeshAsset(TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'"));  

		/*if (DefaultMesh)
		{
			StaticMeshes[tile]->SetStaticMesh(DefaultMesh);

			StaticMeshes[tile]->SetRelativeLocation(FVector(XCoordinates, YCoordinates, 0));
		}*/

		if (StaticMeshAsset.Succeeded())
		{
			StaticMeshes[tile]->SetStaticMesh(StaticMeshAsset.Object);
			StaticMeshes[tile]->SetRelativeLocation(FVector(XCoordinates, YCoordinates, 0));
		}
		
	}
}


// Called when the game starts or when spawned
void AChessBoard::BeginPlay()
{
	Super::BeginPlay();

	for (int tile = 0; tile < 64; tile++)
	{
		int Par = (tile % 8) % 2;
		int Impar = (tile / 8) % 2;

		if (Par == Impar)
		{
			StaticMeshes[tile]->SetMaterial(0, LightMaterial);
			DefaultMaterial = LightMaterial;
		}
		else
		{
			StaticMeshes[tile]->SetMaterial(0, DarkMaterial);
			DefaultMaterial = DarkMaterial;
		}
		
	}

}

// Called every frame
void AChessBoard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}



