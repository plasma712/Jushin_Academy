#pragma once
#include "GameObject.h"
class cBossBullet :
	public CGameObject
{
public:
	cBossBullet();
	virtual ~cBossBullet();

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
	bool m_bDead;

	void vFirstPoint();

};

