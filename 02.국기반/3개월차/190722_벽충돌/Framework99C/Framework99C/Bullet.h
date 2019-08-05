#pragma once
#include "GameObject.h"
class CBullet :
	public CGameObject
{
public:
	CBullet();
	virtual ~CBullet();

public:
	void SetDirection(BULLET_DIRECTION eDir);

public:
	// CGameObject��(��) ���� ��ӵ�
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Render(HDC hDC) override;

private:
	virtual void Release() override;

private:
	void IsMoving();
	void IsOutRange();

private:
	BULLET_DIRECTION	m_eDirection;
	float m_fAngle = 0.f;
	float fPi = 3.14f;
public:
	void SetAngle(float _m_fAngle);
	void SetPos(float _fx, float _fy);
};

