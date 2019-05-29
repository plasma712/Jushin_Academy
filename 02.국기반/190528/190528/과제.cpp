
// 과제 1.
// iA와 iB의 값을 맞교환하는 Swap함수를 작성하라.
// int iA = 10, iB = 20;
// 
// Swap();
// 
// cout << iA << ", " << iB << endl;

// 과제 2.
// 자판기 모든 반환값이 void가 되게 하라.


#include <iostream>

using namespace std;
namespace HomeWork2
{
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
	cout << "입력 A 값 : ";
	cin >> A;
	cout << "입력 B 값 : ";
	cin >> B;
	Swap(&A,&B);
	cout << "A 값 : " << A <<" , "<< "B 값 : " << B << endl;

	system("pause");
	system("cls");
	HomeWork2::VendingMachine();

	return;
}
