#include "stdafx.h"
#include "cPlayer.h"
#include "cBackGround.h"
#include "cBullet.h"

cPlayer::cPlayer()
	: bFirstStart(false), bRight(true), m_bIsJump(false), m_fGroundY(0.f),
	m_fJumpForce(0.f), m_fJumpAcc(0.f), m_fAnimationWorking(false)
	,m_bAniISJump(false), m_OffSetSpeed(10.f)
{
}

cPlayer::~cPlayer()
{
	Release();
}

void cPlayer::Init()
{
	//cLineEditer::GetInstance()->ReadData();

	m_Info.fX = 400;
	m_Info.fY = 0;
	m_Info.fWidthX = 260.f;
	m_Info.fHeightY = 260.f;

	m_fSpeed = 0.0f;
	///////////////////////////////////////////////////////////////////////////

	//cAniMation::GetInstance()->LoadBmp(L"../Resource/Image/01.Player/x_right.bmp", L"_RIGHT");
	//cAniMation::GetInstance()->LoadBmp(L"../Resource/Image/01.Player/x_left.bmp", L"_LEFT");

	cAniMation::GetInstance()->LoadBmp(L"../Resource/Image/01.Player/Left_Player/x_left_01.bmp", L"_IDLE_GAMEEND_LEFT");
	cAniMation::GetInstance()->LoadBmp(L"../Resource/Image/01.Player/Left_Player/x_left_02.bmp", L"_IDLE_GAMESTART_LEFT");
	cAniMation::GetInstance()->LoadBmp(L"../Resource/Image/01.Player/Left_Player/x_left_03.bmp", L"_IDLE_LEFT");
	cAniMation::GetInstance()->LoadBmp(L"../Resource/Image/01.Player/Left_Player/x_left_04.bmp", L"_IDLE_ATTACK_LEFT");
	cAniMation::GetInstance()->LoadBmp(L"../Resource/Image/01.Player/Left_Player/x_left_05.bmp", L"_REINFORCE_ATTACK_LEFT");
	cAniMation::GetInstance()->LoadBmp(L"../Resource/Image/01.Player/Left_Player/x_left_06.bmp", L"_WALK_LEFT");
	cAniMation::GetInstance()->LoadBmp(L"../Resource/Image/01.Player/Left_Player/x_left_07.bmp", L"_WALK_ATTACK_LEFT");
	cAniMation::GetInstance()->LoadBmp(L"../Resource/Image/01.Player/Left_Player/x_left_08.bmp", L"_DASH_LEFT");
	cAniMation::GetInstance()->LoadBmp(L"../Resource/Image/01.Player/Left_Player/x_left_09.bmp", L"_DASH_ATTACK_LEFT");
	cAniMation::GetInstance()->LoadBmp(L"../Resource/Image/01.Player/Left_Player/x_left_10.bmp", L"_DASH_STOP_LEFT");
	cAniMation::GetInstance()->LoadBmp(L"../Resource/Image/01.Player/Left_Player/x_left_11.bmp", L"_ETC");
	cAniMation::GetInstance()->LoadBmp(L"../Resource/Image/01.Player/Left_Player/x_left_12.bmp", L"_JUMP_LEFT");
	cAniMation::GetInstance()->LoadBmp(L"../Resource/Image/01.Player/Left_Player/x_left_13.bmp", L"_JUMP_ATTACK_LEFT");
	cAniMation::GetInstance()->LoadBmp(L"../Resource/Image/01.Player/Left_Player/x_left_14.bmp", L"_ETC");
	cAniMation::GetInstance()->LoadBmp(L"../Resource/Image/01.Player/Left_Player/x_left_15.bmp", L"_ETC");
	cAniMation::GetInstance()->LoadBmp(L"../Resource/Image/01.Player/Left_Player/x_left_16.bmp", L"_ETC");
	cAniMation::GetInstance()->LoadBmp(L"../Resource/Image/01.Player/Left_Player/x_left_17.bmp", L"_ETC");
	cAniMation::GetInstance()->LoadBmp(L"../Resource/Image/01.Player/Left_Player/x_left_18.bmp", L"_ETC");
	cAniMation::GetInstance()->LoadBmp(L"../Resource/Image/01.Player/Left_Player/x_left_19.bmp", L"_ETC");
	cAniMation::GetInstance()->LoadBmp(L"../Resource/Image/01.Player/Left_Player/x_left_20.bmp", L"_ETC");
	cAniMation::GetInstance()->LoadBmp(L"../Resource/Image/01.Player/Left_Player/x_left_21.bmp", L"_ETC");
	cAniMation::GetInstance()->LoadBmp(L"../Resource/Image/01.Player/Left_Player/x_left_22.bmp", L"_ETC");
	cAniMation::GetInstance()->LoadBmp(L"../Resource/Image/01.Player/Left_Player/x_left_23.bmp", L"_ETC");
	cAniMation::GetInstance()->LoadBmp(L"../Resource/Image/01.Player/Left_Player/x_left_24.bmp", L"_ETC");
	cAniMation::GetInstance()->LoadBmp(L"../Resource/Image/01.Player/Left_Player/x_left_25.bmp", L"_ETC");
	cAniMation::GetInstance()->LoadBmp(L"../Resource/Image/01.Player/Left_Player/x_left_26.bmp", L"_ETC");
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	cAniMation::GetInstance()->LoadBmp(L"../Resource/Image/01.Player/Right_Player/x_right_01.bmp", L"_IDLE_GAMEEND_RIGHT");
	cAniMation::GetInstance()->LoadBmp(L"../Resource/Image/01.Player/Right_Player/x_right_02.bmp", L"_IDLE_GAMESTART_RIGHT");
	cAniMation::GetInstance()->LoadBmp(L"../Resource/Image/01.Player/Right_Player/x_right_03.bmp", L"_IDLE_RIGHT");
	cAniMation::GetInstance()->LoadBmp(L"../Resource/Image/01.Player/Right_Player/x_right_04.bmp", L"_IDLE_ATTACK_RIGHT");
	cAniMation::GetInstance()->LoadBmp(L"../Resource/Image/01.Player/Right_Player/x_right_05.bmp", L"_REINFORCE_ATTACK_RIGHT");
	cAniMation::GetInstance()->LoadBmp(L"../Resource/Image/01.Player/Right_Player/x_right_06.bmp", L"_WALK_RIGHT");
	cAniMation::GetInstance()->LoadBmp(L"../Resource/Image/01.Player/Right_Player/x_right_07.bmp", L"_WALK_ATTACK_RIGHT");
	cAniMation::GetInstance()->LoadBmp(L"../Resource/Image/01.Player/Right_Player/x_right_08.bmp", L"_DASH_RIGHT");
	cAniMation::GetInstance()->LoadBmp(L"../Resource/Image/01.Player/Right_Player/x_right_09.bmp", L"_DASH_ATTACK_RIGHT");
	cAniMation::GetInstance()->LoadBmp(L"../Resource/Image/01.Player/Right_Player/x_right_10.bmp", L"_DASH_STOP_RIGHT");
	cAniMation::GetInstance()->LoadBmp(L"../Resource/Image/01.Player/Right_Player/x_right_11.bmp", L"_ETC");
	cAniMation::GetInstance()->LoadBmp(L"../Resource/Image/01.Player/Right_Player/x_right_12.bmp", L"_JUMP_RIGHT");
	cAniMation::GetInstance()->LoadBmp(L"../Resource/Image/01.Player/Right_Player/x_right_13.bmp", L"_JUMP_ATTACK_RIGHT");
	cAniMation::GetInstance()->LoadBmp(L"../Resource/Image/01.Player/Right_Player/x_right_14.bmp", L"_ETC");
	cAniMation::GetInstance()->LoadBmp(L"../Resource/Image/01.Player/Right_Player/x_right_15.bmp", L"_ETC");
	cAniMation::GetInstance()->LoadBmp(L"../Resource/Image/01.Player/Right_Player/x_right_16.bmp", L"_ETC");
	cAniMation::GetInstance()->LoadBmp(L"../Resource/Image/01.Player/Right_Player/x_right_17.bmp", L"_ETC");
	cAniMation::GetInstance()->LoadBmp(L"../Resource/Image/01.Player/Right_Player/x_right_18.bmp", L"_ETC");
	cAniMation::GetInstance()->LoadBmp(L"../Resource/Image/01.Player/Right_Player/x_right_19.bmp", L"_ETC");
	cAniMation::GetInstance()->LoadBmp(L"../Resource/Image/01.Player/Right_Player/x_right_20.bmp", L"_ETC");
	cAniMation::GetInstance()->LoadBmp(L"../Resource/Image/01.Player/Right_Player/x_right_21.bmp", L"_ETC");
	cAniMation::GetInstance()->LoadBmp(L"../Resource/Image/01.Player/Right_Player/x_right_22.bmp", L"_ETC");
	cAniMation::GetInstance()->LoadBmp(L"../Resource/Image/01.Player/Right_Player/x_right_23.bmp", L"_ETC");
	cAniMation::GetInstance()->LoadBmp(L"../Resource/Image/01.Player/Right_Player/x_right_24.bmp", L"_ETC");
	cAniMation::GetInstance()->LoadBmp(L"../Resource/Image/01.Player/Right_Player/x_right_25.bmp", L"_ETC");
	cAniMation::GetInstance()->LoadBmp(L"../Resource/Image/01.Player/Right_Player/x_right_26.bmp", L"_ETC");





	///////////////////////////////////////////////////////////////////////////

	m_wstrObjectKey = L"_IDLE_GAMESTART_RIGHT";
	m_CurState = IDLE_GAMESTART_RIGHT;
	m_PreState = m_CurState;

	m_Frame.iStartX = 0;
	m_Frame.iStartY = 0;
	m_Frame.iFrameCount = 17;

	m_Frame.dwOldTime = GetTickCount();
	m_Frame.dwCurTime = GetTickCount();
	m_Frame.dwFrameSpeed = 20;

	//////////////////////////////////////////////////////////////////////////

}

