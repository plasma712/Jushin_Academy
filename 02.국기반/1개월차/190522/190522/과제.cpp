// 과제 1. 길이가 25개짜리인 배열을 이용하여 다음과 같이 출력하라!

/*
		1	2	3	4	5
		6	7	8	9	10
		11	12	13	14	15
		16	17	18	19	20
		21	22	23	24	25
*/


// 과제 2. 숫자 야구 게임
// 1. 컴퓨터는 1 ~ 9 중 난수 3개를 중복되지 않게 뽑는다.
// 2. 사용자는 이 3개의 숫자를 맞추는 게임.
// 3. 사용자는 3개의 수를 중복없이 입력 할 수 있다.

// ex) 컴퓨터가 뽑은 난수 1 2 3
//	   사용자가 입력한 값 1 3 2
//     결과 : 1스트라이크 2볼;


// 과제.3 로또 제작.
// 1. 1 ~ 45 숫자 중 6개를 랜덤하게 뽑는다.
// 2. 뽑은 6개의 숫자들 중 중복된 값이 없어야 한다.
// 3. 뽑은 6개의 숫자를 오름차순 정렬.


// 과제.4 빙고게임 제작.
// 1. 과제.1처럼 숫자판 생성. 이 숫자판의 숫자들은 섞여있어야 함.
// 2. 사용자가 선택한 숫자는 0으로 교체.
// 3. 가로, 세로, 대각선 합이 5줄 되면 빙고 완성.

#include <iostream>
#include <time.h>

using namespace std;

namespace homework1
{
	void Array25() // 과제 1
	{
		int array[25] = {};

		for (int k = 1; k < 26; k++)
		{
			array[k - 1] = k;
		}

		for (int k = 0; k < 25; k++)
		{
			if (k % 5 == 0)
			{
				cout << endl;
			}
			cout << array[k] << "\t";
		}
		system("pause");
	}
}

namespace homework2
{
	int iSaveNumber = 0;
	int iComRandomNumber[3] = {};
	int iCheckNumber = 3;

	int iUserNumber[3] = {};
	int iStrike = 0, iBall = 0, iOut = 0;


	void RandomNumber()
	{
		unsigned int iSeed = time(nullptr);
		srand(iSeed);
	}

	int NumberBaseball_RandomNumber()
	{
		int iRandomNumber = rand() % 9 + 1; // 0 ~ 8 랜덤이니 + 1 해주어 1 ~ 9 사이가 되도록
		iSaveNumber = iRandomNumber;
		return iSaveNumber;
	}

	void InsertNumber(int _iRandomNumber)
	{
		for (int k = 0; k < 3; k++)
		{
			if (iComRandomNumber[k] == 0)
			{
				iComRandomNumber[k] = _iRandomNumber;
				iCheckNumber--;
				break;
			}
			if (iComRandomNumber[k] == _iRandomNumber)
			{
				break;
			}
		}
	}
	void UserNumber()
	{
		int i = 0, j = 0, k = 0;

	A:
		cout << "--------야구게임--------" << endl;
		cout << "[1] : ";
		cin >> i;
		system("cls");
		if (i < 1 || i > 9)
		{
			goto A;
		}
	B:
		cout << "컴퓨터에서 뽑은 숫자 : " << iComRandomNumber[0] << "\t" << iComRandomNumber[1] << "\t" << iComRandomNumber[2] << endl;
		cout << "--------야구게임--------" << endl;
		cout << "[2] : ";
		cin >> j;
		system("cls");
		if (i < 1 || i > 9)
		{
			goto B;
		}
	C:
		cout << "컴퓨터에서 뽑은 숫자 : " << iComRandomNumber[0] << "\t" << iComRandomNumber[1] << "\t" << iComRandomNumber[2] << endl;
		cout << "--------야구게임--------" << endl;
		cout << "[3] : ";
		cin >> k;
		system("cls");
		if (i < 1 || i > 9)
		{
			goto C;
		}

		iUserNumber[0] = i;
		iUserNumber[1] = j;
		iUserNumber[2] = k;
	}

