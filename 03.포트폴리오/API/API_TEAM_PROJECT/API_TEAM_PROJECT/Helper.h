#pragma once
#include "GameObject.h"
class CHelper :
	public CGameObject
{
public:
	CHelper();
	virtual ~CHelper();

public:
	// CGameObject을(를) 통해 상속됨
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;

private:
	int m_iAttackDelay;
	float m_fDefualt;
	CGameObject*	m_pTarget;
};

/*
INFO

*/