int cPlayer::Update()
{
	// cLineEditer에서 이미 읽어오기때문에 굳이 안읽어도 됨.(생성순서 BackGround -> Player)
	//m_LineList = cLineEditer::GetInstance()->m_LineList;
	if (bFirstStart == true)
		KeyInput();

	IsFrame();
	Animation();
	Jump();

	OffSet();

	return 0;

}

void cPlayer::Draw(HDC hdc)
{
	//Rectangle(hdc,m_Rect.left, m_Rect.top, m_Rect.right, m_Rect.bottom);

	cGameObject::UpdateRect();

	HDC hMemDC = cAniMation::GetInstance()->GetMemDC(m_wstrObjectKey);
	NULL_CHECK(hMemDC);

	GdiTransparentBlt
	(
		hdc,
		m_Rect.left - cScrollMgr::m_fScrollX,
		m_Rect.top - cScrollMgr::m_fScrollY,
		(int)m_Info.fWidthX,
		(int)m_Info.fHeightY,
		hMemDC,
		m_Frame.iStartX * (int)m_Info.fWidthX,
		m_Frame.iStartY * (int)m_Info.fHeightY,
		(int)m_Info.fWidthX,
		(int)m_Info.fHeightY,
		RGB(201, 0, 255)
	);


}

void cPlayer::Release()
{
}

