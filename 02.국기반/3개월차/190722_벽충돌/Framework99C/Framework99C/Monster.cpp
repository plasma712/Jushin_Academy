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
	- 두점을 주고 각을 찾기 -

 

	- arc 코사인 , 사인을 이용해서 찾는다.

	- 빗변 d , 밑변 x , 높이 y 기준 으로 아래와 같은 공식이 된다.

	- acos( x / d ) , asin( y / d ) , atan( y / x )

	- 예외 처리 -> y의 값에 따라 (+-) 각도가 바뀐다. - 아래 그림과 같은 상황이면 비교가 같아진다.

	- 무슨말이냐면 , 단순히 빗변 d , 밑변 x , 높이 y 기준으로만 판단 하기 때문에 , 180도 까지만 판단을 할수있다.

	- 즉 Y 축에 따른 예외 처리를 해주어서 360도에 대한 각을 구해준다.

	
	- 두점을 안다 -> 서로의 거리를 안다 . 목표지점에서 시작지점을 뺀다 ( End - Start = 두 점 사이의 거리 )

	- 위 공식으로 각 점(X,Y) 사이의 변이량을 구한다 (deltaX , deltaY) -*delta는 변이량을 의미

 

	- 대각선 (빗변)의 거리를 구한다

	- distance(빗변) = sqrt( deltaX * deltaX  + deltaY * deltaY );

 

	- 각을 구한다 ( 공식을 사용 )

	- float angle = acos( deltaX  /  distance );

 

	- 각도에 대한 변이량을 구한다

	- float deltaX = cos( Radians ) * distance(이동량);

	- float deltaY = -sin( Radians ) * distance(이동량);


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
