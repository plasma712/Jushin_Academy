#include "stdafx.h"
#include "cPlayerIdleBulletEffect.h"


void cPlayerIdleBulletEffect::Dead()
{
	bDeadCheck = true;
}

cPlayerIdleBulletEffect::cPlayerIdleBulletEffect()
	: bDeadCheck(false)

{
}


cPlayerIdleBulletEffect::~cPlayerIdleBulletEffect()
{
}

void cPlayerIdleBulletEffect::Initialize()
{
	m_tInfo.fX = 0.f;
	m_tInfo.fY = 0.f;
	m_tInfo.fCX = 100.f;
	m_tInfo.fCY = 100.f;

	dwCurTime = GetTickCount();
	dwOldTime = GetTickCount();
	dwFrameSpeed = 30;


	m_iAniCount = 0;

}

int cPlayerIdleBulletEffect::Update()
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

void cPlayerIdleBulletEffect::Render(HDC hDC)
{
	CGameObject::UpdateRect();
	//TransparentBlt(hDC, m_tRect.left, m_tRect.top,m_tInfo.fCX, m_tInfo.fCY, m_Image, 0, 0, m_tInfo.fCX, m_tInfo.fCY, RGB(255, 255, 255));
	//Rectangle(hDC, m_tRect.left, m_tRect.top, m_AniData.iWarpWidth, m_AniData.iHeight);

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

void cPlayerIdleBulletEffect::Release()
{
}
