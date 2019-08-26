#include "stdafx.h"
#include "Player.h"
#include "Bullet.h"
#include "cMiddleChargeBullet.h"
#include "cFullChargeBullet.h"
#include "ResourceManager.h"
#include "EffectManager.h"
#include "SoundManager.h"
#include "Scene.h"
#include "Helper.h"
#include "UIMgr.h"
#include "BombAirplane.h"

//#include "UIMgr.h"

float CPlayer::m_stSpeed = 0.f;

CPlayer::CPlayer()
	:bInputable(false), m_ApperSpeed(15.f), m_bAnimationWorking(false), m_OffSetSpeed(10.f)
	, m_DashCheck(false), m_Reinforce_Time(0.f), m_bReinforce(false), m_bIsJump(false), m_DashSpeedUp(false)
	, m_fJumpForce(0.f), m_fJumpAcc(0.f), m_fGroundY(0.f)
{
}


CPlayer::~CPlayer()
{
	Release();
}

void CPlayer::SetBulletLst(OBJLIST* pBulletLst)
{
	m_pBulletLst = pBulletLst;
}

void CPlayer::Initialize()
{
	m_iCount = 0;
	m_bulletCount = 0;

	m_tInfo.fX = 400.f;
	m_tInfo.fY = 200.f; // 800~500  /300  -30
	m_tInfo.fCX = 260.f;
	m_tInfo.fCY = 260.f;

	m_Direction = true;

	m_fSpeed = 10.f;
	m_Image = CMainGame::GetInstance()->GetResource()->Get(L"PlayerStart");
	m_AniData = CMainGame::GetInstance()->GetResource()->GetAniData(L"PlayerStart");
	//////////////////////////////////////
	m_CurState = IDLE_GAMESTART_RIGHT;
	m_PreState = m_CurState;

	m_AniData.dwCurTime = GetTickCount();
	m_AniData.dwOldTime = GetTickCount();
	m_AniData.dwFrameSpeed = 60;

	m_pKeyMgr = new CKeyManager();

	m_Reinforce_dwOldTime = GetTickCount();
	m_Reinforce_dwCurTime = GetTickCount();

	///////////////////////////////////////
	cLineEditer::GetInstance()->ReadData();
	m_LineList = cLineEditer::GetInstance()->m_LineList;

	m_fJumpForce = 20.f;


	m_Reinforce_CheckTime = 0.f;
	m_Reinforce_Time = 0.f;

	WalkAttackCheck = false;

	m_iHP = 10.f;
	m_iMaxHp = m_iHP;
	CuriHp = m_iHP;
	m_iAttackDamage = 5.f;

	bPlayer = true;

	NotDamage = false;
	dwPatternCurTime = GetTickCount();
	dwPatternOldTime = GetTickCount();

	BossStage = false;
}


void CPlayer::IsFrame()
{
	m_AniData.dwCurTime = GetTickCount();

	if (m_AniData.dwCurTime - m_AniData.dwOldTime > m_AniData.dwFrameSpeed)
	{
		m_iAniCount++;
		m_AniData.dwOldTime = m_AniData.dwCurTime;
		if (m_DashCheck == true && m_Direction == true)
		{
			if (m_DashSpeedUp == false)
				m_fSpeed *= 3.0f;

			m_tInfo.fX += m_fSpeed;
			m_DashSpeedUp = true;
		}
		if (m_DashCheck == true && m_Direction == false)
		{
			if (m_DashSpeedUp == false)
				m_fSpeed *= 3.0f;

			m_tInfo.fX -= m_fSpeed;
			m_DashSpeedUp = true;

		}

	}

	if (m_iAniCount >= m_AniData.iImageCount)
	{
		if (!bInputable)
		{
			if (m_iAniCount >= m_AniData.iImageCount)
			{
				m_iAniCount = 0;
				bInputable = true;
				m_CurState = IDLE_RIGHT;
				NotDamage = false;

			}
		}
		m_iAniCount = 0;
		m_DashCheck = false;
		m_bAnimationWorking = false;
		m_fSpeed = 10.f;
		m_DashSpeedUp = false;
		WalkAttackCheck = false;
		NotDamage = false;
	}
}

void CPlayer::IsAniMation()
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
		case HitRight:
			VDAMAGE_RIGHT();
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
		case HitLeft:
			VDAMAGE_LEFT();
			break;

		}
	}
}

