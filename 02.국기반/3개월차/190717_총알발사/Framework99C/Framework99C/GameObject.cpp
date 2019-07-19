#include "stdafx.h"
#include "GameObject.h"


CGameObject::CGameObject()
	: m_fSpeed(0.f)
{
}


CGameObject::~CGameObject()
{
}

void CGameObject::SetPos(float x, float y)
{
	m_tInfo.fX = x;
	m_tInfo.fY = y;
}

INFO CGameObject::GetPos()
{
	return m_tInfo;
}

void CGameObject::UpdateRect()
{
	m_tRect.left = LONG(m_tInfo.fX - m_tInfo.fCX * 0.5f);
	m_tRect.top = LONG(m_tInfo.fY - m_tInfo.fCY * 0.5f);
	m_tRect.right = LONG(m_tInfo.fX + m_tInfo.fCX * 0.5f);
	m_tRect.bottom = LONG(m_tInfo.fY + m_tInfo.fCY * 0.5f);
}
