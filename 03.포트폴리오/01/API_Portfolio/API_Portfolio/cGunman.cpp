#include "stdafx.h"
#include "cGunman.h"
#include "EffectManager.h"
#include "MainGame.h"
#include "Scene.h"
#include "cGunManBullet.h"

cGunman::cGunman()
	: m_fJumpForce(0.f), m_fJumpAcc(0.f), m_fGroundY(0.f), m_bIsJump(false)
{
}


cGunman::~cGunman()
{
}



void cGunman::Initialize()
{
	m_iCount = 0;
	m_CurState = GUNMAN_IDLE_WALK_RIGHT;
	m_PreState = m_CurState;

	m_AniData.dwCurTime = GetTickCount();
	m_AniData.dwOldTime = GetTickCount();
	m_AniData.dwFrameSpeed = 60;


	m_Image = CMainGame::GetInstance()->GetResource()->Get(L"GunmanRightWalk");
	m_AniData = CMainGame::GetInstance()->GetResource()->GetAniData(L"GunmanRightWalk");



	m_tInfo.fCX = m_AniData.iWarpWidth *1.3f;
	m_tInfo.fCY = m_AniData.iHeight*1.3f;

	m_tInfo.fX = 600.f;
	m_tInfo.fY = 200.f;

	m_fSpeed = 10.f;
	m_bAnimationWorking = false;
	m_iAniCount = 0;

	m_Direction = false;
}

int cGunman::Update()
{
	PlayerX = CMainGame::GetInstance()->GetScene()->GetOBJLST()[OBJECT_PLAYER].front()->GetInfo().fX;
	PlayerY = CMainGame::GetInstance()->GetScene()->GetOBJLST()[OBJECT_PLAYER].front()->GetInfo().fY;
	MonsterX = m_tInfo.fX;
	MonsterY = m_tInfo.fY;

	if (m_bIsDead)
	{
		CEffectManager::CreateMonsterDeadEffect(this->GetInfo().fX - cScrollMgr::m_fScrollX, this->GetInfo().fY - cScrollMgr::m_fScrollY, L"MonsterDeadEffect");
		return DEAD_OBJ;
	}

	vGunManFSM();
	IsFrame();
	IsAniMation();
	IsJump();

	return 0;
}



void cGunman::Render(HDC hDC)
{
	//CGameObject::UpdateRect();
	GunManRect();
//	Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);

	TransparentBlt
	(
		hDC,
		m_tRect.left, //- cScrollMgr::m_fScrollX,
		m_tRect.top,  //- cScrollMgr::m_fScrollY,
		m_tInfo.fCX,
		m_tInfo.fCY,
		m_Image,
		m_iAniCount*m_AniData.iWarpWidth,
		0,
		m_AniData.iWarpWidth,
		m_AniData.iHeight,
		RGB(200, 0, 255)
	);

}

void cGunman::IsFrame()
{

	m_AniData.dwCurTime = GetTickCount();

	if (m_AniData.dwCurTime - m_AniData.dwOldTime > m_AniData.dwFrameSpeed)
	{
		m_iAniCount++;
		m_AniData.dwOldTime = m_AniData.dwCurTime;
		//CreateGunManBullet();

		if (m_iAniCount==2)
		{
			if (m_CurState == GUNMAN_ATTACK_RIGHT)
			{
				m_pBulletLst->push_back(CreateGunManBullet());
			}
		}
	}

	if (m_iAniCount >= m_AniData.iImageCount)
	{
		m_iAniCount = 0;
		m_bAnimationWorking = false;
	}
}

void cGunman::IsAniMation()
{
	if (m_bAnimationWorking)
	{
		if (m_PreState != m_CurState)
		{
			switch (m_CurState)
			{
			case GUNMAN_IDLE_RIGHT:
				vIDLE_RIGHT();
				break;
			case GUNMAN_IDLE_LEFT:
				vIDLE_LEFT();
				break;
			case GUNMAN_IDLE_WALK_RIGHT:
				vIDLE_WALK_LEFT();
				break;
			case GUNMAN_IDLE_WALK_LEFT:
				vIDLE_WALK_LEFT();
				break;
			case GUNMAN_ATTACK_RIGHT:
				vATTACK_RIGHT();
				break;
			case GUNMAN_ATTACK_LEFT:
				vATTACK_LEFT();
				break;
			}
		}
	}
}

void cGunman::vGunManFSM()
{
	if (m_bAnimationWorking == false)
	{
		m_CurState = GUNMAN_IDLE_RIGHT;
		m_bAnimationWorking = true;
	}
	if (MonsterX- PlayerX <300)
	{
		m_CurState = GUNMAN_ATTACK_RIGHT;
	}
}

bool cGunman::IsGround()
{
	LINE* pTarget = nullptr;

	list<LINE*>p_LineList = cLineEditer::GetInstance()->m_LineList;


	for (auto& pLine : p_LineList)
	{
		if (pLine->tLPoint.x <= m_tInfo.fX && m_tInfo.fX <= pLine->tRPoint.x)
		{
			pTarget = pLine;
			break;
		}
	}
	float x1 = pTarget->tLPoint.x;
	float y1 = pTarget->tLPoint.y - 50.f;
	float x2 = pTarget->tRPoint.x;
	float y2 = pTarget->tRPoint.y - 50.f;

	m_fGroundY = (y2 - y1) / (x2 - x1) * (m_tInfo.fX - x1) + y1;

	return true;
}

