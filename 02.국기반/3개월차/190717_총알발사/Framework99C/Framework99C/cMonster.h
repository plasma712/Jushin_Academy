#pragma once
#include "GameObject.h"
class cMonster :
	public CGameObject
{
public:
	cMonster();
	virtual ~cMonster();

	// CGameObject��(��) ���� ��ӵ�
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;

	bool MonsterRightMove = true;
};

