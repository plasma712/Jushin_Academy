#include<iostream>

using namespace std;

// ##1. C++의 동적할당 연산자.
// C언어는 함수를 

void main()
{
	// int a = 100;	// C기반 초기화
	// int b(200);		// C++ 기반초기화
	// 
	// ##2. new 연산자와 delete 연산자.

	// int* ptr_1 = (int*)malloc(4); // C기반
	// int* ptr_2 = new int; //C++기반
	// float* ptr_3 = new float(3.14f); // 할당과 동시에 초기화 가능
	// 
	// cout << *ptr_2 << endl;
	// cout << *ptr_3 << endl;
	// 
	// // 메모리 해제
	// free(ptr_1);	// C   기반
	// delete ptr_2;	// C++ 기반
	// delete ptr_3;	// C++ 기반

	// ##3. C++의 동적배열

	int* ptr_1 = new int[3]; // heap 영역에 int 공간을 3개 연속되게 할당. (쓰레기값으로 초기화)
	int* ptr_2 = new int[3]{}; // 동적배열 0 초기화.
	int* ptr_3 = new int[3]{10,20}; // 값 초기화 가능. 

	for (int i = 0; i < 3; i++)
	{
		cout << ptr_1[i] << endl;
		cout << ptr_2[i] << endl;
		cout << ptr_3[i] << endl;

	}

	// 동적배열 해제

	delete[] ptr_1;
	delete[] ptr_2;
	delete[] ptr_3;



	return;
}