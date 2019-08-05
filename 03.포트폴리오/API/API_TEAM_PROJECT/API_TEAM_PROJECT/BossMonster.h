#pragma once
#include "Monster.h"
class CBossMonster :
	public CMonster
{
public:
	CBossMonster();
	~CBossMonster();

public:
	virtual void Initialize() override;
	virtual int  Update() override;
	virtual void Render(HDC hDC) override;
	virtual	void SetDamaged();
	virtual void CreateBullet();

private:
	bool m_bDir;
};

