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
	cout << "��  �� : " << GetcName() << endl;
	cout << "��  �� : " << GetiLv() << endl;
	cout << "���ݷ� : " << GetiAtk() << endl;
	cout << "���� : " << GetiDef() << endl;
	cout << "ü  �� : " << GetiHp() << " / " << GetiMaxHp() << endl;
}

void cMonster::Draw()
{
	cout << "������" << endl;
}

void cMonster::Update()
{
	Init();
}

void cMonster::Release()
{
	cout << "������" << endl;
}

void cMonster::SetConstructor(int _InherentNumber, const char * _cName, int _iAtk, int _iDef, int _iHp, int _iMaxHp, int _iLv, int _iExp, int _iGold)
{
	cGameObject(_InherentNumber, _cName, _iAtk, _iDef, _iHp, _iMaxHp, _iLv, _iExp, _iGold);
}
