// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseActor.generated.h"

UCLASS()
class CHESS_API ABaseActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
		void SetSelected();

	UFUNCTION()
		void SetDeselected();

	UFUNCTION()
		void MoveActor(FVector MoveLocation);

	UPROPERTY(EditAnywhere)
		bool bIsWhite;

	UPROPERTY(EditAnywhere)
		bool bHasEverMoved;

	UPROPERTY(VisibleAnyWhere)
		class UStaticMeshComponent* StaticMesh;

	UPROPERTY(EditAnywhere)
		class UMaterial* WhiteMaterial;

	UPROPERTY(EditAnywhere)
		class UMaterial* BlackMaterial;


};
