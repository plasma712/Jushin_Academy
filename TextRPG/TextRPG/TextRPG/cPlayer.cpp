#include "cPlayer.h"
#include "include.h"

cPlayer::cPlayer()
{
}

cPlayer::cPlayer(int _InherentNumber, const char * _cName, int _iAtk, int _iDef, int _iHp, int _iMaxHp, int _iLv, int _iExp, int _iGold)
	:cGameObject(_InherentNumber, _cName, _iAtk, _iDef, _iHp, _iMaxHp, _iLv, _iExp, _iGold)
{
}

cPlayer::~cPlayer()
{
}

void cPlayer::Init()
{
	cout << "직  업 : " << GetcName() << endl;
	cout << "레  벨 : " << GetiLv() << endl;
	cout << "공격력 : " << GetiAtk() << endl;
	cout << "방어력 : " << GetiDef() << endl;
	cout << "체  력 : " << GetiHp() << " / " << GetiMaxHp() << endl;
	cout << "경험치 : " << GetiExp() << endl;
	cout << "소지금 : " << GetiGold() << endl;
}

void cPlayer::Draw()
{
	cout << "재정의" << endl;
}

void cPlayer::Update()
{
	Init();
	//CoreStats();
}

void cPlayer::Release()
{
	cout << "재정의" << endl;
}

void cPlayer::CoreStats()
{
	GetiAtk();
	GetiDef();
	GetiHp();
	GetiMaxHp();
	GetiLv();
	GetiExp();
	GetiGold();
}

void cPlayer::LevelUp(cPlayer * _Player)
{
	
}
