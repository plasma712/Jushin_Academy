/*
	// 과제 1.
	// 2차원 배열을 이용하여 다음과 같이 회전시켜라

	1 2 3						7 4 1
	4 5 6	시계방향 90도 ->    8 5 2
	7 8 9						9 6 3

	// 과제 2.
	// 자판기, 홀짝, 가위바위보를 함수로 구현해와라.

*/

#include <iostream> 
#include <time.h>
#include <string>
using namespace std;

// 이중배열 회전
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
			cout << "[회전 하기] 1. 왼쪽  2.오른쪽  0.종료" << endl;
			cout << "번호를 입력하시오 : ";
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
			cout << "회전 결과 " << endl;
			CoutArray2D();
			system("pause");
			system("cls");
		}
	}

}
// 자판기
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
	void MoneyInput() // 돈 투입
	{
		while (true)
		{
			iMoney = 0;
			cout << "돈을 투입해주십시오 : ";
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
			cout << "정상적으로 구매가 되었습니다. " << endl;
			system("pause");
		}
		else
		{
			cout << "잔돈이 부족합니다. 다시 선택해주세요." << endl;
			system("pause");
		}
	}
	void Menu() // 메뉴
	{
		int iMenu = 0;
		while (true)
		{
			system("cls");
			cout << "물건을 골라주세요." << "\t" << "현재 잔액 : " << iMoney << "원" << endl;
			cout << endl;
			cout << "1. 콜라 : 500원 " << "\t" << "2. 사이다 : 600원" << "\t" << endl;
			cout << "3. 환타(포도) : 700원" << "\t" << "4. 환타(오렌지) : 800원" << "\t" << endl;
			cout << "5. 콜라 제로 : 900원" << "\t" << "6. 잔돈반환 " << endl;
			cout << "선택 : ";

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
				cout << "남은 잔돈은 : " << iMoney << "입니다." << endl;
				system("pause");
				break;
			}
		}
	}
	void VendingMachine() // 자판기 메인함수
	{
		system("cls");
		MoneyInput();
		Menu();
	}
}
// 홀 짝 게임
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
			cout << "홀수 일지 짝수 일지 선택해주세요. " << endl;
			cout << "홀수 : 1 , 짝수 : 2 " << " = ";
			cin >> iSelect;
			cout << endl;

			if (iSelect == 1 || iSelect == 2)
			{

				if (iSelect == iOddEvenNumber)
				{
					cout<<"컴퓨터가 선택한 수 : " << _iSaveNumber << endl;
					cout << "정답을 맞추었습니다. " << endl;
					iWin++;
					system("pause");
					break;
				}
				else
				{
					cout << "컴퓨터가 선택한 수 : " << _iSaveNumber << endl;
					cout << "정답을 틀리셨습니다. " << endl;
					iLose++;
					system("pause");
					break;
				}
			}
			else
			{
				cout << "다시 입력해주세요." << endl;
				system("pause");
			}
		}
	}

	void Entirely(int _iWin, int _iDraw, int _iLose)
	{
		system("cls");
		if (_iDraw == 0)
			cout << "승 : " << _iWin << "\t" << "패 : " << _iLose << endl;
		else
			cout << "승 : " << _iWin << "\t" << "무 : " << iDraw << "\t" << "패 : " << _iLose << endl;
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
// 가위바위보
namespace HomeWork4
{
	int iSaveNumber = 0;
	int iWin = 0, iDraw = 0, iLose = 0;

	string chRockPaperScissor[3] = { "가위","바위","보" };

	void RandomNumber()
	{
		unsigned int iSeed = time(nullptr);
		srand(iSeed);
	}

	void Entirely(int _iWin, int _iDraw, int _iLose)
	{
		system("cls");
		if (_iDraw == 0)
			cout << "승 : " << _iWin << "\t" << "패 : " << _iLose << endl;
		else
			cout << "승 : " << _iWin << "\t" << "무 : " << iDraw << "\t" << "패 : " << _iLose << endl;
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
			cout << "가위 바위 보 선택해주세요 " << endl;
			cout << "가위 : 0 , 바위 : 1 , 보 : 2 " << " = ";
			cin >> iSelect;
			cout << endl;

			if (iSelect == 0 || iSelect == 1 || iSelect == 2)
			{

				if (iSelect == _iSaveNumber)
				{
					cout << "컴퓨터는 : " << chRockPaperScissor[_iSaveNumber] << endl;
					cout << "비겼습니다. " << endl;
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
							cout << "컴퓨터는 : " << chRockPaperScissor[_iSaveNumber] << endl;
							cout << "졌습니다. " << endl;
							iLose++;
							system("pause");
							break;
						}
						else if (_iSaveNumber == 2)
						{
							cout << "컴퓨터는 : " << chRockPaperScissor[_iSaveNumber] << endl;
							cout << "이겼습니다. " << endl;
							iWin++;
							system("pause");
							break;
						}
					}
					else if (iSelect == 1)
					{
						if (_iSaveNumber == 2)
						{
							cout << "컴퓨터는 : " << chRockPaperScissor[_iSaveNumber] << endl;
							cout << "졌습니다. " << endl;
							iLose++;
							system("pause");
							break;
						}
						else if (_iSaveNumber == 0)
						{
							cout << "컴퓨터는 : " << chRockPaperScissor[_iSaveNumber] << endl;
							cout << "이겼습니다. " << endl;
							iWin++;
							system("pause");
							break;
						}
					}
					else
					{
						if (_iSaveNumber == 0)
						{
							cout << "컴퓨터는 : " << chRockPaperScissor[_iSaveNumber] << endl;
							cout << "졌습니다. " << endl;
							iLose++;
							system("pause");
							break;
						}
						else if (_iSaveNumber == 1)
						{
							cout << "컴퓨터는 : " << chRockPaperScissor[_iSaveNumber] << endl;
							cout << "이겼습니다. " << endl;
							iWin++;
							system("pause");
							break;
						}
					}

				}
			}
			else
			{
				cout << "다시 입력해주세요." << endl;
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
		cout << "과제 선택 (보기 1, 2, 3, 4) / 종료 : 0 " << endl;
		cout << "선택 : ";
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
			cout << "프로그램 종료합니다. " << endl;
			system("pause");
			break;
		default:
			cout << "다시 선택 해주세요. " << endl;
			system("pause");
			break;

		}
		if (iHomeWorkNumber == 0)
			break;
	}
	return;
}