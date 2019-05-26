#include <iostream>

using namespace std;

void main()
{
	////쉬프트 연산자.
	//int i = 1;
	//i = i << 2;
	//cout << i << endl;


	//int iOctal = 012; // 숫자앞에 0이 들어가면 8진수로 계산함.
	//int iHex = 0xA;   // 숫자앞에 0x이 들어가면 16진수로 계산함 
	//int iDex = 10;
	//cout << iOctal << " , " << iHex << " , " << iDex;

	// 입력 받은 정수 값의 부호 바꿔서 출력하는 프로그램 작성 (비트연산 사용)
	//int iNum = 0;
	//cin >> iNum;
	//iNum = ~iNum;
	//iNum = iNum + 1;
	//cout << iNum << endl;

	// 3*8 /4 의 식을 * 연산과 / 연산을 사용하지 않고 구현하기

	int iA = (3 * 8) / 4;
	cout << iA << endl;
	int iB = (3 << 3) >> 2;
	cout << iB << endl;

	// 축약연산자 , +=, -=, *= , /=, %=, <<= , >>=

}