// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "CardWidget.generated.h"

/**
 * 
 */
UCLASS()
class MAGE_API UCardWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UImage* KeyArt;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,meta =(BindWidget))
	UTextBlock* ButtonTextBlock;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,meta =(BindWidget))
	UTextBlock* ButtonDescriptionTextBlock;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	int32 CardNumber;
};
