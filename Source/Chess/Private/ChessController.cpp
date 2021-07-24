// Fill out your copyright notice in the Description page of Project Settings.


#include "ChessController.h"
#include "Pion.h"
#include "ChessBoard.h"
#include "ChessPlayer.h"


AChessController::AChessController()
{
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Crosshairs;
}

void AChessController::BeginPlay()
{
	Super::BeginPlay();
	
	AChessBoard* Board = GetWorld()->SpawnActor<AChessBoard>(FVector(0, 0, 0), FRotator(0, 0, 0));

	PlayerTwo = GetWorld()->SpawnActor<AChessPlayer>(FVector(410.0, 850.0, 280), FRotator(20.0f, -90.0f, 0.0f));
	PlayerTwo->bIsWhite = false;
	PlayerOne = GetWorld()->SpawnActor<AChessPlayer>(FVector(340.0, -70.0, 280), FRotator(20.0f, 90.0f, 0.0f));
	PlayerOne->bIsWhite = true;
	CurrentPlayer = PlayerOne;

	PreviousPlayer = PlayerOne;

	SpawnWhitePawns();
	SpawnBlackPawns();
	

}

void AChessController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAction("LeftMouseClick", IE_Pressed, this, &AChessController::OnLeftMouseClick);
}

void AChessController::OnLeftMouseClick()
{

	if (this->SelectedPiece != nullptr)
	{
		this->SelectedPiece->SetDeselected();
	}
	
	SelectPiece();
}

void AChessController::SelectPiece()
{
	FHitResult TraceResult(ForceInit);
	GetHitResultUnderCursor(ECollisionChannel::ECC_WorldDynamic, false, TraceResult);

	if (TraceResult.GetActor() != nullptr)
	{
		if (TraceResult.GetActor()->IsA(ABaseActor::StaticClass()))
		{
			SelectedPiece = Cast<ABaseActor>(TraceResult.GetActor());
			if (SelectedPiece != nullptr)
			{
				if (SelectedPiece->bIsWhite == CurrentPlayer->bIsWhite)
				{
					SelectedPiece->SetSelected();
					IsAnythingSelected = true;
					return;
				}
			}
		}
	}
	IsAnythingSelected = false;
}


void AChessController::MakeMove()
{
	SelectedPiece->MoveActor(FVector(GridLocation.X, GridLocation.Y, SelectedPiece->GetActorLocation().Z + 200));
	if (!SelectedPiece->bHasEverMoved)
	{
		SelectedPiece->bHasEverMoved = true;
	}
	SwitchPlayer();
}


void AChessController::SwitchPlayer()
{
	UnPossess();

	if (CurrentPlayer == PlayerTwo)
	{
		PreviousPlayer = PlayerTwo;
		CurrentPlayer = PlayerOne;
		Possess(PlayerOne);
	}
	else if (CurrentPlayer == PlayerOne)
	{
		PreviousPlayer = PlayerOne;
		CurrentPlayer = PlayerTwo;
		Possess(PlayerTwo);
	}
}

AChessPlayer* AChessController::GetCurrentPlayer()
{
	return CurrentPlayer;
}
void AChessController::Cancel()
{
	SelectedPiece->SetDeselected();
	SelectableGrids.Empty();
	SelectedPiece = nullptr;
}

void AChessController::SpawnWhitePawns()
{
	//TArray<class ABaseActor*>SpawnedPioni;

	for (int i = 2; i <= 9; i++)
	{
		/*SpawnedPioni.Add*/(GetWorld()->SpawnActor<APion>(FVector((i * 100.0f), -20.0f, 200.0f), FRotator::ZeroRotator));
	}
	//PlayerOne->Pieces = SpawnedPioni;
	//SpawnedPioni.Empty();
}

void AChessController::SpawnBlackPawns()
{
	//TArray<class ABaseActor*> SpawnedPioni;

	for (int j = 2; j <= 9; j++)
	{
		/*SpawnedPioni.Add*/GetWorld()->SpawnActor<APion>(FVector((j * 100.0f), 500.0f, 120.0f), FRotator::ZeroRotator);
	}
	//PlayerTwo->Pieces = SpawnedPioni;
	//SpawnedPioni.Empty();
}

