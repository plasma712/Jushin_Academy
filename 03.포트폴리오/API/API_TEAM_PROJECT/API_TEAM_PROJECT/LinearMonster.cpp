#include "stdafx.h"
#include "LinearMonster.h"
#include "Scene.h"
#include "Bullet.h"
#include "EffectManager.h"


CLinearMonster::CLinearMonster()
{
}


CLinearMonster::~CLinearMonster()
{
}

void CLinearMonster::Initialize()
{
	m_iCount = 0;
	m_Image = CMainGame::GetInstance()->GetResource()->Get(L"LinearMonster");
	m_AniData = CMainGame::GetInstance()->GetResource()->GetAniData(L"LinearMonster");

	m_tInfo.fCX = m_AniData.iWarpWidth * 2;
	m_tInfo.fCY = m_AniData.iHeight * 2;

	m_fSpeed = 10.f;
	//m_iAniCount = m_AniData.iImageCount * 0.5;
}

int CLinearMonster::Update()
{
	if (m_fDirection==0)
	{
		m_iAniCount = 4;
	}
	else if (m_fDirection == 45)
	{
		m_iAniCount = 6;
	}
	else if (m_fDirection == 90)
	{
		m_iAniCount = 8;
	}
	else if (m_fDirection == 135)
	{
		m_iAniCount = 10;
	}
	else if (m_fDirection == 180)
	{
		m_iAniCount = 12;
	}
	else if (m_fDirection == 225)
	{
		m_iAniCount = 14;
	}
	else if (m_fDirection == 270)
	{
		m_iAniCount = 0;
	}
	else if (m_fDirection == 315)
	{
		m_iAniCount = 2;
	}


	if (m_bIsDead)
		return DEAD_OBJ;
	++m_iCount;
	if (m_iCount == 20)
	{
		CreateBullet();
	}

	/*if (m_iCount % 2 == 0)
	{
		++m_iAniCount;
		m_iAniCount %= m_AniData.iImageCount;
	}*/
	IsMoving();
	IsOutRange();

	return NO_EVENT;
}

void CLinearMonster::Render(HDC hDC)
{
	CGameObject::UpdateRect();
	//Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);

	TransparentBlt(hDC, m_tRect.left, m_tRect.top, m_tInfo.fCX, m_tInfo.fCY,
		m_Image, m_iAniCount*m_AniData.iWarpWidth, 0, m_AniData.iWarpWidth, m_AniData.iHeight,
		RGB(57, 24, 8));
}
