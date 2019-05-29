#include <iostream>

using namespace std;

// 전역 변수
// 어떠한 { } 내에 선언된 변수가 아닌 외부에 선언된 변수.
// 지역에 상관 없이 전역적으로 접근할 수 있다.

int iEx = 0;

void main()
{
	iEx = 100;

	cout << iEx << endl;
	return;
}