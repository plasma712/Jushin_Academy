#include <iostream>

using namespace std;

void main()
{
	cout << "Hello World" << endl;
	// 변수와 자료형
	int i = 0;

	// 변수를 선언하면 메모리공간에 할당된다.
	// 메모리공간에 데이터를 담을 수 있는 공간을 주소라하고 그 주소를 변수명으로 접근해서 사용할 수 있다.
	// 변수 선언시 주의 사항
	/*
		int a;  (- 대소문자 구별)
		int A;  (- 대소문자 구별)
		int A2;
		int 2A; (X)
		int _A;
		int !A; (X)
		int 박태호;
		int A Test; (X)
		int A2#; (X)
		int AAAAAAAAAAAAAAAAAAAA;
	*/
	// 자료형의 종류

	/*
		- 1Byte
		bool(논리자료형), char(단일문자)

		- 2Byte
		short(정수자료형),

		- 4Byte
		int(정수자료형), long(정수자료형), float(실수자료형)

		- 8Byte
		long long(정수자료형), double(정수자료형), long double(실수자료형)
	*/

	// unsigned (양수만)
	// signed (음수포함)
	// 2의 보수 : 양의 정수의 비트들을 1의 보수(비트반전)를 취한 결과 값에 1을 더해주면 된다.


	// 실수 자료형의 표현방식
	// 표현방식은 부동소수점(소수점이 둥둥 떠다닌다 라는 뜻)을 이용
	// 바이어스 표기법(2의 보수를 이용하면 순수한 0을 표현 할 수 가 없기 때문에 사용)


	bool b = true;
	bool b2 = false;

	b = 1;
	b2 = 0;

	bool b3 = 12, b4 = 0.1f, b5 = 'A', b6 = 1.11f;
	
	cout << b << " , " << b2 << " , " << b3 << " , " << b4 << " , " << b5 << " , " << b6 << endl;


	char a1=72, a2=69, a3=76, a4=76, a5=79, a6=87, a7=79, a8=82, a9=76, a10=68;

	cout << a1 << a2 << a3 << a4 << a5 << a6 << a7 << a8 << a9 << a10;

	int iTest;
	iTest = 0;
	cout << iTest << endl;

	// 상수화 . const 키워드를 사용하자
	// 선언과 동시에 초기화를 반드시 해야 하는 문법이다.
	const int Test=100;
	//Test = 299;
}