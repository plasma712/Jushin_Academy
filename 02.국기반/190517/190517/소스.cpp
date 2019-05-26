#include <iostream> 

using namespace std;

float Averge(int _iKor, int _iEng, int _iMath)
{
	int iTotal = 0;
	float iAve = 0;

	iTotal = _iKor + _iEng + _iMath;
	iAve = (float)iTotal / 3;

	return iAve;
}

void Grades(int _iAve)
{
	cout << "평균 점수는 : " << _iAve << "이고 학점은 : ";
	if (_iAve >= 90)
	{
		cout << "A 학점" << endl;
	}
	else if (_iAve >= 80 && _iAve < 90)
	{
		cout << "B 학점" << endl;
	}
	else if (_iAve >= 70 && _iAve < 80)
	{
		cout << "C 학점" << endl;
	}
	else if (_iAve >= 60 && _iAve < 70)
	{
		cout << "D 학점" << endl;
	}
	else
	{
		cout << "F 학점" << endl;
	}
}

void Sign(float _fNumber) // 과제2
{
	if (_fNumber >= 0)
	{
		cout << "양수" << endl;
	}
	else
	{
		cout << "음수" << endl;
	}
} 

void Absolute(float _fNumber1,float _fNumber2) //과제 3
{
	float fMin = 0;
	fMin = _fNumber1 - _fNumber2;

	if (fMin >= 0)
	{
		cout << fMin << endl;
	}
	else
	{
		cout << fMin * -1.f << endl;
	}
}


void main()
{
	// 과제 1. 성적표 평균 점수 토대로 A ~ F학점 매겨보기.
	// 90이상 100이하 -> A학점
	// 80이상 90미만  -> B학점
	// 70이상 80미만  -> C학점
	// 60이상 70미만  -> D학점
	// 60미만  -> F학점
	int iKor, iEng, iMath = 0;
	cin >> iKor >> iEng >> iMath;

	Grades(Averge(iKor, iEng, iMath));

	// 과제 2. 변수에 저장된 값이 음수인지 양수인지 판별하는 프로그램 작성.

	

	// 과제 3. A와 B를 뺼셈하여 절대 값을 구하라.
	// ex) 5 - 3 = 2
	//     3 - 5 = 2

	return;
}