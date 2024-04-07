// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/XRDefenceAIController.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"


AXRDefenceAIController::AXRDefenceAIController()
{
	Blackboard = CreateDefaultSubobject<UBlackboardComponent>(FName("BlackboardComponent"));
	check(Blackboard);

	BehaviorTreeComponent = CreateDefaultSubobject<UBehaviorTreeComponent>(FName("BehaviorTreeComponent"));
	check(BehaviorTreeComponent);



}
