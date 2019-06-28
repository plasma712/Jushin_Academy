#include "cItem.h"
#include "include.h"


cItem::cItem()
	:Player(nullptr)
{
}

cItem::cItem(int _InherentNumber, const char * _cName, int _iAtk, int _iDef, int _iHp, int _iMaxHp, int _iLv, int _iExp, int _iGold)
	:cGameObject(_InherentNumber, _cName, _iAtk, _iDef, _iHp, _iMaxHp, _iLv, _iExp, _iGold)
{
}

cItem::~cItem()
{
}

void cItem::Init()
{
	// 데이터 불러오기.
	
	
}

void cItem::Draw()
{

}

void cItem::Update()
{
}

void cItem::Release()
{
}

cPlayer * cItem::ExtractPlayer()
{
	return Player;
}

void cItem::Receive(cPlayer * _Player)
{
	Player = _Player;
}

void cItem::Setting(int _InherentNumber, const char * _cName, int _iAtk, int _iDef, int _iHp, int _iMaxHp, int _iLv, int _iExp, int _iGold)
{
	cGameObject(_InherentNumber, _cName, _iAtk, _iDef, _iHp, _iMaxHp, _iLv, _iExp, _iGold);
}
