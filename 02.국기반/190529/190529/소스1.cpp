#include<iostream>

using namespace std;

void main()
{
	int iArr2D[2][3] =
	{
		{10,20,30},
		{40,50,60}
	};

	cout << iArr2D[1][1] << endl;
	cout << *(iArr2D[1] + 1) << endl;
	cout << (*(iArr2D + 1))[1] << endl;
	cout << *(*(iArr2D + 1) + 1) << endl;

	// ##1. 2���� �迭�� ������

	// int iArr2D[2][3] =
	// {
	// 	{10,20,30},
	// 	{40,50,60}
	// };

	// cout << iArr2D << endl;
	// // cout << &(iArr2D[0][0]) << endl;
	// cout << iArr2D + 1 << endl;	// 2���� �迭�� ������ ������ ���� ũ�⿡ ������ �޴´�.
	// 
	// // 2���� �迭�� ������ Ÿ��

	// int(*ptr)[3] = iArr2D;
	// 
	// cout << ptr[1][2] << endl;
	// 
	// cout << *(*(ptr + 1) + 2) << endl;
	// 
	// cout << sizeof(ptr[1]) << endl;
	// 
	// cout << sizeof(ptr[1][0]) << endl;


	return;
}