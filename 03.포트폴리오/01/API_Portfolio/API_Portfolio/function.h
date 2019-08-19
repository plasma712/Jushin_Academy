#pragma once
#include "GameObject.h"

void SetObjectDead(CGameObject* pObject)
{
	pObject->SetDamaged();
}