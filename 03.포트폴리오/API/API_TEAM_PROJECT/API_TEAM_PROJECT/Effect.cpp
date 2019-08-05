#include "stdafx.h"
#include "Effect.h"


CEffect::CEffect()
{
}


CEffect::~CEffect()
{
}

void CEffect::Initialize()
{
	m_tInfo.fX = 0.f;
	m_tInfo.fY = 0.f;
	m_tInfo.fCX = 100.f;
	m_tInfo.fCY = 100.f;

	m_iAniCount = 0;
}

int CEffect::Update()
{
	++m_iAniCount;

	if (m_iAniCount >= m_AniData.iImageCount)
		return DEAD_OBJ;

	return 0;
}

void CEffect::Render(HDC hDC)
{
	CGameObject::UpdateRect();
	//TransparentBlt(hDC, m_tRect.left, m_tRect.top,m_tInfo.fCX, m_tInfo.fCY, m_Image, 0, 0, m_tInfo.fCX, m_tInfo.fCY, RGB(255, 255, 255));
	//Rectangle(hDC, m_tRect.left, m_tRect.top, m_AniData.iWarpWidth, m_AniData.iHeight);
	
	TransparentBlt(hDC, m_tRect.left, m_tRect.top, m_tInfo.fCX, m_tInfo.fCY,
		m_Image, m_iAniCount*m_AniData.iWarpWidth, 0, m_AniData.iWarpWidth, m_AniData.iHeight,
		RGB(50, 150, 200));

}

void CEffect::Release()
{
}
