#include <iostream>
using namespace std;

void main()
{
	// ##1. 분기문 (if문, switch문, goto문)
	// 조건에 따라 프로그램의 흐름을 나누는 문법.


	// ##2. if문
	// if의 조건이 참일 때 실행하는 문법.

	/*
		if(조건)
		{
			조건을 만족할 때 실행하는 코드
		}
	*/

	// if (-3) // 0이 아닌 모든 수는 true이다.
	// {
	// 	cout << "Hello" << endl;
	// }

	// if (false) // 조건이 거짓일때 { } 안에 코드는 실행되지 않는다.
	// {
	// 	cout << "World" << endl;
	// }

	// if ~else
	// else는 반드시 if와 짝을 이루어야 한다.
	// 흑백논리
	// 하나의 if에는 둘 이상의 else가 따라 붙을 수 없다.

	// if (true)
	// {
	// 	cout << "Hello" << endl;
	// }
	// else
	// {
	// 	cout << "world" << endl;
	// }

	// int iSelect = 0;
	// 
	// cout << "입력: ";
	// cin >> iSelect;
	// 
	// if (1 == iSelect)
	// {
	// 	cout << "1은 콜라 " << endl;
	// }
	// else if (2 == iSelect)
	// {
	// 	cout << "핫식스" << endl;
	// }
	// else if (3 == iSelect)
	// {
	// 	cout << "환타 " << endl;
	// }
	// else
	// 	cout << "사이다 ." << endl;

	return;
}