void cPlayer::KeyInput()
{
	if (cKeyMgr::GetInstance()->KeyPressing(VK_LEFT))
	{
		bRight = false;
		//m_Info.fX -= m_fSpeed;
		m_wstrObjectKey = L"_LEFT";
		m_CurState = WALK_LEFT;
	}
	else if (cKeyMgr::GetInstance()->KeyPressing(VK_RIGHT))
	{
		bRight = true;
		//m_Info.fX += m_fSpeed;
		//cScrollMgr::m_fScrollX += m_fSpeed;
		m_wstrObjectKey = L"_RIGHT";
		m_CurState = WALK_RIGHT;
	}
	else if (cKeyMgr::GetInstance()->KeyPressing('Z'))
	{
		m_fAnimationWorking = true;
		if (bRight == true)
		{
			//m_fSpeed*=1.8f;
			m_CurState = DASH_RIGHT;
		}
		else
		{
			//m_fSpeed *= 1.8f;
			m_CurState = DASH_LEFT;
		}
	}

	else if (cKeyMgr::GetInstance()->KeyPressing('X'))
	{
		if (bRight == true)
		{
			m_bIsJump = true;
			m_CurState = JUMP_RIGHT;
		}
		else
		{
			m_bIsJump = true;
			m_CurState = JUMP_LEFT;
		}

	}
	else if (cKeyMgr::GetInstance()->KeyPressing('C') || cKeyMgr::GetInstance()->KeyPressing(VK_SPACE))
	{
		m_fAnimationWorking = true;
		if (bRight == true)
		{
			m_CurState = IDLE_ATTACK_RIGHT;
			Create_IDLE_Bullet();
			//m_BulletLst->push_back((Create_IDLE_Bullet()));
		}
		else
		{
			m_CurState = IDLE_ATTACK_LEFT;
			Create_IDLE_Bullet();
			//m_BulletLst->push_back((Create_IDLE_Bullet()));
		}

	}
	else if (m_fAnimationWorking == false)
	{
		m_CurState = IDLE_RIGHT;
		//m_fSpeed = 10.f;
		m_bIsJump = false;
		m_fSpeed = 0.0f;
	}

}

