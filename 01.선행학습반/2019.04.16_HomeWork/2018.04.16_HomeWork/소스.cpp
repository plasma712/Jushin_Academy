/*
	1. 두 수의 값 바꾸기
	ex) int i = 10 , B = 20;

	출력값 B=10 , i=20 (제 3의 변수 사용 , 제 3의 변수 사용X ) 2가지

	2. 10000이하의 정수를 입력 받아 천 백 십 일 의 자리 나눠 출력하기

	ex) 7123  -> 천의자리 7 백의자리 1 십의자리 2 일의자리 3

	3. 점의 갯수에 따라서 선을 그릴 수 있는 방법.

	<시그마>(점의갯수 -1)
*/
#include <iostream>
using namespace std;

void Swap(float &_fNumber1, float &_fNumber2)
{
	float fEtc = 0;
	fEtc = _fNumber1;
	_fNumber1 = _fNumber2;
	_fNumber2 = fEtc;

	cout << "fNumber1 : " << _fNumber1 << endl;
	cout << "fNumber2 : " << _fNumber2 << endl;
	cout << endl;
}

void BitSwap(int &_iA, int &_iB)
{
	_iA = _iA ^ _iB;
	_iB = _iA ^ _iB;
	_iA = _iA ^ _iB;

	cout << _iA << endl;
	cout << _iB << endl;
}

void Digits(int _iDigits)
{
	int iThousand;
	int iHundred;
	int iTen;
	int iOne;
	iThousand = _iDigits / 1000;
	iHundred = float((_iDigits % 1000) / 100);
	iTen = float((_iDigits % 100) / 10);
	iOne = float(_iDigits % 10);

	cout << "천의 자리 : " << iThousand << endl;
	cout << "백의 자리 : " << iHundred << endl;
	cout << "십의 자리 : " << iTen << endl;
	cout << "일의 자리 : " << iOne << endl;
	cout << endl;
}

int PointLine(int _iPoint)
{
	int LineTotal = 0;
	for (_iPoint; _iPoint > 0; _iPoint--)
	{
		LineTotal += (_iPoint - 1);
	}
	return LineTotal;
}

void main()
{
	cout << "두 수의 값 바꾸기" << endl;
	cout << endl;
	float fNumber1 = 0;
	float fNumber2 = 0;
	cout << "fNumber1 : ";
	cin >> fNumber1;
	cout << "fNumber2 : ";
	cin >> fNumber2;
	cout << endl;
	Swap(fNumber1, fNumber2);
	cout << endl;
	
	//int iA = 0, iB = 0;
	//cin >> iA >> iB;
	//
	//cout << iA << iB << endl;
	//
	//BitSwap(iA, iB);
	//
	//cout << endl;



	cout << "10000이하의 정수를 입력 받아 천 백 십 일 의 자리 나눠 출력하기" << endl;
	cout << endl;
	int iDigits = 0;
	cout << "10000이하의 정수를 넣어주세요 : ";
	cin >> iDigits;
	Digits(iDigits);

	cout << "점의 갯수에 따라서 선의 갯수  " << endl;
	cout << endl;

	int iPoint = 0;
	cout << "점의 갯수를 넣어주세요 : ";
	cin >> iPoint;
	cout << PointLine(iPoint) << endl;
}