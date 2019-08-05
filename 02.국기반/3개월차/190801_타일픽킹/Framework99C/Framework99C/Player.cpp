#include "stdafx.h"
#include "Player.h"
#include "Bullet.h"
#include "Shield.h"
#include "GuideBullet.h"
#include "BackGround.h"

CPlayer::CPlayer()
	: m_fPosinX(0.f), m_fPosinY(0.f), m_bIsJump(false), m_fGroundY(0.f),
	m_fJumpForce(0.f), m_fJumpAcc(0.f)
{
}


CPlayer::~CPlayer()
{
	Release();
}

void CPlayer::Initialize()
{
	m_tInfo.fX = 400.f;
	m_tInfo.fY = 300.f;

	m_tInfo.fCX = 200.f;
	m_tInfo.fCY = 200.f;

	m_fSpeed = 3.f;
	m_fAngle = 90.f;
	m_fPosinLength = 100.f;

	m_fJumpForce = 20.f;

	CBmpMgr::GetInstance()->LoadBmp(L"../Image/Player/Player_DOWN.bmp", L"Player_DOWN");
	CBmpMgr::GetInstance()->LoadBmp(L"../Image/Player/Player_LD.bmp", L"Player_LD");
	CBmpMgr::GetInstance()->LoadBmp(L"../Image/Player/Player_LEFT.bmp", L"Player_LEFT");
	CBmpMgr::GetInstance()->LoadBmp(L"../Image/Player/Player_LU.bmp", L"Player_LU");

	CBmpMgr::GetInstance()->LoadBmp(L"../Image/Player/Player_RD.bmp", L"Player_RD");
	CBmpMgr::GetInstance()->LoadBmp(L"../Image/Player/Player_RIGHT.bmp", L"Player_RIGHT");
	CBmpMgr::GetInstance()->LoadBmp(L"../Image/Player/Player_RU.bmp", L"Player_RU");
	CBmpMgr::GetInstance()->LoadBmp(L"../Image/Player/Player_UP.bmp", L"Player_UP");

	m_wstrObjectKey = L"Player_DOWN";
	m_eCurState = IDLE;
	m_ePreState = m_eCurState;

	m_tFrame.iStartX = 0;
	m_tFrame.iStartY = 0;
	m_tFrame.iFrameCount = 4;

	m_tFrame.dwOldTime = GetTickCount();
	m_tFrame.dwCurTime = GetTickCount();
	m_tFrame.dwFrameSpeed = 200;

}

int CPlayer::Update()
{
	KeyInput();
	IsChange();
	IsFrame();
	//IsJump();

	return NO_EVENT;
}

void CPlayer::Render(HDC hDC)
{
	CGameObject::UpdateRect();

	HDC hMemDC = CBmpMgr::GetInstance()->GetMemDC(m_wstrObjectKey);
	NULL_CHECK(hMemDC);

	// 원하는 색상 제거하여 비트맵 출력
	GdiTransparentBlt(hDC, m_tRect.left, m_tRect.top, (int)m_tInfo.fCX, (int)m_tInfo.fCY,
		hMemDC, m_tFrame.iStartX * (int)m_tInfo.fCX, 
		m_tFrame.iStartY * (int)m_tInfo.fCY,
		(int)m_tInfo.fCX, (int)m_tInfo.fCY, RGB(0, 0, 0));
}

void CPlayer::Release()
{
	
}

CGameObject* CPlayer::CreateBullet()
{
	return CAbstractFactory<CBullet>::CreateObject(m_fPosinX, m_fPosinY, m_fAngle);
}

CGameObject* CPlayer::CreateBullet(BULLET_DIRECTION eDir)
{
	CGameObject* pBullet = CAbstractFactory<CBullet>::CreateObject(m_tInfo.fX, m_tInfo.fY);
	dynamic_cast<CBullet*>(pBullet)->SetDirection(eDir);

	return pBullet;
}

CGameObject* CPlayer::CreateShield()
{
	return CAbstractFactory<CShield>::CreateObject();
}

CGameObject* CPlayer::CreateGuideBullet()
{
	return CAbstractFactory<CGuideBullet>::CreateObject(m_fPosinX, m_fPosinY);
}