int CPlayer::Update()
{
	m_stSpeed = m_fSpeed;

	if (m_bIsDead)
	{
		return DEAD_OBJ;
	}

	if (CuriHp != m_iHP)
	{
		CuriHp = m_iHP;
		if (m_Direction == true)
			VDAMAGE_RIGHT();
		if (m_Direction == false)
			VDAMAGE_LEFT();
	}
	//vDelay(30);
	KeyInput();
	IsFrame();

	IsAniMation();
	IsJump();
	IsOutRange();
	OffSet();


	return NO_EVENT;
}

void CPlayer::Render(HDC hDC)
{
	//CGameObject::UpdateRect();
	PlayerRectUpdate();

	//Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);

	TransparentBlt(
		hDC,
		m_tRect.left, //- cScrollMgr::m_fScrollX,	// Rectangle로 보면 Left값
		m_tRect.top,  //- cScrollMgr::m_fScrollY,	// Rectangle로 보면 Bottom값
		m_tInfo.fCX,	// 불러오는값? 이라고해야하나 사이즈 크기에 안맞으면 늘거나 줄어들음.
		m_tInfo.fCY,	// 불러오는값? 이라고해야하나 사이즈 크기에 안맞으면 늘거나 줄어들음.
		m_Image,		// 이미지 불러오기
		m_iAniCount*m_AniData.iWarpWidth,
		0,
		m_AniData.iWarpWidth,	// 사진사이즈 X
		m_AniData.iHeight,		// 사진사이즈 Y
		RGB(200, 0, 255)		// 
	);

}

void CPlayer::Release()
{
	CEffectManager::CreateEffect(this->GetInfo());
	//CSoundManager::PlayMonsterDeadSound();
}

CGameObject* CPlayer::CreateBullet()
{
	return CAbstractFactory<CBullet>::CreateObject(this->GetInfo().fX - cScrollMgr::m_fScrollX, this->GetInfo().fY - cScrollMgr::m_fScrollY, m_Direction);
}

CGameObject * CPlayer::CreateMiddleChargeBullet()
{
	return CAbstractFactory<cMiddleChargeBullet>::CreateObject(this->GetInfo().fX - cScrollMgr::m_fScrollX, this->GetInfo().fY - cScrollMgr::m_fScrollY, m_Direction);
}

CGameObject * CPlayer::CreateFullChargeBullet()
{
	return CAbstractFactory<cFullChargeBullet>::CreateObject(this->GetInfo().fX - cScrollMgr::m_fScrollX, this->GetInfo().fY - cScrollMgr::m_fScrollY, m_Direction);
}

CGameObject * CPlayer::CreateBullet(float _x, float _y)
{
	return CAbstractFactory<CBullet>::CreateObject(this->GetInfo().fX - cScrollMgr::m_fScrollX, this->GetInfo().fY - cScrollMgr::m_fScrollY - _y, m_Direction);
}

CGameObject * CPlayer::CreateMiddleChargeBullet(float _x, float _y)
{
	return CAbstractFactory<cMiddleChargeBullet>::CreateObject(this->GetInfo().fX - cScrollMgr::m_fScrollX, this->GetInfo().fY - cScrollMgr::m_fScrollY - _y, m_Direction);
}

CGameObject * CPlayer::CreateFullChargeBullet(float _x, float _y)
{
	return CAbstractFactory<cFullChargeBullet>::CreateObject(this->GetInfo().fX - cScrollMgr::m_fScrollX, this->GetInfo().fY - cScrollMgr::m_fScrollY - _y, m_Direction);
}

void CPlayer::CreateBomb()
{
	if (CBombAirplane::m_ibombCount != 0)
		return;
	CGameObject* pUI = CMainGame::GetInstance()->GetScene()->GetOBJLST()[OBJECT_UI].front();
	if (dynamic_cast<CUIMgr*>(pUI)->GetPlayerBoom() <= 0)
		return;

	dynamic_cast<CUIMgr*>(pUI)->SetPlayerBoom(-1);
	CGameObject* pBombPlane = CAbstractFactory<CBombAirplane>::CreateObject(200, 1200);
	CMainGame::GetInstance()->GetScene()->GetOBJLST()[OBJECT_EFFECT].push_back(pBombPlane);
	pBombPlane = CAbstractFactory<CBombAirplane>::CreateObject(600, 1300);
	CMainGame::GetInstance()->GetScene()->GetOBJLST()[OBJECT_EFFECT].push_back(pBombPlane);
}

