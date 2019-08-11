#pragma once
#include "cGameObject.h"
class cBackGround :
	public cGameObject
{
public:
	cBackGround();
	virtual ~cBackGround();

public:
	list<LINE*> m_LineList; // 라인에디터를 통해서 호출.

	// cGameObject을(를) 통해 상속됨
	virtual void Init() override;
	virtual int Update() override;
	virtual void Draw(HDC hdc) override;
	virtual void Release() override;

};

