#include "stdafx.h"
#include "cMainGame.h"


cMainGame::cMainGame()
{
}


cMainGame::~cMainGame()
{
	Release();
}

void cMainGame::Init()
{
	m_hdc = GetDC(g_hwnd);

	cAniMation::GetInstance()->LoadBmp(L"../Resource/Image/BackBuffer.bmp", L"BackBuffer");
	//cAniMation::GetInstance()->LoadBmp(L"../Resource/Image/05.Menu/MenuBack.bmp", L"Title");

	cSceneMgr::GetInstance()->SceneChange(SCENE_TITLE);
}

void cMainGame::Update()
{
	cKeyMgr::GetInstance()->Update();
	cSceneMgr::GetInstance()->Update();
}

void cMainGame::Draw()
{
	HDC hBackBuffer = cAniMation::GetInstance()->GetMemDC(L"BackBuffer");

	NULL_CHECK(hBackBuffer);

	cSceneMgr::GetInstance()->Draw(hBackBuffer);

	BitBlt(m_hdc, 0, 0, WINCX, WINCY, hBackBuffer, 0, 0, SRCCOPY);

}

void cMainGame::Release()
{
	ReleaseDC(g_hwnd, m_hdc);

	cKeyMgr::GetInstance()->DestroyInstance();
	cSceneMgr::GetInstance()->DestroyInstance();
	cAniMation::GetInstance()->DestroyInstance();

}
