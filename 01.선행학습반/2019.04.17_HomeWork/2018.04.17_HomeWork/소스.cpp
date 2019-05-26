#include <iostream>
using namespace std;
/* 자판기
void main()
{
	// 자판기
	int iSider = 200, iCoke = 300, iSol = 900;
	int iCash = 0;
	int iSelect = 0;
	while (true)
	{
		cout << "금액을 입력 하시오 ! : " << endl;
		cin >> iCash;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(64, '\n');

			cout << "배드" << endl;
		}
		if (0 >= iCash)
			continue;

		break;
	}
	while (true)
	{
		//system 함수
		system("cls");
		cout << "1.콜라 (300원), 2.사이다(200원), 3.솔의눈(900원), 4.종료" << endl;

		cin >> iSelect;

		if (4 == iSelect)
			break;

		switch (iSelect)
		{
		case 1:
			if (iCoke > iCash)
			{
				cout << "그지새끼" << endl;
				break;
			}
			iCash -= iCoke;
			cout << "감사합니다. 남은 잔액은 :  " << iCash << " 입니다." << endl;
			break;
		case 2:
			if (iSider > iCash)
			{
				cout << "그지새끼" << endl;
				break;
			}
			iCash -= iSider;
			cout << "감사합니다. 남은 잔액은 :  " << iCash << " 입니다." << endl;

			break;
		case 3:
			if (iSol > iCash)
			{
				cout << "그지새끼" << endl;
				break;
			}
			iCash -= iSol;
			cout << "감사합니다. 남은 잔액은 :  " << iCash << " 입니다." << endl;

			break;
		default:
			break;
		}
		system("pause");
	}
	cout << "거스름돈은 : " << iCash << "입니다. " << endl;

}
*/

void main()
{
	int iPlayerHp = 100, iPlayerAtt = 5;
	int iMonsterHp = 30, iMonsterAtt = 5;
	int iSelect = 0;

UP:
	cout << "PlayerHp: " << iPlayerHp << endl;
	cout << "iMonsterHp: " << iMonsterHp << endl;
	cout << "1.공격, 2.도망" << endl;

	cin >> iSelect;

	switch (iSelect)
	{
	case 1:
		iPlayerHp -= iMonsterAtt;
		iMonsterHp -= iPlayerAtt;
		break;
	case 2:
		break;
	default:
		cout << "잘못누름" << endl;
		break;
	}
	if (0 >= iPlayerHp)
	{
		cout << "사망..." << endl;
	}
	if (0 >= iMonsterHp)
	{
		cout << "사냥 성공." << endl;
		goto DOWN;
	}
	goto UP;
DOWN:
}