#include <iostream> 
#include <time.h>
using namespace std;

namespace homework4
{
	// 대각선은 단 2경우 + [0] [6] ... +6씩
	//				       [4] [8] ... +4씩

	// 가로는 [0] [5] [10] [15] [20] 기준으로 ~
	// 세로는 [0]~[4]를 기준으로 +5씩

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
		int iRandomNumber = rand() % 5;//+ 1; // 0 ~ 24 랜덤이니 + 1 해주어 1 ~ 25 사이가 되도록
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
		cout << "현재 빙고 갯수 : " << BingoCompleteSave(iBingoComplete) << endl;
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

	void Horizon() 	// 가로는 [0] [5] [10] [15] [20] 기준으로 ~
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

	void Vertical() // 세로는 [0]~[4]를 기준으로 +5
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

	// 대각선은 단 2경우 + [0] [6] ... +6씩
	// [4] [10]... +6씩
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

		//while (iCheckNumber > 0) // 컴퓨터에서 랜덤값 만들고 빠져나옴;
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
			cout << "빙고 번호 : ";
			cin >> iBingoNumber;
			BingoNumberCheck(iBingoNumber);
			system("cls");
			ArrayCout();
			cout << endl;
			//여기서 카운팅
			//Horizon();
			//Vertical();
			//Diagonal();
			BingoCompleteSave(iBingoComplete);
			//
			system("cls");
		}
		cout << "빙고 완료" << endl;


	}
}


void main()
{
	// ##1. N차원 배열

	// 1차원 배열
	// int iArr[5] = {};
	// 
	// // 2차원 배열
	// int iArr2D[2][5] = {};
	// 
	// // 3차원 배열
	// int iArr3D[3][4][5] = {};


	// ##2. 2차원 배열

	int iArr2D[2][5] =
	{		// 열
		{10,20,30,40,50}, // 행 
		{60,70,80,90,100}
	};

	//[행],[열]
	//cout << iArr2D[1][3] << endl;

	// 2차원 배열도 배열이므로 연속된 공간을 갖기 떄문에 아래와 같이 초기화 가능.
	int iArr2D_2[2][5] = { 10,20,30,40,50,60,70,80,90,100 };

	//22일 과제 빙고

	homework4::Bingo();




	return;
}