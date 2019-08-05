#include "stdafx.h"
#include "Bomb.h"
#include "SoundManager.h"
#include "Scene.h"
#include "GameObject.h"
CBomb::CBomb()
{
}


CBomb::~CBomb()
{
}

void CBomb::Initialize()
{
	m_iCount = 0;
	m_Image = CMainGame::GetInstance()->GetResource()->Get(L"Bomb_Bullet1");
	m_AniData = CMainGame::GetInstance()->GetResource()->GetAniData(L"Bomb_Bullet1");

	m_tInfo.fCX = m_AniData.iWarpWidth*2;
	m_tInfo.fCY = m_AniData.iHeight*2;

	m_fSpeed = 0.f;
	m_iAniCount = 0;
}

int CBomb::Update()
{
	++m_iAniCount;
	if (m_iAniCount == 50)
	{
		//CSoundManager::PlayMonsterDeadSound();
		SetSprite(L"Bomb_Bullet2");
		m_tInfo.fCX = m_AniData.iWarpWidth * 4;
		m_tInfo.fCY = m_AniData.iHeight * 4;
		
	}

	if (m_iAniCount > 100)
	{
		return DEAD_OBJ;
	}
	return 0;
}

void CBomb::Render(HDC hDC)
{
	CGameObject::UpdateRect();
	
	if (m_iAniCount < 50)
	{
		TransparentBlt(hDC, m_tRect.left, m_tRect.top, m_tInfo.fCX, m_tInfo.fCY,
			m_Image, m_iAniCount*m_AniData.iWarpWidth, 0, m_AniData.iWarpWidth, m_AniData.iHeight,
			RGB(0, 248, 0));
	}
	else
	{
		TransparentBlt(hDC, m_tRect.left, m_tRect.top, m_tInfo.fCX, m_tInfo.fCY,
			m_Image, (m_iAniCount-50)*m_AniData.iWarpWidth, 0, m_AniData.iWarpWidth, m_AniData.iHeight,
			RGB(0, 248, 0));
	}
}

void CBomb::Release()
{
	
}
