#include "stdafx.h"
#include "LogoScene.h"
#include "ResourceManager.h"
#include "KeyManager.h"

CLogoScene::CLogoScene()
	:iKeyCheck(0), PressEnterTime(0), Check(true)
{
}

CLogoScene::~CLogoScene()
{
}

void CLogoScene::Initialize()
{
	m_hDC = CMainGame::GetInstance()->GetHDC();
	m_pResourceMgr = CMainGame::GetInstance()->GetResource();
	m_pKeyMgr = new CKeyManager();
	bKeyPressCheck = false;

	dwOldTime = GetTickCount();
	dwCurTime = GetTickCount();

}

void CLogoScene::Update()
{
	m_pKeyMgr->Update();

	if (m_pKeyMgr->KeyPressing(KEY_RETURN))
	{
		//CMainGame::GetInstance()->SetSceneIndex(STAGE1_SCENE);
		CMainGame::GetInstance()->SetSceneIndex(BOSS_SCENE);

	}
	if (m_pKeyMgr->KeyPressing(KEY_DOWN))
	{
		if (bKeyPressCheck == false)
		{
			if (iKeyCheck < 2)
				iKeyCheck++;
			bKeyPressCheck = true;
		}
	}
	if (m_pKeyMgr->KeyUp(KEY_DOWN))
	{
		bKeyPressCheck = false;
	}


	if (m_pKeyMgr->KeyPressing(KEY_UP))
	{
		if (bKeyPressCheck == false)
		{
			if (iKeyCheck > 0)
				iKeyCheck--;
			bKeyPressCheck = true;
		}
	}	
	
	if (m_pKeyMgr->KeyUp(KEY_UP))
	{
		bKeyPressCheck = false;
	}

////////////////////////////////////////////////////////////////////

	dwCurTime = GetTickCount();

	if (dwCurTime - dwOldTime > 500)
	{
		PressEnterTime++;
		dwOldTime = dwCurTime;
		vPressEnterTime();
	}
}

void CLogoScene::Render()
{
	//BitBlt(m_hDC, 0, 0, 800, 900, m_pResourceMgr->Get(L"Logo"), 0, 0, SRCCOPY);
	BitBlt(m_hDC, 0, 0, WINCX, WINCY, m_pResourceMgr->Get(L"Title"), 0, 0, SRCCOPY);

	TransparentBlt
	(
		m_hDC,
		282.5,
		300,
		94*2.5,
		48*2.5,
		m_pResourceMgr->Get(L"TitleMenuSelect"),		// 이미지 불러오기
		94*(iKeyCheck),
		0,
		94,
		48,
		RGB(255, 0, 255)						//RGB(200,0,255)로 맞출껏
	);

	TransparentBlt
	(
		m_hDC,
		252,
		440,
		148 * 2,
		16 * 2,
		m_pResourceMgr->Get(L"TitlePressEnter"),		// 이미지 불러오기
		148 * (Check),
		0,
		148,
		16,
		RGB(255, 0, 255)						//RGB(200,0,255)로 맞출껏
	);

}

void CLogoScene::Release()
{
}

void CLogoScene::LoadMonster()
{
	//do nothing
}

void CLogoScene::vPressEnterTime()
{
	if (PressEnterTime % 2 == 0)
		Check = true;
	else
		Check = false;
}
