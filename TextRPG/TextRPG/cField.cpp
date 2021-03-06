#include "cField.h"
#include "cGameObject.h"
#include "include.h"
#include "cMonster.h"
#include "cPlayer.h"

cField::cField()
	: Player(nullptr), Monster(nullptr)
{
}


cField::~cField()
{
	delete Monster;
}
void cField::Init()
{
}

void cField::Draw()
{
	dynamic_cast<cMonster*>(Monster)->Init();
	//cout << "==========================================" << endl;
	dynamic_cast<cPlayer*>(Player)->Init();
}

void cField::Update()
{
	Player->Update();
	Monster->Update();
}

void cField::Release()
{
}


void cField::Receive(cGameObject * _Player)
{
	Player = _Player;
}

cGameObject * cField::ExtractPlayer()
{
	return Player;
}

void cField::Battle()
{
	SelectFieldLevel();
	while (true)
	{
		system("cls");
		Draw();
		//cout << "==========================================" << endl;
		cout << "1. 공격  2. 도망" << endl;
		cin >> iSelect;
		switch (iSelect)
		{
		case 1:
			AttackFormula(Player, Monster);
			AttackFormula(Monster, Player);
			break;
		case 2:
			return;
		default:
			break;
		}

		//if (Monster->GetiHp() > 0 || Player->GetiHp()<=0)
		if (Player->GetiHp() <= 0)
		{

			break;
		}
		else if(Player->GetiHp()>0&&Monster->GetiHp()<=0)
		{
			Reward(Player, Monster);
			break;
		}
	}


}

void cField::AttackFormula(cGameObject * _To, cGameObject * _From)
{
	if ((_To->GetiAtk()) - (_From->GetiDef()) < 0)
		return;
	else
	{
		_From->SetiHp((_From->GetiHp() - ((_To->GetiAtk()) - (_From->GetiDef()))));
	}
}

bool cField::CheckingDie(cGameObject* _Player, cGameObject* _Monster)
{
	if (_Player->GetiHp() <= 0 || _Monster->GetiHp() <= 0)
	{
		return true;
	}
	else
		return false;
}

void cField::SelectFieldLevel()
{
	while (true)
	{
		system("cls");
		//cout << "1. 초급 던전  2. 중급 던전  3. 고급 던전  4. 나가기" << endl;
		//cout << "선택 : "; cin >> iSelect;
		//
		//switch (iSelect)
		//{
		//case 1:
		//	Monster = new cMonster; //(0, "슬라임", 5, 1, 20, 20, 1, 1000, 100);
		//	dynamic_cast<cMonster*>(Monster)->MonsterStatsLoad(iSelect);
		//	return;
		//case 2:
		//	//Monster = new cMonster(0, "주황버섯", 5, 5, 40, 40, 1, 15, 100);
		//	Monster = new cMonster; //(0, "슬라임", 5, 1, 20, 20, 1, 1000, 100);
		//	dynamic_cast<cMonster*>(Monster)->MonsterStatsLoad(iSelect);
		//	return;
		//case 3:
		//	//Monster = new cMonster(0, "파란버섯", 5, 10, 80, 80, 1, 20, 100);
		//	Monster = new cMonster; //(0, "슬라임", 5, 1, 20, 20, 1, 1000, 100);
		//	dynamic_cast<cMonster*>(Monster)->MonsterStatsLoad(iSelect);
		//
		//	return;
		//case 4:
		//	return;
		//default:
		//	break;
		//}
		Monster = new cMonster; //(0, "슬라임", 5, 1, 20, 20, 1, 1000, 100);
		dynamic_cast<cMonster*>(Monster)->MonsterStatsLoad(Player->GetiLv());
		return;
	}
}

void cField::Reward(cGameObject * _Player, cGameObject * _Monster)
{
	if (_Player->GetiHp() <= 0)
		return;
	else
	{
		_Player->SetiExp(_Monster->GetiExp()+_Player->GetiExp());
		_Player->SetiGold(_Monster->GetiGold() + _Player->GetiGold());
		dynamic_cast<cPlayer*>(_Player)->LevelUp();
	}
}




