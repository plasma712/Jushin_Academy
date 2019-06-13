#include <iostream>
using namespace std;

// ##1. ������ (pointer)

// ���� ���� : �޸𸮿� �����ϴ� ����.
// ���� ���� : �ּҸ� ���� �޸� ���� -> ������ 
// ���� ���� : ������ ���� �޸� ���� / ���۷����� ���� �޸� ����.
void MyFunc(int _in)
{
	_in++;
}

void MyFunc_Two(int* ptr)
{
	(*ptr)++;
}

void main()
{
	// ##1. call by value�� call by pointer
	// int iA = 10;
	// MyFunc(iA); // call by value
	//
	// MyFunc_Two(&iA); // call by pointer (�����͸� ���� ������ ���� �ٲ� �� �ִ�.)
	// 
	// cout << iA << endl;

	// ##2. & (��巹�� ������)
	// int iA = 10, iB = 20, iC = 30;
	// 
	// cout << "iA�� ��" << iA << endl;
	// cout << "iA�� �ּ� : " << &iA << endl;
	// cout << "------------------------" << endl;
	// 
	// cout << "iB�� ��" << iB << endl;
	// cout << "iB�� �ּ� : " << &iB << endl;
	// cout << "------------------------" << endl;
	// 

	// cout << "iC�� ��" << iC << endl;
	// cout << "iC�� �ּ� : " << &iC << endl;
	// cout << "------------------------" << endl;

	// ##3. ������ ����
	// �����Ͷ�, �ּҸ� �����ϰ� �ִ� ����.
	int iA = 10;

	// ������ ���� 
	// int *ptr = &iA; // ptr�� iA�� ����Ų��. 
	// int * ptr = &iA; �� ���� �ǹ�
	// int* ptr = &iA; 



	// // ��������
	// *ptr = 200;
	// 
	// cout << "iA�� �� :" << iA << endl;
	// cout << "iA�� �ּ� : " << &iA << endl;
	// 
	// cout << "ptr�� �� : " << ptr << endl;

	// ##1. call by value�� call by pointer
	// int iA = 10;
	// MyFunc(iA); // call by value
	//
	// MyFunc_Two(&iA); // call by pointer (�����͸� ���� ������ ���� �ٲ� �� �ִ�.)
	// 
	// cout << iA << endl;

	// ##4. �������� ũ��
	int*		ptr1 = nullptr;	// �����͸� 0���� �ʱ�ȭ�Ѵ�.
	double*		ptr2 = nullptr;
	char*		ptr3 = nullptr;

	cout << sizeof(ptr1) << endl; // �����ʹ� ������ ������� ���� ũ�⸦ ���´�.
	cout << sizeof(ptr2) << endl; // 32��Ʈ�� 4����Ʈ , 64��Ʈ�� 8����Ʈ
	cout << sizeof(ptr3) << endl;


	return;
}