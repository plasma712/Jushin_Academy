#pragma once
#include "cScene.h"
class cTitle :
	public cScene
{
public:
	cTitle();
	virtual ~cTitle();

	// cScene��(��) ���� ��ӵ�
	virtual void Init() override;
	virtual int Update() override;
	virtual void Draw(HDC hdc) override;
	virtual void Release() override;
};

