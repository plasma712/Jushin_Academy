#include "stdafx.h"
#include "BossMonster.h"
#include "Player.h"
#include "Scene.h"
#include "Bullet.h"
#include "EffectManager.h"
#include "SoundManager.h"
CBossMonster::CBossMonster()
{
}


CBossMonster::~CBossMonster()
{
}

void CBossMonster::Initialize()
{
	m_bDir = true;
	m_iCount = 0;
	m_Image = CMainGame::GetInstance()->GetResource()->Get(L"Boss");
	m_AniData = CMainGame::GetInstance()->GetResource()->GetAniData(L"Boss");

	m_tInfo.fCX = m_AniData.iWarpWidth * 2;
	m_tInfo.fCY = m_AniData.iHeight * 2;

	m_fSpeed = 10.f;
	m_iAniCount = 0;
	m_fDirection = 90;
	m_iHP = 1000;
}

int CBossMonster::Update()
{
	/*
	if (m_bIsDead)
		return DEAD_OBJ;
*/
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
			CEffectManager::CreateEffect(m_tInfo.fX + 100, m_tInfo.fY , L"Effect2");
			CEffectManager::CreateEffect(m_tInfo.fX + 100, m_tInfo.fY - 100, L"Effect2");

			CEffectManager::CreateEffect(m_tInfo.fX, m_tInfo.fY + 100, L"Effect2");
			CEffectManager::CreateEffect(m_tInfo.fX, m_tInfo.fY, L"Effect2");
			CEffectManager::CreateEffect(m_tInfo.fX, m_tInfo.fY - 100, L"Effect2");

			CEffectManager::CreateEffect(m_tInfo.fX - 100, m_tInfo.fY + 100, L"Effect2");
			CEffectManager::CreateEffect(m_tInfo.fX - 100, m_tInfo.fY, L"Effect2");
			CEffectManager::CreateEffect(m_tInfo.fX - 100, m_tInfo.fY - 100, L"Effect2");
			CSoundManager::PlayMonsterDeadSound();
		}
		else if (m_iCount == 160)
		{
			CMainGame::GetInstance()->SetSceneIndex(END_SCENE);
			return DEAD_OBJ;
		}
	}
	else
	{
		if (m_iCount< 40)
		{
			;
		}
		else
		{
			m_fSpeed = 5;
			if (m_bDir)
				m_fDirection += 3;
			else
				m_fDirection -= 3;

			if (m_fDirection == 360 || m_fDirection == 0)
			{
				m_bDir = !m_bDir;
			}
			CreateBullet();
		}
		IsMoving();
	}
	
	

	if (m_iAniCount >= m_AniData.iImageCount)
		m_iAniCount = 0;

	
	return 0;
}

void CBossMonster::Render(HDC hDC)
{
	if (m_bIsDead && m_iCount > 100)
		return;
	CGameObject::UpdateRect();
	//Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);

	TransparentBlt(hDC, m_tRect.left, m_tRect.top, m_tInfo.fCX, m_tInfo.fCY,
		m_Image, m_iAniCount*m_AniData.iWarpWidth, 0, m_AniData.iWarpWidth, m_AniData.iHeight,
		RGB(237, 28, 36));
}

void CBossMonster::SetDamaged()
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

