#include<iostream>

using namespace std;

void main()
{
	// ##1. �迭�� ������

	// int iArr[5] = { 10,20,30,40,50 };

	// ������ �ּҸ� ���� ����غ��� ���ӵ� ������ ���� Ȯ���� �� �ִ�.
	// for (int i = 0; i < 5; i++)
	// 	cout << &(iArr[i]) << endl;

	// cout << iArr << endl; // �迭�� �̸��� ���� �ּҸ� ���� �������̴�.
	// cout << &(iArr[0]) << endl;
	// 
	// *iArr = 1000;
	// cout << iArr[0] << endl;
	// 
	// int i = 100;
	// iArr = &i; // error �迭�� �̸��� ��� �����ʹ�. ������ �ش� �迭�� ù �ּҸ� ���� �� �ִ�.

	// ##2. ������ ����
	// ������ ������� +, - �� �����ϴ�.
	// �����Ͱ� ����Ű�� ����� �ڷ��� ũ�⸸ŭ �̵��ϴ� �ǹ̴�.

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
	// iArr++; // iArr�� ��������Ͷ� +1�� �ȵ�
	// iArr++;
	// 
	// cout << iArr << endl;


	return;
}