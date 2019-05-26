#include <iostream>

using namespace std;

// ##1. 함수 오버로딩
// 같은 이름으로 함수를 재정의하는 C++ 문법이다.
// 프로그래밍을 좀 더 유연하게 작성 도와주는 문법이다.

// void Print() // 함수 오버로딩은 반환타입으로 구분하는 문법이 아니다!
// {
// 	cout << "Hello" << endl;
// }
// 
// float Print() // 재정의 error!
// {
// 	cout << "World" << endl;
// }

int Add(int a, int b)
{
	return a + b;
}

int Add(int a, int b,int c)
{
	return a + b + c;
}

float Add(float a, float b)
{
	return a + b;
}



void main()
{
	// 함수 오버로딩은 같은 이름의 함수를 매개변수로 구분한다.
	// cout << Add(3.14f,10.f) << endl;

	// 함수 오버로딩은 매개변수 개수로도 구분한다.
	cout << Add(1, 2, 3) << endl;

	return;
}