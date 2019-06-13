// ���� 1. �ζǸ� �Լ��� �ۼ�
// ���� 2. ������� �Լ��� �ۼ� (2�����迭)

#include <iostream>
#include <time.h>
using namespace std;

namespace homework1
{
	int iSaveNumber = 0;
	int iCheckNumber = 6;
	int iLottoNumber[6] = {};

	void RandomNumber()
	{
		unsigned int iSeed = time(nullptr);
		srand(iSeed);
	}

	int LottoNumber_RandomNumber()
	{
		int iRandomNumber = rand() % 45;// +1; // 0 ~ 44 �����̴� + 1 ���־� 1 ~ 45 ���̰� �ǵ���
		iSaveNumber = iRandomNumber;
		//cout << iRandomNumber;
		return iSaveNumber;
	}

	void InsertLotto(int _iRandomNumber)
	{
		for (int k = 0; k < 6; k++)
		{
			if (iLottoNumber[k] == 0)
			{
				iLottoNumber[k] = _iRandomNumber;
				iCheckNumber--;
				break;
			}
			if (iLottoNumber[k] == _iRandomNumber)
			{
				break;
			}
		}
	}

	void LottoNumberBasic()
	{
		for (int k = 0; k < 45; k++)
		{
			iLottoNumber[k] = k + 1;
		}
	}

	void InsertLotto_Revise()
	{
		RandomNumber();
		int _iRandomNumberA = 0;
		int _iRandomNumberB = 0;
		int iTemp = 0;
		for (int k = 0; k < 5000; k++)
		{
			int _iRandomNumberA = rand() % 45;
			int _iRandomNumberB = rand() % 45;

			iTemp = iLottoNumber[_iRandomNumberA];
			iLottoNumber[_iRandomNumberA] = iLottoNumber[_iRandomNumberB];
			iLottoNumber[_iRandomNumberB] = iTemp;
		}
	}

	void ArraySort()
	{

		//3  6  4  2  1  5
		//3  4  6  2  1  5
		//3  4  2  6  1  5
		//3  4  2  1  6  5
		//3  4  2  1  5  6
		//3  2  4  1  5  6
		//3  2  1  4  5  6
		//2  3  1  4  5  6
		//2  1  3  4  5  6
		//1  2  3  4  5  6

		int temp = 0;

		for (int i = 0; i < 6; i++)
		{
			for (int k = 0; k < 6 - i - 1; k++)
			{
				if (iLottoNumber[k] > iLottoNumber[k + 1])
				{
					temp = iLottoNumber[k];
					iLottoNumber[k] = iLottoNumber[k + 1];
					iLottoNumber[k + 1] = temp;
				}
			}
		}

	}

	void ArrayCout()
	{
		cout << "�ζ� ��ȣ :" << "\t";
		for (int k = 0; k < 6; k++)
		{
			cout << iLottoNumber[k] << "\t";
		}
	}

	void Lotto()
	{
		//while (iCheckNumber > 0) // ��ǻ�Ϳ��� ������ ����� ��������;
		//{
		//	RandomNumber();
		//	InsertLotto(LottoNumber_RandomNumber());
		//}
		system("cls");
		LottoNumberBasic();
		InsertLotto_Revise();
		//cout << "<���� �� > "; ArrayCout();
		cout << endl;
		ArraySort();
		//cout << "<���� �� > "; ArrayCout();
		ArrayCout();
	}

	void Test()
	{
		//iLottoNumber[0]= 3  6  4  2  1  5
		iLottoNumber[0] = 3;
		iLottoNumber[1] = 6;
		iLottoNumber[2] = 4;
		iLottoNumber[3] = 2;
		iLottoNumber[4] = 1;
		iLottoNumber[5] = 5;

		ArrayCout();
		cout << endl;
		ArraySort();
		cout << endl;
		ArrayCout();
	}
}

namespace homework2_R
{
	int iSaveNumber = 0;
	int iBingo[5][5] = {};
	int iBingoCompleteSave = 0;
	int iBingoComplete = 0;

	void RandomNumber()
	{
		unsigned int iSeed = time(nullptr);
		srand(iSeed);
	}

	void InsertBingoBasic()
	{
		for (int i = 0; i < 5; i++)
		{
			for (int k = 0; k < 5; k++)
			{
				iBingo[i][k] = i * 5 + (k + 1);
			}
		}
	}
	//int Bingo_RandomNumber()
	//{
	//	int iRandomNumber = rand() % 25;//+ 1; // 0 ~ 24 �����̴� + 1 ���־� 1 ~ 25 ���̰� �ǵ���
	//	iSaveNumber = iRandomNumber;
	//	//cout << iRandomNumber;
	//	return iSaveNumber;
	//}

	void InsertBingoRandom()
	{
		int iRandomNumberA1 = 0;
		int iRandomNumberA2 = 0;
		int iRandomNumberB1 = 0;
		int iRandomNumberB2 = 0;

		int iTemp = 0;

		//Bingo_RandomNumber();
		RandomNumber();
		for (int k = 0; k < 1000; k++)
		{
			//RandomNumber();
			iRandomNumberA1 = rand() % 5;
			iRandomNumberA2 = rand() % 5;

			iRandomNumberB1 = rand() % 5;
			iRandomNumberB2 = rand() % 5;

			iTemp = iBingo[iRandomNumberA1][iRandomNumberA2];
			iBingo[iRandomNumberA1][iRandomNumberA2] = iBingo[iRandomNumberB1][iRandomNumberB2];
			iBingo[iRandomNumberB1][iRandomNumberB2] = iTemp;
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
		for (int i = 0; i < 5; i++)
		{
			for (int k = 0; k < 5; k++)
			{
				cout << iBingo[i][k] << "\t";
			}
			cout << endl;
		}
	}

	void BingoNumberCheck(int _iBingoNumber)
	{
		for (int i = 0; i < 5; i++)
		{
			for (int k = 0; k < 5; k++)
			{
				if (iBingo[i][k] == _iBingoNumber)
				{
					iBingo[i][k] = 0;
				}
			}
		}
	}

	void Horizon()
	{
		int iHorizonNumber = 0;
		while (iHorizonNumber < 5)
		{
			for (int i = 0; i < 5; i++)
			{
				if (iBingo[iHorizonNumber][i] != 0)
				{
					break;
				}
				if (i == 4)
				{
					iBingoComplete++;
				}
			}
			iHorizonNumber += 1;
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
					if (iBingo[i][k] != 0)
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

	void Diagonal()
	{
		for (int k = 0; k < 5; k++)
		{
			if (iBingo[k][k] != 0)
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
			if (iBingo[k][4 - k] != 0)
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

		InsertBingoBasic();
		InsertBingoRandom();

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
			Horizon();
			Vertical();
			Diagonal();
			BingoCompleteSave(iBingoComplete);
			//
			system("cls");
		}
		cout << "���� �Ϸ�" << endl;


	}

}

void main()
{
	//homework1::Lotto();
	homework2_R::Bingo();
	return;
}