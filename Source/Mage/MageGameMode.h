// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BugInfo.h"
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
	UFUNCTION(BlueprintCallable)
	void CardSelect(int32 CardNum);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UBugInfo* MainGameBugInfo;

	UFUNCTION(BlueprintCallable)
	void SpawnBeetle(FTransform Transform);

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	TSubclassOf<class ABeetle> BeetleFactory;
};



