#include "stdafx.h"
#include "Player.h"
#include "Bullet.h"
#include "Shield.h"

CPlayer::CPlayer()
	: m_fPosinX(0.f), m_fPosinY(0.f)
{
}


CPlayer::~CPlayer()
{
	Release();
}

void CPlayer::Initialize()
{
	m_tInfo.fX = 400.f;
	m_tInfo.fY = 400.f;
	m_tInfo.fCX = 100.f;
	m_tInfo.fCY = 100.f;

	m_fSpeed = 10.f;
	m_fAngle = 90.f;
	m_fPosinLength = 100.f;
}

int CPlayer::Update()
{
	KeyInput();

	// Degree -> Radian = Degree * PI / 180.f
	// Radian -> Degree = Radian * 180.f / PI
	m_fPosinX = m_tInfo.fX + cosf(m_fAngle * PI / 180.f) * m_fPosinLength;
	m_fPosinY = m_tInfo.fY - sinf(m_fAngle * PI / 180.f) * m_fPosinLength;

	return NO_EVENT;
}

void CPlayer::Render(HDC hDC)
{
	CGameObject::UpdateRect();
	Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);

	MoveToEx(hDC, (int)m_tInfo.fX, (int)m_tInfo.fY, nullptr);
	LineTo(hDC, (int)m_fPosinX, (int)m_fPosinY);
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

void CPlayer::KeyInput()
{
	if (CKeyMgr::GetInstance()->KeyPressing(KEY_LEFT))
		m_fAngle += 5.f;
	if (CKeyMgr::GetInstance()->KeyPressing(KEY_RIGHT))
		m_fAngle -= 5.f;
	if (CKeyMgr::GetInstance()->KeyPressing(KEY_UP))
	{
		m_tInfo.fX += cosf(m_fAngle * PI / 180.f) * m_fSpeed;
		m_tInfo.fY -= sinf(m_fAngle * PI / 180.f) * m_fSpeed;
	}
	if (CKeyMgr::GetInstance()->KeyPressing(KEY_DOWN))
	{
		m_tInfo.fX += cosf(m_fAngle * PI / 180.f) * -m_fSpeed;
		m_tInfo.fY -= sinf(m_fAngle * PI / 180.f) * -m_fSpeed;
	}
	if (CKeyMgr::GetInstance()->KeyUp(KEY_SPACE))
		CObjectMgr::GetInstance()->AddObject(OBJLECT_BULLET, CreateBullet());
	if (CKeyMgr::GetInstance()->KeyUp(KEY_RETURN))
		CObjectMgr::GetInstance()->AddObject(OBJECT_SHIELD, CreateShield());
}
