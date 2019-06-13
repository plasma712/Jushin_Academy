/*
	// ���� 1.
	// 2���� �迭�� �̿��Ͽ� ������ ���� ȸ�����Ѷ�

	1 2 3						7 4 1
	4 5 6	�ð���� 90�� ->    8 5 2
	7 8 9						9 6 3

	// ���� 2.
	// ���Ǳ�, Ȧ¦, ������������ �Լ��� �����ؿͶ�.

*/

#include <iostream> 
#include <time.h>
#include <string>
using namespace std;

// ���߹迭 ȸ��
namespace HomeWork1
{
	int iArray2D[3][3] = {};

	void BaseArray2D()
	{
		for (int k = 0; k < 3; k++)
		{
			for (int i = 0; i < 3; i++)
			{
				iArray2D[k][i] = k * 3 + i + 1;
			}
		}
	}

	void CoutArray2D()
	{
		for (int k = 0; k < 3; k++)
		{
			for (int i = 0; i < 3; i++)
			{
				cout << iArray2D[k][i] << "\t";
			}
			cout << endl;
		}
	}

	void Array2D_RotationLeft()
	{
		int iCopyArray2D[3][3] = {};

		for (int k = 0; k < 3; k++)
		{
			for (int i = 0; i < 3; i++)
			{
				iCopyArray2D[k][i] = iArray2D[k][i];
			}
		}

		for (int k = 0; k < 3; k++)
		{
			for (int i = 0; i < 3; i++)
			{
				if (k == 0)
				{
					iArray2D[k][i] = iCopyArray2D[i][k + 2];
				}
				else if (k == 1)
				{
					iArray2D[k][i] = iCopyArray2D[i][k];
				}
				else
				{
					iArray2D[k][i] = iCopyArray2D[i][k - 2];
				}
			}
		}

	}

	void Array2D_RotationRight()
	{
		int iCopyArray2D[3][3] = {};

		for (int k = 0; k < 3; k++)
		{
			for (int i = 0; i < 3; i++)
			{
				iCopyArray2D[k][i] = iArray2D[k][i];
			}
		}


		for (int k = 0; k < 3; k++)
		{
			for (int i = 0; i < 3; i++)
			{
				if (k == 0)
				{
					iArray2D[i][k] = iCopyArray2D[k + 2][i];
				}
				else if (k == 1)
				{
					iArray2D[i][k] = iCopyArray2D[k][i];
				}
				else
				{
					iArray2D[i][k] = iCopyArray2D[k - 2][i];
				}
			}
		}


	}

	void Array2D()
	{
		//bool TF = true;
		BaseArray2D();
		CoutArray2D();
		
		while (true)
		{
			system("cls");
			int iInputNumber = 0;
			CoutArray2D();
			cout << "[ȸ�� �ϱ�] 1. ����  2.������  0.����" << endl;
			cout << "��ȣ�� �Է��Ͻÿ� : ";
			cin >> iInputNumber;

			system("cls");

			if (iInputNumber == 0)
				break;

			switch (iInputNumber)
			{
			case 1:
				Array2D_RotationLeft();
				break;
			case 2:
				Array2D_RotationRight();
				break;
			default:
				break;
			}
			cout << "ȸ�� ��� " << endl;
			CoutArray2D();
			system("pause");
			system("cls");
		}
	}

}
// ���Ǳ�
namespace HomeWork2
{
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
			system("cls");
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
			cout << "5. �ݶ� ���� : 900��" << "\t" << "6. �ܵ���ȯ " << endl;
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
				system("pause");
				break;
			}
		}
	}
	void VendingMachine() // ���Ǳ� �����Լ�
	{
		system("cls");
		MoneyInput();
		Menu();
	}
}
// Ȧ ¦ ����
namespace HomeWork3
{
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
					cout<<"��ǻ�Ͱ� ������ �� : " << _iSaveNumber << endl;
					cout << "������ ���߾����ϴ�. " << endl;
					iWin++;
					system("pause");
					break;
				}
				else
				{
					cout << "��ǻ�Ͱ� ������ �� : " << _iSaveNumber << endl;
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
		system("pause");
	}
}
// ����������
namespace HomeWork4
{
	int iSaveNumber = 0;
	int iWin = 0, iDraw = 0, iLose = 0;

	string chRockPaperScissor[3] = { "����","����","��" };

	void RandomNumber()
	{
		unsigned int iSeed = time(nullptr);
		srand(iSeed);
	}

	void Entirely(int _iWin, int _iDraw, int _iLose)
	{
		system("cls");
		if (_iDraw == 0)
			cout << "�� : " << _iWin << "\t" << "�� : " << _iLose << endl;
		else
			cout << "�� : " << _iWin << "\t" << "�� : " << iDraw << "\t" << "�� : " << _iLose << endl;
	}

	

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
					cout << "��ǻ�ʹ� : " << chRockPaperScissor[_iSaveNumber] << endl;
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
							cout << "��ǻ�ʹ� : " << chRockPaperScissor[_iSaveNumber] << endl;
							cout << "�����ϴ�. " << endl;
							iLose++;
							system("pause");
							break;
						}
						else if (_iSaveNumber == 2)
						{
							cout << "��ǻ�ʹ� : " << chRockPaperScissor[_iSaveNumber] << endl;
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
							cout << "��ǻ�ʹ� : " << chRockPaperScissor[_iSaveNumber] << endl;
							cout << "�����ϴ�. " << endl;
							iLose++;
							system("pause");
							break;
						}
						else if (_iSaveNumber == 0)
						{
							cout << "��ǻ�ʹ� : " << chRockPaperScissor[_iSaveNumber] << endl;
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
							cout << "��ǻ�ʹ� : " << chRockPaperScissor[_iSaveNumber] << endl;
							cout << "�����ϴ�. " << endl;
							iLose++;
							system("pause");
							break;
						}
						else if (_iSaveNumber == 1)
						{
							cout << "��ǻ�ʹ� : " << chRockPaperScissor[_iSaveNumber] << endl;
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
		system("pause");

	}
}

void main()
{
	int iHomeWorkNumber = 0;

	while (true)
	{
		system("cls");
		cout << "���� ���� (���� 1, 2, 3, 4) / ���� : 0 " << endl;
		cout << "���� : ";
		cin >> iHomeWorkNumber;
		switch (iHomeWorkNumber)
		{
		case 1:
			HomeWork1::Array2D();
			break;
		case 2:
			HomeWork2::VendingMachine();
			break;
		case 3:
			HomeWork3::OddEvenNumberGame();
			break;
		case 4:
			HomeWork4::RockPaperScissorsGame();
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
	return;
}