void CPlayer::KeyInput()
{
	if (bInputable==true/* && NotDamage==false*/)
	{
		m_pKeyMgr->Update();
	}

	if (m_bAnimationWorking == false && bInputable == true && m_bIsJump == false&&NotDamage==false) // 모든 애니메이션 끝나고 기본상태로 돌아가게 하기위함.
	{
		if (m_Direction == true)
		{
			m_CurState = IDLE_RIGHT;
		}
		else
		{
			m_CurState = IDLE_LEFT;
		}
	}


	if (m_pKeyMgr->KeyPressing(KEY_RIGHT) && m_DashCheck == false && WalkAttackCheck == false)
	{
		m_bAnimationWorking = true;
		m_tInfo.fX += m_fSpeed;
		m_Direction = true;
		m_CurState = WALK_RIGHT;
		WalkCheck = true;
	}

	if (m_pKeyMgr->KeyPressing(KEY_RIGHT) && m_DashCheck == false && WalkAttackCheck == true)
	{
		m_tInfo.fX += m_fSpeed;
	}

	if (m_pKeyMgr->KeyUp(KEY_RIGHT))
	{

		m_CurState = IDLE_RIGHT; // 여기서 멈추는 애니메이션도 추가
		WalkCheck = false;

		m_iAniCount = 20;
		m_DashCheck = false;
		m_bAnimationWorking = false;
		m_fSpeed = 10.f;
		m_DashSpeedUp = false;
		WalkAttackCheck = false;
		//NotDamage = false;

	}

	if (m_pKeyMgr->KeyPressing(KEY_LEFT) && m_DashCheck == false && WalkAttackCheck == false)
	{
		if (WINCX / 2 - 250.f > m_tInfo.fX) // 여기서 뒤로 못가게 함.
		{
			m_bAnimationWorking = true;
			m_Direction = false;
			m_CurState = WALK_LEFT;
		}
		else
		{
			m_bAnimationWorking = true;
			m_tInfo.fX -= m_fSpeed;
			m_Direction = false;
			m_CurState = WALK_LEFT;
			WalkCheck = true;
		}
	}

	if (m_pKeyMgr->KeyPressing(KEY_LEFT) && m_DashCheck == false && WalkAttackCheck == true)
	{
		m_tInfo.fX -= m_fSpeed;
	}



	if (m_pKeyMgr->KeyUp(KEY_LEFT) && m_DashCheck == false)
	{
		m_CurState = IDLE_LEFT; // 여기서 멈추는 애니메이션도 추가
		WalkCheck = false;

		m_iAniCount = 20;
		m_DashCheck = false;
		m_bAnimationWorking = false;
		m_fSpeed = 10.f;
		m_DashSpeedUp = false;
		WalkAttackCheck = false;
		NotDamage = false;

	}

	if (m_pKeyMgr->KeyDown(KEY_C))
	{

		if (m_Direction == true && WalkCheck == false && m_DashCheck == false)
		{
			m_CurState = IDLE_ATTACK_RIGHT;
			BulletNumber = 0;
			m_pBulletLst->push_back(CreateBullet());	//딜레이 넣기
		}

		if (m_Direction == false && WalkCheck == false && m_DashCheck == false)
		{
			m_CurState = IDLE_ATTACK_LEFT;
			BulletNumber = 3;
			m_pBulletLst->push_back(CreateBullet());    //딜레이 넣기
		}

		if (m_Direction == true && WalkCheck == true && m_DashCheck == false)
		{
			m_CurState = WALK_ATTACK_RIGHT;
			BulletNumber = 0;
			WalkAttackCheck = true;
			m_pBulletLst->push_back(CreateBullet());	//딜레이 넣기
		}
		if (m_Direction == false && WalkCheck == true && m_DashCheck == false)
		{
			m_CurState = WALK_ATTACK_LEFT;
			BulletNumber = 3;
			WalkAttackCheck = true;
			m_pBulletLst->push_back(CreateBullet());    //딜레이 넣기
		}

		if (m_Direction == true && m_DashCheck == true)
		{
			m_CurState = DASH_ATTACK_RIGHT;
			BulletNumber = 0;
			m_pBulletLst->push_back(CreateBullet(0, -30));	//딜레이 넣기
		}

		if (m_Direction == false && m_DashCheck == true)
		{
			m_CurState = DASH_ATTACK_LEFT;
			BulletNumber = 0;
			m_pBulletLst->push_back(CreateBullet(0, -30));	//딜레이 넣기
		}



		m_bAnimationWorking = true;

	}
	if (m_pKeyMgr->KeyPressing(KEY_C)) // 여기서 이펙트 관리해야할듯. 차징...
	{
		m_Reinforce_dwCurTime = GetTickCount();

		m_Reinforce_CheckTime += m_Reinforce_dwCurTime - m_Reinforce_dwOldTime;
		m_Reinforce_dwOldTime = m_Reinforce_dwCurTime;

		if (m_Reinforce_CheckTime > 300 && m_Reinforce_Time <= 3)
		{
			m_Reinforce_Time++;
			m_Reinforce_CheckTime = 0;
		}

		while (m_Reinforce_CheckTime > 300 && m_Reinforce_Time < 7 && m_Reinforce_Time>3)
		{
			m_Reinforce_Time++;
			m_Reinforce_CheckTime -= 300;
			m_bReinforce = true;
			if (m_Direction == true)
				BulletNumber = 1;
			else
				BulletNumber = 4;


			CEffectManager::CreatePlayerAttackEffect2(this->GetInfo().fX - cScrollMgr::m_fScrollX, this->GetInfo().fY - cScrollMgr::m_fScrollY, L"Charge");
		}

		while (m_Reinforce_CheckTime > 300 && m_Reinforce_Time >= 7)
		{
			CEffectManager::CreatePlayerAttackEffect(this->GetInfo().fX - cScrollMgr::m_fScrollX, this->GetInfo().fY - cScrollMgr::m_fScrollY, L"ChargeFull");
			CEffectManager::CreatePlayerAttackEffect2(this->GetInfo().fX - cScrollMgr::m_fScrollX, this->GetInfo().fY - cScrollMgr::m_fScrollY, L"Charge");
			CEffectManager::CreatePlayerAttackEffect2(this->GetInfo().fX - cScrollMgr::m_fScrollX, this->GetInfo().fY - cScrollMgr::m_fScrollY, L"ChargeFull11");

			m_Reinforce_Time++;
			m_Reinforce_CheckTime -= 300;
			m_bReinforce = true;
			if (m_Direction == true)
				BulletNumber = 2;
			else
				BulletNumber = 5;

		}
	}
	if (m_pKeyMgr->KeyUp(KEY_C))
	{
		if (m_Reinforce_Time > 2 && m_Reinforce_Time < 7)
		{
			if (m_Direction == true && WalkCheck == false)
				m_CurState = IDLE_ATTACK_RIGHT;
			if (m_Direction == false && WalkCheck == false)
				m_CurState = IDLE_ATTACK_LEFT;
			//if (m_Direction == true && WalkCheck == true)
			//	m_CurState = WALK_ATTACK_RIGHT;
			//if (m_Direction == false && WalkCheck == true)
			//	m_CurState = WALK_ATTACK_LEFT;


			if (m_Direction == true && WalkCheck == true)
			{
				m_CurState = WALK_ATTACK_RIGHT;
				BulletNumber = 0;
				WalkAttackCheck = true;
			}
			if (m_Direction == false && WalkCheck == true)
			{
				m_CurState = WALK_ATTACK_LEFT;
				BulletNumber = 3;
				WalkAttackCheck = true;
			}

			if (m_Direction == false && m_DashCheck == true)
			{
				m_CurState = DASH_ATTACK_LEFT;
				BulletNumber = 0;
			}
			if (m_Direction == true && m_DashCheck == true)
			{
				m_CurState = DASH_ATTACK_RIGHT;
				BulletNumber = 0;
			}
			if (m_DashCheck == true)
				m_pBulletLst->push_back(CreateMiddleChargeBullet(0, -30));

			else
				m_pBulletLst->push_back(CreateMiddleChargeBullet());
		}

		if (m_Reinforce_Time >= 7)
		{
			if (m_Direction == true && WalkCheck == false)
				m_CurState = REINFORCE_ATTACK_RIGHT;
			if (m_Direction == false && WalkCheck == false)
				m_CurState = REINFORCE_ATTACK_LEFT;


			if (m_Direction == true && WalkCheck == true)
			{
				m_CurState = WALK_ATTACK_RIGHT;
				BulletNumber = 0;
				WalkAttackCheck = true;
			}
			if (m_Direction == false && WalkCheck == true)
			{
				m_CurState = WALK_ATTACK_LEFT;
				BulletNumber = 3;
				WalkAttackCheck = true;
			}

			if (m_Direction == false && m_DashCheck == true)
			{
				m_CurState = DASH_ATTACK_LEFT;
				BulletNumber = 0;
			}
			if (m_Direction == true && m_DashCheck == true)
			{
				m_CurState = DASH_ATTACK_RIGHT;
				BulletNumber = 0;
			}
			if (m_DashCheck == true)
				m_pBulletLst->push_back(CreateFullChargeBullet(0, -30));

			else
				m_pBulletLst->push_back(CreateFullChargeBullet());
		}
		m_bAnimationWorking == false;
		bInputable = false;
		m_Reinforce_Time = 0.f;
		m_bReinforce = false;

	}

	if (m_pKeyMgr->KeyPressing(KEY_X))
	{
		m_bAnimationWorking = true;
		m_bIsJump = true;
		if (m_Direction == true)
			m_CurState = JUMP_RIGHT;
		else
			m_CurState = JUMP_LEFT;
	}

	// 최대 높이 일때의 프레임을 맞춰두고, 
	// 높이에 따르는 프레임 속도를 조절,
	// m_blsJump는 건드리면 안되고, 대신 Grivaty를 건드려야함. 




	//if (m_pKeyMgr->KeyUp(KEY_X))
	//{
	//	if(m_AniData.iImageCount >=4)
	//		m_bIsJump = false;
	//}

	if (m_pKeyMgr->KeyDown(KEY_Z))
	{
		m_bAnimationWorking = true;
		if (m_Direction == true)
		{
			//m_tInfo.fX += m_fSpeed*1.8f;
			m_CurState = DASH_RIGHT;
			CEffectManager::CreatePlayerAttackEffect(this->GetInfo().fX - cScrollMgr::m_fScrollX - 100.f, this->GetInfo().fY - cScrollMgr::m_fScrollY + 35.f, L"DashRightEffect");
			CEffectManager::CreatePlayerAttackEffect(this->GetInfo().fX - cScrollMgr::m_fScrollX - 100.f, this->GetInfo().fY - cScrollMgr::m_fScrollY + 35.f, L"DashRightEffect01");

		}
		else
		{
			//m_tInfo.fX -= m_fSpeed*1.8f;
			m_CurState = DASH_LEFT;
			CEffectManager::CreatePlayerAttackEffect(this->GetInfo().fX - cScrollMgr::m_fScrollX + 100.f, this->GetInfo().fY - cScrollMgr::m_fScrollY + 35.f, L"DashLeftEffect");
			CEffectManager::CreatePlayerAttackEffect(this->GetInfo().fX - cScrollMgr::m_fScrollX + 100.f, this->GetInfo().fY - cScrollMgr::m_fScrollY + 35.f, L"DashLeftEffect01");

		}
	}
}