void cGunman::IsJump()
{
	bool bIsGround = IsGround();

	if (m_bIsJump)
	{
		// 수직 낙하 공식
		// y = 힘 * sin(90도) * 가속도 - 중력(9.8) * 가속도의 제곱 * 0.5
		m_tInfo.fY -= m_fJumpForce * m_fJumpAcc - 9.8f * powf(m_fJumpAcc, 2.f) * 0.5f;
		m_fJumpAcc += 0.25f;


		if (bIsGround && m_tInfo.fY + m_tInfo.fHeightY * 0.5f > m_fGroundY)
		{
			m_tInfo.fY = m_fGroundY;
			m_tInfo.fY -= m_tInfo.fHeightY * 0.5f;

			m_bIsJump = false;
			m_fJumpAcc = 0.f;
		}
	}
	else
	{
		m_tInfo.fY = m_fGroundY;
		m_tInfo.fY -= m_tInfo.fHeightY * 0.5f;
	}
}

void cGunman::GunManRect()
{
	m_tRect.left = static_cast<LONG>(m_tInfo.fX - m_tInfo.fCX * 0.5f-cScrollMgr::m_fScrollX);
	m_tRect.top = static_cast<LONG>(m_tInfo.fY - m_tInfo.fCY * 0.5f - cScrollMgr::m_fScrollY);
	m_tRect.right = static_cast<LONG>(m_tInfo.fX + m_tInfo.fCX * 0.5f - cScrollMgr::m_fScrollX);
	m_tRect.bottom = static_cast<LONG>(m_tInfo.fY + m_tInfo.fCY * 0.5f - cScrollMgr::m_fScrollY);
}

CGameObject * cGunman::CreateGunManBullet()
{
	return CAbstractFactory<cGunManBullet>::CreateObject(this->GetInfo().fX - cScrollMgr::m_fScrollX, this->GetInfo().fY - cScrollMgr::m_fScrollY, m_Direction);
}

void cGunman::SetBulletLst(OBJLIST * pBulletLst)
{
	m_pBulletLst = pBulletLst;
}


#pragma region 애니메이션함수

void cGunman::vIDLE_RIGHT()
{
	m_Image = CMainGame::GetInstance()->GetResource()->Get(L"GunmanRightIdle");
	m_AniData = CMainGame::GetInstance()->GetResource()->GetAniData(L"GunmanRightIdle");
	m_CurState = GUNMAN_IDLE_RIGHT;
	m_PreState = m_CurState;

	m_AniData.dwCurTime = GetTickCount();
	m_AniData.dwOldTime = GetTickCount();
	m_AniData.dwFrameSpeed = 300;

}

void cGunman::vIDLE_LEFT()
{
	m_Image = CMainGame::GetInstance()->GetResource()->Get(L"GunmanLeftIdle");
	m_AniData = CMainGame::GetInstance()->GetResource()->GetAniData(L"GunmanLeftIdle");
	m_CurState = GUNMAN_IDLE_LEFT;
	m_PreState = m_CurState;

	m_AniData.dwCurTime = GetTickCount();
	m_AniData.dwOldTime = GetTickCount();
	m_AniData.dwFrameSpeed = 100;

}

void cGunman::vIDLE_WALK_RIGHT()
{
	m_Image = CMainGame::GetInstance()->GetResource()->Get(L"GunmanRightWalk");
	m_AniData = CMainGame::GetInstance()->GetResource()->GetAniData(L"GunmanRightWalk");
	m_CurState = GUNMAN_IDLE_WALK_RIGHT;
	m_PreState = m_CurState;

	m_AniData.dwCurTime = GetTickCount();
	m_AniData.dwOldTime = GetTickCount();
	m_AniData.dwFrameSpeed = 100;

}

void cGunman::vIDLE_WALK_LEFT()
{
	m_Image = CMainGame::GetInstance()->GetResource()->Get(L"GunmanLeftWalk");
	m_AniData = CMainGame::GetInstance()->GetResource()->GetAniData(L"GunmanLeftWalk");
	m_CurState = GUNMAN_IDLE_WALK_LEFT;
	m_PreState = m_CurState;

	m_AniData.dwCurTime = GetTickCount();
	m_AniData.dwOldTime = GetTickCount();
	m_AniData.dwFrameSpeed = 100;

}

void cGunman::vATTACK_RIGHT()
{
	m_Image = CMainGame::GetInstance()->GetResource()->Get(L"GunmanRightGun");
	m_AniData = CMainGame::GetInstance()->GetResource()->GetAniData(L"GunmanRightGun");
	m_CurState = GUNMAN_ATTACK_RIGHT;
	m_PreState = m_CurState;

	m_AniData.dwCurTime = GetTickCount();
	m_AniData.dwOldTime = GetTickCount();
	m_AniData.dwFrameSpeed = 200;

}

void cGunman::vATTACK_LEFT()
{
	m_Image = CMainGame::GetInstance()->GetResource()->Get(L"GunmanLeftGun");
	m_AniData = CMainGame::GetInstance()->GetResource()->GetAniData(L"GunmanLeftGun");
	m_CurState = GUNMAN_ATTACK_LEFT;
	m_PreState = m_CurState;

	m_AniData.dwCurTime = GetTickCount();
	m_AniData.dwOldTime = GetTickCount();
	m_AniData.dwFrameSpeed = 200;

}
#pragma endregion
