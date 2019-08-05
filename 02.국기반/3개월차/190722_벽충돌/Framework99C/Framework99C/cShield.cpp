#include "stdafx.h"
#include "cShield.h"


cShield::cShield()
{
}


cShield::~cShield()
{
	Release();
}

void cShield::Initialize()
{
}

int cShield::Update()
{


	return NO_EVENT;
}

void cShield::Render(HDC hDC)
{
	CGameObject::UpdateRect();
	Ellipse(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void cShield::Release()
{
}