void CPlayer::IsOutRange()
{
	//if (m_tInfo.fX < 50)
	//	m_tInfo.fX = 50;
	//else if (m_tInfo.fX > 750)
	//	m_tInfo.fX = 750;
	//else if (m_tInfo.fY < 50)
	//	m_tInfo.fY = 50;
	//else if (m_tInfo.fY > 850)
	//	m_tInfo.fY = 850;
}

void CPlayer::OffSet()
{
	if (BossStage == false)
	{
		if (WINCX / 2 < m_tInfo.fX - cScrollMgr::m_fScrollX) // 이거문제있음.
		{
			cScrollMgr::m_fScrollX += m_fSpeed;
		}
		if (WINCX / 2 - 300.f > m_tInfo.fX - cScrollMgr::m_fScrollX)
		{
			cScrollMgr::m_fScrollX -= m_fSpeed;
		}
	}
	//if (BossStage == true)
	//{
	//	if (WINCX / 2 < m_tInfo.fX-300.f - cScrollMgr::m_fScrollX) // 이거문제있음.
	//	{
	//		cScrollMgr::m_fScrollX += m_fSpeed;
	//	}
	//	if (WINCX / 2 - 300.f > m_tInfo.fX - cScrollMgr::m_fScrollX)
	//	{
	//		cScrollMgr::m_fScrollX -= m_fSpeed;
	//	}
	//}

}


