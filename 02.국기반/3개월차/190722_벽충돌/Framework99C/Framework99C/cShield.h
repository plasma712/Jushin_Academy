#pragma once
#include "GameObject.h"
class cShield :
	public CGameObject
{
public:
	cShield();
	virtual ~cShield();

	// CGameObject을(를) 통해 상속됨
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;
};

