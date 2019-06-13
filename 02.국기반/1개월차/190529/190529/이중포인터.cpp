#include<iostream>

using namespace std;

void main()
{
	// ##1. 이중 포인터
	// 포인터도 엄연히 변수이므로 주소가 존재한다.
	// 포인터의 주소를 갖는 또다른 포인터를 이중 포인터라 한다.
	int iA = 100;
	int* ptr = &iA;
	int** pptr = &ptr; // 이중 포인터

	cout << "ptr의 주소 : " << &ptr << endl;
	cout << "pptr의 값 : " << pptr << endl;
	cout << "iA의 값 : " << **pptr << endl;

	return;
}