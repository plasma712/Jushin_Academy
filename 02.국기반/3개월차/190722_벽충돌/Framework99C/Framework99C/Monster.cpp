#include "stdafx.h"
#include "Monster.h"


CMonster::CMonster()
{
}


CMonster::~CMonster()
{
	Release();
}

void CMonster::Initialize()
{
	/*m_tInfo.fX = 400.f;
	m_tInfo.fY = 200.f;*/
	m_tInfo.fCX = 100.f;
	m_tInfo.fCY = 100.f;

	m_fSpeed = 1.f;
}

int CMonster::Update()
{
	if (m_bIsDead)
		return DEAD_OBJ;

	IsMoving();
	IsOutRange();

	return NO_EVENT;
}

void CMonster::Render(HDC hDC)
{
	CGameObject::UpdateRect();
	Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void CMonster::Release()
{
}

void CMonster::IsMoving()
{
	////m_tInfo.fX += m_fSpeed;
	/*
	- ������ �ְ� ���� ã�� -

 

	- arc �ڻ��� , ������ �̿��ؼ� ã�´�.

	- ���� d , �غ� x , ���� y ���� ���� �Ʒ��� ���� ������ �ȴ�.

	- acos( x / d ) , asin( y / d ) , atan( y / x )

	- ���� ó�� -> y�� ���� ���� (+-) ������ �ٲ��. - �Ʒ� �׸��� ���� ��Ȳ�̸� �񱳰� ��������.

	- �������̳ĸ� , �ܼ��� ���� d , �غ� x , ���� y �������θ� �Ǵ� �ϱ� ������ , 180�� ������ �Ǵ��� �Ҽ��ִ�.

	- �� Y �࿡ ���� ���� ó���� ���־ 360���� ���� ���� �����ش�.

	
	- ������ �ȴ� -> ������ �Ÿ��� �ȴ� . ��ǥ�������� ���������� ���� ( End - Start = �� �� ������ �Ÿ� )

	- �� �������� �� ��(X,Y) ������ ���̷��� ���Ѵ� (deltaX , deltaY) -*delta�� ���̷��� �ǹ�

 

	- �밢�� (����)�� �Ÿ��� ���Ѵ�

	- distance(����) = sqrt( deltaX * deltaX  + deltaY * deltaY );

 

	- ���� ���Ѵ� ( ������ ��� )

	- float angle = acos( deltaX  /  distance );

 

	- ������ ���� ���̷��� ���Ѵ�

	- float deltaX = cos( Radians ) * distance(�̵���);

	- float deltaY = -sin( Radians ) * distance(�̵���);


	*/
	float fWidth = m_pPlayer->GetInfo().fX - m_tInfo.fX;
	float fHeight = m_pPlayer->GetInfo().fY - m_tInfo.fY;
	float fDistance = sqrtf(fWidth*fWidth + fHeight * fHeight);

	m_fAngle = acosf(fWidth / fDistance) * 180 / fPi;

	if (m_pPlayer->GetInfo().fY > m_tInfo.fY)
		m_fAngle = 360 - m_fAngle;

	m_tInfo.fX += cosf(m_fAngle * fPi / 180) * m_fSpeed;
	m_tInfo.fY -= sinf(m_fAngle * fPi / 180) * m_fSpeed;


}

void CMonster::IsOutRange()
{
	CGameObject::UpdateRect();

	if (0 >= m_tRect.left || WINCX <= m_tRect.right)
		m_fSpeed *= -1.f;
}

void CMonster::IsAngleCheck()
{
	//Player
}

//void CMonster::SetAngle(float _m_fAngle)
//{
//	m_fAngle = _m_fAngle;
//}

void CMonster::SetPos(float _fx, float _fy)
{
	Player_PosX = _fx;
	Player_PosY = _fy;
}

void CMonster::SetPlayerInfo(CGameObject * _pPlayer)
{
	m_pPlayer = _pPlayer;
}
