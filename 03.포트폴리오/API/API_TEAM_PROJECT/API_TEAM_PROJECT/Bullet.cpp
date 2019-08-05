#include "stdafx.h"
#include "Bullet.h"
#include "EffectManager.h"

CBullet::CBullet()
	:m_iFrame(2)
{
}


CBullet::~CBullet()
{
	Release();
}


void CBullet::Initialize()
{
	m_fDirection = 270.f;

	m_Image = CMainGame::GetInstance()->GetResource()->Get(L"Bullet");
	m_AniData = CMainGame::GetInstance()->GetResource()->GetAniData(L"Bullet");

	m_tInfo.fCX = m_AniData.iWarpWidth;
	m_tInfo.fCY = m_AniData.iHeight;

	m_fSpeed = 20.f;
	
}

int CBullet::Update()
{
	if (m_bIsDead)
		return DEAD_OBJ;

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

void CBullet::Render(HDC hDC)
{
	CGameObject::UpdateRect();
	//Ellipse(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
	//TransparentBlt(hDC, m_tRect.left, m_tRect.top,m_tInfo.fCX, m_tInfo.fCY, m_Image, 0, 0, m_tInfo.fCX, m_tInfo.fCY, RGB(255, 255, 255));
	
	TransparentBlt(hDC, m_tRect.left, m_tRect.top, m_tInfo.fCX, m_tInfo.fCY,
		m_Image, m_iAniCount*m_AniData.iWarpWidth, 0, m_AniData.iWarpWidth, m_AniData.iHeight,
		RGB(255, 255, 255));
	
}

void CBullet::Release()
{

}

void CBullet::IsMoving()
{
	m_tInfo.fX += cosf(m_fDirection*PI/180)*m_fSpeed;
	m_tInfo.fY += sinf(m_fDirection*PI /180)*m_fSpeed;
}

void CBullet::IsOutRange()
{
	CGameObject::UpdateRect();

	if (0 >= m_tRect.left || 0 >= m_tRect.top
		|| WINCX <= m_tRect.right || WINCY <= m_tRect.bottom)
		m_bIsDead = true;
}
