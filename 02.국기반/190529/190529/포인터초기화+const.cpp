#include <iostream>

using namespace std;

void main()
{
	// ##1. ������ 0 �ʱ�ȭ
	// int* ptr = nullptr;
	// 
	// if (nullptr != ptr)	// null üũ ����ȭ!
	// 	*ptr = 100;

	// ##2. �����Ϳ� const
	// int iA = 10, iB = 20;

	//
	// const int* ptr1 = &iA; // const �������� ���� iA�� ���� �������� ���ϰ� ��.
	// *ptr1 = 200;	// error
	// ptr1 = &iA;		

	// int* const ptr2 = &iA; // ptr2��ü�� ����� ���� ptr2�� ���� �Ұ���
	// *ptr2 = 200;	// ok
	// ptr2 = &iB;		// error

	
	// const int* const ptr3 = &iA; // �Ѵ� ���� X
	// *ptr3 = 200;  // error
	// ptr3 = &iB;	  // error

	// const int iC = 200; // const ������ ���� ������.
	// 
	// const int* ptr4 = &iC;



	return;
}