#pragma once
#include "Monster.h"
class CLinearMonster :
	public CMonster
{
public:
	CLinearMonster();
	~CLinearMonster();

public:
	virtual void Initialize() override;
	virtual int  Update() override;
	virtual void Render(HDC hDC) override;
};

