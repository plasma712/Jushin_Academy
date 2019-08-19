#include "stdafx.h"
#include "cMiddleChargeBullet.h"
#include "EffectManager.h"


cMiddleChargeBullet::cMiddleChargeBullet()
	:m_iFrame(2), FirstPoint(false)
{
}


cMiddleChargeBullet::~cMiddleChargeBullet()
{
	Release();
}

void cMiddleChargeBullet::Initialize()
{
	m_fDirection = 0.f;
	m_Image = CMainGame::GetInstance()->GetResource()->Get(L"PlayerMiddleAttackBulletRight");
	m_AniData = CMainGame::GetInstance()->GetResource()->GetAniData(L"PlayerMiddleAttackBulletRight");

	m_tInfo.fCX = m_AniData.iWarpWidth;
	m_tInfo.fCY = m_AniData.iHeight;

	m_fSpeed = 20.f;

}

int cMiddleChargeBullet::Update()
{
	if (m_bIsDead)
		return DEAD_OBJ;

	IsMoving();
	IsOutRange();
	if (FirstPoint == false)
		vFirstPoint();

	++m_iCount;

	if (m_iCount >= m_iFrame)
	{
		m_iCount = 0;
		++m_iAniCount;
		if (m_iAniCount >= m_AniData.iImageCount)
			m_iAniCount = m_AniData.iImageCount - 1;
	}
	return NO_EVENT;
}

void cMiddleChargeBullet::Render(HDC hDC)
{
	CGameObject::UpdateRect();

	TransparentBlt
	(
		hDC,
		m_tRect.left,	   	// Rectangle로 보면 Left값
		m_tRect.top, 	   	// Rectangle로 보면 Bottom값
		m_tInfo.fCX*1.3f, 	    // 불러오는값? 이라고해야하나 사이즈 크기에 안맞으면 늘거나 줄어들음.
		m_tInfo.fCY*1.3f,	    // 불러오는값? 이라고해야하나 사이즈 크기에 안맞으면 늘거나 줄어들음.
		m_Image,			// 이미지 불러오기
		m_iAniCount*m_AniData.iWarpWidth,  // m_iAniCount*m_AniData.iWarpWidth,
		0,
		m_AniData.iWarpWidth,  // 사진사이즈 X
		m_AniData.iHeight,	   // 사진사이즈 Y
		RGB(200, 0, 255)
	);

}

void cMiddleChargeBullet::Release()
{
}

void cMiddleChargeBullet::IsMoving()
{
	if (m_bDirection == true)
	{
		//vBulletImage();
		m_Image = CMainGame::GetInstance()->GetResource()->Get(L"PlayerMiddleAttackBulletRight");
		m_AniData = CMainGame::GetInstance()->GetResource()->GetAniData(L"PlayerMiddleAttackBulletRight");
		m_tInfo.fX += cosf(m_fDirection*PI / 180)*m_fSpeed;
		m_tInfo.fY += sinf(m_fDirection*PI / 180)*m_fSpeed;
	}
	if (m_bDirection == false)
	{
		//vBulletImage();
		m_Image = CMainGame::GetInstance()->GetResource()->Get(L"PlayerMiddleAttackBulletLeft");
		m_AniData = CMainGame::GetInstance()->GetResource()->GetAniData(L"PlayerMiddleAttackBulletLeft");
		m_tInfo.fX -= cosf(m_fDirection*PI / 180)*m_fSpeed;
		m_tInfo.fY += sinf(m_fDirection*PI / 180)*m_fSpeed;
	}
}

void cMiddleChargeBullet::IsOutRange()
{
	CGameObject::UpdateRect();

	if (
		   0 >= m_tRect.left 
		|| 0 >= m_tRect.top
		|| WINCX <= m_tRect.right 
		|| WINCY <= m_tRect.bottom
		)
		m_bIsDead = true;
}

void cMiddleChargeBullet::vFirstPoint()
{
	FirstPoint = true;
	if (m_bDirection == true)
	{
		m_tInfo.fX += 45;
		m_tInfo.fY -= 28;
	}
	if (m_bDirection == false)
	{
		m_tInfo.fX -= 45;
		m_tInfo.fY -= 28;
	}

}
