#include "VendingMachine.h"

// ��������
int iMoney = 0;
int iMenu = 0;
enum Drink
{
	Coke = 500,
	Cider = 600,
	Fanta_Gr = 700,
	Fanta_Or = 800,
	Coke_zero = 900
};
void MoneyInput() // �� ����
{
	while (true)
	{
		iMoney = 0;
		cout << "���� �������ֽʽÿ� : ";
		cin >> iMoney;

		if (iMoney > 0)
		{
			system("cls");
			break;
		}
	}
}
void Buy(int _iPrice, int _iMoney)
{
	if (_iMoney >= _iPrice)
	{
		iMoney = _iMoney - _iPrice;
		cout << "���������� ���Ű� �Ǿ����ϴ�. " << endl;
		system("pause");
	}
	else
	{
		cout << "�ܵ��� �����մϴ�. �ٽ� �������ּ���." << endl;
		system("pause");
	}
}
void Menu() // �޴�
{
	int iMenu = 0;
	while (true)
	{
		system("cls");
		cout << "������ ����ּ���." << "\t" << "���� �ܾ� : " << iMoney << "��" << endl;
		cout << endl;
		cout << "1. �ݶ� : 500�� " << "\t" << "2. ���̴� : 600��" << "\t" << endl;
		cout << "3. ȯŸ(����) : 700��" << "\t" << "4. ȯŸ(������) : 800��" << "\t" << endl;
		cout << "5. �ݶ� ���� : 900��" << "\t" << "6. ���� " << endl;
		cout << "���� : ";

		cin >> iMenu;

		switch (iMenu)
		{
		case 1:
			system("cls");
			Buy(Coke, iMoney);
			break;
		case 2:
			system("cls");
			Buy(Cider, iMoney);
			break;
		case 3:
			system("cls");
			Buy(Fanta_Gr, iMoney);
			break;
		case 4:
			system("cls");
			Buy(Fanta_Or, iMoney);
			break;
		case 5:
			system("cls");
			Buy(Coke_zero, iMoney);
			break;
		default:
			system("cls");
			break;
		}
		if (iMenu == 6)
		{
			cout << "���� �ܵ��� : " << iMoney << "�Դϴ�." << endl;
			break;
		}
	}
}
void VendingMachine() // ���Ǳ� �����Լ�
{
	MoneyInput();
	Menu();
}
