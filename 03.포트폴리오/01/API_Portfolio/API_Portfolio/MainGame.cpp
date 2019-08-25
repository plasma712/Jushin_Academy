#include "stdafx.h"
#include "MainGame.h"
#include "ResourceManager.h"
#include "Scene.h"
#include "LogoScene.h"
#include "Stage1Scene.h"
#include "cStageBossScene.h"

#include "EndingScene.h"
#include "UIMgr.h"

CMainGame*	CMainGame::m_instance = nullptr;

CMainGame::CMainGame()
{
}


CMainGame::~CMainGame()
{
}

void CMainGame::Initialize()
{
	m_instance = this;
	m_hDC = GetDC(g_hWnd);
	m_BackDC = CreateCompatibleDC(m_hDC);
	HBITMAP backBitmap = CreateCompatibleBitmap(m_hDC,800,900);
	SelectObject(m_BackDC, backBitmap);

	m_pResourceMgr = new CResourceManager();

	m_pResourceMgr->Initialize(m_hDC);

	m_iSceneIdx = 0;
	m_pScene[0] = new CLogoScene();
	m_pScene[0]->Initialize();
	m_pScene[1] = new CStage1Scene();
	m_pScene[1]->Initialize();
	m_pScene[2] = new cStageBossScene();
	m_pScene[2]->Initialize();
	m_pScene[3] = new CEndingScene();
	m_pScene[3]->Initialize();

}

void CMainGame::Update()
{
	m_pScene[m_iSceneIdx]->Update();
}

void CMainGame::Render()
{

	m_pScene[m_iSceneIdx]->Render();
	//debug 모드에서만 fps 출력
#ifdef _DEBUG
	TCHAR szBuf[32] = L"";
	swprintf_s(szBuf, L"FPS: %d", m_iFPS);
	TextOut(m_BackDC, 0, 0, szBuf, lstrlen(szBuf));
#endif
	BitBlt(m_hDC, 0, 0, 800, 900, m_BackDC, 0, 0, SRCCOPY);
}

void CMainGame::SetFPS(int FPS)
{
	m_iFPS = FPS;
}

CMainGame * CMainGame::GetInstance()
{
	return m_instance;
}

CScene * CMainGame::GetScene()
{
	return m_pScene[m_iSceneIdx];
}

void CMainGame::SetSceneIndex(int idx)
{
	m_iSceneIdx = idx;
}

HDC CMainGame::GetHDC()
{
	return m_BackDC;
}

CResourceManager * CMainGame::GetResource()
{
	return m_pResourceMgr;
}

void CMainGame::RegisterScene()
{

}

void CMainGame::Release()
{
	delete m_pResourceMgr;
	delete m_pScene[0];
	delete m_pScene[1];
	delete m_pScene[2];
}
