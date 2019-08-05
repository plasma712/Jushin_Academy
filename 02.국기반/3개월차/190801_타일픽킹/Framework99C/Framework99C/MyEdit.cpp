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
}