int CPlayer::GetEnergy()
{
	CGameObject* pUIMgr = CMainGame::GetInstance()->GetScene()->GetOBJLST()[OBJECT_UI].front();
	return dynamic_cast<CUIMgr*>(pUIMgr)->GetEnergyBarLV();

}

bool CPlayer::IsGround()
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

void CPlayer::IsJump()
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

void CPlayer::PlayerRectUpdate()
{
	m_tRect.left = static_cast<LONG>(m_tInfo.fX - m_tInfo.fCX * 0.5f - cScrollMgr::m_fScrollX);
	m_tRect.top = static_cast<LONG>(m_tInfo.fY - m_tInfo.fCY * 0.5f - cScrollMgr::m_fScrollY);
	m_tRect.right = static_cast<LONG>(m_tInfo.fX + m_tInfo.fCX * 0.5f - cScrollMgr::m_fScrollX);
	m_tRect.bottom = static_cast<LONG>(m_tInfo.fY + m_tInfo.fCY * 0.5f - cScrollMgr::m_fScrollY);
}


#pragma region 애니메이션함수

void CPlayer::vDelay(DWORD _dwPatternFrameSpeed)
{
	dwPatternCurTime = GetTickCount();
	if (dwPatternCurTime - dwPatternOldTime > _dwPatternFrameSpeed)
	{
		dwPatternOldTime = dwPatternCurTime;
		if (NotDamage == true)
			NotDamage = false;

	}

}

