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
		cout << "����" << "                      ������ : " << Player->GetiGold() << endl;
		cout << "---------------------------------------" << endl;
		cout << "1. ����  2. ��  3. �Һ�  4. ������" << endl;
		cout << "���� : ";
		cin >> _iSelect;
		if (_iSelect == 4)
			return;
		for (int i = (_iSelect - 1) * 100; i < (_iSelect - 1) * 100 + (sizeof(Item) / unsigned(Item->GettagStatsSizeof())); i++)
		{
			if (Item[i].GetcName() == nullptr)
			{
				if (_iChecking == 0)
					cout << "������ �����ϴ�." << endl;

				system("pause");
				break;
			}
			cout << "��  �� : " << Item[i].GetcName() << endl;
			cout << "���ݷ� : " << Item[i].GetiAtk() << endl;
			cout << "���� : " << Item[i].GetiDef() << endl;
			cout << "��  �� : " << Item[i].GetiGold() << endl;
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

