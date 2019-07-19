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

void CBullet::GetMonsterList(MONSTER_LST * pMonsterLst)
{
	m_MonsterLst = *pMonsterLst;
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
	//MONSTER_LST::iterator Monsteriter_Begin = m_MonsterLst.begin();
	//MONSTER_LST::iterator Monsteriter_End = m_MonsterLst.end();
	//
	//for (; Monsteriter_Begin != Monsteriter_End;)
	//{
	//	IsCollision(*Monsteriter_Begin);
	//	++Monsteriter_Begin;
	//}

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
	switch (m_eDirection)
	{
	case BULLET_LEFT:
		m_tInfo.fX -= m_fSpeed;
		break;
	case BULLET_RIGHT:
		m_tInfo.fX += m_fSpeed;
		break;
	case BULLET_UP:
		m_tInfo.fY -= m_fSpeed;
		break;
	case BULLET_DOWN:
		m_tInfo.fY += m_fSpeed;
		break;
	}
}

void CBullet::IsOutRange()
{
	CGameObject::UpdateRect();

	if (100 >= m_tRect.left || 100 >= m_tRect.top
		|| WINCX - 100 <= m_tRect.right || WINCY - 100 <= m_tRect.bottom)
		m_bIsDead = true;
}

//void CBullet::IsCollision(CGameObject* Enemy)
//{
//	if (
//		sqrt(pow(this->GetPos().fX - Enemy->GetPos().fX, 2)
//			+ pow(this->GetPos().fY - Enemy->GetPos().fY, 2))
//		<= (Enemy->GetPos().fX - Enemy->GetPos().fCX)
//		+ (this->GetPos().fX - this->GetPos().fCX)
//		)
//	{
//		m_bIsDead = true;
//	}
//	else
//		m_bIsDead = false;
//}
