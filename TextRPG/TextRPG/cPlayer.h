#pragma once
#include "cGameObject.h"

class cPlayer :public cGameObject
{
public:
	cPlayer();
	cPlayer(
		int  _InherentNumber,
		const char* _cName,
		int  _iAtk,
		int  _iDef,
		int  _iHp,
		int  _iMaxHp,
		int  _iLv,
		int  _iExp,
		int  _iGold
	);
	~cPlayer();

public: // 기본 구조
	virtual void Init() override;
	virtual void Draw() override;
	virtual void Update() override;
	virtual void Release() override;

public:
	void CoreStats();
	void LevelUp();
	void LevelDesignCheck(int _PlayerLv);
	void PlayerStatsSave();
	void PlayerStatsLoad(); //, bool _CharLoadErrorChecking)
};

