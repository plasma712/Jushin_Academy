#include<iostream>

using namespace std;

void main()
{
	// ##1. 배열과 포인터

	// int iArr[5] = { 10,20,30,40,50 };

	// 원소의 주소를 각각 출력해보면 연속된 공간인 것을 확인할 수 있다.
	// for (int i = 0; i < 5; i++)
	// 	cout << &(iArr[i]) << endl;

	// cout << iArr << endl; // 배열의 이름은 시작 주소를 갖는 포인터이다.
	// cout << &(iArr[0]) << endl;
	// 
	// *iArr = 1000;
	// cout << iArr[0] << endl;
	// 
	// int i = 100;
	// iArr = &i; // error 배열의 이름은 상수 포인터다. 오로지 해당 배열의 첫 주소만 가질 수 있다.

	// ##2. 포인터 연산
	// 포인터 대상으로 +, - 이 가능하다.
	// 포인터가 가리키는 대상의 자료형 크기만큼 이동하는 의미다.

	int iArr[5] = { 10,20,30,40,50 };
	int* ptr = iArr;
	// 1.
	// cout << "ptr : " << ptr << endl;
	// cout <<"ptr + 1 : " <<(ptr + 1) << endl;
	// cout << "ptr[1] : " << ptr[1] << endl; // == *(ptr + 1);
	// 
	// cout << "--------------------------------------------" << endl;
	// 
	// cout << "*(iArr + 1) : " << *(iArr + 1) << endl;
	// cout << "iArr[1] : " << iArr[1] << endl;
	// cout << &(iArr[1]) << endl;

	// 2.

	// cout << ptr << endl;
	// 
	// ptr++; // ptr +=1
	// ptr++;
	// 
	// cout << ptr << endl;

	// cout << iArr << endl;
	// 
	// iArr++; // iArr는 상수포인터라서 +1이 안됨
	// iArr++;
	// 
	// cout << iArr << endl;


	return;
}