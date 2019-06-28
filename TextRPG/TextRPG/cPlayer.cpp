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
	cout << "��  �� : " << GetcName() << endl;
	cout << "��  �� : " << GetiLv() << endl;
	cout << "���ݷ� : " << GetiAtk() << endl;
	cout << "���� : " << GetiDef() << endl;
	cout << "ü  �� : " << GetiHp() << " / " << GetiMaxHp() << endl;
	cout << "����ġ : " << GetiExp() << endl;
	cout << "������ : " << GetiGold() << endl;
}

void cPlayer::Draw()
{
	cout << "������" << endl;
}

void cPlayer::Update()
{
	Init();
	//CoreStats();
}

void cPlayer::Release()
{
	cout << "������" << endl;
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
	if (_Player->GetiExp() >= 100)
	{
		_Player->SetiExp(_Player->GetiExp()-100);
		_Player->SetiLv(_Player->GetiLv()+1);
		_Player->SetiAtk(_Player->GetiAtk()+5);
		_Player->SetiDef(_Player->GetiDef()+1);
		_Player->SetiMaxHp(_Player->GetiMaxHp()+20);
		_Player->SetiHp(_Player->GetiMaxHp());
		
	}
	else
		return;

	LevelUp(_Player);

}
