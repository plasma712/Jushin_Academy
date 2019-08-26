#include "stdafx.h"
#include "cBossBullet.h"


cBossBullet::cBossBullet()
{
}


cBossBullet::~cBossBullet()
{
}

void cBossBullet::Initialize()
{
	m_fDirection = 0.f;

	m_Image = CMainGame::GetInstance()->GetResource()->Get(L"ColonelBulletRight");
	m_AniData = CMainGame::GetInstance()->GetResource()->GetAniData(L"ColonelBulletRight");

	m_tInfo.fCX = m_AniData.iWarpWidth*1.5;
	m_tInfo.fCY = m_AniData.iHeight*1.5;

	m_fSpeed = 20.f;

	m_iHP = 0.f;
	m_iAttackDamage = 1.f;
	

}

int cBossBullet::Update()
{
	if (m_bIsDead)
	{
		return DEAD_OBJ;
	}

	if (m_bDead)
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

void cBossBullet::Render(HDC hDC)
{
	CGameObject::UpdateRect();
	//Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
	//TransparentBlt(hDC, m_tRect.left, m_tRect.top,m_tInfo.fCX, m_tInfo.fCY, m_Image, 0, 0, m_tInfo.fCX, m_tInfo.fCY, RGB(255, 255, 255));

	TransparentBlt
	(
		hDC,
		m_tRect.left,	   	// Rectangle로 보면 Left값
		m_tRect.top, 	   	// Rectangle로 보면 Bottom값
		m_tInfo.fCX, 	    // 불러오는값? 이라고해야하나 사이즈 크기에 안맞으면 늘거나 줄어들음.
		m_tInfo.fCY,	    // 불러오는값? 이라고해야하나 사이즈 크기에 안맞으면 늘거나 줄어들음.
		m_Image,			// 이미지 불러오기
		m_iAniCount*m_AniData.iWarpWidth,  // m_iAniCount*m_AniData.iWarpWidth,
		0,
		m_AniData.iWarpWidth,  // 사진사이즈 X
		m_AniData.iHeight,	   // 사진사이즈 Y
		RGB(200, 0, 255)
	);
}

void cBossBullet::Release()
{
}

void cBossBullet::IsMoving()
{
	if (m_bDirection == true)
	{
		m_Image = CMainGame::GetInstance()->GetResource()->Get(L"ColonelBulletRight");
		m_AniData = CMainGame::GetInstance()->GetResource()->GetAniData(L"ColonelBulletRight");

		m_tInfo.fX += cosf(m_fDirection*PI / 180)*m_fSpeed;
		m_tInfo.fY += sinf(m_fDirection*PI / 180)*m_fSpeed;
	}
	if (m_bDirection == false)
	{
		m_Image = CMainGame::GetInstance()->GetResource()->Get(L"ColonelBulletLeft");
		m_AniData = CMainGame::GetInstance()->GetResource()->GetAniData(L"ColonelBulletLeft");

		m_tInfo.fX -= cosf(m_fDirection*PI / 180)*m_fSpeed;
		m_tInfo.fY += sinf(m_fDirection*PI / 180)*m_fSpeed;
	}
}

void cBossBullet::IsOutRange()
{
}

void cBossBullet::vFirstPoint()
{
	if (m_bDirection == true && UpDown == true)
	{
		m_tInfo.fX += 45;
		m_tInfo.fY -= 50;
		FirstPoint = true;
	}
	if (m_bDirection == true && UpDown == false)
	{
		m_tInfo.fX += 45;
		m_tInfo.fY += 30;
		FirstPoint = true;

	}

	if (m_bDirection == false && UpDown == true)
	{
		m_tInfo.fX -= 45;
		m_tInfo.fY -= 50;
		FirstPoint = true;

	}
	if (m_bDirection == false && UpDown == false)
	{
		m_tInfo.fX -= 45;
		m_tInfo.fY += 30;
		FirstPoint = true;

	}

}
