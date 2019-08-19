#include "stdafx.h"
#include "cMainGame.h"
#include "cResourceManager.h"


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
	hBackBuffer = cAniMation::GetInstance()->GetMemDC(L"BackBuffer");

	cSceneMgr::GetInstance()->SceneChange(SCENE_TITLE);
}

void cMainGame::Update()
{
	cKeyMgr::GetInstance()->Update();
	cSceneMgr::GetInstance()->Update();
}

void cMainGame::Draw()
{

	//NULL_CHECK(hBackBuffer);
	cSceneMgr::GetInstance()->Draw(hBackBuffer);

	TCHAR szBuf[32] = L"";
	swprintf_s(szBuf, L"FPS: %d", m_iFPS);
	TextOut(hBackBuffer, 0, 0, szBuf, lstrlen(szBuf));
	BitBlt(m_hdc, 0, 0, WINCX, WINCY, hBackBuffer, 0, 0, SRCCOPY);


}

void cMainGame::Release()
{
	ReleaseDC(g_hwnd, m_hdc);

	cKeyMgr::GetInstance()->DestroyInstance();
	cSceneMgr::GetInstance()->DestroyInstance();
	cAniMation::GetInstance()->DestroyInstance();

}

void cMainGame::SetFPS(int FPS)
{
	m_iFPS = FPS;
}
