#pragma once
#include "GameObject.h"
class cMiddleChargeBullet :
	public CGameObject
{
public:
	cMiddleChargeBullet();
	virtual ~cMiddleChargeBullet();

	// CGameObject��(��) ���� ��ӵ�
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

	void vFirstPoint();

	bool m_bDead;

};

