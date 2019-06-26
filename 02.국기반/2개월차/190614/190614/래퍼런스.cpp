#include <iostream>

using namespace std;

// ##1. ���۷��� (C++ ����)
// ���� ���� , �޸𸮿� ��Ī�� �ο�

void Swap(int& _a, int& _b)
{
	int itemp = _a;
	_a = _b;
	_b = itemp;
}

void main()
{
	// ##2. ���۷��� ����.
	// int a = 10; // ����
	// int& r = a; // ���۷��� ����. a������ r�̶�� �Ǵٸ� ��Ī�� �ο�
	// 
	// r = 200;	// a ������ �����ϴ� �Ͱ� ������ ȿ��. ��������.
	// cout << a << endl;
	// cout << "--------------------" << endl;
	// 
	// // �ᱹ a�� r�� ���� �����̴�.
	// cout << &a << endl;
	// cout << &r << endl;


	// ##3. ���۷����� Ư¡
	// �����Ϳ� �޸� ������ �޸𸮰� �ʿ����. �� ���簡 �ƴϴ�.
	// int& r = nullptr;	// ������ó�� null�ʱ�ȭ �Ұ�. error
	// int& r; // error ����� ���ÿ� ���� ����� �ʿ�.

	// int a = 100, b = 200;
	// int& r = a;

	// ���۷����� ���� ����� ������ �� ����.
	// r = b;
	// cout << a << endl;

	// ##4. call by reference
	// int a = 10, b = 20;
	// 
	// Swap(a, b);
	// 
	// cout << a << " , " << b << endl;

	// // ##5. ���۷����� const
	// const int a = 300;
	// // int& r = a; // error
	// const int& r = a; // ok

	/////////////////////////////////////////////////////////

	// ���ͳ� ����� �����Ϸ��� const ���۷������� �Ѵ�.
	const int& r = 100; // 100�� �ӽð����� 'r' �̶�� const ������ �Ǿ���.



	system("pause");
	return;
}