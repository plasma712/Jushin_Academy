#include "stdafx.h"
#include "Title.h"


CTitle::CTitle()
{
}


CTitle::~CTitle()
{
	Release();
}

void CTitle::Initialize()
{
	CBmpMgr::GetInstance()->LoadBmp(L"../Image/Logo/Logo.bmp", L"Title");
}

int CTitle::Update()
{
	if (CKeyMgr::GetInstance()->KeyUp(KEY_RETURN))
	{
		CSceneMgr::GetInstance()->SceneChange(SCENE_MENU);
		return 0;
	}

	return 0;
}

void CTitle::Render(HDC hDC)
{
	HDC hMemDC = CBmpMgr::GetInstance()->GetMemDC(L"Title");
	NULL_CHECK(hMemDC);

	BitBlt(hDC, 0, 0, WINCX, WINCY, hMemDC, 0, 0, SRCCOPY);
}

void CTitle::Release()
{
}
