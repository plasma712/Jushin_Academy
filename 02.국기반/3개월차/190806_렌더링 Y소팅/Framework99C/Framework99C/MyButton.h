#pragma once
#include "GameObject.h"
class CMyButton :
	public CGameObject
{
public:
	CMyButton();
	virtual ~CMyButton();

public:
	// CGameObject��(��) ���� ��ӵ�
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Render(HDC hDC) override;

private:
	virtual void Release() override;

private:
	int m_iDrawID;
};