void cPlayer::IsFrame()
{

	m_Frame.dwCurTime = GetTickCount();

	if (m_Frame.dwCurTime - m_Frame.dwOldTime > m_Frame.dwFrameSpeed)
	{
		m_Frame.iStartX++;
		m_Frame.dwOldTime = m_Frame.dwCurTime;
		m_Info.fX += m_fSpeed;
		m_bIsJump = m_bAniISJump;
	}

	if (m_Frame.iStartX >= m_Frame.iFrameCount)
	{
		m_Frame.iStartX = 0;
		m_fAnimationWorking = false;
		m_bIsJump = false;

		if (bFirstStart == false)
		{
			m_CurState = IDLE_RIGHT;
			bFirstStart = true;
		}
	}

}

void cPlayer::Animation()
{
	if (m_PreState != m_CurState)
	{
		switch (m_CurState)
		{
		case IDLE_GAMESTART_RIGHT:
			vIDLE_GAMESTART_RIGHT();
			break;
		case IDLE_RIGHT:
			vIDLE_RIGHT();
			break;
		case WALK_RIGHT:
			vWALK_RIGHT();
			break;
		case IDLE_ATTACK_RIGHT:
			vIDLE_ATTACK_RIGHT();
			break;
		case REINFORCE_ATTACK_RIGHT:
			vREINFORCE_ATTACK_RIGHT();
			break;
		case WALK_ATTACK_RIGHT:
			vWALK_ATTACK_RIGHT();
			break;
		case DASH_RIGHT:
			vDASH_RIGHT();
			break;
		case DASH_ATTACK_RIGHT:
			vDASH_ATTACK_RIGHT();
			break;
		case DASH_STOP_RIGHT:
			vDASH_STOP_RIGHT();
			break;
		case JUMP_RIGHT:
			vJUMP_RIGHT();
			break;
		case JUMP_ATTACK_RIGHT:
			vJUMP_ATTACK_RIGHT();
			break;
			//////////////////////////////////////////////////////////////////////////////
		case IDLE_GAMESTART_LEFT:
			vIDLE_GAMESTART_LEFT();
			break;
		case IDLE_LEFT:
			vIDLE_LEFT();
			break;
		case WALK_LEFT:
			vWALK_LEFT();
			break;
		case IDLE_ATTACK_LEFT:
			vIDLE_ATTACK_LEFT();
			break;
		case REINFORCE_ATTACK_LEFT:
			vREINFORCE_ATTACK_LEFT();
			break;
		case WALK_ATTACK_LEFT:
			vWALK_ATTACK_LEFT();
			break;
		case DASH_LEFT:
			vDASH_LEFT();
			break;
		case DASH_ATTACK_LEFT:
			vDASH_ATTACK_LEFT();
			break;
		case DASH_STOP_LEFT:
			vDASH_STOP_LEFT();
			break;
		case JUMP_LEFT:
			vJUMP_LEFT();
			break;
		case JUMP_ATTACK_LEFT:
			vJUMP_ATTACK_LEFT();
			break;

		}

		m_PreState = m_CurState;
	}
}