void CPlayer::vIDLE_GAMESTART_RIGHT()
{
	m_Image = CMainGame::GetInstance()->GetResource()->Get(L"PlayerStart");
	m_AniData = CMainGame::GetInstance()->GetResource()->GetAniData(L"PlayerStart");
	m_CurState = IDLE_GAMESTART_RIGHT;
	m_PreState = m_CurState;

	m_iAniCount = 0;
	m_AniData.dwCurTime = GetTickCount();
	m_AniData.dwOldTime = GetTickCount();
	m_AniData.dwFrameSpeed = 60;
}

void CPlayer::vIDLE_RIGHT()
{
	m_Image = CMainGame::GetInstance()->GetResource()->Get(L"PlayerIdleRight");
	m_AniData = CMainGame::GetInstance()->GetResource()->GetAniData(L"PlayerIdleRight");
	m_CurState = IDLE_RIGHT;
	m_PreState = m_CurState;
	m_iAniCount = 0;
	m_AniData.dwCurTime = GetTickCount();
	m_AniData.dwOldTime = GetTickCount();
	m_AniData.dwFrameSpeed = 100;
	
}

void CPlayer::vWALK_RIGHT()
{
	m_Image = CMainGame::GetInstance()->GetResource()->Get(L"PlayerWalkRight");
	m_AniData = CMainGame::GetInstance()->GetResource()->GetAniData(L"PlayerWalkRight");
	m_CurState = WALK_RIGHT;
	m_PreState = m_CurState;
	m_iAniCount = 0;
	m_AniData.dwCurTime = GetTickCount();
	m_AniData.dwOldTime = GetTickCount();
	m_AniData.dwFrameSpeed = 60;
}

void CPlayer::vIDLE_ATTACK_RIGHT()
{
	m_Image = CMainGame::GetInstance()->GetResource()->Get(L"PlayerIdleAttackRight");
	m_AniData = CMainGame::GetInstance()->GetResource()->GetAniData(L"PlayerIdleAttackRight");
	m_CurState = IDLE_ATTACK_RIGHT;
	m_PreState = m_CurState;
	m_iAniCount = 0;
	m_AniData.dwCurTime = GetTickCount();
	m_AniData.dwOldTime = GetTickCount();
	m_AniData.dwFrameSpeed = 30;
}

void CPlayer::vREINFORCE_ATTACK_RIGHT()
{
	m_Image = CMainGame::GetInstance()->GetResource()->Get(L"PlayerReinForceAttackRight");
	m_AniData = CMainGame::GetInstance()->GetResource()->GetAniData(L"PlayerReinForceAttackRight");
	m_CurState = REINFORCE_ATTACK_RIGHT;
	m_PreState = m_CurState;
	m_iAniCount = 0;
	m_AniData.dwCurTime = GetTickCount();
	m_AniData.dwOldTime = GetTickCount();
	m_AniData.dwFrameSpeed = 60;
}

