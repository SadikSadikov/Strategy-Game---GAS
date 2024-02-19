#include "Actor/ValEffectActor.h"
#include "Components/SphereComponent.h"
#include "AbilitySystemInterface.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystem/ValAttributeSet.h"
#include "NiagaraComponent.h"
#include "NiagaraFunctionLibrary.h"


AValEffectActor::AValEffectActor()
{

	PrimaryActorTick.bCanEverTick = false;

	NiagaraComp = CreateDefaultSubobject<UNiagaraComponent>("NiagaraSystem");
	SetRootComponent(NiagaraComp);

	SphereComp = CreateDefaultSubobject<USphereComponent>("Sphere");
	SphereComp->SetupAttachment(NiagaraComp);


}

void AValEffectActor::Destroyed()
{

	UNiagaraFunctionLibrary::SpawnSystemAtLocation(
		this,
		PickupEffect,
		GetActorLocation(),
		GetActorRotation()
	);

	Super::Destroyed();
}

void AValEffectActor::BeginPlay()
{
	Super::BeginPlay();

	SphereComp->OnComponentBeginOverlap.AddDynamic(this, &AValEffectActor::OnSphereBeginOverlap);
	SphereComp->OnComponentEndOverlap.AddDynamic(this, &AValEffectActor::OnSphereEndOverlap);
	
}

void AValEffectActor::OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// TODO: Change this to the Gameplay Effect. This is for the demostration purpose 

	if (IAbilitySystemInterface* AbilitySysteminterface = Cast<IAbilitySystemInterface>(OtherActor))
	{
		const UValAttributeSet* ValAttributeSet = Cast<UValAttributeSet>(AbilitySysteminterface->GetAbilitySystemComponent()->GetAttributeSet(UValAttributeSet::StaticClass()));

		UValAttributeSet* MutableValAS = const_cast<UValAttributeSet*>(ValAttributeSet);

		MutableValAS->SetHealth(MutableValAS->GetHealth() + 25.f);

		Destroy();
	}
}

void AValEffectActor::OnSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
}



