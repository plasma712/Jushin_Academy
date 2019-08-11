#pragma once
#include "cScene.h"
class cTitle :
	public cScene
{
public:
	cTitle();
	virtual ~cTitle();

	// cScene을(를) 통해 상속됨
	virtual void Init() override;
	virtual int Update() override;
	virtual void Draw(HDC hdc) override;
	virtual void Release() override;
};