	void AnswerChecking()
	{
		iStrike = 0, iBall = 0, iOut = 0;

		for (int k = 0; k < 3; k++)
		{
			for (int i = 0; i < 3; i++)
			{
				if (iComRandomNumber[k] == iUserNumber[i])
				{
					if (k == i)
					{
						iStrike++;
					}
					else
					{
						iBall++;
					}
				}
			}
		}
		iOut = 3 - (iStrike + iBall);
	}


	void NumberBaseballGame()
	{
		while (iCheckNumber > 0) // 컴퓨터에서 랜덤값 만들고 빠져나옴;
		{
			RandomNumber();
			InsertNumber(NumberBaseball_RandomNumber());
		}
		while (iStrike < 3)
		{
			system("cls");
			cout << "컴퓨터에서 뽑은 숫자 : " << iComRandomNumber[0] << "\t" << iComRandomNumber[1] << "\t" << iComRandomNumber[2] << endl;
			UserNumber();
			AnswerChecking();
			cout << "--------야구게임--------" << endl;
			cout << "스트라이크 : " << iStrike << "\t" << "볼 : " << iBall << "\t" << "아웃 : " << iOut << endl;
			system("pause");
		}
	}

}

namespace homework3
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

namespace homework4
{
	// 대각선은 단 2경우 + [0] [6] ... +6씩
	//				       [4] [8] ... +4씩

	// 가로는 [0] [5] [10] [15] [20] 기준으로 ~
	// 세로는 [0]~[4]를 기준으로 +5씩

	int iSaveNumber = 0;
	int iCheckNumber = 25;
	int iBingo[25] = {};
	int iBingoComplete = 0;
	int iBingoCompleteSave = 0;

	void RandomNumber()
	{
		unsigned int iSeed = time(nullptr);
		srand(iSeed);
	}

	int Bingo_RandomNumber()
	{
		int iRandomNumber = rand() % 25;//+ 1; // 0 ~ 24 랜덤이니 + 1 해주어 1 ~ 25 사이가 되도록
		iSaveNumber = iRandomNumber;
		//cout << iRandomNumber;
		return iSaveNumber;
	}

	void InsertBingo(int _iRandomNumber)
	{
		for (int k = 0; k < 25; k++)
		{
			if (iBingo[k] == 0)
			{
				iBingo[k] = _iRandomNumber;
				iCheckNumber--;
				break;
			}
			if (iBingo[k] == _iRandomNumber)
			{
				break;
			}
		}
	}

	void InsertBingoBasic()
	{
		for (int k = 0; k < 25; k++)
		{
			iBingo[k] = k + 1;
		}
	}

	void InsertBingo_Revise()
	{
		int iRandomNumberA = 0;
		int iRandomNumberB = 0;
		int iTemp = 0;

		for (int k = 0; k < 5000; k++)
		{
			Bingo_RandomNumber();
			iRandomNumberA = rand() % 25;
			iRandomNumberB = rand() % 25;

			iTemp = iBingo[iRandomNumberA];
			iBingo[iRandomNumberA] = iBingo[iRandomNumberB];
			iBingo[iRandomNumberB] = iTemp;
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
		for (int k = 0; k < 25; k++)
		{
			if (k % 5 == 0)
			{
				cout << endl;
			}
			cout << iBingo[k] << "\t";
		}
	}

	void BingoNumberCheck(int _iBingoNumber)
	{
		for (int i = 0; i < 25; i++)
		{
			if (iBingo[i] == _iBingoNumber)
			{
				iBingo[i] = 0;
				break;
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
	// homework1::Array25();
	// homework2::NumberBaseballGame();
	// homework3::Lotto();
	// homework4::Bingo();
	return;
}