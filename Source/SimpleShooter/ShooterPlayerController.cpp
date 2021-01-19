#include "ShooterPlayerController.h"
#include "TimerManager.h"
#include "Blueprint/UserWidget.h"

void AShooterPlayerController::BeginPlay() 
{
    Super::BeginPlay();

    HUD = CreateWidget(this, HUDClass);
    if (HUD)
    {
        HUD->AddToViewport();
    }
}

void AShooterPlayerController::GameHasEnded(AActor* EndGameFocus, bool bIsWinner) 
{
    Super::GameHasEnded(EndGameFocus, bIsWinner);
    
    if (HUD)
    {
        HUD->RemoveFromViewport();
    }

    if (bIsWinner)
    {
        if (UUserWidget* WinScreen = CreateWidget(this, WinScreenClass))
        {
            WinScreen->AddToViewport();
        }
    }
    else
    {
        if (UUserWidget* LoseScreen = CreateWidget(this, LoseScreenClass))
        {
            LoseScreen->AddToViewport();
        }
    }

    
    GetWorldTimerManager().SetTimer(RestartHandle, this, &APlayerController::RestartLevel, RestartDelay);
}

