//
//	���� 1. ���Ǳ� ���α׷� �ۼ��ϱ�
//			a. �� ����.
//			b. �޴� �����ֱ� �� ����.
//			C. ����(������ �޴��� ���ݸ�ŭ ������ ����) �Ǵ� ���� ����(������ ����).
//			d. ����ڰ� �ܵ���ȯ �޴��� ������ �������� ���Ǳ� ���α׷��� �ݺ� ����.
//			e. ����ڰ� �ܵ���ȯ �޴��� �����ϸ� ���� ���� �Ž������� ����ϰ� ����.
//
//
//	���� 2. Ȧ¦ ���� ���α׷� �ۼ��ϱ�.
//			a. ������ �����ϸ� 1 ~ 10 ������ ������ �̴´�. (���α׷� ��ܿ� ����)
//			b. ���� ������ Ȧ���� ¦���� ���ߴ� ����.
//			c. �� 3���� ����. ������ ����� �� x�� y�� ���.
//
//
//	���� 3. ���� ���� �� ���� ���α׷� �ۼ��ϱ�.
//			a. ��ǻ�Ϳ� �����������Ͽ� �¸��ϴ� ����.
//			b. �� 3���� ����. ������ ���� �� �� x�� y�� z�� ���.
//
//
//	���� 4. ������ ���� *�� ����϶�. (for���� �̿��Ͽ�)
//
//			a. *
//			   **
//			   ***
//			   ****
//			   *****
//
//
//	���� 5. ������ ���� *�� ����϶�. (for���� �̿��Ͽ�)
//
//			a. *****
//			   ****
//			   ***
//			   **
//			   *
//
//
//	���� 6. ������ ���� *�� ����϶�. (for���� �̿��Ͽ�)
//
//			a.			*
//					   **
//					  ***
//					 ****
//					*****
//
//
//	���� 7. ������ ���� *�� ����϶�. (for���� �̿��Ͽ�)
//
//			a.	    *****
//					 ****
//					  ***
//					   **
//						*
//
//
//
//
//
//

#include <iostream>
#include <time.h>

using namespace std;

// ���� 1. ���Ǳ� ���α׷� �ۼ��ϱ�

// a.�� ����.
// b.�޴� �����ֱ� �� ����.
// C.����(������ �޴��� ���ݸ�ŭ ������ ����) �Ǵ� ���� ����(������ ����).
// d.����ڰ� �ܵ���ȯ �޴��� ������ �������� ���Ǳ� ���α׷��� �ݺ� ����.
// e.����ڰ� �ܵ���ȯ �޴��� �����ϸ� ���� ���� �Ž������� ����ϰ� ����.

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


// ���� 2. Ȧ¦ ���� ���α׷� �ۼ��ϱ�.

// a.������ �����ϸ� 1 ~10 ������ ������ �̴´�. (���α׷� ��ܿ� ����)
// b.���� ������ Ȧ���� ¦���� ���ߴ� ����.
// c.�� 3���� ����.������ ����� �� x�� y�� ���.

int iSaveNumber = 0;
int iWin = 0, iDraw = 0, iLose = 0;
void RandomNumber()
{
	unsigned int iSeed = time(nullptr);
	srand(iSeed);
}

int OddEvenNumber()
{
	int iRandomNumber = rand() % 10;
	iSaveNumber = iRandomNumber;
	return iSaveNumber;
}

void SelcetOddEvenNumber(int _iSaveNumber)
{
	int iSelect = 0;
	int iOddEvenNumber = 0;
	if (_iSaveNumber % 2 == 0)
		iOddEvenNumber = 2;
	else
		iOddEvenNumber = 1;
	while (true)
	{
		system("cls");
		cout << "Ȧ�� ���� ¦�� ���� �������ּ���. " << endl;
		cout << "Ȧ�� : 1 , ¦�� : 2 " << " = ";
		cin >> iSelect;
		cout << endl;

		if (iSelect == 1 || iSelect == 2)
		{

			if (iSelect == iOddEvenNumber)
			{
				cout << _iSaveNumber << endl;
				cout << "������ ���߾����ϴ�. " << endl;
				iWin++;
				system("pause");
				break;
			}
			else
			{
				cout << _iSaveNumber << endl;
				cout << "������ Ʋ���̽��ϴ�. " << endl;
				iLose++;
				system("pause");
				break;
			}
		}
		else
		{
			cout << "�ٽ� �Է����ּ���." << endl;
			system("pause");
		}
	}
}

void Entirely(int _iWin, int _iDraw, int _iLose)
{
	system("cls");
	if (_iDraw == 0)
		cout << "�� : " << _iWin << "\t" << "�� : " << _iLose << endl;
	else
		cout << "�� : " << _iWin << "\t" << "�� : " << iDraw << "\t" << "�� : " << _iLose << endl;
}

void OddEvenNumberGame()
{
	iSaveNumber = 0;
	iWin = 0, iDraw = 0, iLose = 0;

	RandomNumber();
	for (int i = 0; i < 3; i++)
	{
		SelcetOddEvenNumber(OddEvenNumber());
	}
	Entirely(iWin, iDraw, iLose);
}


