#pragma once
#include "GameObject.h"
//class CBullet;

class CPlayer :
	public CGameObject
{
public:
	CPlayer();
	virtual ~CPlayer();

public:
	void SetBulletLst(BULLET_LST* pBulletLst);
	int Number = 1;
public:
	// CGameObject을(를) 통해 상속됨
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Render(HDC hDC) override;
	void DestoryBullet(CGameObject * pBullet);

private:
	virtual void Release() override;

private:
	CGameObject* CreateBullet(int Number);

private:	
	BULLET_LST*	m_pBulletLst;
};

