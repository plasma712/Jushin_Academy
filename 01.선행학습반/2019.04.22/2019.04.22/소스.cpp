#include <iostream>
using namespace std;

int iTest = 0;			// ��������
static int iStatic = 0; // ��������


// ��ȯ�� �Լ���(���� Ȥ�� �Ķ���� Ȥ�� �Ű�����)
// {  // �Լ� ��ü
// 	  // �ڵ� ���
// }

int Add(int _iNum1, int _iNum2)
{
	//int Sum = 0;
	//Sum = _iNum1 + _iNum2;
	//return Sum;
	return _iNum1 + _iNum2;
}

void TestFunc() // static���� ȣ���ϱ� ������ �ʱ�ȭ�� ó�� �Լ� ȣ������ �� �� �ѹ��� �� /
{
	static int iTestStatic = 0;
	iTestStatic++;
	cout << iTestStatic << endl;
}

void main()
{
	//int iTotal = Add(10, 20);
	//cout << iTotal << endl;

	//TestFunc();
	//TestFunc();
	//TestFunc();

	cout << &iTest << endl;
	int iTest = 99;
	cout << &iTest << endl;
}

/*
	Code - ����. ���

	Stack - ��������(�Լ��� ���۰� ��)

	Heap - �����Ҵ�

	Data - ��������, ��������
*/