void CBossMonster::CreateBullet()
{
	if (CMainGame::GetInstance()->GetScene()->GetOBJLST()[OBJECT_PLAYER].empty())
		return;

	CGameObject* bullet;
	float x, y, angle;
	if (m_iHP > 500)
	{
		
		if (m_iCount % 20==0)
		{
			//center
			bullet = CAbstractFactory<CBullet>::CreateObject(m_tInfo.fX, m_tInfo.fY + 136);

			x = CMainGame::GetInstance()->GetScene()->GetOBJLST()[OBJECT_PLAYER].front()->GetInfo().fX;
			y = CMainGame::GetInstance()->GetScene()->GetOBJLST()[OBJECT_PLAYER].front()->GetInfo().fY;
			angle = atan((y - GetInfo().fY + 136) / (x - GetInfo().fX)) * 180 / PI;

			if (x < GetInfo().fX)
				angle += 180;
			bullet->SetDirection(angle);
			bullet->SetSpeed(7);
			bullet->SetSprite(L"Bullet_Mob_A");
			bullet->SetRect();
			CMainGame::GetInstance()->GetScene()->GetOBJLST()[OBJECT_MONSTER_BULLET].push_back(bullet);
		}
		
		if ((m_iCount) % 50 == 0)
		{
			//right
			bullet = CAbstractFactory<CBullet>::CreateObject(m_tInfo.fX + 100, m_tInfo.fY + 100);

			bullet->SetDirection(90);
			bullet->SetSpeed(7);
			bullet->SetSprite(L"Bullet_Mob_A");
			bullet->SetRect();
			CMainGame::GetInstance()->GetScene()->GetOBJLST()[OBJECT_MONSTER_BULLET].push_back(bullet);

			//left
			bullet = CAbstractFactory<CBullet>::CreateObject(m_tInfo.fX - 100, m_tInfo.fY + 100);
			bullet->SetDirection(90);
			bullet->SetSpeed(7);
			bullet->SetSprite(L"Bullet_Mob_A");
			bullet->SetRect();
			CMainGame::GetInstance()->GetScene()->GetOBJLST()[OBJECT_MONSTER_BULLET].push_back(bullet);
		}
		if ((m_iCount) % 101 == 0)
		{
			//right
			bullet = CAbstractFactory<CBullet>::CreateObject(m_tInfo.fX + 100, m_tInfo.fY);

			bullet->SetDirection(30);
			bullet->SetSpeed(7);
			bullet->SetSprite(L"Bullet_Mob_C");
			bullet->SetRect();
			CMainGame::GetInstance()->GetScene()->GetOBJLST()[OBJECT_MONSTER_BULLET].push_back(bullet);

			bullet = CAbstractFactory<CBullet>::CreateObject(m_tInfo.fX + 100, m_tInfo.fY);

			bullet->SetDirection(45);
			bullet->SetSpeed(7);
			bullet->SetSprite(L"Bullet_Mob_C");
			bullet->SetRect();
			CMainGame::GetInstance()->GetScene()->GetOBJLST()[OBJECT_MONSTER_BULLET].push_back(bullet);

			bullet = CAbstractFactory<CBullet>::CreateObject(m_tInfo.fX + 100, m_tInfo.fY);

			bullet->SetDirection(60);
			bullet->SetSpeed(7);
			bullet->SetSprite(L"Bullet_Mob_C");
			bullet->SetRect();
			CMainGame::GetInstance()->GetScene()->GetOBJLST()[OBJECT_MONSTER_BULLET].push_back(bullet);

			bullet = CAbstractFactory<CBullet>::CreateObject(m_tInfo.fX + 100, m_tInfo.fY);

			bullet->SetDirection(75);
			bullet->SetSpeed(7);
			bullet->SetSprite(L"Bullet_Mob_C");
			bullet->SetRect();
			CMainGame::GetInstance()->GetScene()->GetOBJLST()[OBJECT_MONSTER_BULLET].push_back(bullet);

			bullet = CAbstractFactory<CBullet>::CreateObject(m_tInfo.fX + 100, m_tInfo.fY);

			bullet->SetDirection(90);
			bullet->SetSpeed(7);
			bullet->SetSprite(L"Bullet_Mob_C");
			bullet->SetRect();
			CMainGame::GetInstance()->GetScene()->GetOBJLST()[OBJECT_MONSTER_BULLET].push_back(bullet);

			bullet = CAbstractFactory<CBullet>::CreateObject(m_tInfo.fX + 100, m_tInfo.fY);
			bullet->SetDirection(105);
			bullet->SetSpeed(7);
			bullet->SetSprite(L"Bullet_Mob_C");
			bullet->SetRect();
			CMainGame::GetInstance()->GetScene()->GetOBJLST()[OBJECT_MONSTER_BULLET].push_back(bullet);

			bullet = CAbstractFactory<CBullet>::CreateObject(m_tInfo.fX + 100, m_tInfo.fY);
			bullet->SetDirection(120);
			bullet->SetSpeed(7);
			bullet->SetSprite(L"Bullet_Mob_C");
			bullet->SetRect();
			CMainGame::GetInstance()->GetScene()->GetOBJLST()[OBJECT_MONSTER_BULLET].push_back(bullet);

			bullet = CAbstractFactory<CBullet>::CreateObject(m_tInfo.fX + 100, m_tInfo.fY);
			bullet->SetDirection(135);
			bullet->SetSpeed(7);
			bullet->SetSprite(L"Bullet_Mob_C");
			bullet->SetRect();
			CMainGame::GetInstance()->GetScene()->GetOBJLST()[OBJECT_MONSTER_BULLET].push_back(bullet);

			bullet = CAbstractFactory<CBullet>::CreateObject(m_tInfo.fX + 100, m_tInfo.fY);
			bullet->SetDirection(150);
			bullet->SetSpeed(7);
			bullet->SetSprite(L"Bullet_Mob_C");
			bullet->SetRect();
			CMainGame::GetInstance()->GetScene()->GetOBJLST()[OBJECT_MONSTER_BULLET].push_back(bullet);

			//left
			bullet = CAbstractFactory<CBullet>::CreateObject(m_tInfo.fX - 100, m_tInfo.fY);

			bullet->SetDirection(30);
			bullet->SetSpeed(7);
			bullet->SetSprite(L"Bullet_Mob_C");
			bullet->SetRect();
			CMainGame::GetInstance()->GetScene()->GetOBJLST()[OBJECT_MONSTER_BULLET].push_back(bullet);

			bullet = CAbstractFactory<CBullet>::CreateObject(m_tInfo.fX - 100, m_tInfo.fY);

			bullet->SetDirection(45);
			bullet->SetSpeed(7);
			bullet->SetSprite(L"Bullet_Mob_C");
			bullet->SetRect();
			CMainGame::GetInstance()->GetScene()->GetOBJLST()[OBJECT_MONSTER_BULLET].push_back(bullet);

			bullet = CAbstractFactory<CBullet>::CreateObject(m_tInfo.fX - 100, m_tInfo.fY);

			bullet->SetDirection(60);
			bullet->SetSpeed(7);
			bullet->SetSprite(L"Bullet_Mob_C");
			bullet->SetRect();
			CMainGame::GetInstance()->GetScene()->GetOBJLST()[OBJECT_MONSTER_BULLET].push_back(bullet);

			bullet = CAbstractFactory<CBullet>::CreateObject(m_tInfo.fX - 100, m_tInfo.fY);

			bullet->SetDirection(75);
			bullet->SetSpeed(7);
			bullet->SetSprite(L"Bullet_Mob_C");
			bullet->SetRect();
			CMainGame::GetInstance()->GetScene()->GetOBJLST()[OBJECT_MONSTER_BULLET].push_back(bullet);

			bullet = CAbstractFactory<CBullet>::CreateObject(m_tInfo.fX - 100, m_tInfo.fY);

			bullet->SetDirection(90);
			bullet->SetSpeed(7);
			bullet->SetSprite(L"Bullet_Mob_C");
			bullet->SetRect();
			CMainGame::GetInstance()->GetScene()->GetOBJLST()[OBJECT_MONSTER_BULLET].push_back(bullet);

			bullet = CAbstractFactory<CBullet>::CreateObject(m_tInfo.fX - 100, m_tInfo.fY);
			bullet->SetDirection(105);
			bullet->SetSpeed(7);
			bullet->SetSprite(L"Bullet_Mob_C");
			bullet->SetRect();
			CMainGame::GetInstance()->GetScene()->GetOBJLST()[OBJECT_MONSTER_BULLET].push_back(bullet);

			bullet = CAbstractFactory<CBullet>::CreateObject(m_tInfo.fX - 100, m_tInfo.fY);
			bullet->SetDirection(120);
			bullet->SetSpeed(7);
			bullet->SetSprite(L"Bullet_Mob_C");
			bullet->SetRect();
			CMainGame::GetInstance()->GetScene()->GetOBJLST()[OBJECT_MONSTER_BULLET].push_back(bullet);

			bullet = CAbstractFactory<CBullet>::CreateObject(m_tInfo.fX - 100, m_tInfo.fY);
			bullet->SetDirection(135);
			bullet->SetSpeed(7);
			bullet->SetSprite(L"Bullet_Mob_C");
			bullet->SetRect();
			CMainGame::GetInstance()->GetScene()->GetOBJLST()[OBJECT_MONSTER_BULLET].push_back(bullet);

			bullet = CAbstractFactory<CBullet>::CreateObject(m_tInfo.fX - 100, m_tInfo.fY);
			bullet->SetDirection(150);
			bullet->SetSpeed(7);
			bullet->SetSprite(L"Bullet_Mob_C");
			bullet->SetRect();
			CMainGame::GetInstance()->GetScene()->GetOBJLST()[OBJECT_MONSTER_BULLET].push_back(bullet);
		}
	}
	else
	{
		if ((m_iCount) % 3 == 0)
		{
			//right
			bullet = CAbstractFactory<CBullet>::CreateObject(m_tInfo.fX + 100, m_tInfo.fY);

			bullet->SetDirection((m_iCount%60)*6);
			bullet->SetSpeed(10);
			bullet->SetSprite(L"Bullet_Mob_C");
			bullet->SetRect();
			CMainGame::GetInstance()->GetScene()->GetOBJLST()[OBJECT_MONSTER_BULLET].push_back(bullet);
			
			//right
			bullet = CAbstractFactory<CBullet>::CreateObject(m_tInfo.fX - 100, m_tInfo.fY);

			bullet->SetDirection(-(m_iCount % 60) * 6);
			bullet->SetSpeed(10);
			bullet->SetSprite(L"Bullet_Mob_C");
			bullet->SetRect();
			CMainGame::GetInstance()->GetScene()->GetOBJLST()[OBJECT_MONSTER_BULLET].push_back(bullet);
		}
		if ((m_iCount) % 70 == 0)
		{
			//right
			bullet = CAbstractFactory<CBullet>::CreateObject(m_tInfo.fX , m_tInfo.fY);

			bullet->SetDirection(30);
			bullet->SetSpeed(5);
			bullet->SetSprite(L"Bullet_Mob_B");
			bullet->SetRect();
			CMainGame::GetInstance()->GetScene()->GetOBJLST()[OBJECT_MONSTER_BULLET].push_back(bullet);

			bullet = CAbstractFactory<CBullet>::CreateObject(m_tInfo.fX , m_tInfo.fY);

			bullet->SetDirection(45);
			bullet->SetSpeed(5);
			bullet->SetSprite(L"Bullet_Mob_B");
			bullet->SetRect();
			CMainGame::GetInstance()->GetScene()->GetOBJLST()[OBJECT_MONSTER_BULLET].push_back(bullet);

			bullet = CAbstractFactory<CBullet>::CreateObject(m_tInfo.fX , m_tInfo.fY);

			bullet->SetDirection(60);
			bullet->SetSpeed(5);
			bullet->SetSprite(L"Bullet_Mob_B");
			bullet->SetRect();
			CMainGame::GetInstance()->GetScene()->GetOBJLST()[OBJECT_MONSTER_BULLET].push_back(bullet);

			bullet = CAbstractFactory<CBullet>::CreateObject(m_tInfo.fX , m_tInfo.fY);

			bullet->SetDirection(75);
			bullet->SetSpeed(5);
			bullet->SetSprite(L"Bullet_Mob_B");
			bullet->SetRect();
			CMainGame::GetInstance()->GetScene()->GetOBJLST()[OBJECT_MONSTER_BULLET].push_back(bullet);

			bullet = CAbstractFactory<CBullet>::CreateObject(m_tInfo.fX , m_tInfo.fY);

			bullet->SetDirection(90);
			bullet->SetSpeed(5);
			bullet->SetSprite(L"Bullet_Mob_B");
			bullet->SetRect();
			CMainGame::GetInstance()->GetScene()->GetOBJLST()[OBJECT_MONSTER_BULLET].push_back(bullet);

			bullet = CAbstractFactory<CBullet>::CreateObject(m_tInfo.fX , m_tInfo.fY);
			bullet->SetDirection(105);
			bullet->SetSpeed(5);
			bullet->SetSprite(L"Bullet_Mob_B");
			bullet->SetRect();
			CMainGame::GetInstance()->GetScene()->GetOBJLST()[OBJECT_MONSTER_BULLET].push_back(bullet);

			bullet = CAbstractFactory<CBullet>::CreateObject(m_tInfo.fX , m_tInfo.fY);
			bullet->SetDirection(120);
			bullet->SetSpeed(5);
			bullet->SetSprite(L"Bullet_Mob_B");
			bullet->SetRect();
			CMainGame::GetInstance()->GetScene()->GetOBJLST()[OBJECT_MONSTER_BULLET].push_back(bullet);

			bullet = CAbstractFactory<CBullet>::CreateObject(m_tInfo.fX , m_tInfo.fY);
			bullet->SetDirection(135);
			bullet->SetSpeed(5);
			bullet->SetSprite(L"Bullet_Mob_B");
			bullet->SetRect();
			CMainGame::GetInstance()->GetScene()->GetOBJLST()[OBJECT_MONSTER_BULLET].push_back(bullet);

			bullet = CAbstractFactory<CBullet>::CreateObject(m_tInfo.fX , m_tInfo.fY);
			bullet->SetDirection(150);
			bullet->SetSpeed(5);
			bullet->SetSprite(L"Bullet_Mob_B");
			bullet->SetRect();
			CMainGame::GetInstance()->GetScene()->GetOBJLST()[OBJECT_MONSTER_BULLET].push_back(bullet);
		}
	}
}
