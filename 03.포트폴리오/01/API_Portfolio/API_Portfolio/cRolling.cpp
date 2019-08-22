#include "stdafx.h"
#include "cRolling.h"
#include "EffectManager.h"

cRolling::cRolling()
	: m_fJumpForce(0.f), m_fJumpAcc(0.f), m_fGroundY(0.f), m_bIsJump(false)
{
}


cRolling::~cRolling()
{
}

void cRolling::Initialize()
{
	m_iCount = 0;
	//m_CurState = ROLLING_IDLE_RIGHT;
	m_PreState = m_CurState;

	m_AniData.dwCurTime = GetTickCount();
	m_AniData.dwOldTime = GetTickCount();
	m_AniData.dwFrameSpeed = 60;


	m_Image = CMainGame::GetInstance()->GetResource()->Get(L"RollingRightIdle");
	m_AniData = CMainGame::GetInstance()->GetResource()->GetAniData(L"RollingRightIdle");



	m_tInfo.fCX = m_AniData.iWarpWidth *1.3f;
	m_tInfo.fCY = m_AniData.iHeight*1.3f;

	m_tInfo.fX = 600.f;
	m_tInfo.fY = 200.f;

	m_fSpeed = 10.f;
	m_bAnimationWorking = false;
	m_iAniCount = 0;
}

int cRolling::Update()
{
	if (m_bIsDead)
	{
		CEffectManager::CreateMonsterDeadEffect(this->GetInfo().fX - cScrollMgr::m_fScrollX, this->GetInfo().fY - cScrollMgr::m_fScrollY, L"MonsterDeadEffect");
		return DEAD_OBJ;
	}

	vRollingFSM();
	IsFrame();
	IsAniMation();
	IsJump();

	return 0;
}

