#include <iostream>

using namespace std;

void main()
{
	/*
	bool b = true;
	bool b1 = false;
	bool b2 = true, b3 = 'B';

	char A = 'C';
	char ch = 'A';
	char ch1 = 65;
	char ch2 = A;

	short n = 10;



	int i = 32760000000000008;
	n = i;

	cout << n << endl;

	// f 키워드 붙이는 임시 메모리 공간 잡을 때 4byte라는 것을 알려주기 위해 f 키워드를 붙임.
	// 임시 메모리 공간 : 연산을 위해 임시로 구성하는 메모리 공간
	float f = 10.22f;

	i = f;

	cout << i << endl;

	cout << b << endl;
	cout << b1 << endl;
 */
 // 연산자  -> 다항연산자, 이항연산자, 삼항연산자
 // 산술연산, sizeof()연산자, 쉬프트연산자, 논리연산자, 대소비교 연산자, 비트단위 연산자

 // 산술 연산 : + , - , * , / , %
	cout << "산술 연산 : + , - , * , / , %" << endl;
	cout << 10 + 20 << endl;
	cout << 10 - 20 << endl;
	cout << 10 * 20 << endl;
	cout << 10 / 20 << endl;
	cout << 10 % 2 << endl;
	cout << endl;

	// sizeof() - 다항 연산자. 
	cout << "sizeof() - 다항 연산자. " << endl;

	cout << sizeof(int) << endl;
	cout << sizeof(char) << endl;
	long long ll = 200000;
	cout << sizeof(ll) << endl;
	char ch1 = 'A', ch2 = 'B';
	cout << sizeof(ch1 + ch2) << endl;
	cout << endl;

	//대소비교 연산자 >, >=, <, <=, == , !=
	cout << "대소비교 연산자 >, >=, <, <=, == , !=" << endl;

	int iA = 10, iB = 20;

	cout << (iA > iB) << endl;
	cout << (iA >= iB) << endl;
	cout << (iA < iB) << endl;
	cout << (iA <= iB) << endl;
	cout << (iA == iB) << endl;
	cout << (iA != iB) << endl;
	cout << endl;

	// 논리 연산자 &&(AND), ||(or), !(NOT)
	cout << "논리 연산자 &&(AND), ||(or), !(NOT)" << endl;
	bool bTrue = true && true;
	bool bTrue1 = true && false;
	bool bTrue2 = false && true;
	bool bTrue3 = false && false;

	/////////////////////////////////
	// &&연산자의 경우 첫 값이 false 일 경우 뒤의 값이 어떠한지 결과와 상관없기 때문에 연산을 하지 않는다.
	// 따라서 bTest의 경우 i에 99가 들어가지 못하지만 , bTest1의 경우 i에 99가 들어간다.
	int i = 0;
	bool bTest = false && (i = 99);
	cout << i << endl;
	cout << endl;

	bool bTest1 = (i = 99) && false;
	cout << i << endl;
	cout << endl;
	/////////////////////////////////

	cout << bTrue << endl;
	cout << bTrue1 << endl;
	cout << bTrue2 << endl;
	cout << bTrue3 << endl;

	cout << endl;

	int iAge = 0;
	cin >> iAge;
	cout << iAge << endl;

	bool 미성년자 = 0 < iAge && iAge < 20;
	cout << 미성년자 << endl;

	////////////////////////////////
	// ||연산자의 경우 첫 값이 true 일 경우 뒤의 값이 어떠한지 결과와 상관없기 때문에 연산을 하지 않는다.
	// 따라서 aTest의 경우 뒤를 확인해봐야 하기 떄문에 a에 99가 들어간다.

	bool aTrue = true || true;
	bool aTrue1 = true || false;
	bool aTrue2 = false || true;
	bool aTrue3 = false || false;
	int a = 0;
	bool aTest = false || (i = 99);
	cout << a << endl;
	cout << endl;

	cout << aTrue << endl;
	cout << aTrue1 << endl;
	cout << aTrue2 << endl;
	cout << aTrue3 << endl;
	cout << endl;

	// !(NOT)

	cout << !(true) << endl;
	cout << !(false) << endl;

	// 헝가리안 표기법

	bool bOOOO;
	char chOOOOO;
	short nOOOOO;
	int iOOOO;
	float fOOOOO;
	long lOOOO;

	double dOOOO;
	long double ldOOOOO;

	long long llOOOOO;

}