#pragma once
#include "cScene.h"
class cStage01 :
	public cScene
{
public:
	cStage01();
	virtual ~cStage01();

	// cScene��(��) ���� ��ӵ�
	virtual void Init() override;
	virtual int Update() override;
	virtual void Draw(HDC hdc) override;
	virtual void Release() override;
	/////////

};

