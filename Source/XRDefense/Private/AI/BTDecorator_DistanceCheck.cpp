// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/BTDecorator_DistanceCheck.h"
#include "Interaction/CombatInterface.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"


UBTDecorator_DistanceCheck::UBTDecorator_DistanceCheck()
{
	NodeName = "Close Enough to";

}

bool UBTDecorator_DistanceCheck::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
    UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
    if (BlackboardComp == nullptr) return false;
    
    // AI ��Ʈ�ѷ��� ����
    AAIController* AIController = OwnerComp.GetAIOwner();
    if (AIController == nullptr) return false;
    
    // AI ��Ʈ�ѷ��� �����ϴ� ��(ĳ����)�� ����
    APawn* ControlledPawn = AIController->GetPawn();
    if (ControlledPawn == nullptr) return false;
    
    ICombatInterface* Combat = Cast<ICombatInterface>(ControlledPawn);
    if (Combat == nullptr) return false;
    

    // �� Ű�� ���� �����ɴϴ�
    float FirstValue = Combat->GetAttackRange();
    float SecondValue = DIstanceValue;


    FString str = FString::Printf(TEXT("%f : %f"), FirstValue, SecondValue);
    GEngine->AddOnScreenDebugMessage(1, 1.f, FColor::Orange , *str);

    // �� ��
    return FirstValue >= SecondValue; 
}
