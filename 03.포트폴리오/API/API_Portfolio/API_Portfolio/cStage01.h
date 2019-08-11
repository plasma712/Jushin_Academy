#pragma once
#include "cScene.h"
class cStage01 :
	public cScene
{
public:
	cStage01();
	virtual ~cStage01();

	// cScene을(를) 통해 상속됨
	virtual void Init() override;
	virtual int Update() override;
	virtual void Draw(HDC hdc) override;
	virtual void Release() override;
	/////////

};

