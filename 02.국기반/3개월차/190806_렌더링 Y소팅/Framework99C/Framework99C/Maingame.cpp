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
	// GetDC: ��� DC ���� �Լ�.
	m_hDC = GetDC(g_hWnd);

	// �ĸ���� ����
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

	// �ĸ���ۿ� ��� �׸� ��Ʈ�ʵ��� ������ۿ� �ѹ� �����Ѵ�. -> ���� ���۸�
	BitBlt(m_hDC, 0, 0, WINCX, WINCY, hBackBuffer, 0, 0, SRCCOPY);
}	

void CMaingame::Release()
{
	// GetDC�Լ��� �Ҵ���� DC�� �Ʒ� �Լ��� �������־�� �Ѵ�.
	ReleaseDC(g_hWnd, m_hDC);	

	CKeyMgr::GetInstance()->DestroyInstance();
	CSceneMgr::GetInstance()->DestroyInstance();
	CObjectMgr::GetInstance()->DestroyInstance();
	CBmpMgr::GetInstance()->DestroyInstance();
}
