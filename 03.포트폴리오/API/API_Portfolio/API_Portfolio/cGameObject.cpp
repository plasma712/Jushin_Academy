#include "stdafx.h"
#include "cGameObject.h"


cGameObject::cGameObject()
	:m_bImmortal(false), m_bDead(false), m_fSpeed(10.f), m_fHp(10.f)
{
}

cGameObject::~cGameObject()
{
}

void cGameObject::UpdateRect()
{
	m_Rect.left = static_cast<LONG>(m_Info.fX - m_Info.fWidthX*0.5f);
	m_Rect.top = static_cast<LONG>(m_Info.fY - m_Info.fHeightY*0.5f);
	m_Rect.right = static_cast<LONG>(m_Info.fX + m_Info.fWidthX*0.5f);
	m_Rect.bottom = static_cast<LONG>(m_Info.fY + m_Info.fHeightY*0.5);
}

void cGameObject::SetINFO(float _fX, float _fY)
{
	m_Info.fX = _fX;
	m_Info.fY = _fY;
}

INFO cGameObject::GetINFO()
{
	return m_Info;
}

RECT cGameObject::GetRECT()
{
	return m_Rect;
}

void cGameObject::SetImmortal(bool _m_bImmortal)
{
	m_bImmortal = _m_bImmortal;
}

bool cGameObject::GetImmortal()
{
	return m_bImmortal;
}

void cGameObject::SetDead(bool _m_bImmortal, bool _m_Dead)
{
	if (_m_bImmortal == true)
		m_bDead = false;

	m_bDead = _m_Dead;
}

bool cGameObject::GetDead()
{
	return m_bDead;
}

void cGameObject::SetPos(float _fX, float _fY)
{
	m_Info.fX = _fX;
	m_Info.fY = _fY;
}

float cGameObject::GetHp()
{
	return m_fHp;
}

void cGameObject::SetHpDecrease(float _fAtk)
{
	m_fHp -= _fAtk;
}

float cGameObject::GetAttack()
{
	return m_fAtk;
}

bool cGameObject::GetWallCrush()
{
	return m_WallCrush;
}
