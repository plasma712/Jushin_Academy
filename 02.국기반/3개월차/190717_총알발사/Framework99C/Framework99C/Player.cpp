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

void CPlayer::SetBulletLst(BULLET_LST * pBulletLst)
{
	m_pBulletLst = pBulletLst;
}

void CPlayer::Initialize()
{
	m_tInfo.fX = 400.f;
	m_tInfo.fY = 300.f;
	m_tInfo.fCX = 100.f;
	m_tInfo.fCY = 100.f;

	m_fSpeed = 10.f;
}

int CPlayer::Update()
{
	//// GetAsyncKeyState함수: 해당 키가 눌렸는지 조사하는 함수.
	//// 반환값
	//// 0x0000(0)
	//// 0x0001(양수)
	//// 0x8000(음수)
	//// 0x8001(음수)

	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		m_tInfo.fX -= m_fSpeed;
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		m_tInfo.fX += m_fSpeed;
	if (GetAsyncKeyState(VK_UP) & 0x8000)
		m_tInfo.fY -= m_fSpeed;
	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		m_tInfo.fY += m_fSpeed;
	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
		m_pBulletLst->push_back(CreateBullet(Number));
	//A 0x41
	//W 0x57
	//D 0x44
	//S 0x53
	if (GetAsyncKeyState(0x41) & 0x8000)
		Number = 0;
	if (GetAsyncKeyState(0x57) & 0x8000)
		Number = 1;
	if (GetAsyncKeyState(0x44) & 0x8000)
		Number = 2;
	if (GetAsyncKeyState(0x53) & 0x8000)
		Number = 3;

		
		
	return 0;
}

void CPlayer::Render(HDC hDC)
{
	CGameObject::UpdateRect();
	Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void CPlayer::Release()
{
}

CGameObject* CPlayer::CreateBullet(int Number)
{
	CGameObject* pBullet = new CBullet;
	pBullet->Initialize();
	pBullet->SetPos(m_tInfo.fX, m_tInfo.fY);
	dynamic_cast<CBullet*>(pBullet)->BulletArrowNumber = Number;
	return pBullet;
}

void CPlayer::DestoryBullet(CGameObject * pBullet)
{
	//MessageBox(g_hWnd, L"DestoryBullet들어옴", L"메시지박스", MB_OK);
	m_pBulletLst->remove(pBullet);
}

