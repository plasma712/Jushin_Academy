#include<iostream>

using namespace std;

void main()
{
	// ##1. ���� ������
	// A ? B : C
	// (����) ? (������ ���� �� ��ȯ) : (������ ������ �� ��ȯ)

	//���� 3 ����
	int iInputA = 0, iInputB = 0, iABS = 0;

	cout << "�Է� : ";
	cin >> iInputA >> iInputB;

	(iInputA > iInputB) ? (iABS = iInputA - iInputB) : (iABS = iInputB - iInputA);
	cout << iABS << endl;

	return;
}