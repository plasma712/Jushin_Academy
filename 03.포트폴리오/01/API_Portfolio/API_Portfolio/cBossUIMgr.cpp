#include "stdafx.h"
#include "cBossUIMgr.h"
#include "ResourceManager.h"
#include "Scene.h"


cBossUIMgr::cBossUIMgr()
{
}


cBossUIMgr::~cBossUIMgr()
{
}

void cBossUIMgr::Initialize()
{
	m_pUIMgr_BossHpFrame = CMainGame::GetInstance()->GetResource()->Get(L"BossHpFrame");
	m_pUIMgr_BossCurrentHp = CMainGame::GetInstance()->GetResource()->Get(L"BossCurrentHp");
	//m_pUIMgr_BossHpDecrease = CMainGame::GetInstance()->GetResource()->Get(L"HPBar");
}

int cBossUIMgr::Update()
{
	return NO_EVENT;
}

void cBossUIMgr::Render(HDC hDC)
{
	TransparentBlt
	(
		hDC,
		700,	// Rectangle�� ���� Left��
		100,	// Rectangle�� ���� Bottom��
		80, // �ҷ����°�? �̶���ؾ��ϳ� ������ ũ�⿡ �ȸ����� �ðų� �پ����.
		199, // �ҷ����°�? �̶���ؾ��ϳ� ������ ũ�⿡ �ȸ����� �ðų� �پ����.
		m_pUIMgr_BossHpFrame, // �̹��� �ҷ�����
		0,  // m_iAniCount*m_AniData.iWarpWidth,
		0,
		80,	// ���������� X
		199,	// ���������� Y
		RGB(200, 0, 255) // �������̶� ���� �������. ����Ʈ������ ��
	);

	TransparentBlt
	(
		hDC,
		733,	// Rectangle�� ���� Left��
		108 + 0.216* (CMainGame::GetInstance()->GetScene()->GetOBJLST()[OBJECT_MONSTER].front()->m_iMaxHp - CMainGame::GetInstance()->GetScene()->GetOBJLST()[OBJECT_MONSTER].front()->m_iHP),
		14,
		127 - 0.216* (CMainGame::GetInstance()->GetScene()->GetOBJLST()[OBJECT_MONSTER].front()->m_iMaxHp - CMainGame::GetInstance()->GetScene()->GetOBJLST()[OBJECT_MONSTER].front()->m_iHP),
		m_pUIMgr_BossCurrentHp, // �̹��� �ҷ�����
		0,  // m_iAniCount*m_AniData.iWarpWidth,
		0,
		14,	// ���������� X
		133,	// ���������� Y
		RGB(200, 0, 255) // �������̶� ���� �������. ����Ʈ������ ��
	);

}

void cBossUIMgr::Release()
{
}
