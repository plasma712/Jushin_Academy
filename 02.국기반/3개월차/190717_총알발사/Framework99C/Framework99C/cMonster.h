#pragma once
#include "GameObject.h"
class cMonster :
	public CGameObject
{
public:
	cMonster();
	virtual ~cMonster();

	// CGameObject을(를) 통해 상속됨
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;

	bool MonsterRightMove = true;
};

