/*
	1. �� ���� �� �ٲٱ�
	ex) int i = 10 , B = 20;

	��°� B=10 , i=20 (�� 3�� ���� ��� , �� 3�� ���� ���X ) 2����

	2. 10000������ ������ �Է� �޾� õ �� �� �� �� �ڸ� ���� ����ϱ�

	ex) 7123  -> õ���ڸ� 7 �����ڸ� 1 �����ڸ� 2 �����ڸ� 3

	3. ���� ������ ���� ���� �׸� �� �ִ� ���.

	<�ñ׸�>(���ǰ��� -1)
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

	cout << "õ�� �ڸ� : " << iThousand << endl;
	cout << "���� �ڸ� : " << iHundred << endl;
	cout << "���� �ڸ� : " << iTen << endl;
	cout << "���� �ڸ� : " << iOne << endl;
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
	cout << "�� ���� �� �ٲٱ�" << endl;
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



	cout << "10000������ ������ �Է� �޾� õ �� �� �� �� �ڸ� ���� ����ϱ�" << endl;
	cout << endl;
	int iDigits = 0;
	cout << "10000������ ������ �־��ּ��� : ";
	cin >> iDigits;
	Digits(iDigits);

	cout << "���� ������ ���� ���� ����  " << endl;
	cout << endl;

	int iPoint = 0;
	cout << "���� ������ �־��ּ��� : ";
	cin >> iPoint;
	cout << PointLine(iPoint) << endl;
}