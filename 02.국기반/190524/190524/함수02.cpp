#include <iostream>

using namespace std;

// °è»ê±â ÇÁ·Î±×·¥.

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

	cout << "µÎ°³ÀÇ ¼ö¸¦ ÀÔ·Â : ";
	cin >> iInputA >> iInputB;

	cout << "1. µ¡¼À 2. »¬¼À 3.°ö¼À 4.³ª´°¼À" << endl;

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
	cout << "¿¬»ê °á°ú : " << iResult << endl;
}

void main()
{
	Calculator();
	return;
}