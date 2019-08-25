#include "stdafx.h"
#include "cFullChargeBullet.h"
#include "EffectManager.h"

cFullChargeBullet::cFullChargeBullet()
	:m_iFrame(5), FirstPoint(false)
{
}


cFullChargeBullet::~cFullChargeBullet()
{
	Release();
}

void cFullChargeBullet::Initialize()
{
	m_fDirection = 0.f;
	m_Image = CMainGame::GetInstance()->GetResource()->Get(L"PlayerFullAttackBulletRight");
	m_AniData = CMainGame::GetInstance()->GetResource()->GetAniData(L"PlayerFullAttackBulletRight");

	m_tInfo.fCX = m_AniData.iWarpWidth*2.0f;
	m_tInfo.fCY = m_AniData.iHeight*2.0f;

	m_fSpeed = 20.f;

	m_iAttackDamage = 12;
	m_iHP = 5;

}

int cFullChargeBullet::Update()
{
	if (m_bIsDead)
	{
		if(m_bDirection==false)
			CEffectManager::CreatePlayerFullChargeBullet(this->GetInfo().fX , this->GetInfo().fY , L"PlayerBulletChargeEffectLeft",m_bDirection);
		else
			CEffectManager::CreatePlayerFullChargeBullet(this->GetInfo().fX , this->GetInfo().fY , L"PlayerBulletChargeEffectRight", m_bDirection);


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
			m_iAniCount = 0;//m_AniData.iImageCount - 1;
	}
	return NO_EVENT;
}

void cFullChargeBullet::Render(HDC hDC)
{
	CGameObject::UpdateRect();

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

void cFullChargeBullet::Release()
{
}

void cFullChargeBullet::IsMoving()
{
	if (m_bDirection == true)
	{
		m_Image = CMainGame::GetInstance()->GetResource()->Get(L"PlayerFullAttackBulletRight");
		m_AniData = CMainGame::GetInstance()->GetResource()->GetAniData(L"PlayerFullAttackBulletRight");
		m_tInfo.fX += cosf(m_fDirection*PI / 180)*m_fSpeed;
		m_tInfo.fY += sinf(m_fDirection*PI / 180)*m_fSpeed;
	}
	if (m_bDirection == false)
	{
		m_Image = CMainGame::GetInstance()->GetResource()->Get(L"PlayerFullAttackBulletLeft");
		m_AniData = CMainGame::GetInstance()->GetResource()->GetAniData(L"PlayerFullAttackBulletLeft");
		m_tInfo.fX -= cosf(m_fDirection*PI / 180)*m_fSpeed;
		m_tInfo.fY += sinf(m_fDirection*PI / 180)*m_fSpeed;
	}
}

void cFullChargeBullet::IsOutRange()
{
	CGameObject::UpdateRect();

	if (
		0 >= m_tRect.left
		|| 0 >= m_tRect.top
		|| WINCX <= m_tRect.right
		|| WINCY <= m_tRect.bottom
		)
		m_bDead = true;
}

void cFullChargeBullet::vFirstPoint()
{
	FirstPoint = true;
	if (m_bDirection == true)
	{
		m_tInfo.fX += 45;
		m_tInfo.fY -= 33;
	}
	if (m_bDirection == false)
	{
		m_tInfo.fX -= 45;
		m_tInfo.fY -= 33;
	}
}
