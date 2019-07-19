#include "stdafx.h"
#include "Bullet.h"


CBullet::CBullet()
{
}


CBullet::~CBullet()
{
	Release();
}

void CBullet::Initialize()
{
	m_tInfo.fCX = 20.f;
	m_tInfo.fCY = 20.f;

	m_fSpeed = 20.f;
}

int CBullet::Update()
{
	// 어떠한 키 조작없이도 위로 나아감.
	if(BulletArrowNumber == 0)
		m_tInfo.fX -= m_fSpeed;
	else if(BulletArrowNumber==1)
		m_tInfo.fY -= m_fSpeed;
	else if (BulletArrowNumber == 2)
		m_tInfo.fX += m_fSpeed;
	else if (BulletArrowNumber == 3)
		m_tInfo.fY += m_fSpeed;

	return NO_EVENT;
}

void CBullet::Render(HDC hDC)
{
	CGameObject::UpdateRect();
	Ellipse(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void CBullet::Release()
{
}
