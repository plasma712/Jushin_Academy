#pragma once
#include "Scene.h"
class CMyMenu :
	public CScene
{
public:
	CMyMenu();
	virtual ~CMyMenu();

public:
	// CScene��(��) ���� ��ӵ�
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Render(HDC hDC) override;

private:
	virtual void Release() override;
};

