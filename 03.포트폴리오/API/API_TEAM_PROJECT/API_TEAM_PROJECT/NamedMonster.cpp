#include "stdafx.h"
#include "NamedMonster.h"
#include "Player.h"
#include "Scene.h"
#include "Bullet.h"
#include "EffectManager.h"
#include "SoundManager.h"

CNamedMonster::CNamedMonster()
{
}


CNamedMonster::~CNamedMonster()
{
}

void CNamedMonster::Initialize()
{
	m_iCount = 0;
	m_Image = CMainGame::GetInstance()->GetResource()->Get(L"NamedMonster");
	m_AniData = CMainGame::GetInstance()->GetResource()->GetAniData(L"NamedMonster");

	m_tInfo.fCX = m_AniData.iWarpWidth;
	m_tInfo.fCY = m_AniData.iHeight;

	m_fSpeed = 10.f;
	m_iAniCount = 0;

	m_iHP = 400;
}

int CNamedMonster::Update()
{
	/*if (m_bIsDead)
		return DEAD_OBJ;*/

	++m_iCount;
	++m_iAniCount;

	if (m_bIsDead)
	{
		if (m_iCount == 1)
		{
			CEffectManager::CreateEffect(m_tInfo.fX, m_tInfo.fY, L"Effect2");
			CSoundManager::PlayMonsterDeadSound();
		}
		else if (m_iCount == 20)
		{
			CEffectManager::CreateEffect(m_tInfo.fX - 100, m_tInfo.fY - 100, L"Effect2");
			CSoundManager::PlayMonsterDeadSound();
		}
		else if (m_iCount == 30)
		{
			CEffectManager::CreateEffect(m_tInfo.fX + 100, m_tInfo.fY + 100, L"Effect2");
			CSoundManager::PlayMonsterDeadSound();
		}
		else if (m_iCount == 40)
		{
			CEffectManager::CreateEffect(m_tInfo.fX - 100, m_tInfo.fY + 100, L"Effect2");
			CSoundManager::PlayMonsterDeadSound();
		}
		else if (m_iCount == 50)
		{
			CEffectManager::CreateEffect(m_tInfo.fX + 100, m_tInfo.fY - 100, L"Effect2");
			CSoundManager::PlayMonsterDeadSound();
		}
		else if (m_iCount == 60)
		{
			CEffectManager::CreateEffect(m_tInfo.fX - 50, m_tInfo.fY - 50, L"Effect2");
			CSoundManager::PlayMonsterDeadSound();
		}
		else if (m_iCount == 70)
		{
			CEffectManager::CreateEffect(m_tInfo.fX + 50, m_tInfo.fY + 50, L"Effect2");
			CSoundManager::PlayMonsterDeadSound();
		}
		else if (m_iCount == 80)
		{
			CEffectManager::CreateEffect(m_tInfo.fX - 50, m_tInfo.fY + 50, L"Effect2");
			CSoundManager::PlayMonsterDeadSound();
		}
		else if (m_iCount == 90)
		{
			CEffectManager::CreateEffect(m_tInfo.fX + 50, m_tInfo.fY - 50, L"Effect2");
			CSoundManager::PlayMonsterDeadSound();
		}
		else if (m_iCount == 100)
		{
			CEffectManager::CreateEffect(m_tInfo.fX + 100, m_tInfo.fY + 100, L"Effect2");
			CEffectManager::CreateEffect(m_tInfo.fX + 100, m_tInfo.fY, L"Effect2");
			CEffectManager::CreateEffect(m_tInfo.fX + 100, m_tInfo.fY - 100, L"Effect2");

			CEffectManager::CreateEffect(m_tInfo.fX, m_tInfo.fY + 100, L"Effect2");
			CEffectManager::CreateEffect(m_tInfo.fX, m_tInfo.fY, L"Effect2");
			CEffectManager::CreateEffect(m_tInfo.fX, m_tInfo.fY - 100, L"Effect2");

			CEffectManager::CreateEffect(m_tInfo.fX - 100, m_tInfo.fY + 100, L"Effect2");
			CEffectManager::CreateEffect(m_tInfo.fX - 100, m_tInfo.fY, L"Effect2");
			CEffectManager::CreateEffect(m_tInfo.fX - 100, m_tInfo.fY - 100, L"Effect2");
			CSoundManager::PlayMonsterDeadSound();
			return DEAD_OBJ;
		}
	}
	else
	{
		if (m_iCount< 20)
		{
			;
		}
		else
		{
			m_fSpeed = 0.f;
			CreateBullet();
		}
	}
	


	if (m_iAniCount >= m_AniData.iImageCount)
		m_iAniCount = 0;

	IsMoving();

	return NO_EVENT;
}

