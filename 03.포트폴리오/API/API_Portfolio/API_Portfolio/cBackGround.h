#pragma once
#include "cGameObject.h"
class cBackGround :
	public cGameObject
{
public:
	cBackGround();
	virtual ~cBackGround();

public:
	list<LINE*> m_LineList; // ���ο����͸� ���ؼ� ȣ��.

	// cGameObject��(��) ���� ��ӵ�
	virtual void Init() override;
	virtual int Update() override;
	virtual void Draw(HDC hdc) override;
	virtual void Release() override;

};