void CPlayer::KeyInput()
{
	// 플레이어가 움직인만큼 스크롤도 움직인다.
	if (CKeyMgr::GetInstance()->KeyPressing(KEY_LEFT))
	{
		m_tInfo.fX -= m_fSpeed;
		CScrollMgr::m_fScrollX -= m_fSpeed;

		m_wstrObjectKey = L"Player_LEFT";
		m_eCurState = WALK;
	}
	else if (CKeyMgr::GetInstance()->KeyPressing(KEY_RIGHT))
	{
		m_tInfo.fX += m_fSpeed;
		CScrollMgr::m_fScrollX += m_fSpeed;

		m_wstrObjectKey = L"Player_RIGHT";
		m_eCurState = WALK;
	}
	else if (CKeyMgr::GetInstance()->KeyPressing(KEY_UP))
	{
		m_tInfo.fY -= m_fSpeed;

		m_wstrObjectKey = L"Player_UP";
		m_eCurState = WALK;
	}
	else if (CKeyMgr::GetInstance()->KeyPressing(KEY_DOWN))
	{
		m_tInfo.fY += m_fSpeed;

		m_wstrObjectKey = L"Player_DOWN";
		m_eCurState = WALK;
	}
	else
		m_eCurState = IDLE;
}

bool CPlayer::IsGround()
{
	CGameObject* pBackGround = CObjectMgr::GetInstance()->GetBackGround();
	NULL_CHECK_RETURN(pBackGround, false);

	const list<LINE_INFO*>& LineLst = dynamic_cast<CBackGround*>(pBackGround)->GetLineLst();

	// 플레이어가 어떤 라인을 타야하는지 검사.
	LINE_INFO* pTarget = nullptr;

	for (auto& pLine : LineLst)
	{
		if (pLine->fStartX <= m_tInfo.fX && m_tInfo.fX <= pLine->fEndX)
		{
			pTarget = pLine;
			break;
		}
	}

	NULL_CHECK_RETURN(pTarget, false);

	// 두 점을 지나는 직선의 방정식
	// y = (y2 - y1) / (x2 - x1) * (x - x1) + y1
	float x1 = pTarget->fStartX;
	float y1 = pTarget->fStartY;
	float x2 = pTarget->fEndX;
	float y2 = pTarget->fEndY;

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
		m_tInfo.fY -= m_fJumpForce * m_fJumpAcc - GRAVITY * powf(m_fJumpAcc, 2.f) * 0.5f;
		m_fJumpAcc += 0.25f;

		
		if (bIsGround && m_tInfo.fY + m_tInfo.fCY * 0.5f > m_fGroundY)
		{
			m_tInfo.fY = m_fGroundY;
			m_tInfo.fY -= m_tInfo.fCY * 0.5f;

			m_bIsJump = false;
			m_fJumpAcc = 0.f;			
		}
	}
	else
	{
		m_tInfo.fY = m_fGroundY;
		m_tInfo.fY -= m_tInfo.fCY * 0.5f;
	}
}

void CPlayer::IsFrame()
{
	m_tFrame.dwCurTime = GetTickCount();	

	if (m_tFrame.dwCurTime - m_tFrame.dwOldTime > m_tFrame.dwFrameSpeed)
	{
		m_tFrame.iStartX++;
		m_tFrame.dwOldTime = m_tFrame.dwCurTime;
	}

	if (m_tFrame.iStartX >= m_tFrame.iFrameCount)
		m_tFrame.iStartX = 0;
}

void CPlayer::IsChange()
{
	if (m_ePreState != m_eCurState)
	{
		// FSM (Finite State Machine, 유한 상태 기계)
		// 기계는 오로지 하나의 동작만 취한다.
		switch (m_eCurState)
		{
		case IDLE:
			m_tFrame.iStartX = 0;
			m_tFrame.iStartY = 0;
			m_tFrame.iFrameCount = 4;

			m_tFrame.dwOldTime = GetTickCount();
			m_tFrame.dwCurTime = GetTickCount();
			m_tFrame.dwFrameSpeed = 200;
			break;
		case WALK:
			m_tFrame.iStartX = 0;
			m_tFrame.iStartY = 1;
			m_tFrame.iFrameCount = 6;

			m_tFrame.dwOldTime = GetTickCount();
			m_tFrame.dwCurTime = GetTickCount();
			m_tFrame.dwFrameSpeed = 200;
			break;
		case ATTACK:
			break;
		case HIT:
			break;
		case DEAD:
			break;
		}

		m_ePreState = m_eCurState;
	}
}
