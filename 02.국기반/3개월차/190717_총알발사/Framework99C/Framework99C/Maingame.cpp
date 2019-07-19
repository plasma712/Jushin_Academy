#include "stdafx.h"
#include "Maingame.h"
#include "Player.h"
#include "cMonster.h"
#include "Bullet.h"
CMaingame::CMaingame()
	: m_pPlayer(nullptr), m_pMonster(nullptr)
{
}


CMaingame::~CMaingame()
{
	Release();
}

void CMaingame::Initialize()
{
	// GetDC: 출력 DC 생성 함수.
	m_hDC = GetDC(g_hWnd);

	if (nullptr == m_pPlayer)
	{
		m_pPlayer = new CPlayer;
		m_pPlayer->Initialize();
		dynamic_cast<CPlayer*>(m_pPlayer)->SetBulletLst(&m_BulletLst);
	}
	if (nullptr == m_pMonster)
	{
		m_pMonster = new cMonster;
		m_pMonster->Initialize();
	}
}

void CMaingame::Update()
{
	m_pPlayer->Update();
	m_pMonster->Update();
	for (auto& pBullet : m_BulletLst)
	{
		pBullet->Update();
		if (pBullet->GetPos().fY < 100 || pBullet->GetPos().fY>500)
		{
			dynamic_cast<CBullet*>(pBullet)->BulletDestory = true;
			//pBullet.
			//for_each(m_BulletLst.begin(), m_BulletLst.end(), SafeDelete<CGameObject*>);
			//dynamic_cast<CPlayer*>(m_pPlayer)->DestoryBullet(pBullet);
			//MessageBox(g_hWnd, L"DestoryBullet들어옴", L"메시지박스", MB_OK);
		}
		else if (pBullet->GetPos().fX > 700 || pBullet->GetPos().fX < 100)
		{
			dynamic_cast<CBullet*>(pBullet)->BulletDestory = true;
		}
	}

}

void CMaingame::Render()
{
	Rectangle(m_hDC, 0, 0, WINCX, WINCY);
	Rectangle(m_hDC, 100, 100, WINCX - 100, WINCY - 100);
	
	m_pPlayer->Render(m_hDC);
	m_pMonster->Render(m_hDC);

	for (auto& pBullet : m_BulletLst)
	{
		if (dynamic_cast<CBullet*>(pBullet)->BulletDestory==false)
		{
			pBullet->Render(m_hDC);
		}
	}

	//if (m_BulletLst.front() != nullptr)
	//{
	//	if (m_BulletLst.front()->GetPos().fX > 100 && m_BulletLst.front()->GetPos().fY < 50)
	//	{
	//		m_BulletLst.pop_front();
	//	}
	//}
	TCHAR szBuf[32] = L"";

	swprintf_s(szBuf, L"Bullet :%d", m_BulletLst.size());
}

void CMaingame::Release()
{
	// GetDC함수로 할당받은 DC는 아래 함수로 해제해주어야 한다.
	ReleaseDC(g_hWnd, m_hDC);

	SafeDelete(m_pPlayer);
	SafeDelete(m_pMonster);
	for_each(m_BulletLst.begin(), m_BulletLst.end(), SafeDelete<CGameObject*>);
	m_BulletLst.clear();
}
