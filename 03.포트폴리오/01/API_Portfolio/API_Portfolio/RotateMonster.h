#pragma once
#include "Monster.h"
class CRotateMonster :
	public CMonster
{
public:
	CRotateMonster();
	virtual ~CRotateMonster();

public:
	virtual void Initialize() override;
	virtual int  Update() override;
	virtual void Render(HDC hDC) override;

public:
	void SetDir(int _dir);
	int CheckAniCount(int _dir);

private:
	bool m_bDir;

};

