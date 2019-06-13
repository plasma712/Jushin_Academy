#include <iostream> 

using namespace std;

void main()
{
	// ##1. 배열
	// 같은 자료형을 가진 여러 데이터를 효율적으로 보관 및 관리 할 수 있다.
	// int iCoke = 100, iCider = 200, iFanta = 300;
	
	// 배열은 연속된 메모리를 갖는다.


	// 배열선언
	// 자료형 배열이름[배열길이];

	// int iDrinkArr1[3] = { 100,200,300 }; // 배열 초기화.
	// int iDrinkArr2[3] = { 100,200 };	 // 마지막 원소는 0으로 초기화
	// int iDrinkArr3[3] = { 100 };		 // 2, 3번째 원소는 0 초기화
	// int iDrinkArr4[3] = {};			 // 모든 원소 0 초기화.


	// 원소 접근(index로 접근)
	// 배열의 이름은 연속된 메모리의 시작점이다.
	// 배열의 원소에 index로 접근할 때에는 길이를 넘어서지 않게 유의.
	// 배열의 길이가 N인 index의 범위 0 ~ N-1

	// cout << "콜라 : "	<< iDrinkArr1[0] << endl;
	// cout << "사이다 : "	<< iDrinkArr1[1] << endl;
	// cout << "환타 : "	<< iDrinkArr1[2] << endl;

	
	// ##2. 배열의 선언 후 초기화
	
	// int iDrinkArr[3];
	// iDrinkArr = { 100,200,300 }; // error, 배열의 초기화 문법은 선언과 동시에만 가능

	// 각 원소의 값을 초기화하고 있다.
	// iDrinkArr[0] = 100;
	// iDrinkArr[1] = 200;
	// iDrinkArr[2] = 300;


	// ##3. 배열의 또다른 초기화 형태

	// 배열의 길이를 생략했을 때 {}안에 나열된 원소의 개수만큼 메모리가 할당된다.
	// int iDrinkArr[] = { 100, 200 };
	// int iDrinkArr2[]; // error
	// int iDrinkArr3[] = {}; // error


	// sizeof연산 시 피연산자가 배열의 이름이라면 배열의 총 메모리 크기가 반환된다.
	// cout << sizeof(iDrinkArr) << endl;

	// ##4. 배열의 길이 계산

	// double iArr[5] = {};

	// cout << "총 메모리 크기 : " << sizeof(iArr) << endl;
	// cout << "현재 배열의 길이: " << sizeof(iArr) / sizeof(iArr[0]) << endl;

	// ##5. 정적배열

	// int iLength = 0;

	// cout << "배열의 길이를 입력 : ";
	// cin >> iLength;

	// int iArr[iLength];		//error, 배열 선언시 배열의 길이는 상수만 가능


	// const int iMaxcount = 5;
	// 
	// int iArr[iMaxcount] = {};

	// ##6. 배열에 보관될 자료들이 일정한 규칙을 갖고 있다면 반복문을 활용하라.

	// int iArr[1000] = {};
	// 
	// for (int i = 0; i < 1000; i++)
	// {
	// 	iArr[i] = i + 1;
	// }



	return;
}