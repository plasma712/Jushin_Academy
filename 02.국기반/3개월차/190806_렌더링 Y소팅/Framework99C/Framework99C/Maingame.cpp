#include "stdafx.h"
#include "Maingame.h"

CMaingame::CMaingame()	
{
	
}

CMaingame::~CMaingame()
{
	Release();
}

void CMaingame::Initialize()
{
	// GetDC: 출력 DC 생성 함수.
	m_hDC = GetDC(g_hWnd);

	// 후면버퍼 생성
	CBmpMgr::GetInstance()->LoadBmp(L"../Image/BackBuffer.bmp", L"BackBuffer");

	CSceneMgr::GetInstance()->SceneChange(SCENE_TITLE);

	//MessageBox(g_hWnd, L"Hello world", L"Maingame message", MB_OK);
}

void CMaingame::Update()
{
	CKeyMgr::GetInstance()->Update();	
	CSceneMgr::GetInstance()->Update();
}

void CMaingame::Render()
{	
	HDC hBackBuffer = CBmpMgr::GetInstance()->GetMemDC(L"BackBuffer");
	NULL_CHECK(hBackBuffer);

	CSceneMgr::GetInstance()->Render(hBackBuffer);

	// 후면버퍼에 모아 그린 비트맵들을 전면버퍼에 한번 복사한다. -> 더블 버퍼링
	BitBlt(m_hDC, 0, 0, WINCX, WINCY, hBackBuffer, 0, 0, SRCCOPY);
}	

void CMaingame::Release()
{
	// GetDC함수로 할당받은 DC는 아래 함수로 해제해주어야 한다.
	ReleaseDC(g_hWnd, m_hDC);	

	CKeyMgr::GetInstance()->DestroyInstance();
	CSceneMgr::GetInstance()->DestroyInstance();
	CObjectMgr::GetInstance()->DestroyInstance();
	CBmpMgr::GetInstance()->DestroyInstance();
}
