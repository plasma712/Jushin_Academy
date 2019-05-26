// 일반삼각형, 뒤집은 삼각형


#include <iostream>
using namespace std;

void NormalTri(int _iHeight)
{
	for (int i = _iHeight; i > 0; i--)
	{
		for (int k = i; k <= _iHeight; k++)
		{
			cout << "*";
		}
		cout << endl;
	}
}
void ReverseTri(int _iHeight)
{
	for (int i = 0; i < _iHeight; i++)
	{
		for (int k = i; k < _iHeight; k++)
		{
			cout << "*";
		}
		cout << endl;
	}
}

void main()
{
	while (true)
	{
		system("cls");
		int iSelectNum = 0;
		cout << "원하시는 숫자를 입력 해주세요.(일반삼각형 : 1 / 역삼각형 : 2 / 종료 : 3) : ";
		cin >> iSelectNum;
		switch (iSelectNum)
		{
			int iHeight;
		case 1:
			cout << "삼각형의 높이를 입력해주세요. : ";
			cin >> iHeight;
			cout << endl;
			NormalTri(iHeight);
			break;
		case 2:
			cout << "삼각형의 높이를 입력해주세요. : ";
			cin >> iHeight;
			cout << endl;
			ReverseTri(iHeight);
			break;
		default:
			goto END;
			break;
		}
		cout << endl;
		system("pause");
	}
END:
	cout << "종료" << endl;
	return;
}