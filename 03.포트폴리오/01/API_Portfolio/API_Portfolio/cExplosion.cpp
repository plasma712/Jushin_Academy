#include "stdafx.h"
#include "cExplosion.h"


cExplosion::cExplosion()
	:bDeadCheck(false)
{
}


cExplosion::~cExplosion()
{
}

void cExplosion::Dead()
{
	bDeadCheck = true;
}

void cExplosion::Initialize()
{
	m_tInfo.fX = 0.f;
	m_tInfo.fY = 0.f;
	m_tInfo.fCX = 100.f*2.f;
	m_tInfo.fCY = 100.f*2.f;

	dwCurTime = GetTickCount();
	dwOldTime = GetTickCount();
	dwFrameSpeed = 10;


	m_iAniCount = 0;





}

int cExplosion::Update()
{
	dwCurTime = GetTickCount();

	if (dwCurTime - dwOldTime > dwFrameSpeed)
	{
		m_iAniCount++;
		dwOldTime = dwCurTime;
	}

	if (m_iAniCount >= m_AniData.iImageCount)
	{
		return DEAD_OBJ;
	}

	return 0;
}

void cExplosion::Render(HDC hDC)
{
	vRect();
	//TransparentBlt(hDC, m_tRect.left, m_tRect.top,m_tInfo.fCX, m_tInfo.fCY, m_Image, 0, 0, m_tInfo.fCX, m_tInfo.fCY, RGB(255, 255, 255));
	//Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);

	TransparentBlt
	(
		hDC,
		m_tRect.left,
		m_tRect.top,
		m_tInfo.fCX,
		m_tInfo.fCY,
		m_Image,
		m_iAniCount*m_AniData.iWarpWidth,
		0,
		m_AniData.iWarpWidth,
		m_AniData.iHeight,
		RGB(200, 0, 255)
	);
}

void cExplosion::Release()
{
}

void cExplosion::vRect()
{
	m_tRect.left = static_cast<LONG>(m_tInfo.fX - m_tInfo.fCX * 0.5f - CPlayer::m_stSpeed);
	m_tRect.top = static_cast<LONG>(m_tInfo.fY - m_tInfo.fCY * 0.5f);
	m_tRect.right = static_cast<LONG>(m_tInfo.fX + m_tInfo.fCX * 0.5f - CPlayer::m_stSpeed);
	m_tRect.bottom = static_cast<LONG>(m_tInfo.fY + m_tInfo.fCY * 0.5f );
		
}
