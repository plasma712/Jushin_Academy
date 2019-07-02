#pragma once
#include <iostream>

struct tagStats
{
	tagStats() = default;
	tagStats(
		int  _InherentNumber,
		const char* _cName,
		int  _iAtk,
		int  _iDef,
		int  _iHp,
		int  _iMaxHp,
		int  _iLv,
		int  _iExp,
		int  _iGold
	) : InherentNumber(_InherentNumber), iAtk(_iAtk), iDef(_iDef), iHp(_iHp), iMaxHp(_iMaxHp), iLv(_iLv), iExp(_iExp),iGold(_iGold)
	{
		strcpy_s(cName, _cName);
	}
	int  InherentNumber;
	char cName[32];
	int  iAtk;
	int  iDef;
	int  iHp;
	int  iMaxHp;
	int  iLv;
	int  iExp;
	int  iGold;
	int  iMaxExp;
};