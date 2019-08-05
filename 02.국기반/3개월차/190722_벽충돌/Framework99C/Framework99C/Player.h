#pragma once
#include "GameObject.h"
class CPlayer :
	public CGameObject
{
public:
	CPlayer();
	virtual ~CPlayer();

public:
	void SetBulletLst(OBJLIST* pBulletLst);

public:
	// CGameObject을(를) 통해 상속됨
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Render(HDC hDC) override;

private:
	virtual void Release() override;

private:
	CGameObject* CreateBullet();
	CGameObject* CreateBullet(BULLET_DIRECTION eDir,INFO m_tInfo, float _fAngle);
	void KeyInput();

private:	
	OBJLIST*	m_pBulletLst;
public:
	float m_fAngle = 0.f;
	float fPi = 3.14f;
	void PlayerBarrelDraw(HDC hdc);
	void PlayerShield(HDC hdc);
	//CGameObject* PlayerBarrelPos;
	float ShieldAngle = 0.f;
public:
	CGameObject* PlayerShieldCreate(INFO m_tInfo, float _fAngle);
};

