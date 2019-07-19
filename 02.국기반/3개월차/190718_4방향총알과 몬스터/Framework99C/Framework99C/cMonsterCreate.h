#pragma once
#include "Monster.h"
class cMonsterCreate :
	public CMonster
{
public:
	cMonsterCreate();
	virtual ~cMonsterCreate();
	MONSTER_LST*	m_pMonsterLst;

	// CGameObject을(를) 통해 상속됨
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;

public:
	void SetMonsterCreate(MONSTER_LST* pMonsterLst);
	CGameObject* CreateMonster();
	void MonsterLstPush();
};

