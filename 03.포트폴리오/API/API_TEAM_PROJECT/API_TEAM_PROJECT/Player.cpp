#include "stdafx.h"
#include "Player.h"
#include "Bullet.h"
#include "ResourceManager.h"
#include "EffectManager.h"
#include "SoundManager.h"
#include "Scene.h"
#include "Helper.h"
#include "UIMgr.h"
#include "BombAirplane.h"
#include "UIMgr.h"

CPlayer::CPlayer()
	:bInputable(false), m_ApperSpeed(15.f), m_iHelperCount(1)
{
}


CPlayer::~CPlayer()
{
	Release();
}

void CPlayer::SetBulletLst(OBJLIST* pBulletLst)
{
	m_pBulletLst = pBulletLst;
}

void CPlayer::Initialize()
{
	m_iCount = 0;
	m_bulletCount = 0;

	m_tInfo.fX = 400.f;
	m_tInfo.fY = 800.f; // 800~500  /300  -30
	m_tInfo.fCX = 64.f;
	m_tInfo.fCY = 64.f;

	m_HelperPos[0] = -30.f;
	m_HelperPos[1] = 50.f;
	m_HelperPos[2] = -70.f;
	m_HelperPos[3] = 90.f;

	m_fSpeed = 10.f;
	m_Image = CMainGame::GetInstance()->GetResource()->Get(L"Player");
	m_AniData = CMainGame::GetInstance()->GetResource()->GetAniData(L"Player");

	m_iAniCount = m_AniData.iImageCount * 0.5;

	m_AppearPlayerImage = CMainGame::GetInstance()->GetResource()->Get(L"AppearPlayer");
	m_AppearPlayerData = CMainGame::GetInstance()->GetResource()->GetAniData(L"AppearPlayer");

	m_pKeyMgr = new CKeyManager();


}

int CPlayer::Update()
{
	if (!bInputable)
	{
		m_bIsDead = false;
	}//등장 애니메이션 중 사망 방지

	if (m_bIsDead)
		return DEAD_OBJ;

	KeyInput();
	IsOutRange();
	if (!bInputable)
	{
		m_tInfo.fY -= m_ApperSpeed;

		++m_iAniCount;

		if (m_iAniCount >= m_AppearPlayerData.iImageCount - 1)
			m_iAniCount = m_AppearPlayerData.iImageCount - 1;

		if (m_tInfo.fY < 500)
		{
			m_ApperSpeed *= -1;
		}
		if (m_tInfo.fY > 800)
		{
			bInputable = true;
			m_iAniCount = m_AniData.iImageCount * 0.5;
		}
	}

	if (m_bulletCount > 0)
	{
		--m_bulletCount;
		m_pBulletLst->push_back(CreateBullet());
	}

	if (m_iHelperCount <= GetEnergy())
	{
		CreateHelper();
		m_iHelperCount++;
	}

	return NO_EVENT;
}

void CPlayer::Render(HDC hDC)
{
	CGameObject::UpdateRect();

	if (!bInputable)
	{
		TransparentBlt(hDC, m_tRect.left, m_tRect.top, m_AppearPlayerData.iWarpWidth * 2, m_AppearPlayerData.iHeight * 2,
			m_AppearPlayerImage, m_iAniCount*m_AppearPlayerData.iWarpWidth, 0, m_AppearPlayerData.iWarpWidth, m_AppearPlayerData.iHeight,
			RGB(248, 0, 248));
	}

	TransparentBlt(hDC, m_tRect.left, m_tRect.top, m_tInfo.fCX, m_tInfo.fCY,
		m_Image, m_iAniCount*m_AniData.iWarpWidth, 0, m_AniData.iWarpWidth, m_AniData.iHeight,
		RGB(255, 255, 255));
}

void CPlayer::Release()
{
	CEffectManager::CreateEffect(this->GetInfo());
	CSoundManager::PlayMonsterDeadSound();
}

CGameObject* CPlayer::CreateBullet()
{

	return CAbstractFactory<CBullet>::CreateObject(m_tInfo.fX + 8, m_tInfo.fY - 20);
}

void CPlayer::CreateBomb()
{
	if (CBombAirplane::m_ibombCount != 0)
		return;
	CGameObject* pUI = CMainGame::GetInstance()->GetScene()->GetOBJLST()[OBJECT_UI].front();
	if (dynamic_cast<CUIMgr*>(pUI)->GetPlayerBoom() <= 0)
		return;

	dynamic_cast<CUIMgr*>(pUI)->SetPlayerBoom(-1);
	CGameObject* pBombPlane = CAbstractFactory<CBombAirplane>::CreateObject(200, 1200);
	CMainGame::GetInstance()->GetScene()->GetOBJLST()[OBJECT_EFFECT].push_back(pBombPlane);
	pBombPlane = CAbstractFactory<CBombAirplane>::CreateObject(600, 1300);
	CMainGame::GetInstance()->GetScene()->GetOBJLST()[OBJECT_EFFECT].push_back(pBombPlane);
}

void CPlayer::KeyInput()
{
	if (bInputable)
	{
		m_pKeyMgr->Update();
	}

	if (m_pKeyMgr->KeyPressing(KEY_LEFT))
	{
		m_tInfo.fX -= m_fSpeed;
		--m_iAniCount;
		if (m_iAniCount <= 0)
			m_iAniCount = 0;
	}
	if (m_pKeyMgr->KeyPressing(KEY_RIGHT))
	{
		m_tInfo.fX += m_fSpeed;
		++m_iAniCount;
		if (m_iAniCount >= m_AniData.iImageCount)
			m_iAniCount = m_AniData.iImageCount - 1;
	}
	if (m_pKeyMgr->KeyPressing(KEY_UP))
		m_tInfo.fY -= m_fSpeed;
	if (m_pKeyMgr->KeyPressing(KEY_DOWN))
		m_tInfo.fY += m_fSpeed;

	if (m_pKeyMgr->KeyDown(KEY_A))
	{
		CSoundManager::PlayPlayerBulletSound();
		if (m_bulletCount == 0)
			m_bulletCount += 10;
	}

	if (m_pKeyMgr->KeyDown(KEY_S))
	{
		CreateBomb();
	}

	if (m_pKeyMgr->KeyUp(KEY_LEFT) || m_pKeyMgr->KeyUp(KEY_RIGHT))
		m_iAniCount = m_AniData.iImageCount * 0.5;
}

void CPlayer::CreateHelper()
{
	CGameObject* helper = CAbstractFactory<CHelper>::CreateObject(m_tInfo.fX, m_tInfo.fY);
	helper->SetSprite(L"PlayerHelper");
	helper->SetPos(m_HelperPos[m_iHelperCount - 1], 0);

	helper->Initialize();
	CMainGame::GetInstance()->GetScene()->GetOBJLST()[OBJECT_HELPER].push_back(helper);
}

void CPlayer::IsOutRange()
{
	if (m_tInfo.fX < 50)
		m_tInfo.fX = 50;
	else if (m_tInfo.fX > 750)
		m_tInfo.fX = 750;
	else if (m_tInfo.fY < 50)
		m_tInfo.fY = 50;
	else if (m_tInfo.fY > 850)
		m_tInfo.fY = 850;
}

int CPlayer::GetEnergy()
{
	CGameObject* pUIMgr = CMainGame::GetInstance()->GetScene()->GetOBJLST()[OBJECT_UI].front();
	return dynamic_cast<CUIMgr*>(pUIMgr)->GetEnergyBarLV();

}
