#include "stdafx.h"
#include "RotateMonster.h"


CRotateMonster::CRotateMonster()
	:m_bDir(true)
{
}


CRotateMonster::~CRotateMonster()
{
}

void CRotateMonster::Initialize()
{
	m_iCount = 0;
	m_Image = CMainGame::GetInstance()->GetResource()->Get(L"RotateMonster");
	m_AniData = CMainGame::GetInstance()->GetResource()->GetAniData(L"RotateMonster");

	m_tInfo.fCX = m_AniData.iWarpWidth * 2;
	m_tInfo.fCY = m_AniData.iHeight * 2;

	m_fSpeed = 10.f;



	// true : Left false : Right

}

int CRotateMonster::Update()
{
	if (m_bIsDead)
		return DEAD_OBJ;

	++m_iCount;

	if (m_iCount == 30)
	{
		CreateBullet();
	}

	if (m_iCount % 3 == 0)
	{
		if (m_bDir)
		{
			m_fDirection += 5.f;
		}
		else
		{
			m_fDirection -= 5.f;
		}

		m_iAniCount = CheckAniCount(static_cast<int>(m_fDirection));
	}

	IsMoving();
	IsOutRange();

	return NO_EVENT;
}

void CRotateMonster::Render(HDC hDC)
{
	CGameObject::UpdateRect();
	//Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);

	TransparentBlt(hDC, m_tRect.left, m_tRect.top, m_tInfo.fCX, m_tInfo.fCY,
		m_Image, m_iAniCount*m_AniData.iWarpWidth, 0, m_AniData.iWarpWidth, m_AniData.iHeight,
		RGB(57, 24, 8));
}

void CRotateMonster::SetDir(int _dir)
{
	if (_dir == 45)
	{
		m_bDir = true;
		m_iAniCount = 7;
	}

	else
	{
		m_bDir = false;
		m_iAniCount = 9;
	}
}

int CRotateMonster::CheckAniCount(int _dir)
{
	int iCount = -1;

	if (!m_bDir)
	{
		/*	if (135 >= _dir)
		iCount = 9;

		else if (180 <= _dir)
		iCount = 8;

		else if (90 <= _dir)
		iCount = 12;

		else if (225 <= _dir)
		iCount = 3;*/

		if (180 <= _dir)
			iCount = 12;

		else if (157 <= _dir)
			iCount = 11;

		else if (135 <= _dir)
			iCount = 10;

		else if (110 <= _dir)
			iCount = 9;

		else if (90 <= _dir)
			iCount = 8;

		else if (45 <= _dir)
			iCount = 7;

		else if (35 <= _dir)
			iCount = 6;

		else if (25 <= _dir)
			iCount = 5;

		else if (15 <= _dir)
			iCount = 4;
	}

	else 
	{
		if (180 <= _dir)
			iCount = 13;

		else if (180 <= _dir)
			iCount = 12;

		else if (157 <= _dir)
			iCount = 11;

		else if (135 <= _dir)
			iCount = 10;

		else if (110 <= _dir)
			iCount = 9;

		else if (90 <= _dir)
			iCount = 8;

		else if (45 <= _dir)
			iCount = 7;
	}
	return iCount;
}


