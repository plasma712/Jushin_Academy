#include "stdafx.h"
#include "EffectManager.h"
#include "Effect.h"
#include "Scene.h"


CEffectManager::CEffectManager()
{
}


CEffectManager::~CEffectManager()
{
}

void CEffectManager::CreateEffect(INFO _targetInfo)
{
	CreateEffect(_targetInfo.fX, _targetInfo.fY, L"Effect1");
}

void CEffectManager::CreateEffect(float x, float y,wstring name)
{
	if (y > 800)
		return;
	CGameObject* pGameObject = nullptr;
	pGameObject = CAbstractFactory<CEffect>::CreateObject();
	pGameObject->Initialize();
	pGameObject->SetPos(x,y);
	pGameObject->SetSprite(name);
	CMainGame::GetInstance()->GetScene()->GetOBJLST()[OBJECT_EFFECT].push_back(pGameObject);
}

void CEffectManager::CreatePlayerAttackEffect(float x, float y, wstring name)
{
	if (y > 800)
		return;
	CGameObject* pGameObject = nullptr;
	pGameObject = CAbstractFactory<CEffect>::CreateObject();
	pGameObject->Initialize();
	pGameObject->SetPos(x, y);
	pGameObject->SetSprite(name);
	CMainGame::GetInstance()->GetScene()->GetOBJLST()[OBJECT_PLAYERATTACKEFFECT].push_back(pGameObject);
}

void CEffectManager::CreatePlayerAttackEffect2(float x, float y, wstring name)
{
	if (y > 800)
		return;
	CGameObject* pGameObject = nullptr;
	pGameObject = CAbstractFactory<CEffect>::CreateObject();
	pGameObject->Initialize();
	pGameObject->SetPos(x, y);
	pGameObject->SetSprite(name);
	CMainGame::GetInstance()->GetScene()->GetOBJLST()[OBJECT_PLAYERATTACKEFFECT2].push_back(pGameObject);
}
