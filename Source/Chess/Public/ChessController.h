// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ChessBoard.h"
#include "BaseActor.h"
#include "ChessController.generated.h"

/**
 * 
 */
UCLASS()
class CHESS_API AChessController : public APlayerController
{
	GENERATED_BODY()

public:
	AChessController();

	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

	UFUNCTION()
		void OnLeftMouseClick();

	UFUNCTION()
		void SelectPiece();

	UFUNCTION()
		void SwitchPlayer();

	UFUNCTION(BlueprintPure)
		AChessPlayer* GetCurrentPlayer();

	UFUNCTION()
		void MakeMove();

	UFUNCTION()
		void Cancel();

	UFUNCTION()
		void SpawnWhitePawns();

	UFUNCTION()
		void SpawnBlackPawns();


	TArray<class UStaticMeshComponent* > SelectableGrids;
	
	bool IsAnythingSelected = false;

	ABaseActor* SelectedPiece;

	UStaticMeshComponent* SelectableGrid;

	UPROPERTY()
		FVector GridLocation;

	UPROPERTY(VisibleAnyWhere)
		class UMaterial* SelectedMaterial;

	UPROPERTY()
		AChessPlayer* PlayerOne;
	UPROPERTY()
		AChessPlayer* PlayerTwo;
	UPROPERTY()
		AChessPlayer* PreviousPlayer;
	UPROPERTY()
		AChessPlayer* CurrentPlayer;

	AChessBoard* ChessBoard;
	
};