void cPlayer::OffSet()
{
	if (WINCX / 2 + 200.f < m_Info.fX - cScrollMgr::m_fScrollX)
	{
		cScrollMgr::m_fScrollX += m_OffSetSpeed;
	}

	if (WINCX / 2 - 200.f > m_Info.fX - cScrollMgr::m_fScrollX)
		cScrollMgr::m_fScrollX -= m_OffSetSpeed;

	if (m_CurState == IDLE_RIGHT)
	{
		if (m_Info.fX != 400) // 원하는대로... 400에 맞춘다기보단 뒤 오프셋에 맞추는느낌...
		{
			cScrollMgr::m_fScrollX += m_OffSetSpeed;
		}
	}
}

bool cPlayer::GroundCheck()
{
	LINE* pTarget = nullptr;

	list<LINE*>p_LineList = cLineEditer::GetInstance()->m_LineList;


	for (auto& pLine : p_LineList)
	{
		if (pLine->tLPoint.x <= m_Info.fX && m_Info.fX <= pLine->tRPoint.x)
		{
			pTarget = pLine;
			break;
		}
	}
	float x1 = pTarget->tLPoint.x;
	float y1 = pTarget->tLPoint.y;
	float x2 = pTarget->tRPoint.x;
	float y2 = pTarget->tRPoint.y;

	m_fGroundY = (y2 - y1) / (x2 - x1) * (m_Info.fX - x1) + y1;

	return true;

}

void cPlayer::Jump()
{
	bool bIsGround = GroundCheck();

	if (m_bIsJump)
	{
		// 수직 낙하 공식
		// y = 힘 * sin(90도) * 가속도 - 중력(9.8) * 가속도의 제곱 * 0.5
		m_Info.fY -= m_fJumpForce * m_fJumpAcc - GRAVITY * powf(m_fJumpAcc, 2.f) * 0.5f;
		m_fJumpAcc += 0.25f;


		if (bIsGround && m_Info.fY + m_Info.fHeightY * 0.5f > m_fGroundY)
		{
			m_Info.fY = m_fGroundY;
			m_Info.fY -= m_Info.fHeightY * 0.5f;

			m_bIsJump = false;
			m_fJumpAcc = 0.f;
		}
	}
	else
	{
		m_Info.fY = m_fGroundY;
		m_Info.fY -= m_Info.fHeightY * 0.5f;
	}

}


cGameObject * cPlayer::Create_IDLE_Bullet()
{
	cGameObject* pBullet = cAbstractFactory<cBullet>::CreateObject(m_Info.fX,m_Info.fY);
	dynamic_cast<cBullet*>(pBullet)->SetbRight(this->bRight);
	if (this->bRight == true)
	{
		dynamic_cast<cBullet*>(pBullet)->SetState(IDLE_BULLET_RIGHT);
		dynamic_cast<cBullet*>(pBullet)->SetbRight(true);
	}
	else
	{
		dynamic_cast<cBullet*>(pBullet)->SetState(IDLE_BULLET_LEFT);
		dynamic_cast<cBullet*>(pBullet)->SetbRight(false);
	}

	cObjectMgr::GetInstance()->AddObject(OBJECT_PLAYER_BULLET, pBullet);

	return pBullet;
}

cGameObject * cPlayer::Create_Middle_Charge_Bullet(bool _bRight)
{
	return nullptr;
}

cGameObject * cPlayer::Create_Full_Charge_Bullet(bool _bRight)
{
	return nullptr;
}

#pragma region 애니메이션


