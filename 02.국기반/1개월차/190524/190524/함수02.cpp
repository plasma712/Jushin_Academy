#include <iostream>

using namespace std;

// ���� ���α׷�.

int Add(int a, int b)
{
	return a + b;
}

int Min(int a, int b)
{
	return a - b;
}

int Mul(int a, int b)
{
	return a * b;
}

int Div(int a, int b)
{
	return a / b;
}

void Calculator()
{
	int iInputA = 0, iInputB = 0, iSelect = 0, iResult = 0;

	cout << "�ΰ��� ���� �Է� : ";
	cin >> iInputA >> iInputB;

	cout << "1. ���� 2. ���� 3.���� 4.������" << endl;

	cin >> iSelect;

	switch (iSelect)
	{
	case 1:
		iResult = Add(iInputA, iInputB);
		break;
	case 2:
		iResult = Min(iInputA, iInputB);
		break;
	case 3:
		iResult = Mul(iInputA, iInputB);
		break;
	case 4:
		iResult = Div(iInputA, iInputB);
		break;

	default:
		break;
	}
	cout << "���� ��� : " << iResult << endl;
}

void main()
{
	Calculator();
	return;
}