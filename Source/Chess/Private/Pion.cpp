// Fill out your copyright notice in the Description page of Project Settings.



#include "Pion.h"
#include "ChessBoard.h"
#include "ChessController.h"

APion::APion()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> FoundMesh(TEXT("StaticMesh'/Game/ChessPieces/chess_Line015.chess_Line015'"));
	if (FoundMesh.Succeeded())
	{
		StaticMesh->SetStaticMesh(FoundMesh.Object);
		StaticMesh->SetWorldScale3D(FVector(10, 10, 10));
	}

	
}

void APion::DetectSelectableGrids(TArray<UStaticMeshComponent*>* SelectableGrids)
{
	FVector SpawnLocation;

	if (bIsWhite)
	{
		SpawnLocation = FVector(GetActorLocation().X, GetActorLocation().Y + 400.0f, 0.0f);
	}
	else
	{
		SpawnLocation = FVector(GetActorLocation().X, GetActorLocation().Y - 400.0f, 0.0f);
	}

	if (bHasEverMoved)
	{
		if (bIsWhite)
		{
			SpawnLocation = FVector(GetActorLocation().X, GetActorLocation().Y + 800.0f, 0.0f);
		}
		else 
		{
			SpawnLocation = FVector(GetActorLocation().X, GetActorLocation().Y + 800.0f, 0.0f);
		}
	}
}

