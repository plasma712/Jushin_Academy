#include "stdafx.h"
#include "cStage01Boss.h"
#include "EffectManager.h"
#include "MainGame.h"
#include "Scene.h"
#include "cBossBullet.h"
#include "cBossUIMgr.h"



cStage01Boss::cStage01Boss()
	: m_fJumpForce(0.f), m_fJumpAcc(0.f), m_fGroundY(0.f), m_bIsJump(false)
{
}


cStage01Boss::~cStage01Boss()
{
}

void cStage01Boss::Initialize()
{
	m_iCount = 0;
	m_CurState = STAGE01BOSS_START_LEFT;
	m_PreState = m_CurState;

	m_AniData.dwCurTime = GetTickCount();
	m_AniData.dwOldTime = GetTickCount();

	m_Image = CMainGame::GetInstance()->GetResource()->Get(L"ColonelLeftStart");
	m_AniData = CMainGame::GetInstance()->GetResource()->GetAniData(L"ColonelLeftStart");
	m_AniData.dwFrameSpeed = 150;


	m_tInfo.fCX = m_AniData.iWarpWidth *2.5f;
	m_tInfo.fCY = m_AniData.iHeight*2.5f;

	m_tInfo.fX = 1300.f;
	m_tInfo.fY = 200.f;

	m_fSpeed = 10.f;
	m_bAnimationWorking = false;
	m_iAniCount = 0;

	m_Direction = false;

	m_iHP = 500;
	m_iMaxHp = m_iHP;
	CuriHp = m_iHP;
	m_iAttackDamage = 10;

	dwPatternCurTime = GetTickCount();
	dwPatternOldTime = GetTickCount();

	
}

int cStage01Boss::Update()
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

	vBossFSM();
	IsFrame();
	IsAniMation();
	IsJump();

	return 0;
}

void cStage01Boss::Render(HDC hDC)
{
	BossRect();
	Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);

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
		RGB(255, 255, 255)
	);

}

void cStage01Boss::IsFrame()
{
	m_AniData.dwCurTime = GetTickCount();

	if (m_AniData.dwCurTime - m_AniData.dwOldTime > m_AniData.dwFrameSpeed)
	{
		m_iAniCount++;
		m_AniData.dwOldTime = m_AniData.dwCurTime;

		if (m_CurState == STAGE01BOSS_ATTACK01_LEFT)
		{
			if (m_iAniCount % 2 == 0)
			{
				UpDown = false;
				m_pBulletLst->push_back((CreatePattern01Bullet()));
			}
			else
			{
				UpDown = true;
				m_pBulletLst->push_back((CreatePattern01Bullet()));
			}
		}
		if (m_CurState == STAGE01BOSS_ATTACK01_RIGHT)
		{
			if (m_iAniCount % 2 == 0)
			{
				UpDown = false;
				m_pBulletLst->push_back((CreatePattern01Bullet()));
			}
			else
			{
				UpDown = true;
				m_pBulletLst->push_back((CreatePattern01Bullet()));
			}

		}

	}

	if (m_iAniCount >= m_AniData.iImageCount)
	{
		m_iAniCount = 0;
		m_bAnimationWorking = false;
	}
}

void cStage01Boss::IsAniMation()
{
	if (m_bAnimationWorking)
	{
		if (m_PreState != m_CurState)
		{
			switch (m_CurState)
			{
			case STAGE01BOSS_START_RIGHT:
				vSTART_RIGHT();
				break;
			case STAGE01BOSS_START_LEFT:
				vSTART_LEFT();
				break;
			case STAGE01BOSS_IDLE_RIGHT:
				vIDLE_RIGHT();
				break;
			case STAGE01BOSS_IDLE_LEFT:
				vIDLE_LEFT();
				break;
			case STAGE01BOSS_ATTACK01_RIGHT:
				vATTACK01_RIGHT();
				break;
			case STAGE01BOSS_ATTACK01_LEFT:
				vATTACK01_LEFT();
				break;
			}
		}
	}
}

void cStage01Boss::vBossFSM()
{
	if (m_bAnimationWorking == false)
	{

		m_CurState = STAGE01BOSS_IDLE_LEFT;
		
		m_bAnimationWorking = true;
	}
	if (MonsterX - PlayerX < 300)// 플레이어와 맵 위치간의 거리를 특정오브젝트로 체크후 나타남.
	{
		//m_CurState = sta;
	}

}

bool cStage01Boss::IsGround()
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
	float y1 = pTarget->tLPoint.y - 75.f;
	float x2 = pTarget->tRPoint.x;
	float y2 = pTarget->tRPoint.y - 75.f;

	m_fGroundY = (y2 - y1) / (x2 - x1) * (m_tInfo.fX - x1) + y1;

	return true;
}

void cStage01Boss::IsJump()
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

