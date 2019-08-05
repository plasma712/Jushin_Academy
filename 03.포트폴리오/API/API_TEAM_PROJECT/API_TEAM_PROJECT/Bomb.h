#pragma once
#include "GameObject.h"
class CBomb :
	public CGameObject
{
public:
	CBomb();
	~CBomb();

	// CGameObject을(를) 통해 상속됨
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;
};

