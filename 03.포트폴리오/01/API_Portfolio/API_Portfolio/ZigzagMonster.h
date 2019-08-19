#pragma once
#include "Monster.h"
class CZigzagMonster :
	public CMonster
{
public:
	CZigzagMonster();
	~CZigzagMonster();

public:
	virtual void Initialize() override;
	virtual int  Update() override;
	virtual void Render(HDC hDC) override;

private:
	bool m_bDir;

};

