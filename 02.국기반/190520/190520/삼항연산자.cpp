#include<iostream>

using namespace std;

void main()
{
	// ##1. 삼항 연산자
	// A ? B : C
	// (조건) ? (조건이 참일 때 반환) : (조건이 거짓일 때 반환)

	//과제 3 변형
	int iInputA = 0, iInputB = 0, iABS = 0;

	cout << "입력 : ";
	cin >> iInputA >> iInputB;

	(iInputA > iInputB) ? (iABS = iInputA - iInputB) : (iABS = iInputB - iInputA);
	cout << iABS << endl;

	return;
}