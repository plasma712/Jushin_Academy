#include "stdafx.h"
#include "cMouse.h"


cMouse::cMouse()
{
}


cMouse::~cMouse()
{
	Release();
}

void cMouse::Init()
{
	m_Info.fWidthX = 80;
	m_Info.fHeightY = 80;

}

int cMouse::Update()
{
	GetCursorPos(&m_pMouse); // 마우스 xy값 리턴
	ScreenToClient(g_hwnd, &m_pMouse);

	m_Info.fX = float(m_pMouse.x);
	m_Info.fY = float(m_pMouse.y);

	return 0;
}

void cMouse::Draw(HDC hdc)
{
	Ellipse(hdc,
		int(m_Info.fX - m_Info.fWidthX / 2),
		int(m_Info.fY - m_Info.fHeightY / 2),
		int(m_Info.fX + m_Info.fWidthX / 2),
		int(m_Info.fY + m_Info.fHeightY / 2));
}

void cMouse::Release()
{
}
