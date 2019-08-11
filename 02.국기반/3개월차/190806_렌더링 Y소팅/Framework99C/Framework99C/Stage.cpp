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
	dynamic_cast<CBackGround*>(pGameObject)->LoadTile(L"../Data/TileData.dat");

	// Player
	pGameObject = CAbstractFactory<CPlayer>::CreateObject();
	CObjectMgr::GetInstance()->AddObject(OBJECT_PLAYER, pGameObject);

	pGameObject = CAbstractFactory<CMonster>::CreateObject();
	CObjectMgr::GetInstance()->AddObject(OBJECT_MONSTER, pGameObject);

	// Mouse
	//pGameObject = CAbstractFactory<CMouse>::CreateObject();
	//CObjectMgr::GetInstance()->AddObject(OBJECT_MOUSE, pGameObject);	
}

int CStage::Update()
{
	CObjectMgr::GetInstance()->Update();

	// 스크롤 제한
	if (0.f > CScrollMgr::m_fScrollX)
		CScrollMgr::m_fScrollX = 0.f;
	if (0.f > CScrollMgr::m_fScrollY)
		CScrollMgr::m_fScrollY = 0.f;
	if (float(TILEX * TILECX - WINCX) < CScrollMgr::m_fScrollX)
		CScrollMgr::m_fScrollX = float(TILEX * TILECX - WINCX);
	if (float(TILEY * TILECY - WINCY) < CScrollMgr::m_fScrollY)
		CScrollMgr::m_fScrollY = float(TILEY * TILECY - WINCY);

	return 0;
}

void CStage::Render(HDC hDC)
{
	CObjectMgr::GetInstance()->Render(hDC);
}

void CStage::Release()
{
}
