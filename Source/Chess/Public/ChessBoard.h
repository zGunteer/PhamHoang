// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "BaseActor.h"
#include "ChessBoard.generated.h"



UCLASS()
class CHESS_API AChessBoard : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AChessBoard();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY()
		class UBoxComponent* BoxComponent;

	UPROPERTY()
		TArray<class UStaticMeshComponent*> StaticMeshes;

		//TArray<class ABaseActor*> SpawnedPieces;  ?

	UPROPERTY(EditAnywhere)
		class UMaterial* LightMaterial;

	UPROPERTY(EditAnywhere)
		class UMaterial* DarkMaterial;

	UPROPERTY()
		class UMaterial* DefaultMaterial;
	
	UPROPERTY(EditAnywhere)
		class UStaticMesh* DefaultMesh;

};
