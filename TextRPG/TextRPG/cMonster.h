#pragma once
#include "cGameObject.h"


class cMonster :public cGameObject
{
public:
	cMonster();
	cMonster(
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
	~cMonster();

public: // 기본 구조
	virtual void Init() override;
	virtual void Draw() override;
	virtual void Update() override;
	virtual void Release() override;
public:
	//배열에선 생성자를 통해 초기화 불가능?

	void SetConstructor(int _InherentNumber, const char * _cName, int _iAtk, int _iDef, int _iHp, int _iMaxHp, int _iLv, int _iExp, int _iGold);
	
};

