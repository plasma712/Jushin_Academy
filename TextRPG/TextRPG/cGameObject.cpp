#include "cGameObject.h"
#include "include.h"

cGameObject::cGameObject()
{
}

cGameObject::cGameObject(int _InherentNumber, const char* _cName, int _iAtk, int _iDef, int _iHp, int _iMaxHp, int _iLv, int _iExp,int _iGold)
	:Stats(_InherentNumber, _cName, _iAtk, _iDef, _iHp, _iMaxHp, _iLv, _iExp,_iGold)
{
}


cGameObject::~cGameObject()
{
}

void cGameObject::Init()
{
	cout << "직  업 : " << GetcName() << endl;
	cout << "레  벨 : " << GetiLv() << endl;
	cout << "공격력 : " << GetiAtk() << endl;
	cout << "방어력 : " << GetiDef() << endl;
	cout << "체  력 : " << GetiHp() << " / " << GetiMaxHp() << endl;
	cout << "경험치 : " << GetiExp() << endl;
	cout << "소지금 : " << GetiGold() << endl;
}

void cGameObject::Draw()
{// Init();
	cout << "직  업 : " << GetcName() << endl;
	cout << "레  벨 : " << GetiLv() << endl;
	cout << "공격력 : " << GetiAtk() << endl;
	cout << "방어력 : " << GetiDef() << endl;
	cout << "체  력 : " << GetiHp() << " / " << GetiMaxHp() << endl;
	cout << "경험치 : " << GetiExp() << endl;
}

void cGameObject::Update()
{
	Draw();
}

void cGameObject::Release()
{
}

//void cGameObject::Attack(cGameObject * SetObject, cGameObject * GetObject)
//{
//}

int cGameObject::GetInherentNumber()
{
	return Stats.InherentNumber;
}

char* cGameObject::GetcName()
{
	return Stats.cName;
}

int cGameObject::GetiAtk()
{
	return Stats.iAtk;
}

int cGameObject::GetiDef()
{
	return Stats.iDef;
}

int cGameObject::GetiHp()
{
	return Stats.iHp;
}

int cGameObject::GetiMaxHp()
{
	return Stats.iMaxHp;
}

int cGameObject::GetiLv()
{
	return Stats.iLv;
}

int cGameObject::GetiExp()
{
	return Stats.iExp;
}

int cGameObject::GetiGold()
{
	return Stats.iGold;
}

int cGameObject::GettagStatsSizeof()
{
	return sizeof(tagStats);
}


void cGameObject::SetInherentNumber(int _InherentNumber)
{
	Stats.InherentNumber = _InherentNumber;
}

void cGameObject::SetcName(char * _cName)
{
	strcpy_s(Stats.cName, _cName);
}

void cGameObject::SetiAtk(int _iAtk)
{
	Stats.iAtk = _iAtk;
}

void cGameObject::SetiDef(int _iDef)
{
	Stats.iDef = _iDef;
}

void cGameObject::SetiHp(int _iHp)
{
	Stats.iHp = _iHp;
}

void cGameObject::SetiMaxHp(int _iMaxHp)
{
	Stats.iMaxHp = _iMaxHp;
}

void cGameObject::SetiLv(int _iLv)
{
	Stats.iLv = _iLv;
}

void cGameObject::SetiExp(int _iExp)
{
	Stats.iExp = _iExp;
}

void cGameObject::SetiGold(int _iGold)
{
	Stats.iGold = _iGold;
}
