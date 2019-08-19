#pragma once
#include "GameObject.h"
class CMonster :
	public CGameObject
{
public:
	CMonster();
	virtual ~CMonster();

public:
	// CGameObject을(를) 통해 상속됨
	virtual void	Initialize() override;
	virtual int		Update() override;
	virtual void	Render(HDC hDC) override;

private:
	virtual void	Release() override;

public:
	void			SetProgress(int prog);
	const int		GetProgress();
	virtual void	SetDamaged();

protected:
	virtual void	IsMoving();
	void			IsOutRange();
	virtual void	CreateBullet();
	void			CreateItem();
private:
	int				m_iProgress;

};

