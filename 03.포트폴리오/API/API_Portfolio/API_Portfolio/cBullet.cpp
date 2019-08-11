#include "stdafx.h"
#include "cBullet.h"


cBullet::cBullet()
	: fSizeX(1.f), fSizeY(1.f), bRight(true)
{
}


cBullet::~cBullet()
{
	Release();
}

void cBullet::Init()
{
	m_Info.fX = 500.f;
	m_Info.fY = 300.f;

	m_Info.fWidthX = 32.f;
	m_Info.fHeightY = 32.f;

	SpeedCheck();

	cAniMation::GetInstance()->LoadBmp(L"../Resource/Image/02.Bullet/bullet_right.bmp", L"_IDLE_RIGHT");
	cAniMation::GetInstance()->LoadBmp(L"../Resource/Image/02.Bullet/medium_bullet_right.bmp", L"_MIDDLE_RIGHT");
	cAniMation::GetInstance()->LoadBmp(L"../Resource/Image/02.Bullet/charge_bullet_right.bmp", L"_FULL_RIGHT");
	cAniMation::GetInstance()->LoadBmp(L"../Resource/Image/02.Bullet/bullet_left.bmp", L"_IDLE_LEFT");
	cAniMation::GetInstance()->LoadBmp(L"../Resource/Image/02.Bullet/medium_bullet_left.bmp", L"_MIDDLE_LEFT");
	cAniMation::GetInstance()->LoadBmp(L"../Resource/Image/02.Bullet/charge_bullet_left.bmp", L"_FULL_LEFT");


	m_wstrObjectKey = L"_FULL_RIGHT";

	m_Frame.iStartX = 0;
	m_Frame.iStartY = 0;
	m_Frame.iFrameCount = 3;
	m_Info.fWidthX = 64.f;
	m_Info.fHeightY = 48.f;

	fSizeX = 64.f *1.6f;
	fSizeY = 48.f*1.6f;

	m_Frame.dwOldTime = GetTickCount();
	m_Frame.dwCurTime = GetTickCount();
	m_Frame.dwFrameSpeed = 30;
}

int cBullet::Update()
{
	SpeedCheck();
	Move();
	IsFrame();
	Animation();


	return 0;
}

void cBullet::Draw(HDC hdc)
{
	cGameObject::UpdateRect();

	HDC hMemDC = cAniMation::GetInstance()->GetMemDC(m_wstrObjectKey);
	NULL_CHECK(hMemDC);

	GdiTransparentBlt
	(
		hdc,
		m_Rect.left - cScrollMgr::m_fScrollX,
		m_Rect.top - cScrollMgr::m_fScrollY,
		fSizeX,//(int)m_Info.fWidthX*fSizeX,
		fSizeY,//(int)m_Info.fHeightY*fSizeY,
		hMemDC,
		m_Frame.iStartX * (int)m_Info.fWidthX,
		m_Frame.iStartY * (int)m_Info.fHeightY,
		(int)m_Info.fWidthX,
		(int)m_Info.fHeightY,
		RGB(200, 0, 255)
	);
}


void cBullet::Release()
{
}

void cBullet::Move()
{
	m_Info.fX += m_fSpeed;
}

void cBullet::SetbRight(bool _bRight)
{
	bRight = _bRight;
}

void cBullet::SetState(STATEBULLET _m_CurState)
{
	m_CurState = _m_CurState;
}

void cBullet::SpeedCheck()
{
	if (bRight == true)
		m_fSpeed = 20.f;
	else
		m_fSpeed = -20.f;
}

void cBullet::IsFrame()
{
	m_Frame.dwCurTime = GetTickCount();

	if (m_Frame.dwCurTime - m_Frame.dwOldTime > m_Frame.dwFrameSpeed)
	{
		m_Frame.iStartX++;
		m_Frame.dwOldTime = m_Frame.dwCurTime;
	}

	if (m_Frame.iStartX >= m_Frame.iFrameCount)
	{
		m_Frame.iStartX = 0;
	}
}

