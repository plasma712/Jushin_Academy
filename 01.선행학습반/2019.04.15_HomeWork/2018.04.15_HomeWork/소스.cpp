/*
����
�������� : �Է� �ް�
�������� : �Է� �ް�
�������� : �Է� �ް�

�Է°� ���

���� ������ OO���Դϴ�.
���� ������ OO���Դϴ�.
���� ������ OO���Դϴ�.

���� ������ OO ���̰�, ��������� OO���Դϴ�.
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

	cout << "���� ������ �Է� �Ͻÿ� : ";
	cin >> iKor;
	cout << "���� ������ �Է� �Ͻÿ� : ";
	cin >> iEng;
	cout << "���� ������ �Է� �Ͻÿ� : ";
	cin >> iMath;

	iSum = iKor + iEng + iMath;
	fAverage = (float)iSum / 3;

	cout << "���� ������ : " << iKor << "�� �Դϴ�." << endl;
	cout << "���� ������ : " << iEng << "�� �Դϴ�." << endl;
	cout << "���� ������ : " << iMath << "�� �Դϴ�." << endl;
	cout.precision(4); // ��¼��ڰ���
	cout << "���� ������ " << iSum << "���̰�,��������� " << fAverage << "���Դϴ�." << endl;

	/* ����ȯ �켱����
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