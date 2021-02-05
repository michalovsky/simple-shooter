#include "KillThemAllGameMode.h"
#include "EngineUtils.h"
#include "GameFramework/Controller.h"
#include "ShooterAIController.h"


void AKillThemAllGameMode::StartPlay() 
{
    Super::StartPlay();

    for (AShooterAIController* Controller : TActorRange<AShooterAIController>(GetWorld()))
    {
        NumberOfEnemies++;
    }
}

void AKillThemAllGameMode::PawnKilled(APawn* PawnKilled) 
{
    Super::PawnKilled(PawnKilled);

    if (APlayerController* PlayerController = Cast<APlayerController>(PawnKilled->GetController()))
    {
        EndGame(false);
    }
    else
    {
        NumberOfKilledEnemies++;
    }

    for (AShooterAIController* Controller : TActorRange<AShooterAIController>(GetWorld()))
    {
        if (!Controller->IsDead())
        {
            return;
        }
    }

    EndGame(true);
}

int AKillThemAllGameMode::GetNumberOfKilledEnemies() const
{
    return NumberOfKilledEnemies;
}

int AKillThemAllGameMode::GetNumberOfEnemies() const
{
    return NumberOfEnemies;
}

void AKillThemAllGameMode::EndGame(bool bIsPlayerWinner) 
{
    NumberOfKilledEnemies = 0;

    for (AController* Controller : TActorRange<AController>(GetWorld()))
    {
        bool IsWinner = Controller->IsPlayerController() == bIsPlayerWinner;
        Controller->GameHasEnded(Controller->GetPawn(), IsWinner);
    }
}
