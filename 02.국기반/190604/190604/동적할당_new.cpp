#include<iostream>

using namespace std;

// ##1. C++�� �����Ҵ� ������.
// C���� �Լ��� 

void main()
{
	// int a = 100;	// C��� �ʱ�ȭ
	// int b(200);		// C++ ����ʱ�ȭ
	// 
	// ##2. new �����ڿ� delete ������.

	// int* ptr_1 = (int*)malloc(4); // C���
	// int* ptr_2 = new int; //C++���
	// float* ptr_3 = new float(3.14f); // �Ҵ�� ���ÿ� �ʱ�ȭ ����
	// 
	// cout << *ptr_2 << endl;
	// cout << *ptr_3 << endl;
	// 
	// // �޸� ����
	// free(ptr_1);	// C   ���
	// delete ptr_2;	// C++ ���
	// delete ptr_3;	// C++ ���

	// ##3. C++�� �����迭

	int* ptr_1 = new int[3]; // heap ������ int ������ 3�� ���ӵǰ� �Ҵ�. (�����Ⱚ���� �ʱ�ȭ)
	int* ptr_2 = new int[3]{}; // �����迭 0 �ʱ�ȭ.
	int* ptr_3 = new int[3]{10,20}; // �� �ʱ�ȭ ����. 

	for (int i = 0; i < 3; i++)
	{
		cout << ptr_1[i] << endl;
		cout << ptr_2[i] << endl;
		cout << ptr_3[i] << endl;

	}

	// �����迭 ����

	delete[] ptr_1;
	delete[] ptr_2;
	delete[] ptr_3;



	return;
}