
// ���� 1.
// iA�� iB�� ���� �±�ȯ�ϴ� Swap�Լ��� �ۼ��϶�.
// int iA = 10, iB = 20;
// 
// Swap();
// 
// cout << iA << ", " << iB << endl;

// ���� 2.
// ���Ǳ� ��� ��ȯ���� void�� �ǰ� �϶�.


#include <iostream>

using namespace std;
namespace HomeWork2
{
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
}

void Swap(int *_iA, int *_iB)
{
	int temp = 0;

	temp = *_iA;
	*_iA = *_iB;
	*_iB = temp;
}


void main()
{
	int A = 0, B = 0;
	cout << "�Է� A �� : ";
	cin >> A;
	cout << "�Է� B �� : ";
	cin >> B;
	Swap(&A,&B);
	cout << "A �� : " << A <<" , "<< "B �� : " << B << endl;

	system("pause");
	system("cls");
	HomeWork2::VendingMachine();

	return;
}
