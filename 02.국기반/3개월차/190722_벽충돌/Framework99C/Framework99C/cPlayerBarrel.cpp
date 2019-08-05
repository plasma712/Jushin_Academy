#include "stdafx.h"
#include "cPlayerBarrel.h"


cPlayerBarrel::cPlayerBarrel()
{
}


cPlayerBarrel::~cPlayerBarrel()
{
	Release();
}

void cPlayerBarrel::Initialize()
{
	m_tInfo.fX = 400.f;
	m_tInfo.fY = 400.f;
	m_tInfo.fCX = 100.f;
	m_tInfo.fCY = 100.f;

	m_fSpeed = 10.f;

}

int cPlayerBarrel::Update()
{
	KeyInput();
}

void cPlayerBarrel::Render(HDC hDC)
{
	
}

void cPlayerBarrel::Release()
{
}

void cPlayerBarrel::KeyInput()
{
	if (GetAsyncKeyState(VK_LEFT) & 0x8000) // 왼쪽으로 회전
	{
	}
	else if (GetAsyncKeyState(VK_RIGHT) & 0x8000) // 오른쪽으로 회전
	{
	}

	else if (GetAsyncKeyState(VK_UP) & 0x8000)
		m_tInfo.fY -= m_fSpeed;
	else if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		m_tInfo.fY += m_fSpeed;

}


void GetcPlayerPos()
{

}