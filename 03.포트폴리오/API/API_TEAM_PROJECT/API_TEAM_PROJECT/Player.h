#pragma once
#include "GameObject.h"
class CBullet;
class CPlayer :
	public CGameObject
{
public:
	CPlayer();
	virtual			~CPlayer();

public:
	void			SetBulletLst(OBJLIST* pBulletLst);

public:
	// CGameObject을(를) 통해 상속됨
	virtual void	Initialize() override;
	virtual int		Update() override;
	virtual void	Render(HDC hDC) override;

private:
	virtual void	Release() override;

private:
	CGameObject*	CreateBullet();
	void			CreateBomb();
	void			KeyInput();
	void			CreateHelper();
	void			IsOutRange();

private:
	int				m_bulletCount;
	OBJLIST*		m_pBulletLst;
	CKeyManager*	m_pKeyMgr;
	bool			bInputable;
	HDC				m_AppearPlayerImage;
	AniData			m_AppearPlayerData;

	float			m_ApperSpeed;

	float			m_HelperPos[4];
	int				m_iHelperCount;

	int            GetEnergy();
};