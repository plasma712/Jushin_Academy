#include "cMainGame.h"
#include "include.h"
#include "cGameObject.h"
#include "cShop.h"
#include "cField.h"
#include "cMonster.h"

cMainGame::cMainGame()
	: Player(nullptr), Monster(nullptr)
{
}

cMainGame::~cMainGame()
{
}

void cMainGame::NewGame()
{

	// Monster = new cMonster();
	// dynamic_cast<cMonster*>(Monster)->CreateMonster();
	
	int k = 0;
	TitleCout();
	cin >> k;
	if (k == 2)
	{
		Player = new cPlayer();

		dynamic_cast<cPlayer*>(Player)->PlayerStatsLoad();

		return;
	}
	while (true)
	{
		system("cls");
		int iSelectNumber;
		PlayerSelectCout();
		cin >> iSelectNumber;

		system("cls");
		switch (iSelectNumber)
		{
		case 1:								//데이터 저장위치로 계산해도 됨. 
			Player = new cPlayer(0, "전사", 10, 5, 60, 60, 1, 0, 0);
			Player->Init();
			dynamic_cast<cPlayer*>(Player)->PlayerStatsSave();
			return;
		case 2:
			Player = new cPlayer(0, "도적", 15, 3, 45, 45, 1, 0, 0);
			Player->Init();
			dynamic_cast<cPlayer*>(Player)->PlayerStatsSave();
			return;
		case 3:
			Player = new cPlayer(0, "마법사", 20, 1, 30, 30, 1, 0, 0);
			Player->Init();
			dynamic_cast<cPlayer*>(Player)->PlayerStatsSave();
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

		cout << "1. 사냥터  2. 상점  3. 인벤토리  4. 저장  5. 나가기" << endl;
		cout << "선택 : ";
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

		if (Player->GetiHp() <= 0)
		{
			system("cls");
			cout << "사망 하였습니다." << endl;
			system("pause");
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

void cMainGame::TitleCout()
{
	cout << "==========================================" << endl;
	cout << "|     텍    스    트     R    P    G     |" << endl;
	cout << "==========================================" << endl;
	cout << "|  1. 새로운 모험.      2.이어서 하기    |" << endl;
	cout << "==========================================" << endl;
	cout << "선택 : ";
}

void cMainGame::PlayerSelectCout()
{
	cout << "==========================================" << endl;
	cout << "|   1. 전사     2. 도적     3. 마법사	 |" << endl;
	cout << "==========================================" << endl;
	cout << "선택 : ";
}

cGameObject* cMainGame::ExtractPlayer()
{
	return Player;
}

void cMainGame::Receive(cGameObject* _Player)
{
	Player = _Player;
}
