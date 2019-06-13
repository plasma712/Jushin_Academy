#include<iostream>
using namespace std;

// 메모리 관련 표준 함수.

void main()
{
	// ##1. memcpy 함수.
	// 메모리 대 메모리 간의 값 복사 함수.
	// 복사 수행 과정 중에 임시 버퍼를 거치지 않는다.

	// int iArr_1[5] = {};
	// int iArr_2[5] = { 10,20,30,40,50 };

	// memcpy(dst, src, size)
	// src로부터 size만큼 dst에게 복사한다.

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

	// ##2. memmove 함수.
	// 메모리 대 메모리 간의 함수
	// 복사 수행 과정 중에 임시 버퍼를 거친다.
	// 복사 수행 과정에서 데이터 손실을 방지 할 수 있다.

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