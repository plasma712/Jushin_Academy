#pragma once
#include "GameObject.h"
class cShield :
	public CGameObject
{
public:
	cShield();
	virtual ~cShield();

	// CGameObject��(��) ���� ��ӵ�
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;
};

