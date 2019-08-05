#pragma once
#include "GameObject.h"
class CMonster :
	public CGameObject
{
public:
	CMonster();
	virtual ~CMonster();

public:
	// CGameObject을(를) 통해 상속됨
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Render(HDC hDC) override;

private:
	virtual void Release() override;

private:
	void IsMoving();
	void IsOutRange();
	void IsAngleCheck();
	float m_fAngle = 0.f;
	float fPi = 3.14f;
public:
	//void SetAngle(float _m_fAngle);
	void SetPos(float _fx, float _fy);

	float Player_PosX=0;
	float Player_PosY=0;
	CGameObject* m_pPlayer;
	void SetPlayerInfo(CGameObject* _pPlayer);
};

