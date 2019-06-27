#include "cMonster.h"
#include "include.h"


cMonster::cMonster()
{
}

cMonster::cMonster(int _InherentNumber, const char * _cName, int _iAtk, int _iDef, int _iHp, int _iMaxHp, int _iLv, int _iExp, int _iGold)
	:cGameObject(_InherentNumber, _cName, _iAtk, _iDef, _iHp, _iMaxHp, _iLv, _iExp, _iGold)
{
}


cMonster::~cMonster()
{
}

void cMonster::Init()
{
	cout << "이  름 : " << GetcName() << endl;
	cout << "레  벨 : " << GetiLv() << endl;
	cout << "공격력 : " << GetiAtk() << endl;
	cout << "방어력 : " << GetiDef() << endl;
	cout << "체  력 : " << GetiHp() << " / " << GetiMaxHp() << endl;
}

void cMonster::Draw()
{
	cout << "재정의" << endl;
}

void cMonster::Update()
{
	Init();
}

void cMonster::Release()
{
	cout << "재정의" << endl;
}

void cMonster::SetConstructor(int _InherentNumber, const char * _cName, int _iAtk, int _iDef, int _iHp, int _iMaxHp, int _iLv, int _iExp, int _iGold)
{
	cGameObject(_InherentNumber, _cName, _iAtk, _iDef, _iHp, _iMaxHp, _iLv, _iExp, _iGold);
}
