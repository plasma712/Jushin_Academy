#include "stdafx.h"
#include "cStage01Object.h"


cStage01Object::cStage01Object()
{
}


cStage01Object::~cStage01Object()
{
}

void cStage01Object::Initialize()
{
	m_tInfo.fX = 600.f;
	m_tInfo.fY = 200.f;

	m_tInfo.fCX = 10.f;
	m_tInfo.fCY = 300.f;

}

int cStage01Object::Update()
{
	return 0;
}

void cStage01Object::Render(HDC hDC)
{

	vRect();
	Rectangle
	(
		hDC,
		m_tRect.left-100,
		m_tRect.top-100,
		m_tRect.right+100,
		m_tRect.bottom+100
	);


	//TransparentBlt
	//(
	//	hDC,
	//	m_tRect.left, //- cScrollMgr::m_fScrollX,
	//	m_tRect.top,  //- cScrollMgr::m_fScrollY,
	//	m_tInfo.fCX,
	//	m_tInfo.fCY,
	//	m_Image,
	//	m_iAniCount*m_AniData.iWarpWidth,
	//	0,
	//	m_AniData.iWarpWidth,
	//	m_AniData.iHeight,
	//	RGB(200, 0, 255)
	//);

}


void cStage01Object::Release()
{
}

void cStage01Object::vRect()
{
	m_tRect.left = static_cast<LONG>(m_tInfo.fX - m_tInfo.fCX * 0.5f)-cScrollMgr::m_fScrollX;
	m_tRect.top = static_cast<LONG>(m_tInfo.fY - m_tInfo.fCY * 0.5f) - cScrollMgr::m_fScrollY;
	m_tRect.right = static_cast<LONG>(m_tInfo.fX + m_tInfo.fCX * 0.5f) - cScrollMgr::m_fScrollX;
	m_tRect.bottom = static_cast<LONG>(m_tInfo.fY + m_tInfo.fCY * 0.5f) - cScrollMgr::m_fScrollY;
}
