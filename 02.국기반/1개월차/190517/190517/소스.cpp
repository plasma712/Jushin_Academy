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
	cout << "��� ������ : " << _iAve << "�̰� ������ : ";
	if (_iAve >= 90)
	{
		cout << "A ����" << endl;
	}
	else if (_iAve >= 80 && _iAve < 90)
	{
		cout << "B ����" << endl;
	}
	else if (_iAve >= 70 && _iAve < 80)
	{
		cout << "C ����" << endl;
	}
	else if (_iAve >= 60 && _iAve < 70)
	{
		cout << "D ����" << endl;
	}
	else
	{
		cout << "F ����" << endl;
	}
}

void Sign(float _fNumber) // ����2
{
	if (_fNumber >= 0)
	{
		cout << "���" << endl;
	}
	else
	{
		cout << "����" << endl;
	}
} 

void Absolute(float _fNumber1,float _fNumber2) //���� 3
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
	// ���� 1. ����ǥ ��� ���� ���� A ~ F���� �Űܺ���.
	// 90�̻� 100���� -> A����
	// 80�̻� 90�̸�  -> B����
	// 70�̻� 80�̸�  -> C����
	// 60�̻� 70�̸�  -> D����
	// 60�̸�  -> F����
	int iKor, iEng, iMath = 0;
	cin >> iKor >> iEng >> iMath;

	Grades(Averge(iKor, iEng, iMath));

	// ���� 2. ������ ����� ���� �������� ������� �Ǻ��ϴ� ���α׷� �ۼ�.

	

	// ���� 3. A�� B�� �E���Ͽ� ���� ���� ���϶�.
	// ex) 5 - 3 = 2
	//     3 - 5 = 2

	return;
}