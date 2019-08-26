#pragma once
#include "GameObject.h"
class cBossBullet :
	public CGameObject
{
public:
	cBossBullet();
	virtual ~cBossBullet();

	// CGameObject을(를) 통해 상속됨
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;

private:
	void IsMoving();
	void IsOutRange();

private:
	int m_iFrame;
	bool FirstPoint;
	bool m_bDead;

	void vFirstPoint();

};

