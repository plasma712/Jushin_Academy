#include <iostream>

using namespace std;

void MyFunc(/*int* ptr*/ int ptr[],int iLength)
{
	cout << sizeof(ptr) << endl;  // 엄연히 포인터 크기

	for (int i = 0; i < iLength; i++)
		cout << ptr[i] << endl;

	int iA = 100;
	int p[] = &iA; //int p[] 표현은 함수 인자 형식으로만 사용가능. error
}

void main()
{
	int iArr[5] = { 10,20,30,40,50 };

	MyFunc(iArr,5);
	return;
}