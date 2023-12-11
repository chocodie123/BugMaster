// Fill out your copyright notice in the Description page of Project Settings.


#include "Widget/CardSelectWidget.h"
#include "Components/Image.h"
#include "Mage/MageGameMode.h"


void UCardSelectWidget::NativeConstruct()
{
	Super::NativeConstruct();

	UDataTable* CardTable = LoadObject<UDataTable>(
		nullptr,TEXT("/Script/Engine.DataTable'/Game/Data/NewDataTable.NewDataTable'"));
	if(CardTable)
	{
		TArray<FCardTableStructure*> Rows ;
		CardTable->GetAllRows<FCardTableStructure>(TEXT("GetAllRows"),Rows);
		if(Rows.Num()>=3)
		{
			
			int Random = FMath::RandRange(1,Rows.Num());
			FCardTableStructure* RandItem = Rows[Random-1];
			Card1->KeyArt->SetBrushResourceObject(RandItem->Image);
			Card1->ButtonTextBlock->SetText(RandItem->Title);
			Card1->ButtonDescriptionTextBlock->SetText(RandItem->SubTitle);
			Rows.RemoveAt(Random-1);

			Random = FMath::RandRange(1,Rows.Num()-1);
			RandItem = Rows[Random-1];
			Card2->KeyArt->SetBrushResourceObject(RandItem->Image);
			Card2->ButtonTextBlock->SetText(RandItem->Title);
			Card2->ButtonDescriptionTextBlock->SetText(RandItem->SubTitle);
			Rows.RemoveAt(Random-1);

			Random = FMath::RandRange(1,Rows.Num()-2);
			RandItem = Rows[Random-1];
			Card3->KeyArt->SetBrushResourceObject(RandItem->Image);
			Card3->ButtonTextBlock->SetText(RandItem->Title);
			Card3->ButtonDescriptionTextBlock->SetText(RandItem->SubTitle);
			
		}
		
	}
}


