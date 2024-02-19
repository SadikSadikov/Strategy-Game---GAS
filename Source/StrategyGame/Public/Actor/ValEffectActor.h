#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ValEffectActor.generated.h"

class UNiagaraComponent;
class UNiagaraSystem;
class USphereComponent;

UCLASS()
class STRATEGYGAME_API AValEffectActor : public AActor
{
	GENERATED_BODY()
	
public:	

	AValEffectActor();

	virtual void Destroyed() override;

protected:
	
	virtual void BeginPlay() override;

private:

	UPROPERTY(EditAnywhere)
	TObjectPtr<UNiagaraComponent> NiagaraComp;

	UPROPERTY(EditAnywhere)
	TObjectPtr<UNiagaraSystem> PickupEffect;
	
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USphereComponent> SphereComp;

	UFUNCTION()
	void OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
};
