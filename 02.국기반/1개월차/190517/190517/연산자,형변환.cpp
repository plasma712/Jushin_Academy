#include<iostream>

using namespace std;

void main()
{
	// ##1. 증감 연산자 (++,--)
	// 현재 변수가 갖고 있는 값에 1씩 증가(++) 또는 감소(--) 시키는 연산자.

	// 1.전위 증감 연산자
	// int a = 10;
	
	// ++a; // 전위 연산  or  --a;


	// cout << a << endl;

	// 2. 후위 증감 연산자.

	// int b = 10;

	// b++; // 후위 연산


	// 3. 전위와 후위의 차이
	// int a = 10, b = 10, c = 0, d = 0;
	// c = ++a;		// 선 증감 후 연산
	// d = b++;		// 선 연산 후 증감

	// cout << "a: " << a << endl;
	// cout << "c: " << c << endl;
	// cout << "============================" << c << endl;
	// cout << "b: " << b << endl;
	// cout << "d: " << d << endl;


	// ##2. 형변환 (캐스팅)

	// 1. 대입 연산 시 형변환
	
	// 묵시적 형변환
	// int a = 'A'; // 대입 연산 기준으로 우측의 자료는 좌측 기준으로 형변환 된다.
	
	// cout << a << endl;

	// 명시적 형변환
	// int b = (int)'B';


	// 2. 연산 과정에서의 형변환

	// 서로 유형이 다를 때
	 int a = 10;
	 float b = 3.14f;

	// 정수 vs 실수 간의 연산 결과는 실수 타입으로 묵시적 형변환이 일어난다.
	 cout << sizeof(a*b) << endl;
	 cout << a * b << endl; // 묵시적 형변환
	 cout << int(a*b) << endl; // 명시적 형변환

	// 서로 유형이 같을 때
	// int a = 10;
	// long long b = 10;
	
	// cout << a * b << endl;

	// 같은 유형끼리 연산일 때에는 메모리가 큰쪽으로 묵시적 형변환
	// cout << sizeof(a*b) << endl;


	// cout << (char)72 << (char)101 << (char)108 << (char)108 << endl;

	// int itotal = 275;
	// float fAverage = (float)itotal / 3;
	// 
	// cout << fAverage << endl;
	return;
}