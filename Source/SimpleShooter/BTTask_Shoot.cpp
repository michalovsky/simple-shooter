#include "BTTask_Shoot.h"

#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "ShooterCharacter.h"

UBTTask_Shoot::UBTTask_Shoot() 
{
    NodeName = TEXT("Shoot");
}

EBTNodeResult::Type UBTTask_Shoot::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) 
{
    Super::ExecuteTask(OwnerComp, NodeMemory);

    auto AIOwner = OwnerComp.GetAIOwner();
    if (!AIOwner)
    {
        return EBTNodeResult::Type::Failed;
    }

    AShooterCharacter* Character = Cast<AShooterCharacter>(AIOwner->GetPawn());

    if (!Character)
    {
        return EBTNodeResult::Type::Failed;
    }

    Character->ShootGun();
    
    return EBTNodeResult::Type::Succeeded;
}