void CPlayer::vWALK_ATTACK_RIGHT()
{
	m_Image = CMainGame::GetInstance()->GetResource()->Get(L"PlayerWalkAttackRight");
	m_AniData = CMainGame::GetInstance()->GetResource()->GetAniData(L"PlayerWalkAttackRight");
	m_CurState = WALK_ATTACK_RIGHT;
	m_PreState = m_CurState;
	m_iAniCount = 0;
	m_AniData.dwCurTime = GetTickCount();
	m_AniData.dwOldTime = GetTickCount();
	m_AniData.dwFrameSpeed = 15;
}

void CPlayer::vDASH_RIGHT()
{
	m_Image = CMainGame::GetInstance()->GetResource()->Get(L"PlayerDashRight");
	m_AniData = CMainGame::GetInstance()->GetResource()->GetAniData(L"PlayerDashRight");
	m_CurState = DASH_RIGHT;
	m_PreState = m_CurState;
	m_iAniCount = 0;
	m_AniData.dwCurTime = GetTickCount();
	m_AniData.dwOldTime = GetTickCount();
	m_AniData.dwFrameSpeed = 45;
	m_DashCheck = true;
}

void CPlayer::vDASH_ATTACK_RIGHT()
{
	m_Image = CMainGame::GetInstance()->GetResource()->Get(L"PlayerDashAttackRight");
	m_AniData = CMainGame::GetInstance()->GetResource()->GetAniData(L"PlayerDashAttackRight");
	m_CurState = DASH_RIGHT;
	m_PreState = m_CurState;
	m_iAniCount = 0;
	m_AniData.dwCurTime = GetTickCount();
	m_AniData.dwOldTime = GetTickCount();
	m_AniData.dwFrameSpeed = 45;
	m_DashCheck = true;
}

void CPlayer::vDASH_STOP_RIGHT()
{
}

void CPlayer::vJUMP_RIGHT()
{
	m_Image = CMainGame::GetInstance()->GetResource()->Get(L"PlayerJumpRight");
	m_AniData = CMainGame::GetInstance()->GetResource()->GetAniData(L"PlayerJumpRight");
	m_CurState = JUMP_RIGHT;
	m_PreState = m_CurState;
	m_iAniCount = 0;
	m_AniData.dwCurTime = GetTickCount();
	m_AniData.dwOldTime = GetTickCount();
	m_AniData.dwFrameSpeed = 60;
}

void CPlayer::vJUMP_ATTACK_RIGHT()
{
}

void CPlayer::VDAMAGE_RIGHT()
{
	m_Image = CMainGame::GetInstance()->GetResource()->Get(L"PlayerHitRight");
	m_AniData = CMainGame::GetInstance()->GetResource()->GetAniData(L"PlayerHitRight");
	m_CurState = HitRight;

	m_PreState = m_CurState;
	m_iAniCount = 0;
	m_AniData.dwCurTime = GetTickCount();
	m_AniData.dwOldTime = GetTickCount();
	m_AniData.dwFrameSpeed = 100;
	NotDamage = true;
}

void CPlayer::vIDLE_GAMESTART_LEFT()
{
}

void CPlayer::vIDLE_LEFT()
{
	m_Image = CMainGame::GetInstance()->GetResource()->Get(L"PlayerIdleLeft");
	m_AniData = CMainGame::GetInstance()->GetResource()->GetAniData(L"PlayerIdleLeft");
	m_CurState = IDLE_LEFT;
	m_PreState = m_CurState;
	m_iAniCount = 0;
	m_AniData.dwCurTime = GetTickCount();
	m_AniData.dwOldTime = GetTickCount();
	m_AniData.dwFrameSpeed = 100;

}

void CPlayer::vWALK_LEFT()
{
	m_Image = CMainGame::GetInstance()->GetResource()->Get(L"PlayerWalkLeft");
	m_AniData = CMainGame::GetInstance()->GetResource()->GetAniData(L"PlayerWalkLeft");
	m_CurState = WALK_LEFT;
	m_PreState = m_CurState;
	m_iAniCount = 0;
	m_AniData.dwCurTime = GetTickCount();
	m_AniData.dwOldTime = GetTickCount();
	m_AniData.dwFrameSpeed = 60;

}

