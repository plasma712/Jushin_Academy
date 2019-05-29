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

	// ##1. 2차원 배열과 포인터

	// int iArr2D[2][3] =
	// {
	// 	{10,20,30},
	// 	{40,50,60}
	// };

	// cout << iArr2D << endl;
	// // cout << &(iArr2D[0][0]) << endl;
	// cout << iArr2D + 1 << endl;	// 2차원 배열의 포인터 연산은 열의 크기에 영향을 받는다.
	// 
	// // 2차원 배열의 포인터 타입

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