void cPlayer::vIDLE_GAMESTART_RIGHT()
{
	m_Frame.iStartX = 0;
	m_Frame.iStartY = 0;
	m_Frame.iFrameCount = 17;

	m_Frame.dwOldTime = GetTickCount();
	m_Frame.dwCurTime = GetTickCount();
	m_Frame.dwFrameSpeed = 20;
}

void cPlayer::vIDLE_RIGHT()
{
	m_Frame.iStartX = 0;
	m_Frame.iStartY = 1;
	m_Frame.iFrameCount = 9;

	m_Frame.dwOldTime = GetTickCount();
	m_Frame.dwCurTime = GetTickCount();
	m_Frame.dwFrameSpeed = 30;
	m_fSpeed = 0.0f;
}

void cPlayer::vWALK_RIGHT()
{
	m_Frame.iStartX = 2;
	m_Frame.iStartY = 4;
	m_Frame.iFrameCount = 16;

	m_Frame.dwOldTime = GetTickCount();
	m_Frame.dwCurTime = GetTickCount();
	m_Frame.dwFrameSpeed = 30;
	m_fSpeed = 10.0f;
}

void cPlayer::vIDLE_ATTACK_RIGHT()
{
	m_Frame.iStartX = 0;
	m_Frame.iStartY = 2;
	m_Frame.iFrameCount = 8;

	m_Frame.dwOldTime = GetTickCount();
	m_Frame.dwCurTime = GetTickCount();
	m_Frame.dwFrameSpeed = 30;

}

void cPlayer::vREINFORCE_ATTACK_RIGHT()
{
	m_Frame.iStartX = 0;
	m_Frame.iStartY = 3;
	m_Frame.iFrameCount = 8;

	m_Frame.dwOldTime = GetTickCount();
	m_Frame.dwCurTime = GetTickCount();
	m_Frame.dwFrameSpeed = 30;

}

void cPlayer::vWALK_ATTACK_RIGHT()
{
	m_Frame.iStartX = 0;
	m_Frame.iStartY = 5;
	m_Frame.iFrameCount = 16;

	m_Frame.dwOldTime = GetTickCount();
	m_Frame.dwCurTime = GetTickCount();
	m_Frame.dwFrameSpeed = 30;

}

void cPlayer::vDASH_RIGHT()
{
	m_Frame.iStartX = 0;
	m_Frame.iStartY = 6;
	m_Frame.iFrameCount = 12;

	m_Frame.dwOldTime = GetTickCount();
	m_Frame.dwCurTime = GetTickCount();
	m_Frame.dwFrameSpeed = 30;

	m_fSpeed = 18.f;
}

void cPlayer::vDASH_ATTACK_RIGHT()
{
	m_Frame.iStartX = 0;
	m_Frame.iStartY = 7;
	m_Frame.iFrameCount = 12;

	m_Frame.dwOldTime = GetTickCount();
	m_Frame.dwCurTime = GetTickCount();
	m_Frame.dwFrameSpeed = 30;

}

void cPlayer::vDASH_STOP_RIGHT()
{
	m_Frame.iStartX = 0;
	m_Frame.iStartY = 8;
	m_Frame.iFrameCount = 4;

	m_Frame.dwOldTime = GetTickCount();
	m_Frame.dwCurTime = GetTickCount();
	m_Frame.dwFrameSpeed = 30;

}

void cPlayer::vJUMP_RIGHT()
{
	m_Frame.iStartX = 0;
	m_Frame.iStartY = 10;
	m_Frame.iFrameCount = 4;

	m_Frame.dwOldTime = GetTickCount();
	m_Frame.dwCurTime = GetTickCount();
	m_Frame.dwFrameSpeed = 100;
	m_bAniISJump = true;
	

}

void cPlayer::vJUMP_ATTACK_RIGHT()
{
	m_Frame.iStartX = 0;
	m_Frame.iStartY = 11;
	m_Frame.iFrameCount = 4;

	m_Frame.dwOldTime = GetTickCount();
	m_Frame.dwCurTime = GetTickCount();
	m_Frame.dwFrameSpeed = 30;

}

//////////////////////////////////////////////////////////////

