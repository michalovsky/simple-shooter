#pragma once

#include "CoreMinimal.h"
#include "SimpleShooterGameModeBase.h"
#include "KillThemAllGameMode.generated.h"

UCLASS()
class SIMPLESHOOTER_API AKillThemAllGameMode : public ASimpleShooterGameModeBase
{
	GENERATED_BODY()
public:
    void StartPlay() override;
	void PawnKilled(APawn* PawnKilled) override;

	UFUNCTION(BlueprintPure)
	int GetNumberOfKilledEnemies() const;

	UFUNCTION(BlueprintPure)
	int GetNumberOfEnemies() const;

private:
	void EndGame(bool bIsPlayerWinner);
	
	UPROPERTY(VisibleAnywhere)
	int NumberOfKilledEnemies = 0;

	UPROPERTY(VisibleAnywhere)
	int NumberOfEnemies = 0;
};
