#pragma once
#include "GameObject.h"
class CBullet :
	public CGameObject
{
public:
	CBullet();
	virtual ~CBullet();

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

private:
	int m_iFrame;
};

