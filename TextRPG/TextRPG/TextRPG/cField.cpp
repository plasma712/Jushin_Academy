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
}
void cField::Init()
{
}

void cField::Draw()
{
	dynamic_cast<cMonster*>(Monster)->Init();
	cout << "------------------------------------" << endl;
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
		cout << "------------------------------------" << endl;
		cout << "1. ����  2. ����" << endl;
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
		if (CheckingDie(Player,Monster) == true)
			break;
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
		cout << "1. �ʱ� ����  2. �߱� ����  3. ��� ����  4. ������" << endl;
		cout << "���� : "; cin >> iSelect;

		switch (iSelect)
		{
		case 1:
			Monster = new cMonster(0, "������", 5, 1, 20, 20, 1, 10, 100);
			return;
		case 2:
			Monster = new cMonster(0, "��Ȳ����", 5, 5, 40, 40, 1, 10, 100);
			return;
		case 3:
			Monster = new cMonster(0, "�Ķ�����", 5, 10, 80, 80, 1, 10, 100);
			return;
		case 4:
			return;
		default:
			break;
		}
	}
}

void cField::Reward(cGameObject * _Player, cGameObject * _Monster)
{
	if (_Player->GetiHp() <= 0)
		return;
	else
	{
		_Player->SetiExp(_Monster->GetiExp());
	}
}




