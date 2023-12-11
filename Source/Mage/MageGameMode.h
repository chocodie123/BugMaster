// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MageGameMode.generated.h"


UENUM(BlueprintType)
enum class ECardType
{
	Bug UMETA(DisplayName = "Bug")
	,Skill UMETA(DisplayName = "Skill")
	,Upgrade UMETA(DisplayName = "Upgrade")
};

USTRUCT(BlueprintType)
struct FCardTableStructure : public FTableRowBase
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	ECardType CardType;	
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	UMaterialInstance* Image;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText Title;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText SubTitle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 CardNum;
};



UCLASS(minimalapi)
class AMageGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AMageGameMode();
};



