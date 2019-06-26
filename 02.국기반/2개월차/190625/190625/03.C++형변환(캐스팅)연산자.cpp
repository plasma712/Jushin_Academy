#include <iostream>

using namespace std;

void main()
{
	// ##1. const_cast
	// const 타입 포인터나 래퍼런스에 대해 사용하는 형변환 연산자.

	// int a = 100;
	// const int* ptr = &a;
	// cout << a << endl;
	// // int* ptr2 = ptr; // error
	// int* ptr2 = const_cast<int*>(ptr); // ok
	// 
	// *ptr2 = 200;
	// cout << a << endl;

	// const int a = 100;
	// const_cast<int>(a) = 200; // error



	// ##2. reinterpret_cast
	// 형변환 대상이 포인터나 래퍼런스이다. 강제 형변환을 허용.

	int a = 100;

	float* ptr = reinterpret_cast<float*>(&a);
}