void CPlayer::vIDLE_ATTACK_LEFT()
{
	m_Image = CMainGame::GetInstance()->GetResource()->Get(L"PlayerIdleAttackLeft");
	m_AniData = CMainGame::GetInstance()->GetResource()->GetAniData(L"PlayerIdleAttackLeft");
	m_CurState = IDLE_ATTACK_LEFT;
	m_PreState = m_CurState;
	m_iAniCount = 0;
	m_AniData.dwCurTime = GetTickCount();
	m_AniData.dwOldTime = GetTickCount();
	m_AniData.dwFrameSpeed = 60;
}

void CPlayer::vREINFORCE_ATTACK_LEFT()
{
	m_Image = CMainGame::GetInstance()->GetResource()->Get(L"PlayerReinForceAttackLeft");
	m_AniData = CMainGame::GetInstance()->GetResource()->GetAniData(L"PlayerReinForceAttackLeft");
	m_CurState = REINFORCE_ATTACK_LEFT;
	m_PreState = m_CurState;
	m_iAniCount = 0;
	m_AniData.dwCurTime = GetTickCount();
	m_AniData.dwOldTime = GetTickCount();
	m_AniData.dwFrameSpeed = 60;
}

void CPlayer::vWALK_ATTACK_LEFT()
{
	m_Image = CMainGame::GetInstance()->GetResource()->Get(L"PlayerWalkAttackLeft");
	m_AniData = CMainGame::GetInstance()->GetResource()->GetAniData(L"PlayerWalkAttackLeft");
	m_CurState = WALK_ATTACK_LEFT;
	m_PreState = m_CurState;
	m_iAniCount = 0;
	m_AniData.dwCurTime = GetTickCount();
	m_AniData.dwOldTime = GetTickCount();
	m_AniData.dwFrameSpeed = 60;
}

void CPlayer::vDASH_LEFT()
{
	m_Image = CMainGame::GetInstance()->GetResource()->Get(L"PlayerDashLeft");
	m_AniData = CMainGame::GetInstance()->GetResource()->GetAniData(L"PlayerDashLeft");
	m_CurState = DASH_LEFT;
	m_PreState = m_CurState;
	m_iAniCount = 0;
	m_AniData.dwCurTime = GetTickCount();
	m_AniData.dwOldTime = GetTickCount();
	m_AniData.dwFrameSpeed = 60;
	m_DashCheck = true;

}

void CPlayer::vDASH_ATTACK_LEFT()
{
	m_Image = CMainGame::GetInstance()->GetResource()->Get(L"PlayerDashAttackLeft");
	m_AniData = CMainGame::GetInstance()->GetResource()->GetAniData(L"PlayerDashAttackLeft");
	m_CurState = DASH_ATTACK_LEFT;
	m_PreState = m_CurState;
	m_iAniCount = 0;
	m_AniData.dwCurTime = GetTickCount();
	m_AniData.dwOldTime = GetTickCount();
	m_AniData.dwFrameSpeed = 45;
	m_DashCheck = true;
}

void CPlayer::vDASH_STOP_LEFT()
{
}

void CPlayer::vJUMP_LEFT()
{
	m_Image = CMainGame::GetInstance()->GetResource()->Get(L"PlayerJumpLeft");
	m_AniData = CMainGame::GetInstance()->GetResource()->GetAniData(L"PlayerJumpLeft");
	m_CurState = JUMP_LEFT;
	m_PreState = m_CurState;
	m_iAniCount = 0;
	m_AniData.dwCurTime = GetTickCount();
	m_AniData.dwOldTime = GetTickCount();
	m_AniData.dwFrameSpeed = 60;
}

void CPlayer::vJUMP_ATTACK_LEFT()
{
}
void CPlayer::VDAMAGE_LEFT()
{
	m_Image = CMainGame::GetInstance()->GetResource()->Get(L"PlayerHitLeft");
	m_AniData = CMainGame::GetInstance()->GetResource()->GetAniData(L"PlayerHitLeft");
	m_CurState = HitLeft;

	m_PreState = m_CurState;
	m_iAniCount = 0;
	m_AniData.dwCurTime = GetTickCount();
	m_AniData.dwOldTime = GetTickCount();
	m_AniData.dwFrameSpeed = 100;
	NotDamage = true;
}
#pragma endregion 애니메이션함수