//	���� 3. ���� ���� �� ���� ���α׷� �ۼ��ϱ�.

//	a. ��ǻ�Ϳ� �����������Ͽ� �¸��ϴ� ����.
//	b. �� 3���� ����. ������ ���� �� �� x�� y�� z�� ���.

int RockPaperScissorsNumber()
{
	int iRandomNumber = rand() % 3;
	iSaveNumber = iRandomNumber;
	return iSaveNumber;
}

void SelcetRockPaperScissors(int _iSaveNumber)
{
	int iSelect = 0;
	while (true)
	{
		system("cls");
		cout << "���� ���� �� �������ּ��� " << endl;
		cout << "���� : 0 , ���� : 1 , �� : 2 " << " = ";
		cin >> iSelect;
		cout << endl;

		if (iSelect == 0 || iSelect == 1 || iSelect == 2)
		{

			if (iSelect == _iSaveNumber)
			{
				cout << _iSaveNumber << endl;
				cout << "�����ϴ�. " << endl;
				iDraw++;
				system("pause");
				break;
			}
			else
			{
				if (iSelect == 0)
				{
					if (_iSaveNumber == 1)
					{
						cout << _iSaveNumber << endl;
						cout << "�����ϴ�. " << endl;
						iLose++;
						system("pause");
						break;
					}
					else if (_iSaveNumber == 2)
					{
						cout << _iSaveNumber << endl;
						cout << "�̰���ϴ�. " << endl;
						iWin++;
						system("pause");
						break;
					}
				}
				else if (iSelect == 1)
				{
					if (_iSaveNumber == 2)
					{
						cout << _iSaveNumber << endl;
						cout << "�����ϴ�. " << endl;
						iLose++;
						system("pause");
						break;
					}
					else if (_iSaveNumber == 0)
					{
						cout << _iSaveNumber << endl;
						cout << "�̰���ϴ�. " << endl;
						iWin++;
						system("pause");
						break;
					}
				}
				else
				{
					if (_iSaveNumber == 0)
					{
						cout << _iSaveNumber << endl;
						cout << "�����ϴ�. " << endl;
						iLose++;
						system("pause");
						break;
					}
					else if (_iSaveNumber == 1)
					{
						cout << _iSaveNumber << endl;
						cout << "�̰���ϴ�. " << endl;
						iWin++;
						system("pause");
						break;
					}
				}

			}
		}
		else
		{
			cout << "�ٽ� �Է����ּ���." << endl;
			system("pause");
		}
	}
}

void RockPaperScissorsGame()
{
	iSaveNumber = 0;
	iWin = 0, iDraw = 0, iLose = 0;

	RandomNumber();

	for (int k = 0; k < 3; k++)
		SelcetRockPaperScissors(RockPaperScissorsNumber());

	Entirely(iWin, iDraw, iLose);


}


// ���� 4,5,6,7

void HomeWork4()
{
	for (int k = 0; k < 5; k++)
	{
		for (int i = 0; i <= k; i++)
		{
			cout << "*";
		}
		cout << endl;
	}
}
void HomeWork5()
{
	for (int k = 4; k >= 0; k--)
	{
		for (int i = 0; i <= k; i++)
		{
			cout << "*";
		}
		cout << endl;
	}
}
void HomeWork6()
{
	for (int k = 0; k < 5; k++)
	{
		for (int i = 4; i > k; i--)
		{
			cout << " ";
		}
		for (int j = 0; j <= k; j++)
		{
			cout << "*";
		}
		cout << endl;
	}
}
void HomeWork7()
{
	for (int k = 0; k < 5; k++)
	{
		for (int i = 5; i > k; i--)
		{
			cout << "*";
		}
		for (int j = 0; j <= k; j++)
		{
			cout << " ";
		}
		cout << endl;
	}
}

void HomeWorkSelect()
{
	int iHomeWorkNumber = 0;
	while (true)
	{
		system("cls");
		cout << "���� ���� (���� 1, 2, 3, 4, 5, 6, 7 ) / ���� : 0 " << endl;
		cout << "���� : ";
		cin >> iHomeWorkNumber;
		switch (iHomeWorkNumber)
		{
		case 1:
			VendingMachine();
			system("pause");
			break;
		case 2:
			OddEvenNumberGame();
			system("pause");
			break;
		case 3:
			RockPaperScissorsGame();
			system("pause");
			break;
		case 4:
			HomeWork4();
			system("pause");
			break;
		case 5:
			HomeWork5();
			system("pause");
			break;
		case 6:
			HomeWork6();
			system("pause");
			break;
		case 7:
			HomeWork7();
			system("pause");
			break;
		case 0:
			cout << "���α׷� �����մϴ�. " << endl;
			system("pause");
			break;
		default:
			cout << "�ٽ� ���� ���ּ���. " << endl;
			system("pause");
			break;

		}
		if (iHomeWorkNumber == 0)
			break;
	}
}

void main()
{
	HomeWorkSelect();
	return;
}