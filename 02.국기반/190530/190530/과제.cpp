/*
	���� 1.
	�Է� ���� ���ڿ��� ������ �Լ��� ������.
	ex)
	�Է� : tomato
	��� : otamot

	���� 2.
	�Է� ���� ���ڿ��� ���̸� ���ϴ� �Լ��� ������.
	ex)
	�Է� : tomato
	��� : 6

	���� 3.
	�Է� ���� ���ڿ��� ��ҹ��ڸ� �ٲٴ� �Լ��� ������.
	ex)
	�Է� : HellO
	��� : hELLo
*/

#include<iostream>

using namespace std;

// ���ڿ� �Ųٷ� �ٲٱ�
void ReSequence(char _cInput[], int _iLength)
{
	char *cCopy = _cInput;
	char cTemp;
	//char cTemp[1] = "";
	for (int k = 0; k < _iLength / 2; k++)
	{
		cTemp = cCopy[k];
		cCopy[k] = _cInput[_iLength - 1 - k];
		_cInput[_iLength - 1 - k] = cTemp;
	}
}

// ���ڿ����� 
int CharLength(char _cInput[])
{
	int iCheckNum = 0;
	while (true)
	{
		if (_cInput[iCheckNum] == '\0')
			break;
		iCheckNum++;
	}
	return iCheckNum;
}

// ���ڿ��� ��ҹ��ڸ� �ٲٱ�
// �ƽ�Ű�ڵ� 65~90 �빮��
// �ƽ�Ű�ڵ� 97~122 �ҹ���
void ConversionAlphabet(char _cInput[], int _iLength)
{
	char* cCopy = _cInput;

	for (int k = 0; k < _iLength; k++)
	{
		//cout << int(cCopy[k]) << endl;
		if (int(cCopy[k]) < 91)
			cCopy[k] += 32;
		else if (int(cCopy[k]) > 96)
			cCopy[k] -= 32;
	}
}


void main()
{
	const int ilength = 100;
	char cInput[ilength] = "";
	// 
	cout << "�Է°� : ";
	cin >> cInput;
	// //ReSequence(cInput, strlen(cInput));
	cout << "���� 1------------------------------------------" << endl;
	ReSequence(cInput, CharLength(cInput));
	cout << cInput << endl;
	system("pause");
	system("cls");
	cin >> cInput;
	cout << "���� 2------------------------------------------" << endl;
	cout << CharLength(cInput) << endl;
	system("pause");
	system("cls");
	cout << "�Է°� : ";
	cin >> cInput;
	cout << "���� 3------------------------------------------" << endl;
	ConversionAlphabet(cInput, CharLength(cInput));
	cout << cInput << endl;

	return;
}