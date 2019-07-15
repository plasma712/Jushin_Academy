#include "cShop.h"
#include "include.h"
#include "cGameObject.h"

cShop::cShop()
	:Player(nullptr)
{
}


cShop::~cShop()
{

}

void cShop::Init()
{
	Item = new cItem;

}

void cShop::Draw()
{
	//Init();
	//Item->CreateItem();

	while (true)
	{
		system("cls");
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
		//for (int i = (_iSelect - 1) * 100; i < (_iSelect - 1) * 100 + (sizeof(Item[i]) / unsigned(Item[i].GettagStatsSizeof())); i++)
		//{
		//	if (Item[i].GetcName() == nullptr)
		//	{
		//		if (_iChecking == 0)
		//			cout << "물건이 없습니다." << endl;
		//		system("pause");
		//		break;
		//	}
		//	cout << "이  름 : " << Item[i].GetcName() << endl;
		//	cout << "공격력 : " << Item[i].GetiAtk() << endl;
		//	cout << "방어력 : " << Item[i].GetiDef() << endl;
		//	cout << "금  액 : " << Item[i].GetiGold() << endl;
		//	cout << "------------------------------" << endl;
		//	_iChecking++;
		//}
		if (_iSelect == 1)
		{
			ItemScroll();
			break;
			system("pause");
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

void cShop::ItemScroll()
{
	static int iInherentNumber = 0;
	while (true)
	{
		int Direction = 0;
		system("cls");
		//cout << "iInherentNumber : " << iInherentNumber << endl;
		Item->LoadItem(iInherentNumber);
		cout << "무기 상점 입니다." << endl;
		cout << "==========================================" << endl;
		Item->Draw();
		cout << "==========================================" << endl;
		cout << "다른   아이템   보기" << endl;
		cout << "1. 왼쪽   2. 오른쪽   3. 구매   4.나가기 " << endl;
		cout << "선택 : ";
		cin >> Direction;

		if (Direction == 1)
		{
			--iInherentNumber;
			if (iInherentNumber < 0)
			{
				++iInherentNumber;
				cout << "상점의 첫번째 아이템입니다." << endl;
				system("pause");
			}
		}
		else if (Direction == 2)
		{
			++iInherentNumber;
			if (iInherentNumber > 99)
			{
				--iInherentNumber;
				cout << "상점의 마지막 아이템입니다." << endl;
				system("pause");
			}
		}
		else if (Direction == 3)
		{
			int iBuySelect = 0;
			cout << " 정말로 구매하시겠습니까? " << endl;
			cout << "구매 전 : " << Player->GetiGold()<<"골드" << endl; 
			cout << "구매 후 : " << Player->GetiGold() - Item->GetiGold() << "골드" << endl;
			cout << "==========================================" << endl;
			cout << "1. 구매완료.  2.구매취소  :";
			cin >> iBuySelect;
			if (iBuySelect == 1)
			{
				if (Player->GetiGold() >= Item->GetiGold())
				{
					Player->ExpendiGold(Item->GetiGold());
					Inventory->SaveHavingItem(Item);
					dynamic_cast<cPlayer*>(Player)->PlayerStatsSave();
					cout << "구매완료" << endl;
					system("pause");
				}
				else
				{
					system("cls");
					cout << "돈이 부족합니다." << endl;
					system("pause");
					break;
				}
			}
			else
				break;
		}
		else
		{
			return;
		}
	}
	return;
}

