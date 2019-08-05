#include "stdafx.h"
#include "Stage.h"
#include "Player.h"
#include "Monster.h"
#include "Mouse.h"
#include "BackGround.h"


CStage::CStage()
{
}


CStage::~CStage()
{
	Release();
}

void CStage::Initialize()
{
	srand((unsigned)time(nullptr));

	CGameObject* pGameObject = nullptr;

	// BackGround
	pGameObject = CAbstractFactory<CBackGround>::CreateObject();
	CObjectMgr::GetInstance()->AddObject(OBJECT_BACKGROUND, pGameObject);

	// Player
	pGameObject = CAbstractFactory<CPlayer>::CreateObject();
	CObjectMgr::GetInstance()->AddObject(OBJECT_PLAYER, pGameObject);

	////// Monster
	//for (int i = 0; i < 5; ++i)
	//{
	//	float x = float(rand() % (WINCX - 200)) + 100.f;
	//	float y = float(rand() % (WINCY - 200)) + 100.f;

	//	pGameObject = CAbstractFactory<CMonster>::CreateObject(x, y);
	//	CObjectMgr::GetInstance()->AddObject(OBJECT_MONSTER, pGameObject);	//	
	//}

	// Mouse
	//pGameObject = CAbstractFactory<CMouse>::CreateObject();
	//CObjectMgr::GetInstance()->AddObject(OBJECT_MOUSE, pGameObject);	
}

int CStage::Update()
{
	CObjectMgr::GetInstance()->Update();

	return 0;
}

void CStage::Render(HDC hDC)
{
	CObjectMgr::GetInstance()->Render(hDC);
}

void CStage::Release()
{
}
