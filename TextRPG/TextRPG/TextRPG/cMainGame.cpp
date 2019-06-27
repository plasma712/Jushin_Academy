#include "cMainGame.h"
#include "include.h"
#include "cGameObject.h"
#include "cShop.h"
#include "cField.h"

cMainGame::cMainGame()
	: Player(nullptr),Monster(nullptr)
{
}

cMainGame::~cMainGame()
{
}

void cMainGame::NewGame()
{
	while (true)
	{
		int iSelectNumber;
		
		cout << "1.����  2.����  3.������" << endl;
		cout << "���� : ";
		cin >> iSelectNumber;

		system("cls");
		switch (iSelectNumber)
		{
		case 1:								//������ ������ġ�� ����ص� ��. 
			Player = new cPlayer(0, "����", 10, 5, 60, 60, 1, 0, 0);
			Player->Init();
			return;
		case 2:
			Player = new cPlayer(0, "����", 15, 3, 45, 45, 1, 0, 0);
			Player->Init();
			return;
		case 3:
			Player = new cPlayer(0, "������", 20, 1, 30, 30, 1, 0, 0);
			Player->Init();
			return;
		default:
			break;
		}
	}
}

void cMainGame::Lobby()
{
	Init();
	while (true)
	{
		system("cls");
		int iSelectNumber = 0;
		dynamic_cast<cPlayer*>(Player)->Init();

		cout << "1. �����  2. ����  3. �κ��丮  4. ����  5. ������" << endl;
		cout << "���� : ";
		cin >> iSelectNumber;
		system("cls");
		switch (iSelectNumber)
		{
		case 1:
			Field->Receive(Player);
			Field->Battle();
			break;
		case 2:
			Shop->Receive(Player);
			Shop->Draw();
			break;
		case 3:
			return;
		default:
			break;
		}
	}
}

void cMainGame::Init()
{
	if (Shop == nullptr)
	{
		Shop = new cShop;
		Shop->Init();
	}
	if (Player == nullptr)
	{
		NewGame();
	}
	if (Monster == nullptr)
	{
		 Monster = new cGameObject;
		Monster->Init();
	}
	if (Field == nullptr)
	{
		Field = new cField;
		Field->Init();
	}
}

cGameObject* cMainGame::ExtractPlayer()
{
	return Player;
}

void cMainGame::Receive(cGameObject* _Player)
{
	Player = _Player;
}
