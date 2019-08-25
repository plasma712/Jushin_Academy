#include "stdafx.h"
#include "Bullet.h"
#include "EffectManager.h"

CBullet::CBullet()
	:m_iFrame(2), FirstPoint(false)
{
}


CBullet::~CBullet()
{
	Release();
}


void CBullet::Initialize()
{
	m_fDirection = 0.f;

	m_Image = CMainGame::GetInstance()->GetResource()->Get(L"PlayerIdleAttackBulletRight");
	m_AniData = CMainGame::GetInstance()->GetResource()->GetAniData(L"PlayerIdleAttackBulletRight");

	m_tInfo.fCX = m_AniData.iWarpWidth;
	m_tInfo.fCY = m_AniData.iHeight;
	
	m_fSpeed = 20.f;
	m_iAttackDamage = 1;
	m_iHP = 0;
	//m_bDirection = true;

}

int CBullet::Update()
{
	if (m_bIsDead)
	{
		if (m_bDirection == false)
			CEffectManager::CreatePlayerFullChargeBullet(this->GetInfo().fX, this->GetInfo().fY, L"PlayerBulletIdleEffectLeft", m_bDirection);
		else
			CEffectManager::CreatePlayerFullChargeBullet(this->GetInfo().fX, this->GetInfo().fY, L"PlayerBulletIdleEffectRight", m_bDirection);

		return DEAD_OBJ;
	}

	if (m_bDead)
		return DEAD_OBJ;

	IsMoving();
	IsOutRange();
	if(FirstPoint==false)
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

void CBullet::Render(HDC hDC)
{
	CGameObject::UpdateRect();
	//Ellipse(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
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

void CBullet::Release()
{

}

void CBullet::IsMoving()
{
	if (m_bDirection == true)
	{
		//vBulletImage();
		m_Image = CMainGame::GetInstance()->GetResource()->Get(L"PlayerIdleAttackBulletRight");
		m_AniData = CMainGame::GetInstance()->GetResource()->GetAniData(L"PlayerIdleAttackBulletRight");
		m_tInfo.fX += cosf(m_fDirection*PI / 180)*m_fSpeed;
		m_tInfo.fY += sinf(m_fDirection*PI / 180)*m_fSpeed;
	}
	if(m_bDirection==false)
	{
		//vBulletImage();
		m_Image = CMainGame::GetInstance()->GetResource()->Get(L"PlayerIdleAttackBulletLeft");
		m_AniData = CMainGame::GetInstance()->GetResource()->GetAniData(L"PlayerIdleAttackBulletLeft");
		m_tInfo.fX -= cosf(m_fDirection*PI / 180)*m_fSpeed;
		m_tInfo.fY += sinf(m_fDirection*PI / 180)*m_fSpeed;
	}
}

void CBullet::IsOutRange()
{
	CGameObject::UpdateRect();

	if (0 >= m_tRect.left || 0 >= m_tRect.top
		|| WINCX <= m_tRect.right || WINCY <= m_tRect.bottom)
		m_bDead = true;
}

void CBullet::vFirstPoint()
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

void CBullet::vBulletImage()
{
	switch (BulletNumber)
	{
	case 0:
		m_Image = CMainGame::GetInstance()->GetResource()->Get(L"PlayerIdleAttackBulletRight");
		m_AniData = CMainGame::GetInstance()->GetResource()->GetAniData(L"PlayerIdleAttackBulletRight");
		break;
	case 1:
		m_Image = CMainGame::GetInstance()->GetResource()->Get(L"PlayerMiddleAttackBulletRight");
		m_AniData = CMainGame::GetInstance()->GetResource()->GetAniData(L"PlayerMiddleAttackBulletRight");
		break;
	case 2:
		m_Image = CMainGame::GetInstance()->GetResource()->Get(L"PlayerFullAttackBulletRight");
		m_AniData = CMainGame::GetInstance()->GetResource()->GetAniData(L"PlayerFullAttackBulletRight");
		break;
	case 3:
		m_Image = CMainGame::GetInstance()->GetResource()->Get(L"PlayerIdleAttackBulletLeft");
		m_AniData = CMainGame::GetInstance()->GetResource()->GetAniData(L"PlayerIdleAttackBulletLeft");
		break;
	case 4:
		m_Image = CMainGame::GetInstance()->GetResource()->Get(L"PlayerMiddleAttackBulletLeft");
		m_AniData = CMainGame::GetInstance()->GetResource()->GetAniData(L"PlayerMiddleAttackBulletLeft");
		break;
	case 5:
		m_Image = CMainGame::GetInstance()->GetResource()->Get(L"PlayerFullAttackBulletLeft");
		m_AniData = CMainGame::GetInstance()->GetResource()->GetAniData(L"PlayerFullAttackBulletLeft");
		break;
	}
}
