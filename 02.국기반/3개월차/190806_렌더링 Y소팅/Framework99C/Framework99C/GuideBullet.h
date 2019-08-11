#pragma once
#include "GameObject.h"
class CGuideBullet :
	public CGameObject
{
public:
	CGuideBullet();
	virtual ~CGuideBullet();

public:
	// CGameObject��(��) ���� ��ӵ�
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Render(HDC hDC) override;

private:
	virtual void Release() override;

private:
	void IsMoving();

private:
	CGameObject*	m_pTarget;
};

