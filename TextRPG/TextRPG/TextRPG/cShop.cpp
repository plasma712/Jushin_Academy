#include "cShop.h"
#include "include.h"
#include "cGameObject.h"

cShop::cShop()
	:Player(nullptr), Item(nullptr)
{
}


cShop::~cShop()
{
}

void cShop::Init()
{

}

void cShop::Draw()
{
	while (true)
	{
		int _iSelect = 0;
		int _iChecking = 0;
		cout << "---------------------------------------" << endl;
		cout << "상점" << "                      소지금 : " << Player->GetiGold() << endl;
		cout << "---------------------------------------" << endl;
		cout << "1. 무기  2. 방어구  3. 소비  4. 나가기" << endl;
		cout << "선택 : ";
		cin >> _iSelect;
		if (_iSelect == 4)
			return;
		for (int i = (_iSelect - 1) * 100; i < (_iSelect - 1) * 100 + (sizeof(Item) / unsigned(Item->GettagStatsSizeof())); i++)
		{
			if (Item[i].GetcName() == nullptr)
			{
				if (_iChecking == 0)
					cout << "물건이 없습니다." << endl;

				system("pause");
				break;
			}
			cout << "이  름 : " << Item[i].GetcName() << endl;
			cout << "공격력 : " << Item[i].GetiAtk() << endl;
			cout << "방어력 : " << Item[i].GetiDef() << endl;
			cout << "금  액 : " << Item[i].GetiGold() << endl;
			cout << "------------------------------" << endl;
			_iChecking++;
		}
	}
}

void cShop::Update()
{
	Draw();
}

void cShop::Release()
{
}

cGameObject * cShop::ExtractPlayer()
{
	return Player;
}

void cShop::Receive(cGameObject * _Player)
{
	Player = _Player;
}

cItem * cShop::ExtractItem()
{
	return Item;
}

void cShop::Receive(cItem * _Item)
{
	Item = _Item;
}

void cShop::Buy()
{
}

void cShop::Sell()
{
}

