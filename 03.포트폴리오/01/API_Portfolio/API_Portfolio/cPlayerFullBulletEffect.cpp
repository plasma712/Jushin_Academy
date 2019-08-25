#include "stdafx.h"
#include "cPlayerFullBulletEffect.h"
#include "Scene.h"

void cPlayerFullBulletEffect::Dead()
{
	bDeadCheck = true;
}

cPlayerFullBulletEffect::cPlayerFullBulletEffect()
{
}


cPlayerFullBulletEffect::~cPlayerFullBulletEffect()
{
}

void cPlayerFullBulletEffect::Initialize()
{
	m_tInfo.fX = 0.f;
	m_tInfo.fY = 0.f;
	m_tInfo.fCX = 100.f*1.5f;
	m_tInfo.fCY = 100.f*1.5f;

	dwCurTime = GetTickCount();
	dwOldTime = GetTickCount();
	dwFrameSpeed = 30;


	m_iAniCount = 0;
	


}

int cPlayerFullBulletEffect::Update()
{
	CGameObject::UpdateRect();
	vRect();
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

void cPlayerFullBulletEffect::Render(HDC hDC)
{
	CGameObject::UpdateRect();
	//vRect();
	//TransparentBlt(hDC, m_tRect.left, m_tRect.top,m_tInfo.fCX, m_tInfo.fCY, m_Image, 0, 0, m_tInfo.fCX, m_tInfo.fCY, RGB(255, 255, 255));
	//Rectangle(hDC, m_tRect.left, m_tRect.top, m_AniData.iWarpWidth, m_AniData.iHeight);
	Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);

	TransparentBlt
	(
		hDC,
		m_tRect.left +100,
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

void cPlayerFullBulletEffect::Release()
{
}

void cPlayerFullBulletEffect::vRect()
{
	m_tRect.left = static_cast<LONG>(m_tInfo.fX - m_tInfo.fCX * 0.5f);
	m_tRect.top = static_cast<LONG>(m_tInfo.fY - m_tInfo.fCY * 0.5f);
	m_tRect.right = static_cast<LONG>(m_tInfo.fX + m_tInfo.fCX * 0.5f );
	m_tRect.bottom = static_cast<LONG>(m_tInfo.fY + m_tInfo.fCY * 0.5f );
}
