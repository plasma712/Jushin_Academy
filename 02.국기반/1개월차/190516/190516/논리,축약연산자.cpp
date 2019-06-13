#include <iostream>

using namespace std;

void main()
{
	// ##1. 논리 연산자 (and, or, not)

	// && (and 연산자)
	// 두 개의 조건이 모두 참이면 결과는 참.
	// 하나라도 거짓이면 결과는 참.
	// cout << (true && true) << endl;
	// cout << (true && false) << endl;
	// cout << (false && true) << endl;
	// cout << (false && false) << endl;

	//int a = 10, b = 200, c = 30;

	// cout << (a < b < c) << endl;	// 결과 오류. a<b의 결과값이 true -> 1로 바뀜 1<C로 식이 바뀌어 true로 나옴.
	// cout << (a < b && b < c) << endl;

	// int d = 0;
	// (true) && (d = 100);
	// (false) && (d = 100);
	// 앞의 조건이 거짓인 경우 뒤의 조건은 검사하지 않는다.(수행 되지 않음.)
	// 이 경우 바로 거짓 변환 따라서 d에 100이 대입되지 못한다. *
	// cout << d << endl;


	// || (or 연산자)
	// 두 개의 조건 중 하나라도 참이면 결과는 참.
	// 둘 다 거짓이어야 결과는 거짓.
	// cout << (true || true) << endl;
	// cout << (true || false) << endl;
	// cout << (false || true) << endl;
	// cout << (false || false) << endl;
	
	// int d = 0;
	// (false) || (d = 100);
	// (true) || (d = 100);
	// 앞의 조건이 참인 경우 뒤의 조건은 검사하지 않는다.(수행 되지 않음.)
	// 이 경우 바로 참 변환 따라서 d에 100이 대입되지 못한다. *
	// cout << d << endl;

	// !  (not 연산자)
	// 논리 부정.

	// cout << !true << endl;
	// cout << !false << endl;


	// ##2. 축약 연산자 (+=, -=, *=, /=, %=)
	// int a = 100;
	// a = a + 50;
	// a += 50;

	// int b = 1, c = 2, d = 3;

	// 축약 연산자도 대입 연산자와 마찬가자로 오른쪽부터 연산 순서가 진행된다.
	// b += c += d += 50;

	// cout << b << endl;
	// cout << c << endl;
	// cout << d << endl;



	return; 
}