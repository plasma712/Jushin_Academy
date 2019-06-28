#pragma once
#include "cGameObject.h"
#include "cPlayer.h"

class cItem : public cGameObject
{
public:
	cPlayer* Player;
public:
	cItem();
	cItem(
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

	virtual ~cItem();
public:
	virtual void Init() override;
	virtual void Draw() override;
	virtual void Update() override;
	virtual void Release() override;

public:
	cPlayer* ExtractPlayer();
	void Receive(cPlayer* _Player);
	void Setting(int  _InherentNumber,
		const char* _cName,
		int  _iAtk,
		int  _iDef,
		int  _iHp,
		int  _iMaxHp,
		int  _iLv,
		int  _iExp,
		int  _iGold
	);
};

