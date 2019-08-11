#include "stdafx.h"
#include "cBackGround.h"


cBackGround::cBackGround()
{
}


cBackGround::~cBackGround()
{
	Release();
}

void cBackGround::Init()
{
	m_Info.fX = 5438.f;
	m_Info.fY = 400.f;

	//m_Info.fWidthX = (float)WINCX;
	//m_Info.fHeightY = (float)WINCY;
	m_Info.fWidthX = 10876.f;
	m_Info.fHeightY = 856.f;

	cLineEditer::GetInstance()->ReadData();
	m_LineList = cLineEditer::GetInstance()->m_LineList;


	cAniMation::GetInstance()->LoadBmp(L"../Resource/Image/00.Map/Stage01_Far_short.bmp", L"BackGround");

}

int cBackGround::Update()
{

	return 0;
}

void cBackGround::Draw(HDC hdc)
{
	cGameObject::UpdateRect();

	HDC hMemDC = cAniMation::GetInstance()->GetMemDC(L"BackGround");
	NULL_CHECK(hMemDC);

	BitBlt
	(
		hdc, 
		m_Rect.left-cScrollMgr::m_fScrollX, 
		m_Rect.top-cScrollMgr::m_fScrollY, 
		(int)m_Info.fWidthX, 
		(int)m_Info.fHeightY,
		hMemDC,
		0,
		0,
		SRCCOPY
	);

	


}

void cBackGround::Release()
{
}
