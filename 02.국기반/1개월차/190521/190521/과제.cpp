//
//	과제 1. 자판기 프로그램 작성하기
//			a. 돈 투입.
//			b. 메뉴 보여주기 및 선택.
//			C. 구매(선택한 메뉴의 가격만큼 소지금 차감) 또는 구매 거절(소지금 부족).
//			d. 사용자가 잔돈반환 메뉴를 선택할 때까지는 자판기 프로그램은 반복 진행.
//			e. 사용자가 잔돈반환 메뉴를 선택하면 현재 남은 거스름돈을 출력하고 종료.
//
//
//	과제 2. 홀짝 게임 프로그램 작성하기.
//			a. 게임을 시작하면 1 ~ 10 사이의 난수를 뽑는다. (프로그램 상단에 노출)
//			b. 뽑은 난수가 홀인지 짝인지 맞추는 게임.
//			c. 총 3라운드 진행. 게임이 종료될 때 x승 y패 출력.
//
//
//	과제 3. 가위 바위 보 게임 프로그램 작성하기.
//			a. 컴퓨터와 가위바위보하여 승리하는 게임.
//			b. 총 3라운드 진행. 게임이 종료 될 때 x승 y무 z패 출력.
//
//
//	과제 4. 다음과 같이 *을 출력하라. (for문을 이용하여)
//
//			a. *
//			   **
//			   ***
//			   ****
//			   *****
//
//
//	과제 5. 다음과 같이 *을 출력하라. (for문을 이용하여)
//
//			a. *****
//			   ****
//			   ***
//			   **
//			   *
//
//
//	과제 6. 다음과 같이 *을 출력하라. (for문을 이용하여)
//
//			a.			*
//					   **
//					  ***
//					 ****
//					*****
//
//
//	과제 7. 다음과 같이 *을 출력하라. (for문을 이용하여)
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

// 과제 1. 자판기 프로그램 작성하기

// a.돈 투입.
// b.메뉴 보여주기 및 선택.
// C.구매(선택한 메뉴의 가격만큼 소지금 차감) 또는 구매 거절(소지금 부족).
// d.사용자가 잔돈반환 메뉴를 선택할 때까지는 자판기 프로그램은 반복 진행.
// e.사용자가 잔돈반환 메뉴를 선택하면 현재 남은 거스름돈을 출력하고 종료.

// 전역변수
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
		cout << "5. 콜라 제로 : 900원" << "\t" << "6. 종료 " << endl;
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
			break;
		}
	}
}
void VendingMachine() // 자판기 메인함수
{
	MoneyInput();
	Menu();
}


// 과제 2. 홀짝 게임 프로그램 작성하기.

// a.게임을 시작하면 1 ~10 사이의 난수를 뽑는다. (프로그램 상단에 노출)
// b.뽑은 난수가 홀인지 짝인지 맞추는 게임.
// c.총 3라운드 진행.게임이 종료될 때 x승 y패 출력.

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
				cout << _iSaveNumber << endl;
				cout << "정답을 맞추었습니다. " << endl;
				iWin++;
				system("pause");
				break;
			}
			else
			{
				cout << _iSaveNumber << endl;
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
}


//	과제 3. 가위 바위 보 게임 프로그램 작성하기.

//	a. 컴퓨터와 가위바위보하여 승리하는 게임.
//	b. 총 3라운드 진행. 게임이 종료 될 때 x승 y무 z패 출력.

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
				cout << _iSaveNumber << endl;
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
						cout << _iSaveNumber << endl;
						cout << "졌습니다. " << endl;
						iLose++;
						system("pause");
						break;
					}
					else if (_iSaveNumber == 2)
					{
						cout << _iSaveNumber << endl;
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
						cout << _iSaveNumber << endl;
						cout << "졌습니다. " << endl;
						iLose++;
						system("pause");
						break;
					}
					else if (_iSaveNumber == 0)
					{
						cout << _iSaveNumber << endl;
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
						cout << _iSaveNumber << endl;
						cout << "졌습니다. " << endl;
						iLose++;
						system("pause");
						break;
					}
					else if (_iSaveNumber == 1)
					{
						cout << _iSaveNumber << endl;
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


}


// 과제 4,5,6,7

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
		cout << "과제 선택 (보기 1, 2, 3, 4, 5, 6, 7 ) / 종료 : 0 " << endl;
		cout << "선택 : ";
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
}

void main()
{
	HomeWorkSelect();
	return;
}