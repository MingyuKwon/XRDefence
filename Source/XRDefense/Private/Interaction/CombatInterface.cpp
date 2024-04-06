// Fill out your copyright notice in the Description page of Project Settings.


#include "Interaction/CombatInterface.h"

// Add default functionality here for any ICombatInterface functions that are not pure virtual.

EObjectType ICombatInterface::GetObjectType()
{
    return EObjectType();
}

float ICombatInterface::GetAttackRange()
{
    return 0.0f;
}
