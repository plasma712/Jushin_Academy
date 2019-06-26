#include <iostream>

using namespace std;

// ##1. 래퍼런스 (C++ 문법)
// 직접 참조 , 메모리에 별칭을 부여

void Swap(int& _a, int& _b)
{
	int itemp = _a;
	_a = _b;
	_b = itemp;
}

void main()
{
	// ##2. 래퍼런스 선언.
	// int a = 10; // 변수
	// int& r = a; // 래퍼런스 선언. a변수에 r이라는 또다른 별칭을 부여
	// 
	// r = 200;	// a 변수에 접근하는 것과 동일한 효과. 직접참조.
	// cout << a << endl;
	// cout << "--------------------" << endl;
	// 
	// // 결국 a와 r은 같은 공간이다.
	// cout << &a << endl;
	// cout << &r << endl;


	// ##3. 래퍼런스의 특징
	// 포인터와 달리 별도의 메모리가 필요없다. 값 복사가 아니다.
	// int& r = nullptr;	// 포인터처럼 null초기화 불가. error
	// int& r; // error 선언과 동시에 참조 대상이 필요.

	// int a = 100, b = 200;
	// int& r = a;

	// 래퍼런스는 참조 대상을 변경할 수 없다.
	// r = b;
	// cout << a << endl;

	// ##4. call by reference
	// int a = 10, b = 20;
	// 
	// Swap(a, b);
	// 
	// cout << a << " , " << b << endl;

	// // ##5. 래퍼런스와 const
	// const int a = 300;
	// // int& r = a; // error
	// const int& r = a; // ok

	/////////////////////////////////////////////////////////

	// 리터널 상수를 참조하려면 const 래퍼런스여야 한다.
	const int& r = 100; // 100의 임시공간은 'r' 이라는 const 변수가 되었다.



	system("pause");
	return;
}