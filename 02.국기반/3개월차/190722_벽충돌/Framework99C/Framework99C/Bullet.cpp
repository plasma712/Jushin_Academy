#include "stdafx.h"
#include "Bullet.h"


CBullet::CBullet()
	: m_eDirection(BULLET_UP)
{
}


CBullet::~CBullet()
{
	Release();
}

void CBullet::SetDirection(BULLET_DIRECTION eDir)
{
	m_eDirection = eDir;
}



void CBullet::Initialize()
{
	m_tInfo.fCX = 20.f;
	m_tInfo.fCY = 20.f;

	m_fSpeed = 20.f;
}

int CBullet::Update()
{
	if (m_bIsDead)
		return DEAD_OBJ;

	IsMoving();
	IsOutRange();	

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

void CBullet::IsMoving()
{
	//switch (m_eDirection)
	//{
	//case BULLET_LEFT:
	//	m_tInfo.fX -= m_fSpeed;
	//	break;
	//case BULLET_RIGHT:
	//	m_tInfo.fX += m_fSpeed;
	//	break;
	//case BULLET_UP:
	//	m_tInfo.fY -= m_fSpeed;
	//	break;
	//case BULLET_DOWN:
	//	m_tInfo.fY += m_fSpeed;
	//	break;
	//}
	m_tInfo.fX += cosf(m_fAngle * fPi / 180) * m_fSpeed;
	m_tInfo.fY -= sinf(m_fAngle * fPi / 180) * m_fSpeed;

}

void CBullet::IsOutRange()
{
	CGameObject::UpdateRect();

	if (0 >= m_tRect.left || 0 >= m_tRect.top
		|| WINCX <= m_tRect.right || WINCY <= m_tRect.bottom)
		m_bIsDead = true;
}

void CBullet::SetAngle(float _m_fAngle)
{
	m_fAngle = _m_fAngle;
}

void CBullet::SetPos(float _fx, float _fy)
{
	m_tInfo.fX = _fx;
	m_tInfo.fY = _fy;
}
