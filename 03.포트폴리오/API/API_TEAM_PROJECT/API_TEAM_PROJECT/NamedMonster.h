#pragma once
#include "Monster.h"
class CNamedMonster :
	public CMonster
{
public:
	CNamedMonster();
	virtual ~CNamedMonster();

public:
	// CGameObject을(를) 통해 상속됨
	virtual void	Initialize() override;
	virtual int		Update() override;
	virtual void	Render(HDC hDC) override;

	virtual	void SetDamaged();
	virtual void CreateBullet();


};

