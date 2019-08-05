#include "stdafx.h"
#include "MyMenu.h"
#include "MyButton.h"

CMyMenu::CMyMenu()
{
}


CMyMenu::~CMyMenu()
{
	Release();
}

void CMyMenu::Initialize()
{
	CBmpMgr::GetInstance()->LoadBmp(L"../Image/Button/Start.bmp", L"StartButton");
	CBmpMgr::GetInstance()->LoadBmp(L"../Image/Button/Edit.bmp", L"EditButton");
	CBmpMgr::GetInstance()->LoadBmp(L"../Image/Button/Exit.bmp", L"ExitButton");

	CGameObject* pButton = CAbstractFactory<CMyButton>::CreateObject(200.f, 400.f, L"StartButton");
	CObjectMgr::GetInstance()->AddObject(OBJECT_UI, pButton);

	pButton = CAbstractFactory<CMyButton>::CreateObject(400.f, 500.f, L"ExitButton");
	CObjectMgr::GetInstance()->AddObject(OBJECT_UI, pButton);

	pButton = CAbstractFactory<CMyButton>::CreateObject(600.f, 400.f, L"EditButton");
	CObjectMgr::GetInstance()->AddObject(OBJECT_UI, pButton);
}

int CMyMenu::Update()
{
	CObjectMgr::GetInstance()->Update();

	return 0;
}

void CMyMenu::Render(HDC hDC)
{
	CObjectMgr::GetInstance()->Render(hDC);
}

void CMyMenu::Release()
{
	CObjectMgr::GetInstance()->ReleaseGroup(OBJECT_UI);
}
