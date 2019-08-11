#include "stdafx.h"
#include "MyEdit.h"
#include "BackGround.h"

CMyEdit::CMyEdit()
{
}


CMyEdit::~CMyEdit()
{
	Release();
}

void CMyEdit::Initialize()
{
	CGameObject* pBackGround = CAbstractFactory<CBackGround>::CreateObject();
	CObjectMgr::GetInstance()->AddObject(OBJECT_BACKGROUND, pBackGround);
}

int CMyEdit::Update()
{
	KeyInput();

	// 스크롤 제한
	if (0.f > CScrollMgr::m_fScrollX)
		CScrollMgr::m_fScrollX = 0.f;
	if (0.f > CScrollMgr::m_fScrollY)
		CScrollMgr::m_fScrollY = 0.f;
	if (float(TILEX * TILECX - WINCX) < CScrollMgr::m_fScrollX)
		CScrollMgr::m_fScrollX = float(TILEX * TILECX - WINCX);
	if (float(TILEY * TILECY - WINCY) < CScrollMgr::m_fScrollY)
		CScrollMgr::m_fScrollY = float(TILEY * TILECY - WINCY);

	CObjectMgr::GetInstance()->Update();

	return 0;
}

void CMyEdit::Render(HDC hDC)
{
	CObjectMgr::GetInstance()->Render(hDC);
}

void CMyEdit::Release()
{
}

void CMyEdit::KeyInput()
{
	if (CKeyMgr::GetInstance()->KeyPressing(KEY_LEFT))
		CScrollMgr::m_fScrollX -= 10;
	if (CKeyMgr::GetInstance()->KeyPressing(KEY_RIGHT))
		CScrollMgr::m_fScrollX += 10;
	if (CKeyMgr::GetInstance()->KeyPressing(KEY_UP))
		CScrollMgr::m_fScrollY -= 10;
	if (CKeyMgr::GetInstance()->KeyPressing(KEY_DOWN))
		CScrollMgr::m_fScrollY += 10;

	if (CKeyMgr::GetInstance()->KeyUp(KEY_A))
	{
		CBackGround* pBackGround = dynamic_cast<CBackGround*>(CObjectMgr::GetInstance()->GetBackGround());
		NULL_CHECK(pBackGround);

		pBackGround->SaveTile(L"../Data/TileData.dat");
	}

	if (CKeyMgr::GetInstance()->KeyUp(KEY_S))
	{
		CBackGround* pBackGround = dynamic_cast<CBackGround*>(CObjectMgr::GetInstance()->GetBackGround());
		NULL_CHECK(pBackGround);

		pBackGround->LoadTile(L"../Data/TileData.dat");
	}
}
