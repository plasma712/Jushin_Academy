#pragma once
#include "cGameObject.h"
class cEnemy :
	public cGameObject
{
public:
	cEnemy();
	virtual ~cEnemy();

	// cGameObject��(��) ���� ��ӵ�
	virtual void Init() override;
	virtual int Update() override;
	virtual void Draw(HDC hdc) override;
	virtual void Release() override;
};

