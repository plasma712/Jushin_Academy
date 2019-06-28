#include<iostream>
using namespace std;

void main()
{
	// ##1. 기본 연산자.
	// 산술 연산자, 대입 연산자, sizeof 연산자, 관계 연산자, 논리 연산자
	// 비트단위 연산자

	// 연산자 : 연산한 결과를 반환.
	// 피연산자 : 연산의 대상

//////////////////////////////////////////////////////////////////////////////////////////////////////

	// ##2. 대입 연산자 (할당 연산자)
	//int a = 0, b = 0, c = 0;

	// = (대입 연산자)
	// 우측 피연산자가 갖고 있는 값을 좌측 피연산자로 복사 수행.
	//a = 100;

	// 대입 연산자는 오른쪽부터 수행.

	//b = c = a;

	//cout << "a : " << a << endl;
	//cout << "b : " << b << endl;
	//cout << "c : " << c << endl;

//////////////////////////////////////////////////////////////////////////////////////////////////////

	// ##3. 산술 연산자 ( + , - , * , / , % )
	// 기본 왼쪽부터 연산 진행

	// 연산자도 우선순위가 반드시 존재한다. 곱셈 우선
	//cout << 3 + 3 * 3 + 3 << endl;

	// 우선순위를 가릴 땐 ( ) 를 이용하라.

	//cout << (3 + 3) * (3 + 3) << endl;

	//int a = 5;
	//int b = 5 / 2; // 나누기 연산 (둘을 나눈 몫이 결과)
	//int c = 5 % 2; // 나머지 연산자 (둘을 나눈 나머지가 결과)

	//cout << b << endl;
	//cout << c << endl;

	// ##4. sizeof 연산자
	// 피연산자의 메모리크기를 측정하는 연산자. (byte 단위.)

	// char				a = 'A';
	// bool				b = true;
	// short			c = 100;
	// int				d = 1000;
	// long long		e = 10000;
	// float			f = 3.14f; //float 타입은 값 뒤에 f키워드를 붙여준다.
	// double			g = 3.141592;
	// 
	// cout << "char의 크기: " << sizeof(char) << endl;
	// cout << "a의 크기" << sizeof(a) << endl;
	// cout << "---------------------------------" << endl;
	// 
	// cout << "bool의 크기: " << sizeof(bool) << endl;
	// cout << "b의 크기" << sizeof(b) << endl;
	// cout << "---------------------------------" << endl;
	// 
	// cout << "short의 크기: " << sizeof(short) << endl;
	// cout << "c의 크기" << sizeof(c) << endl;
	// cout << "---------------------------------" << endl;
	// 
	// cout << "int의 크기: " << sizeof(int) << endl;
	// cout << "d의 크기" << sizeof(d) << endl;
	// cout << "---------------------------------" << endl;
	// 
	// cout << "long long의 크기: " << sizeof(long long) << endl;
	// cout << "e의 크기" << sizeof(e) << endl;
	// cout << "---------------------------------" << endl;
	// 
	// cout << "float의 크기: " << sizeof(float) << endl;
	// cout << "f의 크기" << sizeof(f) << endl;
	// cout << "---------------------------------" << endl;
	// 
	// cout << "double의 크기: " << sizeof(double) << endl;
	// cout << "g의 크기" << sizeof(g) << endl;
	// cout << "---------------------------------" << endl;

	// ##5. 임시 메모리
	// 임시 메모리란 이름이 없는 공간을 의미한다.
	// 해당 코드라인을 벗어나자마자 소멸되는 공간이다.

	// int a = 5 + 5;
	// cout << a << endl;
	// cout << sizeof(a) << endl;
	// cout << "---------------------------------" << endl;
	//  임시메모리가 할당 될 때 정수는 int로 간주
	// cout << 5 + 5 << endl;
	// cout << sizeof(5 + 5) << endl;

	// char a = 100, b = 50;
	// cout << sizeof(a + b) << endl;

	// 임시메모리가 할당 될 때 실수는 double로 간주 (실수 뒤에 f가 없을 경우)
	// cout << sizeof(3.14f) << endl;
	// cout << sizeof(3.14) << endl;

	// ##6. 관계 연산자 (> , >= , < , <= , == , !=)
	// 두 피연산자의 관계를 따져서 참 또는 거짓을 반환하는 연산자.
	// int a = 100, b = 200;
	// 
	// cout << (a > b) << endl;
	// cout << (a >= b) << endl;
	// cout << (a < b) << endl;
	// cout << (a <= b) << endl;
	// cout << (a == b) << endl;
	// cout << (a != b) << endl;

	// 변수 이름은 대소문자를 확실히 가린다.
	int a = 100;
	int A = 200;

	// 같은 공간에 같은 이름의 변수를 선언할 수 없음.
	//int b = 100;
	//int b = 200; // error


	// ##7. 키보드로부터 값 입력받기.

	//int Input = 0;

	// console in
	// >> (삽입 연산자)
	//cout << "키보드 입력: ";
	//cin >> Input;
	//
	//cout << "출력: " << Input << endl;

	return;
}