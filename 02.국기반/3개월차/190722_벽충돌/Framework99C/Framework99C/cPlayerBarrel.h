#pragma once
#include "Player.h"
class cPlayerBarrel :
	public CPlayer
{
public:
	cPlayerBarrel();
	virtual ~cPlayerBarrel();

	// CGameObject��(��) ���� ��ӵ�
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;

	void KeyInput();
};

