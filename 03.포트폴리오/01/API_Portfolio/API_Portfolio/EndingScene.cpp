#include "stdafx.h"
#include "EndingScene.h"


CEndingScene::CEndingScene()
{

}


CEndingScene::~CEndingScene()
{
}

void CEndingScene::Initialize()
{
	m_hDC = CMainGame::GetInstance()->GetHDC();
	m_pResourceMgr = CMainGame::GetInstance()->GetResource();
}

void CEndingScene::Update()
{
	if (GetAsyncKeyState(VK_RETURN) & 0x8000)
		exit(0);
}

void CEndingScene::Render()
{
	BitBlt(m_hDC, 0, 0, 800, 900, m_pResourceMgr->Get(L"End"), 0, 0, SRCCOPY);
}

void CEndingScene::Release()
{
}

void CEndingScene::LoadMonster()
{
}
