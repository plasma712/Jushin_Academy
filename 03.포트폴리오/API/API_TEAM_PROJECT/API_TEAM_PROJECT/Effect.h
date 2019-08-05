#pragma once
#include "GameObject.h"
class CEffect :
	public CGameObject
{
public:
	CEffect();
	virtual ~CEffect();

public:
	// CGameObject을(를) 통해 상속됨
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Render(HDC hDC) override;

private:
	virtual void Release() override;

	/*
	INFO
	ANIDATA
	IMAGE
	iAniCount
	*/
};

