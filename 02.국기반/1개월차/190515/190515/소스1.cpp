/*
	����. ������ ����ǥ �����

	�Է�
	���� : 90
	���� : 70
	���� : 100

	��� ���
	���� : 90
	���� : 70
	���� : 100
	���� : 260
	��� : 
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
		cout << "������ ��� ���� " << endl;
		cout << endl;
		cout << "���� : ";
		cin >> iKor;
		cout << "���� : ";
		cin >> iEng;
		cout << "���� : ";
		cin >> iMath;

		cout<< "������ ���� : " << Total(iMath, iEng, iKor) << endl;
		cout <<"������ ��� : "<< Average(Total(iMath, iEng, iKor)) << endl;

		system("pause");
		system("cls");
	}
	return;
}