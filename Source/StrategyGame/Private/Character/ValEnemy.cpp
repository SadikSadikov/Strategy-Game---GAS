// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/ValEnemy.h"
#include "StrategyGame/StrategyGame.h"
#include "AbilitySystem/ValAbilitySystemComponent.h"
#include "AbilitySystem/ValAttributeSet.h"

AValEnemy::AValEnemy()
{
	GetMesh()->SetCollisionResponseToChannel(ECollisionChannel::ECC_Visibility, ECollisionResponse::ECR_Block);

	AbilitySystemComp = CreateDefaultSubobject<UValAbilitySystemComponent>("AbilitySytemComponent");
	AbilitySystemComp->SetIsReplicated(true);
	AbilitySystemComp->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);

	AttributeSet = CreateDefaultSubobject<UValAttributeSet>("Attribute Set");
}

void AValEnemy::BeginPlay()
{
	Super::BeginPlay();

	AbilitySystemComp->InitAbilityActorInfo(this, this);
}

void AValEnemy::Highlight()
{
	GetMesh()->SetRenderCustomDepth(true);
	GetMesh()->SetCustomDepthStencilValue(CUSTOM_DEPTH_STENCIL_BLUE);

	Weapon->SetRenderCustomDepth(true);
	Weapon->SetCustomDepthStencilValue(CUSTOM_DEPTH_STENCIL_BLUE);
}

void AValEnemy::UnHighlight()
{
	GetMesh()->SetRenderCustomDepth(false);
	Weapon->SetRenderCustomDepth(false);
}