void cStage01Boss::BossRect()
{
	m_tRect.left = static_cast<LONG>(m_tInfo.fX - m_tInfo.fCX * 0.5f - cScrollMgr::m_fScrollX);
	m_tRect.top = static_cast<LONG>(m_tInfo.fY - m_tInfo.fCY * 0.5f - cScrollMgr::m_fScrollY);
	m_tRect.right = static_cast<LONG>(m_tInfo.fX + m_tInfo.fCX * 0.5f - cScrollMgr::m_fScrollX);
	m_tRect.bottom = static_cast<LONG>(m_tInfo.fY + m_tInfo.fCY * 0.5f - cScrollMgr::m_fScrollY);
}

CGameObject * cStage01Boss::CreatePattern01Bullet()
{
	return CAbstractFactory<cBossBullet>::CreateObject(this->GetInfo().fX - cScrollMgr::m_fScrollX, this->GetInfo().fY - cScrollMgr::m_fScrollY, m_Direction,UpDown);
}

void cStage01Boss::SetBulletLst(OBJLIST * pBulletLst)
{
	m_pBulletLst = pBulletLst;
}

#pragma region 애니메이션

void cStage01Boss::vDelay(DWORD _dwPatternFrameSpeed)
{
	while (true)
	{
		dwPatternCurTime = GetTickCount();
		if (dwPatternCurTime - dwPatternOldTime > _dwPatternFrameSpeed)
		{
			dwPatternOldTime = dwPatternCurTime;
			return;
		}
	}
}

void cStage01Boss::vSTART_RIGHT()
{
	m_Image = CMainGame::GetInstance()->GetResource()->Get(L"ColonelRightStart");
	m_AniData = CMainGame::GetInstance()->GetResource()->GetAniData(L"ColonelRightStart");
	m_CurState = STAGE01BOSS_START_RIGHT;
	m_PreState = m_CurState;

	m_AniData.dwCurTime = GetTickCount();
	m_AniData.dwOldTime = GetTickCount();
	m_AniData.dwFrameSpeed = 300;
}

void cStage01Boss::vSTART_LEFT()
{
	m_Image = CMainGame::GetInstance()->GetResource()->Get(L"ColonelLeftStart");
	m_AniData = CMainGame::GetInstance()->GetResource()->GetAniData(L"ColonelLeftStart");
	m_CurState = STAGE01BOSS_START_LEFT;
	m_PreState = m_CurState;

	m_AniData.dwCurTime = GetTickCount();
	m_AniData.dwOldTime = GetTickCount();
	m_AniData.dwFrameSpeed = 300;
}

void cStage01Boss::vIDLE_RIGHT()
{
	//m_Image = CMainGame::GetInstance()->GetResource()->Get(L"ColonelIdleRight");
	//m_AniData = CMainGame::GetInstance()->GetResource()->GetAniData(L"ColonelIdleRight");
	//m_CurState = STAGE01BOSS_IDLE_RIGHT;
	//m_PreState = m_CurState;

	//m_AniData.dwCurTime = GetTickCount();
	//m_AniData.dwOldTime = GetTickCount();
	//m_AniData.dwFrameSpeed = 30;
}

void cStage01Boss::vIDLE_LEFT()
{
	//m_Image = CMainGame::GetInstance()->GetResource()->Get(L"ColonelIdleLeft");
	//m_AniData = CMainGame::GetInstance()->GetResource()->GetAniData(L"ColonelIdleLeft");
	//m_CurState = STAGE01BOSS_IDLE_LEFT;
	//m_PreState = m_CurState;

	//m_AniData.dwCurTime = GetTickCount();
	//m_AniData.dwOldTime = GetTickCount();
	//m_AniData.dwFrameSpeed = 300;
}

void cStage01Boss::vIDLE_WALK_RIGHT()
{
}

void cStage01Boss::vIDLE_WALK_LEFT()
{
}

void cStage01Boss::vATTACK01_RIGHT()
{
	m_Image = CMainGame::GetInstance()->GetResource()->Get(L"ColonelRightAttack");
	m_AniData = CMainGame::GetInstance()->GetResource()->GetAniData(L"ColonelRightAttack");
	m_CurState = STAGE01BOSS_ATTACK01_RIGHT;
	m_PreState = m_CurState;

	m_AniData.dwCurTime = GetTickCount();
	m_AniData.dwOldTime = GetTickCount();
	m_AniData.dwFrameSpeed = 500;

}

void cStage01Boss::vATTACK01_LEFT()
{
	m_Image = CMainGame::GetInstance()->GetResource()->Get(L"ColonelLeftAttack");
	m_AniData = CMainGame::GetInstance()->GetResource()->GetAniData(L"ColonelLeftAttack");
	m_CurState = STAGE01BOSS_ATTACK01_LEFT;
	m_PreState = m_CurState;

	m_AniData.dwCurTime = GetTickCount();
	m_AniData.dwOldTime = GetTickCount();
	m_AniData.dwFrameSpeed = 500;

}

#pragma endregion