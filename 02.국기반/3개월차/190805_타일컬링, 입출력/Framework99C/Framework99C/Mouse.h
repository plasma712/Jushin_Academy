#pragma once
#include "GameObject.h"
class CMouse :
	public CGameObject
{
public:
	CMouse();
	virtual ~CMouse();

public:
	// CGameObject��(��) ���� ��ӵ�
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Render(HDC hDC) override;

private:
	virtual void Release() override;
};