void cPlayer::vIDLE_GAMESTART_LEFT()
{
	m_Frame.iStartX = 0;
	m_Frame.iStartY = 0;
	m_Frame.iFrameCount = 17;

	m_Frame.dwOldTime = GetTickCount();
	m_Frame.dwCurTime = GetTickCount();
	m_Frame.dwFrameSpeed = 20;

}

void cPlayer::vIDLE_LEFT()
{
	m_Frame.iStartX = 0;
	m_Frame.iStartY = 1;
	m_Frame.iFrameCount = 9;

	m_Frame.dwOldTime = GetTickCount();
	m_Frame.dwCurTime = GetTickCount();
	m_Frame.dwFrameSpeed = 100;
	m_fSpeed = 0.0f;

}

void cPlayer::vWALK_LEFT()
{
	m_Frame.iStartX = 2;
	m_Frame.iStartY = 4;
	m_Frame.iFrameCount = 16;

	m_Frame.dwOldTime = GetTickCount();
	m_Frame.dwCurTime = GetTickCount();
	m_Frame.dwFrameSpeed = 30;
	m_fSpeed = -10.0f;
}

void cPlayer::vIDLE_ATTACK_LEFT()
{
	m_Frame.iStartX = 0;
	m_Frame.iStartY = 2;
	m_Frame.iFrameCount = 8;

	m_Frame.dwOldTime = GetTickCount();
	m_Frame.dwCurTime = GetTickCount();
	m_Frame.dwFrameSpeed = 30;

}

void cPlayer::vREINFORCE_ATTACK_LEFT()
{
	m_Frame.iStartX = 0;
	m_Frame.iStartY = 3;
	m_Frame.iFrameCount = 8;

	m_Frame.dwOldTime = GetTickCount();
	m_Frame.dwCurTime = GetTickCount();
	m_Frame.dwFrameSpeed = 30;
}

void cPlayer::vWALK_ATTACK_LEFT()
{
	m_Frame.iStartX = 0;
	m_Frame.iStartY = 5;
	m_Frame.iFrameCount = 16;

	m_Frame.dwOldTime = GetTickCount();
	m_Frame.dwCurTime = GetTickCount();
	m_Frame.dwFrameSpeed = 30;
}

void cPlayer::vDASH_LEFT()
{
	m_Frame.iStartX = 0;
	m_Frame.iStartY = 6;
	m_Frame.iFrameCount = 12;

	m_Frame.dwOldTime = GetTickCount();
	m_Frame.dwCurTime = GetTickCount();
	m_Frame.dwFrameSpeed = 30;
	m_fSpeed = -18.0f;

}

void cPlayer::vDASH_ATTACK_LEFT()
{
	m_Frame.iStartX = 0;
	m_Frame.iStartY = 7;
	m_Frame.iFrameCount = 12;

	m_Frame.dwOldTime = GetTickCount();
	m_Frame.dwCurTime = GetTickCount();
	m_Frame.dwFrameSpeed = 30;
}

void cPlayer::vDASH_STOP_LEFT()
{
	m_Frame.iStartX = 0;
	m_Frame.iStartY = 8;
	m_Frame.iFrameCount = 4;

	m_Frame.dwOldTime = GetTickCount();
	m_Frame.dwCurTime = GetTickCount();
	m_Frame.dwFrameSpeed = 30;
}

void cPlayer::vJUMP_LEFT()
{
	m_Frame.iStartX = 0;
	m_Frame.iStartY = 10;
	m_Frame.iFrameCount = 4;

	m_Frame.dwOldTime = GetTickCount();
	m_Frame.dwCurTime = GetTickCount();
	m_Frame.dwFrameSpeed = 30;
}

void cPlayer::vJUMP_ATTACK_LEFT()
{
	m_Frame.iStartX = 0;
	m_Frame.iStartY = 11;
	m_Frame.iFrameCount = 4;

	m_Frame.dwOldTime = GetTickCount();
	m_Frame.dwCurTime = GetTickCount();
	m_Frame.dwFrameSpeed = 30;
}

#pragma endregion
