#pragma once
#include "GameObject.h"
class cStage01Object :
	public CGameObject
{
public:
	cStage01Object();
	virtual ~cStage01Object();

	// CGameObject��(��) ���� ��ӵ�
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;
public:

	void vRect();
};

