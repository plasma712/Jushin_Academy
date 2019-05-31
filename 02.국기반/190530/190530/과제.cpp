/*
	과제 1.
	입력 받은 문자열을 뒤집는 함수를 만들어라.
	ex)
	입력 : tomato
	출력 : otamot

	과제 2.
	입력 받은 문자열의 길이를 구하는 함수를 만들어라.
	ex)
	입력 : tomato
	출력 : 6

	과제 3.
	입력 받은 문자열의 대소문자를 바꾸는 함수를 만들어라.
	ex)
	입력 : HellO
	출력 : hELLo
*/

#include<iostream>

using namespace std;

// 문자열 거꾸로 바꾸기
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

// 문자열길이 
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

// 문자열의 대소문자를 바꾸기
// 아스키코드 65~90 대문자
// 아스키코드 97~122 소문자
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
	cout << "입력값 : ";
	cin >> cInput;
	// //ReSequence(cInput, strlen(cInput));
	cout << "과제 1------------------------------------------" << endl;
	ReSequence(cInput, CharLength(cInput));
	cout << cInput << endl;
	system("pause");
	system("cls");
	cin >> cInput;
	cout << "과제 2------------------------------------------" << endl;
	cout << CharLength(cInput) << endl;
	system("pause");
	system("cls");
	cout << "입력값 : ";
	cin >> cInput;
	cout << "과제 3------------------------------------------" << endl;
	ConversionAlphabet(cInput, CharLength(cInput));
	cout << cInput << endl;

	return;
}