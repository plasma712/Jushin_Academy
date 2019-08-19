#include "stdafx.h"
#include "ZigzagMonster.h"
#include "ResourceManager.h"
#include "Scene.h"
#include "Bullet.h"
#include "EffectManager.h"

CZigzagMonster::CZigzagMonster()
{
	
}


CZigzagMonster::~CZigzagMonster()
{
	
}

void CZigzagMonster::Initialize()
{
	m_iCount = 0;
	m_Image = CMainGame::GetInstance()->GetResource()->Get(L"Monster");
	m_AniData = CMainGame::GetInstance()->GetResource()->GetAniData(L"Monster");

	m_tInfo.fCX = m_AniData.iWarpWidth * 2;
	m_tInfo.fCY = m_AniData.iHeight * 2;

	m_fSpeed = 10.f;
	m_iAniCount = 0;
	m_fDirection = 135;
	m_bDir = true;
	//false-left
	//true-right
}

int CZigzagMonster::Update()
{
	
	
	if (m_bIsDead)
		return DEAD_OBJ;

	++m_iCount;

	if (m_iCount == 30)
	{
		CreateBullet();
	}

	if (m_iCount % 4 == 0)
	{
		if (m_bDir)
		{
			++m_iAniCount;
			m_fDirection = 45;
		}
		else
		{
			--m_iAniCount;
			m_fDirection = 135;
		}

	//	std::cout << m_bDir << std::endl;
		

		if (m_iAniCount == m_AniData.iImageCount - 1)
			m_bDir = false;
		if (m_iAniCount == 0)
			m_bDir = true;
	}
	IsMoving();
	IsOutRange();

	return NO_EVENT;
}

void CZigzagMonster::Render(HDC hDC)
{
	CGameObject::UpdateRect();
	//Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);

	TransparentBlt(hDC, m_tRect.left, m_tRect.top, m_tInfo.fCX, m_tInfo.fCY,
		m_Image, m_iAniCount*m_AniData.iWarpWidth, 0, m_AniData.iWarpWidth, m_AniData.iHeight,
		RGB(0, 128, 128));
}
