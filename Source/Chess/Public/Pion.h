// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseActor.h"
#include "Pion.generated.h"

/**
 * 
 */
UCLASS()
class CHESS_API APion : public ABaseActor
{
	GENERATED_BODY()

public:

	APion();

	void DetectSelectableGrids(TArray<UStaticMeshComponent*>* SelectableGrids);
};