void CNamedMonster::Render(HDC hDC)
{
	CGameObject::UpdateRect();
	//Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);

	TransparentBlt(hDC, m_tRect.left, m_tRect.top, m_tInfo.fCX, m_tInfo.fCY,
		m_Image, m_iAniCount*m_AniData.iWarpWidth, 0, m_AniData.iWarpWidth, m_AniData.iHeight,
		RGB(0, 128, 128));

}

void CNamedMonster::SetDamaged()
{
	if (m_bIsDead)
		return;

	m_iHP -= 5;
	if (m_iHP <= 0)
	{
		SetDead(true);
		m_iCount = 0;
	}
}

void CNamedMonster::CreateBullet()
{
	if (CMainGame::GetInstance()->GetScene()->GetOBJLST()[OBJECT_PLAYER].empty())
		return;

	CGameObject* bullet;
	float x, y, angle;
	if (m_iHP > 0)
	{

		if (m_iCount % 40 == 0)
		{
			//center 플레이어쪽으로 발사
			bullet = CAbstractFactory<CBullet>::CreateObject(m_tInfo.fX, m_tInfo.fY + 100);

			x = CMainGame::GetInstance()->GetScene()->GetOBJLST()[OBJECT_PLAYER].front()->GetInfo().fX;
			y = CMainGame::GetInstance()->GetScene()->GetOBJLST()[OBJECT_PLAYER].front()->GetInfo().fY;
			angle = atan((y - GetInfo().fY + 136) / (x - GetInfo().fX)) * 180 / PI;

			if (x < GetInfo().fX)
				angle += 180;
			bullet->SetDirection(angle);
			bullet->SetSpeed(7.f);
			bullet->SetSprite(L"Bullet_Mob_A");
			bullet->SetRect();
			CMainGame::GetInstance()->GetScene()->GetOBJLST()[OBJECT_MONSTER_BULLET].push_back(bullet);

			bullet = CAbstractFactory<CBullet>::CreateObject(m_tInfo.fX + 25, m_tInfo.fY + 100);
			bullet->SetDirection(angle);
			bullet->SetSpeed(6.5f);
			bullet->SetSprite(L"Bullet_Mob_A");
			bullet->SetRect();
			CMainGame::GetInstance()->GetScene()->GetOBJLST()[OBJECT_MONSTER_BULLET].push_back(bullet);

			bullet = CAbstractFactory<CBullet>::CreateObject(m_tInfo.fX - 25, m_tInfo.fY + 100);
			bullet->SetDirection(angle);
			bullet->SetSpeed(6.5f);
			bullet->SetSprite(L"Bullet_Mob_A");
			bullet->SetRect();
			CMainGame::GetInstance()->GetScene()->GetOBJLST()[OBJECT_MONSTER_BULLET].push_back(bullet);

			//left
			bullet = CAbstractFactory<CBullet>::CreateObject(m_tInfo.fX + 50, m_tInfo.fY + 100);
			bullet->SetDirection(angle);
			bullet->SetSpeed(6.f);
			bullet->SetSprite(L"Bullet_Mob_A");
			bullet->SetRect();
			CMainGame::GetInstance()->GetScene()->GetOBJLST()[OBJECT_MONSTER_BULLET].push_back(bullet);

			bullet = CAbstractFactory<CBullet>::CreateObject(m_tInfo.fX - 50, m_tInfo.fY + 100);
			bullet->SetDirection(angle);
			bullet->SetSpeed(6.f);
			bullet->SetSprite(L"Bullet_Mob_A");
			bullet->SetRect();
			CMainGame::GetInstance()->GetScene()->GetOBJLST()[OBJECT_MONSTER_BULLET].push_back(bullet);

			bullet = CAbstractFactory<CBullet>::CreateObject(m_tInfo.fX - 75, m_tInfo.fY + 100);
			bullet->SetDirection(angle);
			bullet->SetSpeed(5.5f);
			bullet->SetSprite(L"Bullet_Mob_A");
			bullet->SetRect();
			CMainGame::GetInstance()->GetScene()->GetOBJLST()[OBJECT_MONSTER_BULLET].push_back(bullet);

			bullet = CAbstractFactory<CBullet>::CreateObject(m_tInfo.fX + 75, m_tInfo.fY + 100);
			bullet->SetDirection(angle);
			bullet->SetSpeed(5.5f);
			bullet->SetSprite(L"Bullet_Mob_A");
			bullet->SetRect();
			CMainGame::GetInstance()->GetScene()->GetOBJLST()[OBJECT_MONSTER_BULLET].push_back(bullet);
		}
	}
}