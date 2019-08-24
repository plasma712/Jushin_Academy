#pragma once
#include "GameObject.h"
class cGunManBullet :
	public CGameObject
{
public:
	cGunManBullet();
	virtual ~cGunManBullet();

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

public:
	void vBulletImage();


	bool m_bDead;

};

