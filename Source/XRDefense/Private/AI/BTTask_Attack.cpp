// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/BTTask_Attack.h"
#include "AIController.h"
#include "Interaction/CombatInterface.h"

EBTNodeResult::Type UBTTask_Attack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    AAIController* AIController = OwnerComp.GetAIOwner();
    if (AIController == nullptr) return EBTNodeResult::Failed;

    APawn* ControlledPawn = AIController->GetPawn();
    if (ControlledPawn == nullptr) return EBTNodeResult::Failed;

    ICombatInterface* Combat = Cast<ICombatInterface>(ControlledPawn);
    if (Combat == nullptr) return EBTNodeResult::Failed;

    // �񵿱� ���� ����. ���� �Ϸ� �� OnAttackFinished �ݹ� ȣ�� ����
    Combat->Attack(FOnAttackFinished::CreateUObject(this, &UBTTask_Attack::OnAttackFinished));

    // �½�ũ�� ���� ������ �˸�. ���� �Ϸ�� �ݹ鿡�� ó����
    return EBTNodeResult::InProgress;
}

// ���� �Ϸ� �ݹ�
void UBTTask_Attack::OnAttackFinished(bool bSuccess)
{
    if (bSuccess)
    {
        FinishExecute(true); // ���������� �Ϸ�
    }
    else
    {
        FinishExecute(false); // ���з� �Ϸ�
    }
}