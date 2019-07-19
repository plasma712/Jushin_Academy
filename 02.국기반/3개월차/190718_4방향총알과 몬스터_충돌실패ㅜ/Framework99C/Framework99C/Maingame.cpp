#include "stdafx.h"
#include "Maingame.h"
#include "Player.h"
#include "Monster.h"
#include "cMonsterCreate.h"

CMaingame::CMaingame()
	: m_pPlayer(nullptr), m_MonsterCreate(nullptr)
{
}


CMaingame::~CMaingame()
{
	Release();
}

void CMaingame::Initialize()
{

	// GetDC: ��� DC ���� �Լ�.
	m_hDC = GetDC(g_hWnd);

	if (nullptr == m_pPlayer)
	{
		m_pPlayer = new CPlayer;
		m_pPlayer->Initialize();
		dynamic_cast<CPlayer*>(m_pPlayer)->SetBulletLst(&m_BulletLst);
		dynamic_cast<CPlayer*>(m_pPlayer)->SetBulletLst(&m_MonsterLst);
	}

	if (m_MonsterCreate == nullptr)
	{
		m_MonsterCreate = new cMonsterCreate;
		m_MonsterCreate->Initialize();
		dynamic_cast<cMonsterCreate*>(m_MonsterCreate)->SetMonsterCreate(&m_MonsterLst);
	}

	//if (nullptr == m_pMonster)
	//{
	//	m_pMonster = new CMonster;
	//	m_pMonster->Initialize();
	//}
}

void CMaingame::Update()
{
	m_pPlayer->Update();
	//m_pMonster->Update();
	// if�� ����

	//dwCurTime = GetTickCount();

	//if (dwCurTime - dwOldTime >= 3000) // 3�� �������� ����.
	//{
	//	//dynamic_cast<cMonsterCreate*>(m_MonsterCreate)->CreateMonster();
	//	dynamic_cast<cMonsterCreate*>(m_MonsterCreate)->Update();
	//	dwOldTime = dwCurTime;
	//}

	//MONSTER_LST::iterator Monsteriter_Begin = m_MonsterLst.begin();
	//MONSTER_LST::iterator Monsteriter_End = m_MonsterLst.end();
	//
	//for (; Monsteriter_Begin != Monsteriter_End;)
	//{
	//	(*Monsteriter_Begin)->Update();
	//	++Monsteriter_Begin;
	//}

	BULLET_LST::iterator iter_Begin = m_BulletLst.begin();
	BULLET_LST::iterator iter_End = m_BulletLst.end();

	for (; iter_Begin != iter_End; )
	{
		int iEvent = (*iter_Begin)->Update();

		if (DEAD_OBJ == iEvent)
		{
			SafeDelete(*iter_Begin);
			iter_Begin = m_BulletLst.erase(iter_Begin);
		}
		else
			++iter_Begin;
	}
}

void CMaingame::Render()
{
	Rectangle(m_hDC, 0, 0, WINCX, WINCY);
	Rectangle(m_hDC, 100, 100, WINCX - 100, WINCY - 100);

	m_pPlayer->Render(m_hDC);
	//m_pMonster->Render(m_hDC);

	for (auto& pBullet : m_BulletLst)
		pBullet->Render(m_hDC);

	for (auto& pMonster : m_MonsterLst)
		pMonster->Render(m_hDC);

	/*system("cls");
	cout << m_BulletLst.size() << endl;*/
	
	 //DC�� �ؽ�Ʈ ���
	 //TextOut�Լ�, DrawText�Լ�

	TCHAR szBuf[32] = L"";
	swprintf_s(szBuf, L"Bullet: %d", m_BulletLst.size());

	// TextOut(DC, �����ġ x, y, ����� ���ڿ�, ���ڿ� ����)
	//TextOut(m_hDC, 50, 50, szBuf, lstrlen(szBuf));

	RECT rc = { 50, 50, 150, 150 };

	// DrawText(DC, ����� ���ڿ�, ���ڿ� ����, RECT ������, �Ӽ�)
	// ����ڰ� ������ �簢�� ���� ���� �ؽ�Ʈ�� ����Ѵ�.
	DrawText(m_hDC, szBuf, lstrlen(szBuf), &rc, DT_NOCLIP);
}

void CMaingame::Release()
{
	// GetDC�Լ��� �Ҵ���� DC�� �Ʒ� �Լ��� �������־�� �Ѵ�.
	ReleaseDC(g_hWnd, m_hDC);

	SafeDelete(m_pPlayer);
	//SafeDelete(m_pMonster);

	for_each(m_BulletLst.begin(), m_BulletLst.end(), SafeDelete<CGameObject*>);
	m_BulletLst.clear();

	for_each(m_MonsterLst.begin(), m_MonsterLst.end(), SafeDelete<CGameObject*>);
	m_MonsterLst.clear();

}