void cBullet::Animation()
{
	if (m_PreState != m_CurState)
	{
		switch (m_CurState)
		{
		case IDLE_BULLET_RIGHT:
			vIDLE_RIGHT();
			break;
		case MIDDLE_RIGHT:
			vMIDDLE_RIGHT();
			break;
		case FULL_RIGHT:
			vFULL_RIGHT();
			break;
		case IDLE_BULLET_LEFT:
			vIDLE_LEFT();
			break;
		case MIDDLE_LEFT:
			vMIDDLE_LEFT();
			break;
		case FULL_LEFT:
			vFULL_LEFT();
			break;
		}

		m_PreState = m_CurState;
	}
}

void cBullet::vIDLE_RIGHT()
{
	m_wstrObjectKey = L"_IDLE_RIGHT";
	m_Frame.iStartX = 0;
	m_Frame.iStartY = 0;
	m_Frame.iFrameCount = 5;
	m_Info.fWidthX = 32.f;
	m_Info.fHeightY = 32.f;

	fSizeX = 32.f;
	fSizeY = 32.f;


	m_Frame.dwOldTime = GetTickCount();
	m_Frame.dwCurTime = GetTickCount();
	m_Frame.dwFrameSpeed = 30;
}

void cBullet::vMIDDLE_RIGHT()
{
	m_wstrObjectKey = L"_MIDDLE_RIGHT";

	m_Frame.iStartX = 0;
	m_Frame.iStartY = 0;
	m_Frame.iFrameCount = 4;
	m_Info.fWidthX = 48.f;
	m_Info.fHeightY = 32.f;

	fSizeX = 48.f;
	fSizeY = 32.f;

	m_Frame.dwOldTime = GetTickCount();
	m_Frame.dwCurTime = GetTickCount();
	m_Frame.dwFrameSpeed = 30;

}

void cBullet::vFULL_RIGHT()
{
	m_wstrObjectKey = L"_FULL_RIGHT";

	m_Frame.iStartX = 0;
	m_Frame.iStartY = 0;
	m_Frame.iFrameCount = 3;
	m_Info.fWidthX = 64.f;
	m_Info.fHeightY = 48.f;

	fSizeX = 64.f *1.6f;
	fSizeY = 48.f*1.6f;

	m_Frame.dwOldTime = GetTickCount();
	m_Frame.dwCurTime = GetTickCount();
	m_Frame.dwFrameSpeed = 30;

}

void cBullet::vIDLE_LEFT()
{
	m_wstrObjectKey = L"_IDLE_LEFT";
	m_Frame.iStartX = 0;
	m_Frame.iStartY = 0;
	m_Frame.iFrameCount = 5;
	m_Info.fWidthX = 32.f;
	m_Info.fHeightY = 32.f;

	fSizeX = 32.f;
	fSizeY = 32.f;

	m_Frame.dwOldTime = GetTickCount();
	m_Frame.dwCurTime = GetTickCount();
	m_Frame.dwFrameSpeed = 30;

}

void cBullet::vMIDDLE_LEFT()
{
	m_wstrObjectKey = L"_MIDDLE_LEFT";

	m_Frame.iStartX = 0;
	m_Frame.iStartY = 0;
	m_Frame.iFrameCount = 4;
	m_Info.fWidthX =  48.f;
	m_Info.fHeightY = 32.f;

	fSizeX = 48.f;
	fSizeY = 32.f;


	m_Frame.dwOldTime = GetTickCount();
	m_Frame.dwCurTime = GetTickCount();
	m_Frame.dwFrameSpeed = 30;

}

void cBullet::vFULL_LEFT()
{
	m_wstrObjectKey = L"_FULL_LEFT";

	m_Frame.iStartX = 0;
	m_Frame.iStartY = 0;
	m_Frame.iFrameCount = 3;
	m_Info.fWidthX = 64.f;
	m_Info.fHeightY = 48.f;

	fSizeX = 64.f *1.6f;
	fSizeY = 48.f*1.6f;

	m_Frame.dwOldTime = GetTickCount();
	m_Frame.dwCurTime = GetTickCount();
	m_Frame.dwFrameSpeed = 30;

}
