#include <iostream>

using namespace std;

void MyFunc(/*int* ptr*/ int ptr[],int iLength)
{
	cout << sizeof(ptr) << endl;  // ������ ������ ũ��

	for (int i = 0; i < iLength; i++)
		cout << ptr[i] << endl;

	int iA = 100;
	int p[] = &iA; //int p[] ǥ���� �Լ� ���� �������θ� ��밡��. error
}

void main()
{
	int iArr[5] = { 10,20,30,40,50 };

	MyFunc(iArr,5);
	return;
}