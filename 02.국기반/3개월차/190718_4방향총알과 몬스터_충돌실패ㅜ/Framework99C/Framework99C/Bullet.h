#pragma once
#include "GameObject.h"
class CBullet :
	public CGameObject
{
public:
	CBullet();
	virtual ~CBullet();

public:
	void SetDirection(BULLET_DIRECTION eDir);
	void GetMonsterList(MONSTER_LST* pMonsterLst);
public:
	// CGameObject을(를) 통해 상속됨
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Render(HDC hDC) override;

private:
	virtual void Release() override;

private:
	void IsMoving();
	void IsOutRange();
	//void IsCollision(CGameObject* Enemy);
private:
	BULLET_DIRECTION	m_eDirection;
	MONSTER_LST			m_MonsterLst;
};

