#include <iostream>

using namespace std;

void main()
{
	// ##1. const_cast
	// const Ÿ�� �����ͳ� ���۷����� ���� ����ϴ� ����ȯ ������.

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
	// ����ȯ ����� �����ͳ� ���۷����̴�. ���� ����ȯ�� ���.

	int a = 100;

	float* ptr = reinterpret_cast<float*>(&a);
}