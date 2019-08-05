#include "stdafx.h"
#include "LogoScene.h"
#include "ResourceManager.h"

CLogoScene::CLogoScene()
{
}

CLogoScene::~CLogoScene()
{
}

void CLogoScene::Initialize()
{
	m_hDC = CMainGame::GetInstance()->GetHDC();
	m_pResourceMgr = CMainGame::GetInstance()->GetResource();
}

void CLogoScene::Update()
{
	if (GetAsyncKeyState(VK_RETURN) & 0x8000)
		CMainGame::GetInstance()->SetSceneIndex(STAGE1_SCENE);
}

void CLogoScene::Render()
{
	BitBlt(m_hDC, 0, 0, 800, 900, m_pResourceMgr->Get(L"Logo"), 0, 0, SRCCOPY);
}

void CLogoScene::Release()
{
}

void CLogoScene::LoadMonster()
{
	//do nothing
}
