#include <iostream>

using namespace std;

// ##1. 재귀 함수
// 자기 자신을 호출하는 함수
// 탈출 조건이 없다면 Stack overflow 현상이 일어난다.
// 재귀함수를 다룰 때 반드시 탈출 조건이 있어야한다.
// 코드가 간결해진다.
// 깊이를 알 수 없는 상황(얼마나 반복될지 모르는 상황)에 적절.


// 탈출조건이 없는 재귀함수.
void Recursive()
{
	cout << "Hello" << endl;

	Recursive(); // 재귀 호출
}

void Recursive_Two(int _n)
{
	if (_n == 0)
		return;

	cout << "Hello" << endl;
	Recursive_Two(_n - 1);
}

// 팩토리얼 (순차곱)
// 3! = 3 * 2 * 1
// 5! = 5 * 4 * 3 * 2 * 1
// N! = N * N-1 * N-2 * N-3 *---* 1

// 재귀함수를 이용한 팩토리얼
int Factorial_(int n)
{
	if (1 == n)
		return n;

	return n * Factorial_(n - 1);
}


// 내가만든.
void Factorial(int _iNum)
{
	static int k = 1;

	if (_iNum == 0)
	{
		cout << k << endl;
		return;
	}

	k *= _iNum;
	
	Factorial(_iNum-1);
}

void main()
{
	// 탈출 조건이 없는 재귀함수
	// Recursive();

	// 재귀함수는 탈출 조건이 있어야 한다.
	// Recursive_Two(3);
	Factorial(6);
	return;
}