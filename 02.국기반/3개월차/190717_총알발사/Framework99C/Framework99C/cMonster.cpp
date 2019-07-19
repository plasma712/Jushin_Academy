#include "stdafx.h"
#include "cMonster.h"


cMonster::cMonster()
{
}


cMonster::~cMonster()
{
	Release();
}

void cMonster::Initialize()
{
	m_tInfo.fX = 400.f;
	m_tInfo.fY = 100.f;
	m_tInfo.fCX = 50.f;
	m_tInfo.fCY = 50.f;
	m_fSpeed = 5.f;

}

int cMonster::Update()
{
	if (MonsterRightMove == true)
	{
		if (m_tInfo.fX > 700)
		{
			MonsterRightMove = false;
		}
		else
		{
			m_tInfo.fX += m_fSpeed;
		}
	}
	else
	{
		if (m_tInfo.fX<100)
		{
			MonsterRightMove = true;
		}
		else
		{
			m_tInfo.fX -= m_fSpeed;
		}
	}


	return 0;
}

void cMonster::Render(HDC hDC)
{
	CGameObject::UpdateRect();
	Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void cMonster::Release()
{
}
