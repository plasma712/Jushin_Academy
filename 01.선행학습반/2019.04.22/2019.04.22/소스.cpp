#include <iostream>
using namespace std;

int iTest = 0;			// 전역변수
static int iStatic = 0; // 지역변수


// 반환값 함수명(인자 혹은 파라미터 혹은 매개변수)
// {  // 함수 몸체
// 	  // 코드 블록
// }

int Add(int _iNum1, int _iNum2)
{
	//int Sum = 0;
	//Sum = _iNum1 + _iNum2;
	//return Sum;
	return _iNum1 + _iNum2;
}

void TestFunc() // static으로 호출하기 때문에 초기화는 처음 함수 호출했을 때 단 한번만 됨 /
{
	static int iTestStatic = 0;
	iTestStatic++;
	cout << iTestStatic << endl;
}

void main()
{
	//int iTotal = Add(10, 20);
	//cout << iTotal << endl;

	//TestFunc();
	//TestFunc();
	//TestFunc();

	cout << &iTest << endl;
	int iTest = 99;
	cout << &iTest << endl;
}

/*
	Code - 정수. 제어문

	Stack - 지역변수(함수의 시작과 끝)

	Heap - 동적할당

	Data - 전역변수, 정적변수
*/