void cRolling::Render(HDC hDC)
{
	RollingRect();

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

void cRolling::IsFrame()
{
	m_AniData.dwCurTime = GetTickCount();

	if (m_AniData.dwCurTime - m_AniData.dwOldTime > m_AniData.dwFrameSpeed)
	{
		m_iAniCount++;
		m_AniData.dwOldTime = m_AniData.dwCurTime;
	}

	if (m_iAniCount >= m_AniData.iImageCount)
	{
		m_iAniCount = 0;
		m_bAnimationWorking = false;
	}
}

void cRolling::IsAniMation()
{
	if (m_PreState != m_CurState)
	{
		switch (m_CurState)
		{
		case ROLLING_IDLE_RIGHT:
			vIDLE_RIGHT();
			break;
		case ROLLING_IDLE_ROLLING_ATTACK_RIGHT:
			vIDLE_ROLLING_ATTACK_RIGHT();
			break;
		case ROLLING_RIGHT_LEFT:
			vLEFT_RIGHT();
			break;
		case ROLLING_IDLE_LEFT:
			vIDLE_LEFT();
			break;
		case ROLLING_IDLE_ROLLING_ATTACK_LEFT:
			vIDLE_ROLLING_ATTACK_LEFT();
			break;
		case ROLLING_LEFT_RIGHT:
			vRIGHT_LEFT();
			break;
		}
	}

}

void cRolling::vRollingFSM()
{
	if (m_bAnimationWorking == false)
	{
		m_CurState = ROLLING_IDLE_RIGHT;
		m_bAnimationWorking = true;
	}

}

bool cRolling::IsGround()
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

void cRolling::IsJump()
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

void cRolling::RollingRect()
{
	m_tRect.left = static_cast<LONG>(m_tInfo.fX - m_tInfo.fCX * 0.5f - cScrollMgr::m_fScrollX);
	m_tRect.top = static_cast<LONG>(m_tInfo.fY - m_tInfo.fCY * 0.5f - cScrollMgr::m_fScrollY);
	m_tRect.right = static_cast<LONG>(m_tInfo.fX + m_tInfo.fCX * 0.5f - cScrollMgr::m_fScrollX);
	m_tRect.bottom = static_cast<LONG>(m_tInfo.fY + m_tInfo.fCY * 0.5f - cScrollMgr::m_fScrollY);
}





#pragma region 애니메이션함수

void cRolling::vIDLE_RIGHT()
{
	m_Image = CMainGame::GetInstance()->GetResource()->Get(L"RollingRightIdle");
	m_AniData = CMainGame::GetInstance()->GetResource()->GetAniData(L"RollingRightIdle");
	m_CurState = ROLLING_IDLE_RIGHT;
	m_PreState = m_CurState;

	m_AniData.dwCurTime = GetTickCount();
	m_AniData.dwOldTime = GetTickCount();
	m_AniData.dwFrameSpeed = 300;
}

void cRolling::vIDLE_LEFT()
{
	m_Image = CMainGame::GetInstance()->GetResource()->Get(L"RollingLeftIdle");
	m_AniData = CMainGame::GetInstance()->GetResource()->GetAniData(L"RollingLeftIdle");
	m_CurState = ROLLING_IDLE_LEFT;
	m_PreState = m_CurState;

	m_AniData.dwCurTime = GetTickCount();
	m_AniData.dwOldTime = GetTickCount();
	m_AniData.dwFrameSpeed = 300;
}

void cRolling::vIDLE_ROLLING_ATTACK_RIGHT()
{
	m_Image = CMainGame::GetInstance()->GetResource()->Get(L"RollingRightAttack");
	m_AniData = CMainGame::GetInstance()->GetResource()->GetAniData(L"RollingRightAttack");
	m_CurState = ROLLING_IDLE_ROLLING_ATTACK_RIGHT;
	m_PreState = m_CurState;

	m_AniData.dwCurTime = GetTickCount();
	m_AniData.dwOldTime = GetTickCount();
	m_AniData.dwFrameSpeed = 300;
}

void cRolling::vIDLE_ROLLING_ATTACK_LEFT()
{
	m_Image = CMainGame::GetInstance()->GetResource()->Get(L"RollingLeftAttack");
	m_AniData = CMainGame::GetInstance()->GetResource()->GetAniData(L"RollingLeftAttack");
	m_CurState = ROLLING_IDLE_ROLLING_ATTACK_LEFT;
	m_PreState = m_CurState;

	m_AniData.dwCurTime = GetTickCount();
	m_AniData.dwOldTime = GetTickCount();
	m_AniData.dwFrameSpeed = 300;
}

void cRolling::vIDLE_ROLLING_ATTACK_RIGHT_STOP()
{
	m_Image = CMainGame::GetInstance()->GetResource()->Get(L"RollingRightAttackStop");
	m_AniData = CMainGame::GetInstance()->GetResource()->GetAniData(L"RollingRightAttackStop");
	m_CurState = ROLLING_RIGHT_LEFT;
	m_PreState = m_CurState;

	m_AniData.dwCurTime = GetTickCount();
	m_AniData.dwOldTime = GetTickCount();
	m_AniData.dwFrameSpeed = 300;
}

void cRolling::vIDLE_ROLLING_ATTACK_LEFT_STOP()
{
	m_Image = CMainGame::GetInstance()->GetResource()->Get(L"RollingLeftAttackStop");
	m_AniData = CMainGame::GetInstance()->GetResource()->GetAniData(L"RollingLeftAttackStop");
	m_CurState = ROLLING_RIGHT_LEFT;
	m_PreState = m_CurState;

	m_AniData.dwCurTime = GetTickCount();
	m_AniData.dwOldTime = GetTickCount();
	m_AniData.dwFrameSpeed = 300;
}

void cRolling::vLEFT_RIGHT()
{
	m_Image = CMainGame::GetInstance()->GetResource()->Get(L"RollingRightLeft");
	m_AniData = CMainGame::GetInstance()->GetResource()->GetAniData(L"RollingRightLeft");
	m_CurState = ROLLING_RIGHT_LEFT;
	m_PreState = m_CurState;

	m_AniData.dwCurTime = GetTickCount();
	m_AniData.dwOldTime = GetTickCount();
	m_AniData.dwFrameSpeed = 300;
}

void cRolling::vRIGHT_LEFT()
{
	m_Image = CMainGame::GetInstance()->GetResource()->Get(L"RollingLeftRight");
	m_AniData = CMainGame::GetInstance()->GetResource()->GetAniData(L"RollingLeftRight");
	m_CurState = ROLLING_LEFT_RIGHT;
	m_PreState = m_CurState;

	m_AniData.dwCurTime = GetTickCount();
	m_AniData.dwOldTime = GetTickCount();
	m_AniData.dwFrameSpeed = 300;
}
#pragma endregion
