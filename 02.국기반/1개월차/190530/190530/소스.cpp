#include <iostream> 

using namespace std;

int Add(int a, int b);
void PrintHello();

void main()
{
	// ##1. 함수 포인터
	// 함수의 이름은 함수 코드가 등록되어있는 메모리 영역상의 주소를 의미한다.
	// 함수이름이 곧 포인터이다.

	// cout << Add << endl;
	// Add(10, 20);
	

	// ##2. 함수 포인터 타입.
	// 반환타입(*변수명)(매개변수타입)
	int(*ptr)(int, int) = Add;
	void(*ptr2)() = PrintHello;


	int iResult = ptr(10, 20);
	cout << iResult << endl;
	ptr2();

	return;
}

int Add(int a, int b)
{
	return a + b;
}

void PrintHello()
{
	cout << "Hello" << endl;
}