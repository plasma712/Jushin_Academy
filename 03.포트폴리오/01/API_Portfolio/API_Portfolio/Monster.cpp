#include "stdafx.h"
#include "Monster.h"
#include "ResourceManager.h"
#include "Scene.h"
#include "Bullet.h"
#include "EffectManager.h"
#include "SoundManager.h"
#include "UIMgr.h"
#include "Item.h"
CMonster::CMonster()
{
}


CMonster::~CMonster()
{
	Release();
}

void CMonster::Initialize()
{
	m_iCount = 0;
	m_Image = CMainGame::GetInstance()->GetResource()->Get(L"Monster");
	m_AniData = CMainGame::GetInstance()->GetResource()->GetAniData(L"Monster");

	m_tInfo.fCX = m_AniData.iWarpWidth*2;
	m_tInfo.fCY = m_AniData.iHeight*2;
	
	m_fSpeed = 10.f;
	m_iAniCount = m_AniData.iImageCount * 0.5;
}

int CMonster::Update()
{
	if (m_bIsDead)
		return DEAD_OBJ;
	
	++m_iCount;
	if (m_iCount % 30 == 0)
	{
		CGameObject* bullet = CAbstractFactory<CBullet>::CreateObject(m_tInfo.fX, m_tInfo.fY);
		bullet->SetDirection(270);
		bullet->SetSpeed(15);
		bullet->SetSprite(L"Bullet_Mob_A");
		bullet->SetRect();
		CMainGame::GetInstance()->GetScene()->GetOBJLST()[OBJECT_MONSTER_BULLET].push_back(bullet);
	}

	if (m_iCount % 2 == 0)
	{
		++m_iAniCount;
		m_iAniCount %= m_AniData.iImageCount;
	}
	IsMoving();
	IsOutRange();

	return NO_EVENT;
}

void CMonster::Render(HDC hDC)
{
	CGameObject::UpdateRect();
	//Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
	
	TransparentBlt(hDC, m_tRect.left, m_tRect.top, m_tInfo.fCX, m_tInfo.fCY,
		m_Image, m_iAniCount*m_AniData.iWarpWidth, 0, m_AniData.iWarpWidth, m_AniData.iHeight,
		RGB(0, 128, 128));
}

void CMonster::Release()
{
	

}

void CMonster::SetProgress(int prog)
{
	m_iProgress = prog;
}

const int CMonster::GetProgress()
{
	return m_iProgress;
}

void CMonster::SetDamaged()
{
	//CSoundManager::PlayMonsterDeadSound();

	//CGameObject* pUIMgr = CMainGame::GetInstance()->GetScene()->GetOBJLST()[OBJECT_UI].front();
	//dynamic_cast<CUIMgr*>(pUIMgr)->SetScroe(100);

	//CEffectManager::CreateEffect(this->GetInfo());

	//CreateItem();
	SetDead(true);
}

void CMonster::IsMoving()
{
	m_tInfo.fX += cosf(m_fDirection*PI / 180)*m_fSpeed;
	m_tInfo.fY += sinf(m_fDirection*PI / 180)*m_fSpeed;
}

void CMonster::IsOutRange()
{
	//if (m_tInfo.fX > 1100 || m_tInfo.fX < -100 || m_tInfo.fY > 900 || m_tInfo.fX < -100)
	//	SetDead(true);

}

void CMonster::CreateBullet()
{
	
	if (CMainGame::GetInstance()->GetScene()->GetOBJLST()[OBJECT_PLAYER].empty())
		return;
	CGameObject* bullet = CAbstractFactory<CBullet>::CreateObject(m_tInfo.fX, m_tInfo.fY);
	float x = CMainGame::GetInstance()->GetScene()->GetOBJLST()[OBJECT_PLAYER].front()->GetInfo().fX;
	float y = CMainGame::GetInstance()->GetScene()->GetOBJLST()[OBJECT_PLAYER].front()->GetInfo().fY;
	float angle = atan((y - GetInfo().fY) / (x - GetInfo().fX)) * 180 / PI;

	//		270
	//180	 .	0(360)
	//		90

	if (x < GetInfo().fX)
		angle += 180;
	bullet->SetDirection(angle);
	bullet->SetSpeed(11);
	bullet->SetSprite(L"Bullet_Mob_A");
	bullet->SetRect();
	CMainGame::GetInstance()->GetScene()->GetOBJLST()[OBJECT_MONSTER_BULLET].push_back(bullet);
}

void CMonster::CreateItem()
{
	CGameObject* pItem = CAbstractFactory<CItem>::CreateObject(m_tInfo.fX, m_tInfo.fY);
	CMainGame::GetInstance()->GetScene()->GetOBJLST()[OBJECT_ITEM].push_back(pItem);
}
