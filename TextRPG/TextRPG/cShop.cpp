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
		cout << "����" << "                      ������ : " << Player->GetiGold() << endl;
		cout << "---------------------------------------" << endl;
		cout << "1. ����  2. ��  3. �Һ�  4. ������" << endl;
		cout << "���� : ";
		cin >> _iSelect;
		if (_iSelect == 4)
			return;
		//for (int i = (_iSelect - 1) * 100; i < (_iSelect - 1) * 100 + (sizeof(Item[i]) / unsigned(Item[i].GettagStatsSizeof())); i++)
		//{
		//	if (Item[i].GetcName() == nullptr)
		//	{
		//		if (_iChecking == 0)
		//			cout << "������ �����ϴ�." << endl;
		//		system("pause");
		//		break;
		//	}
		//	cout << "��  �� : " << Item[i].GetcName() << endl;
		//	cout << "���ݷ� : " << Item[i].GetiAtk() << endl;
		//	cout << "���� : " << Item[i].GetiDef() << endl;
		//	cout << "��  �� : " << Item[i].GetiGold() << endl;
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
		cout << "���� ���� �Դϴ�." << endl;
		cout << "==========================================" << endl;
		Item->Draw();
		cout << "==========================================" << endl;
		cout << "�ٸ�   ������   ����" << endl;
		cout << "1. ����   2. ������   3.������ " << endl;
		cout << "���� : ";
		cin >> Direction;

		if (Direction == 1)
		{
			--iInherentNumber;
			if (iInherentNumber < 0)
			{
				++iInherentNumber;
				cout << "������ ù��° �������Դϴ�." << endl;
				system("pause");
			}
		}
		else if (Direction == 2)
		{
			++iInherentNumber;
			if (iInherentNumber > 99)
			{
				--iInherentNumber;
				cout << "������ ������ �������Դϴ�." << endl;
				system("pause");
			}
		}
		else
		{
			return;
		}
	}
}

