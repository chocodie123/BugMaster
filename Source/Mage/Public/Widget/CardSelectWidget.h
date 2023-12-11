// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CardWidget.h"
#include "Blueprint/UserWidget.h"
#include "CardSelectWidget.generated.h"

struct FCardTableStructure;
/**
 * 
 */
UCLASS()
class MAGE_API UCardSelectWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	

	virtual void NativeConstruct() override;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,meta=(BindWidget))
	UCardWidget* Card1;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,meta=(BindWidget))
	UCardWidget* Card2;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,meta=(BindWidget))
	UCardWidget* Card3;
	
	
};
