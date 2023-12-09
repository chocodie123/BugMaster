// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyHPWidget.h"

#include "Components/ProgressBar.h"

void UEnemyHPWidget::UpdateHP(float HP, float MaxHp)
{
	HPBar->SetPercent(HP/MaxHp); 
}
