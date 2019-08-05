#include "stdafx.h"
#include "Player.h"
#include "Bullet.h"

CPlayer::CPlayer()
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
	m_tInfo.fX = 400.f;
	m_tInfo.fY = 400.f;
	m_tInfo.fCX = 100.f;
	m_tInfo.fCY = 100.f;

	m_fSpeed = 10.f;
}

int CPlayer::Update()
{
	KeyInput();

	return NO_EVENT;
}

void CPlayer::Render(HDC hDC)
{
	CGameObject::UpdateRect();
	Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
	PlayerBarrelDraw(hDC);
	PlayerShield(hDC);
}

void CPlayer::Release()
{
}

CGameObject* CPlayer::CreateBullet()
{
	return CAbstractFactory<CBullet>::CreateObject(m_tInfo.fX, m_tInfo.fY);
}

CGameObject* CPlayer::CreateBullet(BULLET_DIRECTION eDir, INFO m_tInfo,float _fAngle)
{
	CGameObject* pBullet = CAbstractFactory<CBullet>::CreateObject(m_tInfo.fX, m_tInfo.fY);
	dynamic_cast<CBullet*>(pBullet)->SetPos(m_tInfo.fX, m_tInfo.fY);
	dynamic_cast<CBullet*>(pBullet)->SetAngle(_fAngle);
	dynamic_cast<CBullet*>(pBullet)->SetDirection(eDir);

	return pBullet;
}


void CPlayer::KeyInput()
{
	if (GetAsyncKeyState(VK_UP) & 0x8000)
	{
		 m_tInfo.fX += cosf(m_fAngle * fPi / 180) * m_fSpeed;
		 m_tInfo.fY -= sinf(m_fAngle * fPi / 180) * m_fSpeed;
	}
	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
	{
		m_tInfo.fX -= cosf(m_fAngle * fPi / 180) * m_fSpeed;
		m_tInfo.fY += sinf(m_fAngle * fPi / 180) * m_fSpeed;
	}
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		m_fAngle -= 5;
	}
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		m_fAngle += 5;
	}
	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
	{
		m_pBulletLst->push_back(CreateBullet(BULLET_UP,this->m_tInfo,this->m_fAngle));
	}


}

void CPlayer::PlayerBarrelDraw(HDC hdc)
{
	float fx = m_tInfo.fX + cosf(m_fAngle * fPi / 180) * 100;
	float fy = m_tInfo.fY - sinf(m_fAngle * fPi / 180) * 100;


	//Rectangle(hdc, m_tInfo.fX-10, m_tInfo.fY-10, fx+10, fy+10);

	MoveToEx(hdc, m_tInfo.fX, m_tInfo.fY, NULL);
	LineTo(hdc, fx, fy);

}

void CPlayer::PlayerShield(HDC hdc)
{
	//static float ShieldAngle= 0.f;

	ShieldAngle += 2.f;

	float fx = m_tInfo.fX + cosf(ShieldAngle * fPi / 180) * 150;
	float fy = m_tInfo.fY - sinf(ShieldAngle * fPi / 180) * 150;
	
	float Top = fx + cosf(45 * fPi / 180) * 30;
	float Left = fy - sinf(45 * fPi / 180) * 30;

	float Bottom = fx - cosf(45 * fPi / 180) * 30;
	float Right = fy + sinf(45 * fPi / 180) * 30;


	Ellipse(hdc,Top,Left,Bottom, Right );
}

CGameObject * CPlayer::PlayerShieldCreate(INFO m_tInfo, float _fAngle)
{
	float fx = m_tInfo.fX + cosf(ShieldAngle * fPi / 180) * 150;
	float fy = m_tInfo.fY - sinf(ShieldAngle * fPi / 180) * 150;

	float Top = fx + cosf(45 * fPi / 180) * 30;
	float Left = fy - sinf(45 * fPi / 180) * 30;

	float Bottom = fx - cosf(45 * fPi / 180) * 30;
	float Right = fy + sinf(45 * fPi / 180) * 30;
	
	return nullptr;
}

//void CPlayer::PlayerShieldCreate(INFO m_tInfo, float _fAngle)
//{
//
//	float fx = m_tInfo.fX + cosf(ShieldAngle * fPi / 180) * 150;
//	float fy = m_tInfo.fY - sinf(ShieldAngle * fPi / 180) * 150;
//
//	float Top = fx + cosf(45 * fPi / 180) * 30;
//	float Left = fy - sinf(45 * fPi / 180) * 30;
//
//	float Bottom = fx - cosf(45 * fPi / 180) * 30;
//	float Right = fy + sinf(45 * fPi / 180) * 30;
//
//
//	//Ellipse(hdc, Top, Left, Bottom, Right);
//}


