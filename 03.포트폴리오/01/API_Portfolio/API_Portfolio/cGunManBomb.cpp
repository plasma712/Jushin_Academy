#include "stdafx.h"
#include "cGunManBomb.h"


cGunManBomb::cGunManBomb()
	:Monster_Direction(false)
{
}

cGunManBomb::cGunManBomb(float x, float y, bool _Direction)
{
	sx = m_tInfo.fX = x;
	sy = m_tInfo.fY = y;
	Monster_Direction = _Direction;
}


cGunManBomb::~cGunManBomb()
{
	Release();
}

void cGunManBomb::Initialize()
{
	m_Image = CMainGame::GetInstance()->GetResource()->Get(L"GunmanBomb");
	m_AniData = CMainGame::GetInstance()->GetResource()->GetAniData(L"GunmanBomb");

	m_tInfo.fCX = m_AniData.iWarpWidth;
	m_tInfo.fCY = m_AniData.iHeight;

	m_fSpeed = 20.f;

	m_iHP = 0.f;
	m_iAttackDamage = 1.f;

}

int cGunManBomb::Update()
{
	if (m_bIsDead)
	{
		return DEAD_OBJ;
	}

	IsMoving();
	IsOutRange();

	++m_iCount;

	if (m_iCount >= m_iFrame)
	{
		m_iCount = 0;
		++m_iAniCount;
		if (m_iAniCount >= m_AniData.iImageCount)
			m_iAniCount = m_AniData.iImageCount - 1;
	}
	return NO_EVENT;
}

void cGunManBomb::Render(HDC hDC)
{
}

void cGunManBomb::Release()
{
}

void cGunManBomb::IsMoving()
{
}

void cGunManBomb::IsOutRange()
{
}

void cGunManBomb::vFirstPoint()
{
}
