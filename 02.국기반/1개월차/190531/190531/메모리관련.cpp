#include<iostream>
using namespace std;

// �޸� ���� ǥ�� �Լ�.

void main()
{
	// ##1. memcpy �Լ�.
	// �޸� �� �޸� ���� �� ���� �Լ�.
	// ���� ���� ���� �߿� �ӽ� ���۸� ��ġ�� �ʴ´�.

	// int iArr_1[5] = {};
	// int iArr_2[5] = { 10,20,30,40,50 };

	// memcpy(dst, src, size)
	// src�κ��� size��ŭ dst���� �����Ѵ�.

	// memcpy(iArr_1, iArr_2, 16);

	// for (int i = 0; i < 5; i++)
	// {
	// 	cout << "iArr_1 [" << i << "] : " << iArr_1[i] << endl;
	// 	cout << "iArr_2 [" << i << "] : " << iArr_2[i] << endl;
	// }
	// 
	// memcpy(iArr_1 + 1, iArr_2, 16);
	// 
	// for (int i = 0; i < 5; i++)
	// {
	// 	cout << "iArr_1 [" << i << "] : " << iArr_1[i] << endl;
	// 	cout << "iArr_2 [" << i << "] : " << iArr_2[i] << endl;
	// }
	// 
	// memcpy(iArr_1, iArr_2 + 1, 16);
	// 
	// for (int i = 0; i < 5; i++)
	// {
	// 	cout << "iArr_1 [" << i << "] : " << iArr_1[i] << endl;
	// 	cout << "iArr_2 [" << i << "] : " << iArr_2[i] << endl;
	// }

	// ##2. memmove �Լ�.
	// �޸� �� �޸� ���� �Լ�
	// ���� ���� ���� �߿� �ӽ� ���۸� ��ģ��.
	// ���� ���� �������� ������ �ս��� ���� �� �� �ִ�.

	int iArr_1[5] = {};
	int iArr_2[5] = { 10,20,30,40,50 };
	
	memmove(iArr_1, iArr_2, 16);

	for (int i = 0; i < 5; i++)
	{
		cout << "iArr_1 [" << i << "] : " << iArr_1[i] << endl;
		cout << "iArr_2 [" << i << "] : " << iArr_2[i] << endl;
	}



	return;
}