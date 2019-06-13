/*
	문제. 간단한 성적표 만들기

	입력
	국어 : 90
	영어 : 70
	수학 : 100

	출력 결과
	국어 : 90
	영어 : 70
	수학 : 100
	총점 : 260
	평균 : 
*/


#include<iostream>

using namespace std;

float Average(int _iTotal)
{
//	float fTotal = _iTotal;
	float Ave = (float)_iTotal / 3;
	return Ave;
}

int Total(int _iMath, int _iEng, int _iKor)
{
	int iTotal = _iMath + _iEng + _iKor;
	return iTotal;
}

void main()
{
	int iMath, iEng, iKor = 0;

	while (true)
	{
		cout << "국영수 평균 계산기 " << endl;
		cout << endl;
		cout << "국어 : ";
		cin >> iKor;
		cout << "영어 : ";
		cin >> iEng;
		cout << "수학 : ";
		cin >> iMath;

		cout<< "국영수 총점 : " << Total(iMath, iEng, iKor) << endl;
		cout <<"국영수 평균 : "<< Average(Total(iMath, iEng, iKor)) << endl;

		system("pause");
		system("cls");
	}
	return;
}