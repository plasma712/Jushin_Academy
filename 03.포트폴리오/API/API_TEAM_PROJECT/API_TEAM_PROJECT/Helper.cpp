#include "stdafx.h"
#include "Helper.h"
#include "Scene.h"
#include "Bullet.h"


CHelper::CHelper()
	:m_iAttackDelay(20.f)
{
}


CHelper::~CHelper()
{
}

void CHelper::Initialize()
{
	m_tInfo.fCX = 20.f;
	m_tInfo.fCY = 20.f;

	m_fDefualt = m_tInfo.fX;
}

int CHelper::Update()
{
	
	if (!CMainGame::GetInstance()->GetScene()->GetOBJLST()[OBJECT_PLAYER].empty())
		m_pTarget = CMainGame::GetInstance()->GetScene()->GetOBJLST()[OBJECT_PLAYER].front();
	else
	{
		return DEAD_OBJ;
	}

	m_tInfo.fX = m_pTarget->GetInfo().fX + m_fDefualt;
	m_tInfo.fY = m_pTarget->GetInfo().fY;
	
	++m_iCount;

	if (m_iCount > m_iAttackDelay)
	{
		m_iCount = 0;
		CGameObject* bullet = CAbstractFactory<CBullet>::CreateObject(m_tInfo.fX, m_tInfo.fY);
		bullet->SetDirection(270);
		bullet->SetSpeed(15);
		bullet->SetSprite(L"Helper_Bullet");
		bullet->SetRect();
		CMainGame::GetInstance()->GetScene()->GetOBJLST()[OBJECT_BULLET].push_back(bullet);
	}

	if (m_iCount % 5 == 0)
	{
		++m_iAniCount;
		m_iAniCount %= m_AniData.iImageCount;
	}

	return 0;
}

void CHelper::Render(HDC hDC)
{
	CGameObject::UpdateRect();

	TransparentBlt(hDC, m_tRect.left, m_tRect.top, m_tInfo.fCX, m_tInfo.fCY,
		m_Image, m_iAniCount*m_AniData.iWarpWidth, 0, m_AniData.iWarpWidth, m_AniData.iHeight,
		RGB(0, 128, 128));
}

void CHelper::Release()
{
}

