/*
과제
국어점수 : 입력 받고
영어점수 : 입력 받고
수학점수 : 입력 받고

입력값 출력

국어 점수는 OO점입니다.
영어 점수는 OO점입니다.
수학 점수는 OO점입니다.

통합 점수는 OO 점이고, 평균점수는 OO점입니다.
*/

#include <iostream>

using namespace std;

void main()
{
	int iKor;
	int iEng;
	int iMath;
	int iSum;
	float fAverage;

	cout << "국어 점수를 입력 하시오 : ";
	cin >> iKor;
	cout << "영어 점수를 입력 하시오 : ";
	cin >> iEng;
	cout << "수학 점수를 입력 하시오 : ";
	cin >> iMath;

	iSum = iKor + iEng + iMath;
	fAverage = (float)iSum / 3;

	cout << "국어 점수는 : " << iKor << "점 입니다." << endl;
	cout << "영어 점수는 : " << iEng << "점 입니다." << endl;
	cout << "수학 점수는 : " << iMath << "점 입니다." << endl;
	cout.precision(4); // 출력숫자갯수
	cout << "통합 점수는 " << iSum << "점이고,평균점수는 " << fAverage << "점입니다." << endl;

	/* 형변환 우선순위
	long double
	double
	float
	long long
	int
	short
	char
	*/

	return;
}