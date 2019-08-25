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
		700,	// Rectangle로 보면 Left값
		100,	// Rectangle로 보면 Bottom값
		80, // 불러오는값? 이라고해야하나 사이즈 크기에 안맞으면 늘거나 줄어들음.
		199, // 불러오는값? 이라고해야하나 사이즈 크기에 안맞으면 늘거나 줄어들음.
		m_pUIMgr_BossHpFrame, // 이미지 불러오기
		0,  // m_iAniCount*m_AniData.iWarpWidth,
		0,
		80,	// 사진사이즈 X
		199,	// 사진사이즈 Y
		RGB(200, 0, 255) // 투명배경이라서 딱히 상관없음. 디폴트값으로 둠
	);

	TransparentBlt
	(
		hDC,
		733,	// Rectangle로 보면 Left값
		108 + 0.216* (CMainGame::GetInstance()->GetScene()->GetOBJLST()[OBJECT_MONSTER].front()->m_iMaxHp - CMainGame::GetInstance()->GetScene()->GetOBJLST()[OBJECT_MONSTER].front()->m_iHP),
		14,
		127 - 0.216* (CMainGame::GetInstance()->GetScene()->GetOBJLST()[OBJECT_MONSTER].front()->m_iMaxHp - CMainGame::GetInstance()->GetScene()->GetOBJLST()[OBJECT_MONSTER].front()->m_iHP),
		m_pUIMgr_BossCurrentHp, // 이미지 불러오기
		0,  // m_iAniCount*m_AniData.iWarpWidth,
		0,
		14,	// 사진사이즈 X
		133,	// 사진사이즈 Y
		RGB(200, 0, 255) // 투명배경이라서 딱히 상관없음. 디폴트값으로 둠
	);

}

void cBossUIMgr::Release()
{
}
