// 과제 1. 로또를 함수로 작성
// 과제 2. 빙고게임 함수로 작성 (2차원배열)

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
		int iRandomNumber = rand() % 45;// +1; // 0 ~ 44 랜덤이니 + 1 해주어 1 ~ 45 사이가 되도록
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
		cout << "로또 번호 :" << "\t";
		for (int k = 0; k < 6; k++)
		{
			cout << iLottoNumber[k] << "\t";
		}
	}

	void Lotto()
	{
		//while (iCheckNumber > 0) // 컴퓨터에서 랜덤값 만들고 빠져나옴;
		//{
		//	RandomNumber();
		//	InsertLotto(LottoNumber_RandomNumber());
		//}
		system("cls");
		LottoNumberBasic();
		InsertLotto_Revise();
		//cout << "<정렬 전 > "; ArrayCout();
		cout << endl;
		ArraySort();
		//cout << "<정렬 후 > "; ArrayCout();
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
	int Bingo_RandomNumber()
	{
		int iRandomNumber = rand() % 25;//+ 1; // 0 ~ 24 랜덤이니 + 1 해주어 1 ~ 25 사이가 되도록
		iSaveNumber = iRandomNumber;
		//cout << iRandomNumber;
		return iSaveNumber;
	}

	void InsertBingoRandom()
	{
		int iRandomNumberA = 0;
		int iRandomNumberB = 0;
		int iTemp = 0;

		RandomNumber();
		for (int k = 0; k < 300; k++)
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
		cout << "현재 빙고 갯수 : " << BingoCompleteSave(iBingoComplete) << endl;
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

	void Vertical() // 세로는 [0]~[4]를 기준으로 +5
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
			cout << "빙고 번호 : ";
			cin >> iBingoNumber;
			BingoNumberCheck(iBingoNumber);
			system("cls");
			ArrayCout();
			cout << endl;
			//여기서 카운팅
			Horizon();
			Vertical();
			Diagonal();
			BingoCompleteSave(iBingoComplete);
			//
			system("cls");
		}
		cout << "빙고 완료" << endl;


	}

}

void main()
{
	homework2_R::Bingo();
	return;
}