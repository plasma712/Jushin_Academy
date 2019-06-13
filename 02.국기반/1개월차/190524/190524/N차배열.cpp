#include <iostream> 
#include <time.h>
using namespace std;

namespace homework4
{
	// �밢���� �� 2��� + [0] [6] ... +6��
	//				       [4] [8] ... +4��

	// ���δ� [0] [5] [10] [15] [20] �������� ~
	// ���δ� [0]~[4]�� �������� +5��

	int iSaveNumber = 0;
	int iCheckNumber = 25;
	int iBingo[5][5] = {};
	int iBingoComplete = 0;
	int iBingoCompleteSave = 0;

	void RandomNumber()
	{
		unsigned int iSeed = time(nullptr);
		srand(iSeed);
	}

	int Bingo_RandomNumber()
	{
		int iRandomNumber = rand() % 5;//+ 1; // 0 ~ 24 �����̴� + 1 ���־� 1 ~ 25 ���̰� �ǵ���
		iSaveNumber = iRandomNumber;
		//cout << iRandomNumber;
		return iSaveNumber;
	}


	void InsertBingoBasic()
	{
		for (int k = 0; k < 5; k++)
		{
			for (int i = 0; i < 5; i++)
			{
				iBingo[k][i] = k * 5 + i + 1;
			}
		}
	}

	void InsertBingo_Revise()
	{
		int iRandomNumberA = 0;
		int iRandomNumberB = 0;
		int iTemp = 0;

		for (int k = 0; k < 500000; k++)
		{
			Bingo_RandomNumber();
			iRandomNumberA = rand() % 5;
			iRandomNumberB = rand() % 5;

			iTemp = iBingo[iRandomNumberA][iRandomNumberB];
			iBingo[iRandomNumberA][iRandomNumberB] = iBingo[iRandomNumberB][iRandomNumberA];
			iBingo[iRandomNumberB][iRandomNumberA] = iTemp;
		}

	}

	int BingoCompleteSave(int _iBingoComplete)
	{
		if (iBingoCompleteSave < _iBingoComplete)
		{
			iBingoCompleteSave = _iBingoComplete;
		}
		return iBingoCompleteSave;
	}

	void ArrayCout()
	{
		cout << "���� ���� ���� : " << BingoCompleteSave(iBingoComplete) << endl;
		for (int k = 0; k < 5; k++)
		{
			for (int i = 0; i < 5; i++)
			{
				cout << iBingo[k][i] << "\t";
			}
			cout << endl;
		}
	}

	void BingoNumberCheck(int _iBingoNumber)
	{
		for (int k = 0; k < 5; k++)
		{
			for (int i = 0; i < 5; i++)
			{
				if (iBingo[k][i] == _iBingoNumber)
				{
					iBingo[k][i] = 0;
					break;
				}
			}
		}
	}

	void Horizon() 	// ���δ� [0] [5] [10] [15] [20] �������� ~
	{
		int iHorizonNumber = 0;
		while (iHorizonNumber < 24)
		{
			for (int i = 0; i < 5; i++)
			{
				if (iBingo[iHorizonNumber + i] != 0)
				{
					break;
				}
				if (i == 4)
				{
					iBingoComplete++;
				}
			}
			iHorizonNumber += 5;
		}
	}

	void Vertical() // ���δ� [0]~[4]�� �������� +5
	{
		//		int iVerticalNumber = 0;
		while (true)
		{
			for (int k = 0; k < 5; k++)
			{
				for (int i = 0; i < 5; i++)
				{
					if (iBingo[k + 5 * i] != 0)
					{
						break;
					}
					if (i == 4)
					{
						iBingoComplete++;
					}
				}
			}
			break;
		}
	}

	// �밢���� �� 2��� + [0] [6] ... +6��
	// [4] [10]... +6��
	void Diagonal()
	{
		for (int k = 0; k < 5; k++)
		{
			if (iBingo[6 * k] != 0)
			{
				break;
			}
			if (k == 4)
			{
				iBingoComplete++;
			}
		}

		for (int k = 0; k < 5; k++)
		{
			if (iBingo[4 + 4 * k] != 0)
			{
				break;
			}
			if (k == 4)
			{
				iBingoComplete++;
			}
		}
	}

	void Bingo()
	{
		system("cls");
		int iBingoNumber = 0;

		//while (iCheckNumber > 0) // ��ǻ�Ϳ��� ������ ����� ��������;
		//{
		//	RandomNumber();
		//	InsertBingo(Bingo_RandomNumber());
		//}
		InsertBingoBasic();
		InsertBingo_Revise();

		while (iBingoComplete < 5)
		{
			iBingoComplete = 0;
			ArrayCout();
			cout << endl;
			cout << "���� ��ȣ : ";
			cin >> iBingoNumber;
			BingoNumberCheck(iBingoNumber);
			system("cls");
			ArrayCout();
			cout << endl;
			//���⼭ ī����
			//Horizon();
			//Vertical();
			//Diagonal();
			BingoCompleteSave(iBingoComplete);
			//
			system("cls");
		}
		cout << "���� �Ϸ�" << endl;


	}
}


void main()
{
	// ##1. N���� �迭

	// 1���� �迭
	// int iArr[5] = {};
	// 
	// // 2���� �迭
	// int iArr2D[2][5] = {};
	// 
	// // 3���� �迭
	// int iArr3D[3][4][5] = {};


	// ##2. 2���� �迭

	int iArr2D[2][5] =
	{		// ��
		{10,20,30,40,50}, // �� 
		{60,70,80,90,100}
	};

	//[��],[��]
	//cout << iArr2D[1][3] << endl;

	// 2���� �迭�� �迭�̹Ƿ� ���ӵ� ������ ���� ������ �Ʒ��� ���� �ʱ�ȭ ����.
	int iArr2D_2[2][5] = { 10,20,30,40,50,60,70,80,90,100 };

	//22�� ���� ����

	homework4::Bingo();




	return;
}